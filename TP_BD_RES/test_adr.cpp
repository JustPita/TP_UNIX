#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(int argc, char** argv) {
    std::string ip;
    ip = argv[1];

    unsigned long addr = inet_addr(ip.c_str());
    if (addr != INADDR_NONE){
        std::cout << "Adresse IP valide " << std::endl;
        return 0;
    }
    else{
        std::cout << "Adresse IP invalide " << std::endl;
        return -1;
    }

    return 0;
}