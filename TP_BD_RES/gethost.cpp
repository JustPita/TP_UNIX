#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <netdb.h>


int main(int argc, char* argv[]){
    if (argc != 2){
        std::string input;
        std::cout << "Veuillez entrer un nom d'hôte ou une adresse IP : ";
        std::cin >> input;
        char* entrer = new char[input.length() + 1];
        strcpy(entrer, input.c_str());
        struct in_addr addr;
        if (inet_aton(entrer, &addr) == 0){
            struct hostent* host = gethostbyname(entrer);
            if (host == NULL){
                std::cerr << "Erreur : Impossible de récupérer le nom d'hôte." << std::endl;
                return 1;
            }
            std::cout << "Nom d'hôte : " << host->h_name << std::endl;
            for (int i = 0; host->h_addr_list[i] != NULL; i++){
                struct in_addr addr;
                memcpy(&addr, host->h_addr_list[i], sizeof(struct in_addr));
                std::cout << "Adresse IP : " << inet_ntoa(addr) << std::endl;
            }
        }
        else{
            struct hostent* host = gethostbyaddr(&addr, sizeof(addr), AF_INET);
            if (host == NULL){
                std::cerr << "Erreur : Impossible de récupérer le nom d'hôte." << std::endl;
                return 1;
            }
            std::cout << "Nom d'hôte : " << host->h_name << std::endl;
            std::cout << "Adresse IP : " << inet_ntoa(addr) << std::endl;
        }
        delete[] entrer;
    }
    else {
        char* input = argv[1];
        struct in_addr addr;
        if (inet_aton(input, &addr) == 0){
            struct hostent* host = gethostbyname(input);
            if (host == NULL){
                std::cerr << "Erreur : Impossible de récupérer le nom d'hôte." << std::endl;
                return 1;
            }
            std::cout << "Nom d'hôte : " << host->h_name << std::endl;
            for (int i = 0; host->h_addr_list[i] != NULL; i++){
                struct in_addr addr;
                memcpy(&addr, host->h_addr_list[i], sizeof(struct in_addr));
                std::cout << "Adresse IP : " << inet_ntoa(addr) << std::endl;
            }
        }
        else{
            struct hostent* host = gethostbyaddr(&addr, sizeof(addr), AF_INET);
            if (host == NULL){
                std::cerr << "Erreur : Impossible de récupérer le nom d'hôte." << std::endl;
                return 1;
            }
            std::cout << "Nom d'hôte : " << host->h_name << std::endl;
            std::cout << "Adresse IP : " << inet_ntoa(addr) << std::endl;
        }
    }
    return 0;
}