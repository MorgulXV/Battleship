#include <cstdlib>
#include <iostream>
#include "setup.hpp"
#include "input.hpp"
#include "termcolor.hpp"
#include "reset.hpp"
#include "game.hpp"

int main(){
    std::cout << "Size of Board: " << sizeof(Board) << std::endl;
    std::cout << &Board[0][0] << std::endl;
    input();
    assignPos();
    output();
    outputShips(Board);
    reset();
    return 0;
}