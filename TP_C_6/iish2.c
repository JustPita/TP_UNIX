#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>

#define MAX_PARAMS 50
#define HISTORY_FILE ".iish_history"

typedef struct histo{
    char *dir;
    struct histo *suivant;
}histo;

histo *histoList = NULL;

void addToHistory(char *dir){
    histo *newNode = (histo *)malloc(sizeof(histo));
    newNode->dir = strdup(dir);
    newNode->suivant = histoList;
    histoList = newNode;
    while (newNode->suivant != NULL && newNode->suivant->suivant != NULL){
        histo *temp = newNode->suivant;
        newNode->suivant = temp->suivant;
        free(temp->dir);
        free(temp);
    }
}

void affichageHisto(){
    histo *cmd = histoList;
    while (cmd != NULL){
        printf("%s\n", cmd->dir);
        cmd = cmd->suivant;
    }
}

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
        if (strcmp(params[1], "&") != 0){
            printf("Processus fils créé avec PID : %d\n", pid);
        } else {
            waitpid(pid, NULL, WNOHANG);
        }
    }
}

void changeDir(char *path){
    char *histo;
    switch (path == NULL){
    case 1:
        fprintf(stderr, "Usage: cd <directory>\n");
        break;
    case 0:
        histo = getcwd(NULL, 0);
        if (histo != NULL){
            addToHistory(histo);
            free(histo);
        }
        if (chdir(path) != 0){
            perror("Erreur lors du changement de répertoire");
        }
        break;
    }
}

void cdHist(char *params[]){
    if (strcmp(params[0], "cdhist") == 0){
        affichageHisto();
    }
    else if (strcmp(params[0], "cd") == 0){
        changeDir(params[1]);
    }
    else if (strcmp(params[0], "cd-") == 0){
        if (histoList != NULL){
            changeDir(histoList->dir);
        }
    }
    else if (strcmp(params[0], "cd+") == 0){
        if (histoList != NULL && histoList->suivant != NULL){
            changeDir(histoList->suivant->dir);
        }
    }
    else if (strncmp(params[0], "cd%", 3) == 0){
        int index = atoi(params[0] + 3);
        histo *temp = histoList;
        while (temp != NULL && index > 1){
            temp = temp->suivant;
            index--;
        }
        if (temp != NULL){
            changeDir(temp->dir);
        }
    }
}

void redirect(char *params[]){
    int i = 0;
    int sortieRedirect = 0;
    int entreeRedirect = 0;
    while (params[i] != NULL){
        if (strcmp(params[i], ">") == 0){
            sortieRedirect = i;
        }
        else if (strcmp(params[i], "<") == 0){
            entreeRedirect = i;
        }
        i++;
    }
    if (sortieRedirect > 0){
        int fd = open(params[sortieRedirect + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        dup2(fd, STDOUT_FILENO);
        close(fd);
        params[sortieRedirect] = NULL;
    }
    if (entreeRedirect > 0){
        int fd = open(params[entreeRedirect + 1], O_RDONLY);
        dup2(fd, STDIN_FILENO);
        close(fd);
        params[entreeRedirect] = NULL;
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
            redirect(params);
            cdHist(params);
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