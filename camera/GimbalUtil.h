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


class GimbalController {
    int     fd;
    bool    active;

    int set_interface_attribs(int, int);
    template<typename Out>
        void split(const std::string &s, char delim, Out result);
    std::vector<std::string> split(const std::string &s, char delim);
public:
    GimbalController(std::string);
    ~GimbalController();

    void writeToUART(std::string s);
    bool isActive(){ return active; }
};
