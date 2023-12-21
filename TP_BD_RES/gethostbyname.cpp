#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char* argv[]){
    char* hostname;
    if (argc > 1){
        hostname = argv[1];
    }
    else{
        std::cout << "Entrez le nom d'hôte : ";
        hostname= new char[256];
        std::cin >>hostname;
    }
    struct hostent* host = gethostbyname(hostname);
    if (host == NULL){
        std::cerr << "Erreur : Impossible de récupéré le nom d'hôte." << std::endl;
        return 1;
    }
    std::cout << "Nom d'hôte : " << host->h_name << std::endl;
    for (int i = 0; host->h_addr_list[i] != NULL; i++){
        struct in_addr addr;
        memcpy(&addr, host->h_addr_list[i], sizeof(struct in_addr));
        std::cout << "Adresse IP : " << inet_ntoa(addr) << std::endl;
    }
    return 0;
}