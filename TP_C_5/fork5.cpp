#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void fils_process(int compt){
    printf("Début du processus %d (PID : %d, PPID : %d)\n", compt, getpid(), getppid());
    sleep(compt);
    printf("Fin du processus %d (PID : %d, PPID : %d)\n", compt, getpid(), getppid());
}

int main(){
    printf("Début du Père.\n");
    int compt = 0;
    while (1){
        printf("Père : Création d'un nouveau fils.\n");
        pid_t pid = fork();
        switch (pid){
            case -1:
                fprintf(stderr, "Erreur lors de la création du processus fils.\n");
                exit(1);
            case 0:
                fils_process(compt);
                exit(0);
            default:
                printf("Je suis le processus père. Mon PID est : %d, Le PID de mon fils est : %d\n", getpid(), pid);
                int status;
                wait(&status);

                char choix;
                printf("Voulez-vous créer un autre fils ? (O/N): ");
                scanf(" %c", &choix);

                if (choix == 'N' || choix == 'n'){
                    printf("Fin du Père.\n");
                    exit(0);
                }
                compt+=1;
        }
    }
    return 0;
}
