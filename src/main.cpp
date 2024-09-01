#include <cstdlib>
#include <iostream>
#include "setup.hpp"
#include "input.hpp"
#include "termcolor.hpp"
#include "reset.hpp"
#include "game.hpp"
#include "multiplayer.hpp"

int main(){
    std::cout << "Size of Board: " << sizeof(Board) << std::endl;
    std::cout << &Board[0][0] << std::endl;
    setClient();
    input();
    assignPos();
    output();
    outputShips(Board);
    openTerminal();
    reset();
    return 0;
}