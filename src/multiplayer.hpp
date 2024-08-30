#ifndef MULTIPLAYER_HPP
#define MULTIPLAYER_HPP
#include "setup.hpp"
#include <unistd.h>
#include <stdatomic.h>
#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "/Users/timheilmann/homebrew/Cellar/zeromq/4.3.5_1/include/zmq.h"


void setClient(){
    int tmp;
    std::cout << "What are you?: Client(1), Host(0)";
    std::cin >> tmp;
    if (std::cin.fail()){
            std::cout << termcolor::red << "Error invalid input type\n" << termcolor::reset;
            throw std::invalid_argument{"InvalidInputType"};
        }else{
            isClient = bool(tmp);
        }
}

bool hit(int x, int y){
    //send message to other player
    //returns true if ship is hit
}

void openTerminal(){
    execlp("open", "-n", "/System/Applications/Utilities/Terminal.app", NULL);
    
}


void runHost(){

}
#endif