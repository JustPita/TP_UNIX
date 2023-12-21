#include <stdio.h>
#include <iostream>
extern int _etext;
extern int _edata;
extern int __bss_start;
extern int _end;

    void fct1() {}
    void fct2() {}
    void fct3() {}
    int glob_i = 10;
    char glob_s_i[] = "Hello";
    float fct_s_i = 3.14;
    char prin_s_i;
    char bloc_s_i[100];
    int errno;
    float fct_s;
    char prin_s;
    char bloc_s[100];
    static int glob_s = 20;
    int glob=358;
    int variable_locale = 42;
    static int variable_statique = 1337;
    int variable_globale_init = 99;
    static int variable_globale_non_init;

int main(int argc, char *argv[], char *envp[]) {
    
    std::system("clear");
    printf("MEMOIRE D'UN PROCESSUS LINUX\n\n");
    printf("CODE\n");
    
    printf("Fonction fct1 : %08X\n", (void*)&fct1);
    printf("Fonction fct2 : %08X\n", (void*)&fct2);
    printf("Fonction fct3 : %08X\n", (void*)&fct3);
    printf("Fonction main : %08X\n", (void*)&main);

    printf("FIN CODE DATA\n");
    
    printf("Variable glob_i : %08X\n", (void*)&glob_i);
    printf("Variable glob_s_i : %08X\n", (void*)&glob_s_i);
    printf("Variable fct_s_i : %08X\n", (void*)&fct_s_i);
    printf("Variable prin_s_i : %08X\n", (void*)&prin_s_i);
    printf("Variable bloc_s_i : %08X\n", (void*)&bloc_s_i);

    printf("FIN DATA\n");
    printf("DEBUT BSS\n");
    
    printf("Variable errno : %08X\n", (void*)&errno);
    printf("Variable fct_s : %08X\n", (void*)&fct_s);
    printf("Variable prin_s : %08X\n", (void*)&prin_s);
    printf("Variable bloc_s : %08X\n", (void*)&bloc_s);
    printf("Variable glob_s : %08X\n", (void*)&glob_s);
    printf("Variable glob : %08X\n", (void*)&glob);

    printf("FIN DATA+BSS\n");
    
    printf("Adresse de variable_locale : %08X\n", (void*)&variable_locale);
    printf("Adresse de variable_statique : %08X\n", (void*)&variable_statique);
    printf("Adresse de variable_globale_init : %08X\n", (void*)&variable_globale_init);
    printf("Adresse de variable_globale_non_init s: %08X\n", (void*)&variable_globale_non_init);
    printf("\nAdresses des paramètres de la ligne de commande (argv) :\n");
    for(int i = 0; i < argc; i++) {
        printf("argv[%d] : %08X %s\n", i, (void*)argv[i],argv[i]);
    }
    printf("\nAdresses des variables d'environnement (arge) :\n");
    for(int i = 0; envp[i] != NULL; i++) {
        printf("arge[%d] : %08X %s\n", i, (void*)envp[i],envp[i]);
    }
    return 0;
}
