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
    if (argc ==1){
        std::cerr << "Usage : ./client_gest <serveur> <cmde> <num> [intitule]" << std::endl;
        return 1;
    }
    const char* serverHostname = argv[1];
    const int port = 26000;
    const int taille = 256;
    char trame[taille];
    const char* cmde = argv[2];
    const char* num = argv[3];
    const char* intitule = argv[4];
    if (argc == 4){
        strcpy(trame, cmde);
        strcat(trame, "|");
        strcat(trame, num);
    }
    else if(argc == 5){
        strcpy(trame, cmde);
        strcat(trame, "|");
        strcat(trame, num);
        strcat(trame, "|");
        strcat(trame, intitule);
    }
    int socketClient;
    struct hostent* serverHost = gethostbyname(serverHostname);
    if (serverHost == NULL){
        std::cerr << "Impossible de trouver l'adresse IP du serveur" << std::endl;
        return 1;
    }
    socketClient = socket(AF_INET, SOCK_STREAM, 0);
    if (socketClient < 0){
        std::cerr << "Erreur lors de la création du socket" << std::endl;
        return 1;
    }
    sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    memcpy(&addr.sin_addr, serverHost->h_addr, serverHost->h_length);
    if (connect(socketClient, (struct sockaddr*)&addr, sizeof(addr)) < 0){
        std::cerr << "Erreur lors de la connexion au serveur" << std::endl;
        return 1;
    }
    else{
        if (send(socketClient, trame, sizeof(trame), 0) < 0){
        std::cerr << "Erreur lors de l'envoi de la trame" << std::endl;
        return 1;
        }
        char message[taille];
        memset(message, 0, taille);
        if (recv(socketClient, message, taille-1, 0) < 0){
            std::cerr << "Erreur lors de la réception du message" << std::endl;
            return 1;
        }
        std::cout << "Intitulé du cours : " << message << std::endl;
    }
    return 0;
}