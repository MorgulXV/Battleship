#ifndef MULTIPLAYER_HPP
#define MULTIPLAYER_HPP
#include "setup.hpp"
#include <unistd.h>
#include <stdatomic.h>
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>


sockaddr_in convertStringToSockaddr(const std::string &ip, int port) {
    sockaddr_in address;
    address.sin_family = AF_INET; // Use IPv4
    address.sin_port = htons(port); // Convert port to network byte order

    // Convert the IP address from string to binary form
    if (inet_pton(AF_INET, ip.c_str(), &address.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        // Handle error appropriately
    }

    return address;
}


sockaddr_in serverAddress;

void setupSocket(){
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    if(isClient == static_cast<bool>(true)){
        sockaddr_in serverAddress = convertStringToSockaddr(enemy_ip, port);
        bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    }else{
        sockaddr_in serverAddress = convertStringToSockaddr(my_ip, port);
        bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    }
}

void hit(){
    int x;
    int y;
    int tmp;

    std::cout << "Where do you want to shoot";
    std::cout << "Input X coordinate";
    std::cin >> tmp;
    x = static_cast<int>(tmp);
    std::cout << "Input Y coordinate";
    std::cin >> tmp;
    y = static_cast<int>(tmp);
    Packet Packet;
    Packet.x = x;
    Packet.y = y;
    //sendPacket(Packet);
}


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
            isClient = static_cast<bool>(tmp);
            //std::cout << termcolor::red << "Error invalid input type\n" << termcolor::reset;
        }else{
            isClient = static_cast<bool>(tmp);
        }if(isClient == bool(1)){
            Client();
        }else{
            Server();
        }
    }

void createPipe(){
    
}
#endif