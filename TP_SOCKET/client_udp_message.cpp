/*~~~~~~~~~~~~~~~~~~~~
Peter SARRITZU
SNIR2
04/12/2023
~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char* argv[]){
    if (argc < 2){
        std::cout << "client_udp_message <NomDuServeur> [message]" << std::endl;
        return 1;
    }
    const char* serverHostname = argv[1];
    const int port = 20000;
    const int taille = 10;
    const char* message = "test";
    
    if(argc >= 3){
        message = argv[2];
    }
    
    int socketClient;
    struct hostent* serverHost = gethostbyname(serverHostname);
    if (serverHost == NULL){
        std::cerr << "Impossible de trouver l'adresse IP du serveur" << std::endl;
        return 1;
    }
    socketClient = socket(AF_INET, SOCK_DGRAM, 0);
    if (socketClient < 0){
        std::cerr << "Erreur lors de la création du socket" << std::endl;
        return 1;
    }
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    memcpy(&addr.sin_addr, serverHost->h_addr, serverHost->h_length);
    if (sendto(socketClient, message, taille, 0, (struct sockaddr*)&addr, sizeof(addr)) < 0){
        std::cerr << "Erreur lors de l'envoi du message" << std::endl;
        return 1;
    }
    std::cout << "Message envoyé avec succès" << std::endl;
    return 0;
}