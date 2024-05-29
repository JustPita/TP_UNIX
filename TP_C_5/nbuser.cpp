#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <cstring>

int main(){
    // Utilise execlp pour exécuter la commande Unix
    execlp("wc", "wc", "-l", "/etc/passwd", NULL);

    // Si execlp échoue, affiche une erreur
    perror("Erreur lors du recouvrement du processus");
    return 1;
}
