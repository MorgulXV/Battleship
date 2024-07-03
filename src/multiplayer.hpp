#include "setup.hpp"
#include <unistd.h>
#include <cstdio.h>
#include <atomic.h>

struct Packet{
    unsigned char x : 4;
    unsigned char y : 4;
    unsigned char isShip : 1;
    unsigned char isSunken : 1;
};