#include "setup.hpp"
#include <unistd.h>
#include <cstdio.h>
#include <atomic.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void createSocket(){
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr << "Error creating socket" << std::endl;
    }
}
