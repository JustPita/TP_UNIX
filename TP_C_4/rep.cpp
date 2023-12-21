#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char dir[1024];
    if (getcwd(dir, sizeof(dir)) != NULL) {
        printf("Répertoire de travail courant : %s\n",dir);
        if (chdir("..") == 0) {
            if (getcwd(dir, sizeof(dir)) != NULL) {
                printf("Répertoire de travail après passage au répertoire parent : %s\n", dir);
            } else {
                perror("getcwd");
                return 1;
            }
        } else {
            perror("chdir");
            return 1;
        }
    } else {
        perror("getcwd");
        return 1;
    }
    return 0;
}
