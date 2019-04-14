#include "../inc/GimbalUtil.h"
#include <assert.h>
#include <ctime>

#define HMID 310
#define VMID 240
#define MAX_MARGIN 50
#define DEAD_BAND 25
// change port name to your port
GimbalController::GimbalController(std::string portname):
    fd(open(portname.c_str(), O_RDWR | O_NOCTTY | O_SYNC)),active(true)
{
    if (fd < 0) {
        std::cerr << "Error opening " << portname << ": " << strerror(errno) << std::endl;
        active = false;
        return;
    }


    /*baudrate 115200, 8 bits, no parity, 1 stop bit */
    set_interface_attribs(fd, B115200);

    face_x = 100, face_y = 100;
    for(int i = 0;i < 6;i++) pwm[i] = 100;
    pwm[1] = 150;
    sender = new std::thread(GimbalController::send, this);
    sleep(1);
}

GimbalController::~GimbalController() {
    delete sender;
}


template<typename Out>
void GimbalController::split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}


std::vector<std::string> GimbalController::split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}


int GimbalController::set_interface_attribs(int fd, int speed)
{
    struct termios tty;

    if (tcgetattr(fd, &tty) < 0) {
        printf("Error from tcgetattr: %s\n", strerror(errno));
        return -1;
    }

    cfsetospeed(&tty, (speed_t)speed);
    cfsetispeed(&tty, (speed_t)speed);

    tty.c_cflag &= ~PARENB;             /* no parity bit */
    tty.c_cflag &= ~CSTOPB;             /* only need 1 stop bit */
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;                 /* 8-bit characters */

    /* fetch bytes as they become available */
    tty.c_cc[VMIN] = 1;
    tty.c_cc[VTIME] = 5;
    tty.c_cflag |= (CLOCAL | CREAD);    /* ignore modem controls */
    tty.c_cflag &= ~CRTSCTS;            /* no hardware flowcontrol */

    /* Make raw */
    cfmakeraw(&tty);

    /* Flush Port, then applies attributes */
    tcflush( fd, TCIFLUSH );
    if ( tcsetattr ( fd, TCSANOW, &tty ) != 0) {
        std::cout << "Error " << errno << " from tcsetattr" << std::endl;
        return -1;
    }

    return 0;
}


void GimbalController::writeToUART(uint8_t* data, uint8_t size) {

    if(!active) return;
    int n_written = 0, spot = 0;

    do {
        n_written = write(fd, &data[spot], 1);
        spot += n_written;
    } while (spot < size);

    uint8_t ter = 255;
    do {
        n_written = write(fd, &ter, 1);
    } while (!n_written);
}


void GimbalController::sendMessage() {

    uint8_t ss=1, xval=0, yval=0;
    uint8_t dataOut[9];
    if(active) {
        
        if      (face_x > HMID + MAX_MARGIN) xval = 0;
        else if (face_x < HMID - MAX_MARGIN) xval = 200;
        else if (face_x < HMID + DEAD_BAND && 
                face_x > HMID - DEAD_BAND) xval = 100;
        else    xval = HMID - face_x + 100;

        if      (face_y > VMID + MAX_MARGIN) yval = 200;
        else if (face_y < VMID - MAX_MARGIN) yval = 0;
        else if (face_y < VMID + DEAD_BAND && 
                face_y > VMID - DEAD_BAND) yval = 100;
        else    yval = face_y - VMID + 100;
    }

    dataOut[0] = ss; dataOut[1] = xval; dataOut[2] = yval;
    for(int i = 0;i < 6;i++) {
        dataOut[3+i] = pwm[i];
    }

    std::cout << "sending: signal select:" << (int)dataOut[0];
    std::cout << " face_x:" << (int)dataOut[1];
    std::cout << " face_y:" << (int)dataOut[2];
    for(int i = 0;i < 6;i++) {
        std::cout << " ch[" << i << "]:" << (int)dataOut[3+i];
    }
    std::cout << std::endl;

    writeToUART(dataOut, 9);
}

void GimbalController::send(GimbalController* gc) {
    static int i = 0;
    while(true) {
        gc->sendMessage();
        std::cout << i++ << std::endl;
        usleep(10000);
    }
}

void GimbalController::updateFace(int face_x, int face_y) {
    this->face_x = face_x;
    this->face_y = face_y;
}
