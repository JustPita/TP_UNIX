#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <cstring>

int main(){
    printf("ID avant processus de recouvrement - PID : %d, PPID : %d\n", getpid(), getppid());

    int fd = open("fic_exec", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1){
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }
    execl("./pg_ext", "pg_ext", NULL);
    perror("Erreur lors du recouvrement du processus");
    return 1;
}
