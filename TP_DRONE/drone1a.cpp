/*~~~~~~~~~~~~~~~~~~~~
Peter SARRITZU
SNIR2
21/12/2023
~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char* argv[]){
    if (argc != 2){
        std::cout << "Usage: drone1a <AdresseIPServeur>" << std::endl;
        return 1;
    }
    const char* serverIP = argv[1];
    const int port = 8889;
    const int taille = 256;
    char requete[taille];
    int socketClient;
    socketClient = socket(AF_INET, SOCK_DGRAM, 0);
    if (socketClient < 0){
        std::cerr << "Erreur lors de la création du socket" << std::endl;
        return 1;
    }
    sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_pton(AF_INET, serverIP, &(addr.sin_addr)) <= 0){
        std::cerr << "Adresse IP du serveur invalide" << std::endl;
        return 1;
    }
    while (true){
        std::cout << "Entrez une requête : ";
        std::cin >> requete;
        std::cout << "\n";
        if (sendto(socketClient, requete, strlen(requete), 0, (struct sockaddr*)&addr, sizeof(addr)) < 0){
            std::cerr << "Erreur lors de l'envoi de la requête" << std::endl;
            return 1;
        }
        char message[taille];
        memset(message, 0, taille);
        socklen_t serverAddrLen = sizeof(addr);
        if (recvfrom(socketClient, message, taille-1, 0, (struct sockaddr*)&addr, &serverAddrLen) < 0){
            std::cerr << "Erreur lors de la réception du message" << std::endl;
            return 1;
        }
        else if (strcmp(message, "OK") == 0){
            continue;
        }
        std::cout << "Message reçu : " << message << std::endl;
    }
    return 0;
}