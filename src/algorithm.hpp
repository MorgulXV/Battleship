#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <array>
#include <algorithm>
#include "setup.hpp"
#include "input.hpp"

void outputShips(const std::array<std::array<Field, MAX_X>, MAX_Y> Board){
    for(int j = 0; j < MAX_X; j++){
        for(int k = 0; k < MAX_Y; k++){
            if(Board[j][k].isShip == true){
                std::cout << "Ship at x:" << j << "\n";
                std::cout << "Ship at y:" << k << "\n";
            }
        } 
    }
}

int left(int x, int y){

}


void findShips(const std::array<std::array<Field, MAX_X>, MAX_Y> Board){
    unsigned char currX = 0;
    unsigned char currY = 0;
    unsigned char shipsCounter = 0;
    if(Board[currX][currY].isShip == true) && (Board[currX][currY].visited == 0){
        Ships[shipsCounter].startX = currX;
        Ships[shipsCounter].startY = currY;
        Board[currX][currY].visited = true;
        
    }
    
}
#endif
