#include <iostream>
#include "window_class.h"


int main() {
    Window* newWindow = new Window ();
    std::string command;

    while (command != "close"){
        std::cout << ": ";
        std::cin >> command;
        if (command == "display"){
            newWindow ->display();
        }
        if(command == "resize"){
            newWindow ->resize ();
        }
        if(command == "move"){
            newWindow -> move();
        }
        if (command == "close"){
            newWindow ->close();
        }
    }
    delete newWindow;
    newWindow = nullptr;

}
