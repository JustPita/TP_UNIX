/*~~~~~~~~~~~~~~~~~~~~
Peter SARRITZU
SNIR2
20/12/2023
~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <iomanip>
#include <unistd.h> // Ajout de cette ligne pour utiliser fork()

int main() {
    const int port = 25000;
    const int taille = 10;
    char message[taille];
    system("clear");
    sql::Driver *dr;
    sql::Connection *cnx;
    sql::Statement *st;
    sql::ResultSet *res;
    dr = get_driver_instance();
    cnx = dr->connect("localhost", "root", "adminx");
    cnx->setSchema("FORMAPRO");
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
    if (bind(socketServeur, (struct sockaddr*)&addrServeur, sizeof(addrServeur)) < 0){
        std::cerr << "Erreur lors du bind du socket" << std::endl;
        return 1;
    }
    if (listen(socketServeur, 1) < 0){
        std::cerr << "Erreur lors de l'écoute du socket" << std::endl;
        return 1;
    }
    while (true){
        sockaddr_in addrClient;
        socklen_t addrClientTaille = sizeof(addrClient);
        int socketClient = accept(socketServeur, (struct sockaddr*)&addrClient, &addrClientTaille);
        if (socketClient < 0){
            std::cerr << "Erreur lors de l'acceptation de la connexion client" << std::endl;
            return 1;
        }
        std::cout << "Connexion client acceptée pour l'adresse IP : " << inet_ntoa(addrClient.sin_addr) << std::endl;
        memset(message, 0, taille);
        if (recv(socketClient, message, taille-1, 0) < 0){
            std::cerr << "Erreur lors de la réception du numéro de cours" << std::endl;
            return 1;
        }
        st = cnx->createStatement();
        std::string requete = "SELECT intitule FROM cours WHERE numco = " + std::string(message);
        res = st->executeQuery(requete);
        std::string intitule;
        if (res->next()){
            intitule = res->getString("intitule");
        }
        else{
            intitule = "Cours non trouvé.";
        }
        pid_t pid = fork();
        if (pid < 0) {
            std::cerr << "Erreur lors de la création du processus fils" << std::endl;
            return 1;
        }
        else if (pid == 0){
            if (send(socketClient, intitule.c_str(), intitule.length(),0) < 0) {
                std::cerr << "Erreur lors de l'envoi de l'intitulé du cours" << std::endl;
                return 1;
            }
            close(socketClient);
            return 0;
        }
        else{
            close(socketClient);
        }
    }
    close(socketServeur);
    return 0;
}