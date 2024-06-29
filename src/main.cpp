#include <cstdlib>
#include <iostream>
#include "setup.hpp"
#include "input.hpp"
#include "termcolor.hpp"
#include "reset.hpp"
#include "kelp.hpp"

int main(){
    std::cout << "Size of Board: " << sizeof(Board) << std::endl;
    input();
    assignPos();
    output();
    searchAdjacentShips(Board);
    reset();
    return 0;
}