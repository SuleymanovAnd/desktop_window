#include "window_class.h"

void Window::resize (){
    std::cout << "Enter height: ";
    std::cin >> height;
    while (overflow()){std::cin >> height;}
    while ((int)(screen -> Y - upperLeftCorner[1] - height) < 0) {std::cout << "window coordinates go off screen. Re-enter the height:";
        std::cin >> height; while (overflow()){std::cin >> height;}}

    std::cout << "Enter width: ";
    std::cin >> width;
    while (overflow()){std::cin >> width;}
    while ((int)(screen -> X - upperLeftCorner[0]- width) < 0) {std::cout << "window coordinates go off screen. Re-enter the width:";
        std::cin >> width; while (overflow()){std::cin >> width;}}
}

void Window::move(){
    std::cout << "Enter window coordinate offset: ";
    int offset [2];
    std::cin >> offset[0] >> offset [1];

    while (overflow ()){std::cin >> offset[0] >> offset [1];}
    while ( (int)(screen -> X - (upperLeftCorner[0] + offset[0]) - width) < 0 ||
            (int)(screen -> X -(upperLeftCorner[0] + offset[0] + width)) > 80 ||
            (int) (screen -> Y -(upperLeftCorner[1] + offset [1])) > 50 ||
            (int)(screen -> Y - (upperLeftCorner[1] + offset [1]) - height) < 0){
        std::cout <<  (int)(screen -> X - (upperLeftCorner[0] + offset[0]) - width) << " " << 1 << std::endl;
        std::cout << (int)(screen -> Y - (upperLeftCorner[1] + offset [1]) - height) << " " << 2 << std::endl;
        std::cout << "window coordinates go off screen.Re-enter the coordinate: ";
        std::cin >> offset[0] >>  offset [1];
        while (overflow ()){std::cin >> offset[0] >> offset [1];;}
    }
    upperLeftCorner[0] += offset[0];
    upperLeftCorner[1] += offset[1];
    std::cout << "New window coordinates: " << upperLeftCorner[0] << " / " << upperLeftCorner[1];
}
void Window::display(){
    system ("cls");
    int display [screen -> X] [screen -> Y];
    for (int i = 0; i< screen->Y;i++){
        for(int j = 0; j <screen ->X;j++){
            if (j < upperLeftCorner[0] && i < upperLeftCorner [1]){display [i][j] = 0;}
            if ((j >= upperLeftCorner[0] && j < (width + upperLeftCorner[0]))&&
                ( i >= upperLeftCorner [1] && i < (height + upperLeftCorner [1]))) {display [i][j] = 1;}
            else {display [i][j] = 0;}
            std::cout << display [i][j];
        }
        std::cout << std::endl;
    }
}
void Window::close(){
    delete screen;
    screen = nullptr;
}