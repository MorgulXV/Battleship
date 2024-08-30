#ifndef SETUP_HPP
#define SETUP_HPP
#define MAX_X 10
#define MAX_Y 10
#define MIN_X 0
#define MIN_Y 0
#define MAX_SHIPS 5
#define MAX_SHIP_LENGTH 5

#include <iostream>
#include <cstdlib>
#include <array>

int port = 1234;

int shipCounter = 0;
struct pos{
    int x;
    int y;
};

bool isClient;

struct Field
{
    unsigned char isShip : 1;
    unsigned char isSunken : 1;
    unsigned char x : 4;
    unsigned char y : 4;
    unsigned char visited : 1;

    Field() : isShip(0), isSunken(0), x(0), y(0) {}
};

std::array<std::array<Field, MAX_X>, MAX_Y> Board;

struct Ship
{
    int startX;
    int startY;
    int endX;
    int endY;
    int length = MAX_SHIP_LENGTH;
};

const int Mask = 0xF;

struct Packet{
    int x : 4;
    int y : 4;

    uint8_t merge(int x, int y){
        x = this -> x;
        y = this -> y;
        uint8_t data;
        uint8_t tmp = x;
        tmp <<= 4;
        data = (tmp & Mask) | y;
        return data;
    }
};
std::array<Ship, 5> Ships;
#endif