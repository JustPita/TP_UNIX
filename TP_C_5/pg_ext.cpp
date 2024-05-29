#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <cstring>

int main(){
    int fd=3;
    const char *message = "Bonjour !!";
    printf("ID après recouvrement - PID : %d, PPID : %d\n", getpid(), getppid());
    if (write(fd, message, strlen(message)) == -1){
        perror("Erreur lors de l'écriture dans le fichier");
        return 1;
    }
    return 0;
}
