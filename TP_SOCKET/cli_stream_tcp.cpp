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
    if (argc != 2){
        std::cout << "cli_stream_tcp <NomDuServeur>" << std::endl;
        return 1;
    }
    const char* serverHostname = argv[1];
    const int port = 23000;
    const int nbMessages = 1024;
    const int taille = 128;
    const char* message = "P.SARRITZU";
    int socketClient = socket(AF_INET, SOCK_STREAM, 0);
    if (socketClient < 0){
        std::cerr << "Erreur lors de la création du socket" << std::endl;
        return 1;
    }
    sockaddr_in addrServeur;
    memset(&addrServeur, 0, sizeof(addrServeur));
    addrServeur.sin_family = AF_INET;
    addrServeur.sin_port = htons(port);
    inet_pton(AF_INET, serverHostname, &(addrServeur.sin_addr));
    if (connect(socketClient, (struct sockaddr*)&addrServeur, sizeof(addrServeur)) < 0){
        std::cerr << "Erreur lors de la connexion au serveur" << std::endl;
        return 1;
    }
    std::cout << "Envoi de " << nbMessages << " messages au serveur TCP..." << std::endl;
    for (int i = 0; i < nbMessages; i++){
        if (send(socketClient, message, taille, 0) < 0){
            std::cerr << "Erreur lors de l'envoi du message" << std::endl;
            return 1;
        }
    }
    std::cout << "Tous les messages ont été envoyés avec succès" << std::endl;
    return 0;
}