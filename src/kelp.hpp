#ifndef KELP_HPP
#define KELP_HPP

#include <array>
#include <algorithm>
#include "setup.hpp"
#include "input.hpp"

std::array<Ship, 5> searchAdjacentShips(const std::array<std::array<Field, MAX_X>, MAX_Y> Board){
    for(int j = 0; j < 10; j++){
        for(int k = 0; k < 10; k++){
            if(Board[j][k].isShip == true){
                std::cout << "Ship at x:" << j << "\n";
                std::cout << "Ship at y:" << k << "\n";
            }
        } 
    }
    return Ships;
}


#endif
