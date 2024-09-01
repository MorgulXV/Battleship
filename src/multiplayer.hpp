#ifndef MULTIPLAYER_HPP
#define MULTIPLAYER_HPP
#include "setup.hpp"
#include <unistd.h>
#include <stdatomic.h>
#include <cstdlib>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>



void setupSocket(){

}

/*bool hit(int x, int y){
    //sendPacket();
}
*/

void openTerminal(){
    execlp("open", "-n", "/System/Applications/Utilities/Terminal.app", NULL);
    
}


void Server(){
    std::cout << "What port do you want to use to recieve and send packets?:\n";
    std::cin >> port;
    if(std::cin.fail() || port > 65535){
        std::cout << termcolor::red << "Error invalid port\n" << termcolor::reset;
        throw std::invalid_argument{"InvalidPort"};
    }else{
        std::cout << "Input IPv4 adress of the other player:\n";
        std::cin >> enemy_ip;
        if(std::cin.fail()){
        std::cout << termcolor::red << "Error invalid IPv4 adress\n" << termcolor::reset;
        throw std::invalid_argument{"InvalidIPv4Address"};
    }
    if (!std::regex_match(enemy_ip, IPv4Regex)) {
        std::cout << termcolor::red << "Error invalid IPv4 adress\n" << termcolor::reset;
        throw std::invalid_argument{"InvalidIPv4Address"};
        }else{
            setupSocket();
        }
    }
}

void Client(){
    std::cout << "What port do you want to use to recieve and send packets?:\n";
    std::cin >> port;
    if(std::cin.fail() || port > 65535){
        std::cout << termcolor::red << "Error invalid port\n" << termcolor::reset;
        throw std::invalid_argument{"InvalidPort"};
    }else{
        std::cout << "Input IPv4 adress of the other player:\n";
        std::cin >> enemy_ip;
        if(std::cin.fail()){
        std::cout << termcolor::red << "Error invalid IPv4 adress\n" << termcolor::reset;
        throw std::invalid_argument{"InvalidIPv4Address"};
    }
    if (!std::regex_match(enemy_ip, IPv4Regex)) {
        std::cout << termcolor::red << "Error invalid IPv4 adress\n" << termcolor::reset;
        throw std::invalid_argument{"InvalidIPv4Address"};
        }else{
            setupSocket();
        }
    }
}

void setClient(){
    int tmp;
    std::cout << "What are you?: Client(1), Host(0)\n";
    std::cin >> tmp;
    if (std::cin.fail()){
            std::cout << termcolor::red << "Error invalid input type\n" << termcolor::reset;
            throw std::invalid_argument{"InvalidInputType"};
        }else{
            isClient = static_cast<bool>(tmp);
        }if(isClient == bool(1)){
            Client();
        }else{
            Server();
        }
    }

#endif