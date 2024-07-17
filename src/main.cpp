#include <cstdlib>
#include <iostream>
#include "setup.hpp"
#include "input.hpp"
#include "termcolor.hpp"
#include "reset.hpp"
#include "algorithm.hpp"

int main(){
    std::cout << "Size of Board: " << sizeof(Board) << std::endl;
    std::cout << &Board[0][0] << std::endl;
    input();
    assignPos();
    output();
    searchAdjacentShips(Board);
    reset();
    return 0;
}