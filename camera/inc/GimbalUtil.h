#include <errno.h>
#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <thread>


class GimbalController {
    int     fd;
    bool    active;
    int     face_x, face_y;
    int     pwm[6];
    std::thread* sender;

    int set_interface_attribs(int, int);
    template<typename Out>
        void split(const std::string &s, char delim, Out result);
    std::vector<std::string> split(const std::string &s, char delim);
    void sendMessage();
    void writeToUART(std::string s);
    static void send(GimbalController* gc);
public:
    GimbalController(std::string portname);
    ~GimbalController();

    bool isActive(){ return active; }
    void updateFace(int face_x, int face_y);
};
