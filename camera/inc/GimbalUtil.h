#ifndef _GIMBAL_UTIL_H_
#define _GIMBAL_UTIL_H_
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
    uint8_t pwm[6];
    std::thread* sender;

    int set_interface_attribs(int, int);
    template<typename Out>
        void split(const std::string &s, char delim, Out result);
    std::vector<std::string> split(const std::string &s, char delim);
    void sendMessage();
    void writeToUART(uint8_t* data, uint8_t size);
    static void send(GimbalController* gc);
public:
    GimbalController(std::string portname);
    ~GimbalController();

    void Activative() {active = true;}
    void Deactivative() {active = false;}
    bool isActive(){ return active; }
    void updateFace(int face_x, int face_y);
    void updatePWM(int channel, int value);
    void Arm();
};

#endif
