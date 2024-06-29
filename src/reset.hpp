#ifndef RESET_HPP
#define RESET_HPP
#include "setup.hpp"

void reset(){
    for(int j = 0; j<10; j++){
        for(int k = 0; k < 10; k++){
            Board[j][k].isShip = 0;
            Board[j][k].isSunken = 0;
            Board[j][k].x = 0;
            Board[j][k].y = 0;
        }
    }
    for(int i = 0; i<=MAX_SHIPS; i++){
        Ships[i].startX = 0;
        Ships[i].startY = 0;
        Ships[i].length = 0;
    }
}


#endif









