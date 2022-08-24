#include <iostream>

bool overflow ( ){

    if (! std::cin){
        std::cout <<"Input error. Enter again: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        return true;
    } else {return false;}
}