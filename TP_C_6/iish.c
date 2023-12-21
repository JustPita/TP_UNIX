#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MAX_PARAMS 50
#define HISTORY_FILE ".iish_history"

void commandExt(char *params[]){
    pid_t pid = fork();
    switch (pid){
        case -1:
            perror("Erreur lors de lancement de la commande");
            exit(EXIT_FAILURE);
        case 0:
            execvp(params[0], params);
            perror("Erreur lors de l'exécution de la commande");
            exit(EXIT_FAILURE);
        default:
            wait(NULL);
    }
}

void changeDir(char *path){
    switch (path == NULL){
        case 1:
            fprintf(stderr, "Usage: ed <directory>\n");
            break;
        case 0:
            if (chdir(path) != 0){
                perror("Erreur lors du changement de répertoire");
            }
            break;
    }
}


int main(){
    char *input;
    char *params[MAX_PARAMS + 1];
    using_history();
    read_history(HISTORY_FILE);
    do {
        input = readline("IISH> ");
        if (input == NULL){
            printf("BYE !\n");
            exit(0);
        }
        add_history(input);
        write_history(HISTORY_FILE);
        if (strcmp(input, "") != 0){
            int i = 0;
            char *caract = strtok(input, " ");
            while (caract != NULL && i < MAX_PARAMS){
                params[i++] = caract;
                caract = strtok(NULL, " ");
            }
            switch (strcmp(params[0], "exit")){
                case 0:
                    printf("Bye !\n");
                    return 0;
                default:
                    switch (strcmp(params[0], "ed")){
                        case 0:
                            changeDir(params[1]);
                            break;
                        default:
                            commandExt(params);
                    }
            }
        }
        free(input);
    } while (strcmp(input, "exit") != 0);
    clear_history();
    return 0;
}