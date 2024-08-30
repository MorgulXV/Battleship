#ifndef MULTIPLAYER_HPP
#define MULTIPLAYER_HPP
#include "setup.hpp"
#include <unistd.h>
#include <stdatomic.h>
#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

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

/*bool hit(int x, int y){
    //sendPacket();
}
*/

void openTerminal(){
    execlp("open", "-n", "/System/Applications/Utilities/Terminal.app", NULL);
    
}


void Host(){
    std::cout << "What port do you want to use to recieve and send packets ?\n";
    std::cin >> port;
    if(std::cin.fail() || port > 65535){
        std::cout << termcolor::red << "Error invalid port\n" << termcolor::reset;
    }else{
        Host();
    }
}

void Client(){
    std::cout << "What port do you want to use to recieve and send packets ?\n";
    std::cin >> port;
    if(std::cin.fail() || port > 65535){
        std::cout << termcolor::red << "Error invalid port\n" << termcolor::reset;
    }else{
        Client();
    }
}

void createSocket(){

}

#endif