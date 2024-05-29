#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    printf("Début du Père.\n");
    pid_t pid = fork();
    switch (pid){
        case -1:
            fprintf(stderr, "Erreur lors de la création du processus fils.\n");
            exit(1);
        case 0:
            printf("Je suis le processus fils.\n");
            system("ps -f");
            printf("Mort du processus fils.\n");
            exit(0);
        default:
            printf("Je suis le processus père et je reprends après la naissance du fils.\n");
            sleep(5);
            exit(0);
    }
    return 0;
}
