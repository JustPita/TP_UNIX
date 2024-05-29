/*~~~~~~~~~~~~~~~~~~~~
Peter SARRITZU
SNIR2
06/12/2023
~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(){
    const int port = 20000;
    const int taille = 10;
    int socketDuServeur = socket(AF_INET, SOCK_DGRAM, 0);
    if (socketDuServeur < 0){
        std::cerr << "Erreur lors de la création du socket" << std::endl;
        return 1;
    }
    sockaddr_in addrServeur;
    memset(&addrServeur, 0, sizeof(addrServeur));
    addrServeur.sin_family = AF_INET;
    addrServeur.sin_port = htons(port);
    addrServeur.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(socketDuServeur, (struct sockaddr*)&addrServeur, sizeof(addrServeur)) < 0){
        std::cerr << "Erreur lors de la liaison du socket" << std::endl;
        return 1;
    }
    char messageEnMemoire[taille];
    sockaddr_in addrClient;
    socklen_t addrClientSize = sizeof(addrClient);
    while (true){
        int i = recvfrom(socketDuServeur, messageEnMemoire, taille, 0, (struct sockaddr*)&addrClient, &addrClientSize);
        if (i < 0) {
            std::cerr << "Erreur lors de la réception du message" <<i<< std::endl;
            return 1;
        }
        else if (sizeof(messageEnMemoire)>10){
            std::cerr << "Message trop long (max 10)" << std::endl;
            continue;
        }
        else{
        std::cout << "Message reçu: " << messageEnMemoire <<" de taille: <" << taille<<"oct>"<< std::endl;
        std::cout << "Adresse IP du client: " << inet_ntoa(addrClient.sin_addr) << std::endl;
        }
    }
    return 0;
}