/*~~~~~~~~~~~~~~~~~~~~
Peter SARRITZU
SNIR2
04/12/2023
~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(){
    const int port = 22000;
    const int taille = 10;
    char message[taille];
    int socketServeur = socket(AF_INET, SOCK_STREAM, 0);
    if (socketServeur < 0){
        std::cerr << "Erreur lors de la création du socket" << std::endl;
        return 1;
    }
    sockaddr_in addrServeur;
    memset(&addrServeur, 0, sizeof(addrServeur));
    addrServeur.sin_family = AF_INET;
    addrServeur.sin_port = htons(port);
    addrServeur.sin_addr.s_addr = INADDR_ANY;
    if (bind(socketServeur, (struct sockaddr*)&addrServeur, sizeof(addrServeur))<0){
        std::cerr << "Erreur lors du bind du socket" << std::endl;
        return 1;
    }
    if (listen(socketServeur, 1) < 0){
        std::cerr << "Erreur lors de l'écoute du socket" << std::endl;
        return 1;
    }
    while (true){
        sockaddr_in addrClient;
        socklen_t addrClientLength = sizeof(addrClient);
        int socketClient = accept(socketServeur, (struct sockaddr*)&addrClient, &addrClientLength);
        if (socketClient < 0){
            std::cerr << "Erreur lors de l'acceptation de la connexion client" << std::endl;
            return 1;
        }
        std::cout << "Connexion client acceptée pour l'adresse IP : " << inet_ntoa(addrClient.sin_addr) << std::endl;
        memset(message, 0, taille);
        if (recv(socketClient, message, taille-1, 0)<0){
            std::cerr << "Erreur lors de la réception du message" << std::endl;
            return 1;
        }
        std::cout << "Message reçu : " << message<<" de taille: <" << taille<<"oct>"<< std::endl;
    }
    return 0;
}