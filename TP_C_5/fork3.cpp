#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    printf("Début du Père.\n");
    pid_t pid = fork();
    switch (pid) {
        case -1:
            fprintf(stderr, "Erreur lors de la création du processus fils.\n");
            exit(1);
        case 0:
            printf("Je suis le processus fils. Mon PID est : %d, Mon PPID est : %d\n", getpid(), getppid());
            sleep(5);
            printf("Mort du processus fils.\n");
            exit(0);
        default:
            printf("Je suis le processus père. Mon PID est : %d, Le PID de mon fils est : %d\n", getpid(), pid);
            int status;
            wait(&status);
            exit(0);
    }
    return 0;
}
