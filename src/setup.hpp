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
#include <cstdint>
#include <regex>
#include <string>

bool win;

int port = 1234;
std::string enemy_ip = "192.168.178.20";

std::string pattern = R"(\b(?:(?:2(?:[0-4][0-9]|5[0-5])|[0-1]?[0-9]?[0-9])\.){3}(?:(?:2([0-4][0-9]|5[0-5])|[0-1]?[0-9]?[0-9]))\b)";
std::regex IPv4Regex(pattern);


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
std::array<std::array<Field, MAX_X>, MAX_Y> Enemy;

struct Ship
{
    int startX;
    int startY;
    int endX;
    int endY;
    int length = MAX_SHIP_LENGTH;
};


struct Packet{
    int x : 4;
    int y : 4;
    
    uint8_t merge() const{
        uint8_t data = (static_cast<uint8_t>(x) << 4) | (static_cast<uint8_t>(y));
        return data;
    }
};

struct firstPacket{
    uint8_t data =  255;
}

struct winPacket{
    uint8_t data = 240
}


std::array<Ship, 5> Ships;
#endif