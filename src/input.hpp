#ifndef INPUT_HPP
#define INPUT_HPP

#include "setup.hpp"
#include <iostream>
#include <cstdlib>
#include "termcolor.hpp"
#include <stdexcept>
#include "game.hpp"

void setShip(int x, int y, bool d, int l = 5){
    int z = y;
    int f = x;
    if(d==true){//true is down
        for(int i = 0; i<5; i++){
                if(Board[f][z].isShip==true){
                    std::cout << termcolor::red << "Error you cant let ships intersect\n" << termcolor::reset;
                    throw std::invalid_argument{"InvalidShipPlacement"};
                }else{
                    f++;
                }
                }
        if(x==6){
                std::cout << termcolor::red << "Error invalid ship placement\n" << termcolor::reset;
                throw std::invalid_argument{"InvalidShipPlacement"};
            }
            else{
                Ships[shipCounter].startX = x;
                Ships[shipCounter].startY = y;
                for(int i = 0; i<5; i++){
                Board[x][y].isShip=1;
                x++;
                }
            }
        }
        if(d==false){//false is right
            for(int i = 0; i<5; i++){
                if(Board[f][z].isShip==true){
                    std::cout << termcolor::red << "Error you cant let ships intersect\n" << termcolor::reset;
                    throw std::invalid_argument{"InvalidShipPlacement"};
                }else{
                    z++;
                }
                }
            if(y==6){
                std::cout << termcolor::red << "Error invalid ship placement\n" << termcolor::reset;
                throw std::invalid_argument{"InvalidShipPlacement"};
            }
            else{
                Ships[shipCounter].startX = x;
                Ships[shipCounter].startY = y;
                for(int i = 0; i<5; i++){
                Board[x][y].isShip=1;
                y++;
                }
            }
        }
        Ships[shipCounter].endX = x;
        Ships[shipCounter].endY = y;
        shipCounter++;
    }



void assignPos(){
    for(int j = 0; j<10; j++){
        for(int k = 0; k < 10; k++){
            Board[j][k].x = j;
            Board[j][k].y = k;
        }
    }
    
}

void input(){
    int i = 0;
    int counter = 0;
    while (i == 0 && counter <=5)
    {
        int x;
        int d;
        int y;
        int c = 0;
        int l;
        bool up;
        bool down;
        std::cout << termcolor::white << "Hello, please enter ship x start coordinate\n";
        std::cin >> x;
        if(x > MAX_X or x < MIN_X){
            std::cout << termcolor::red << "Error invalid coordinate\n" << termcolor::reset;
            throw std::invalid_argument{"InvalidCoordinate"};
        }
        if (std::cin.fail()){
            std::cout << termcolor::red << "Error invalid input type\n" << termcolor::reset;
            throw std::invalid_argument{"InvalidInputType"};
        }
        std::cout << termcolor::white << "Hello, please enter ship y start coordinate\n";
        std::cin >> y;
        if(y > MAX_Y or y < MIN_Y){
            std::cout << termcolor::red << "Error invalid coordinate\n" << termcolor::reset;
            throw std::invalid_argument{"InvalidCoordinate"};
        }
        if (std::cin.fail()){
            std::cout << termcolor::red << "Error invalid input type\n" << termcolor::reset;
            throw std::invalid_argument{"InvalidInputType"};
        }
        std::cout << termcolor::white << "Hello, please enter ship length\n";
        std::cin >> l;
        if(l!=5){
            std::cout << termcolor::red << "Error invalid ship length\n" << termcolor::reset;
            throw std::invalid_argument{"InvalidShipLength"};
        }
        if (std::cin.fail()){
            std::cout << termcolor::red << "Error invalid input type\n" << termcolor::reset;
            throw std::invalid_argument{"InvalidInputType"};
        }
        std::cout << termcolor::white << "Hello, please enter ship direction: 1 = down 0 = left\n";
        std::cin >> d;
        if (std::cin.fail()){
            std::cout << termcolor::red << "Error invalid input type\n" << termcolor::reset;
            throw std::invalid_argument{"InvalidInputType"};
        }
        setShip(x,y,d,l);
        counter++;
        if(counter == 5){
            //isClient();
            break;
        }
        std::cout << termcolor::white << "Do you want to enter more? 1 = no 0 = yes\n";
        std::cin >> i;
        std::cout << termcolor::reset << std::endl;
        if(std::cin.fail()){
            std::cout << termcolor::red << "Error invalid input type\n" << termcolor::reset;
            throw std::invalid_argument{"InvalidInputType"};
        }
        
    }
}

void output(){
    int counter = 0;
    for(int j = 0; j < 10; j++){
        for(int k = 0; k < 10; k++){
            if(Board[j][k].isShip == true){
                std::cout << termcolor::grey << "X " << termcolor::reset;
                counter++;
                if(counter == 10){
                    std::cout << std::endl;
                    counter -= 10;
                }
            }
            else{
                std::cout << termcolor::blue << "0 " << termcolor::reset;
                counter++;
                if(counter == 10){
                    std::cout << std::endl;
                    counter -= 10;
                }
            }
        }
    }
}

#endif