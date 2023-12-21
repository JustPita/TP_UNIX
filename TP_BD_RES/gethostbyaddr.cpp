#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char* argv[]){
    char* ipAdress;
    if (argc > 1){
        ipAdress = argv[1];
    }
    else{
        std::cout << "Entrez l'adresse IP : ";
        ipAdress = new char[256];
        std::cin >> ipAdress;
    }
    
    struct in_addr addr;
    if (inet_aton(ipAdress, &addr) == 0){
        std::cerr << "Erreur : Adresse IP invalide." << std::endl;
        return 1;
    }
    
    struct hostent* host = gethostbyaddr(&addr, sizeof(addr), AF_INET);
    if (host == NULL){
        std::cerr << "Erreur : Impossible de récupérer le nom d'hôte." << std::endl;
        return 1;
    }
    
    std::cout << "Nom d'hôte : " << host->h_name << std::endl;
    std::cout << "Adresse IP : " << inet_ntoa(addr) << std::endl;
    
    return 0;
}