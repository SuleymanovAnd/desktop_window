#include <vector>
#include <iostream>
#include "overflow.h"
#include "monitor.h"
class Window {
    Monitor* screen = new Monitor();
    unsigned int upperLeftCorner [2] = {0,0};
    unsigned int height = 0;
    unsigned int width = 0;

public:
    void resize ();
    void move ();
    void display ();
    void close ();
};