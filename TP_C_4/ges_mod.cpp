#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    uid_t uid = getuid();
    uid_t euid = geteuid();
    gid_t gid = getgid();
    gid_t egid = getegid();
    printf("Utilisateur reel : %d\n", uid);
    printf("Utilisateur effectif : %d\n", euid);
    printf("Groupe reel : %d\n", gid);
    printf("Groupe effectif : %d\n", egid);
    char filename[] = "mon_fichier.txt";
    chown(filename, uid, gid);
    chmod(filename, S_IRUSR);
    FILE *f = fopen(filename, "r");
    if (f) {
        printf("Fichier ouvert avec succes !\n");
        fclose(f);
    } else {
        printf("Impossible d'ouvrir le fichier.\n");
    }
    chown(filename, 0, 0);
    chmod(filename, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    return 0;
}
