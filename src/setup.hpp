#ifndef SETUP_HPP
#define SETUP_HPP
#define MAX_X 10
#define MAX_Y 10
#define MIN_X 0
#define MIN_Y 0
#define MAX_SHIPS 5

#include <iostream>
#include <cstdlib>
#include <array>

struct Field
{
    unsigned char isShip : 1;
    unsigned char isSunken : 1;
    unsigned char x : 4;
    unsigned char y : 4;

    Field() : isShip(0), isSunken(0), x(0), y(0) {}
};

std::array<std::array<Field, MAX_X>, MAX_Y> Board;

struct Ship
{
    int startX;
    int startY;
    int endX;
    int endY;
    int length;
};

std::array<Ship, 5> Ships;
#endif