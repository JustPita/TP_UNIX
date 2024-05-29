#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void fils_process(int nombre){
    printf("Début du processus %d (PID : %d, PPID : %d)\n", nombre, getpid(), getppid());
    sleep(nombre);
    printf("Fin du processus %d (PID : %d, PPID : %d)\n", nombre, getpid(), getppid());
}

int main(){
    printf("Début du Père.\n");
    for (int i = 1; i <= 5; i++){
        pid_t pid = fork();
    switch (pid){
            case -1:
                fprintf(stderr, "Erreur lors de la création du processus fils %d.\n", i);
                exit(1);
            case 0:
                
                fils_process(i);
                exit(0);
            default:
                printf("Pére : Au suivant !!!.\n");
                //printf("Je suis le processus père. Mon PID est : %d, Le PID de mon fils est : %d\n", getpid(), pid);
        }
    }
    printf("Fin du Père.\n");
    return 0;
}
