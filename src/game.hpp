#ifndef GAME_HPP
#define GAME_HPP

#include <ncurses.h>
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

void startGame(){

}
#endif
