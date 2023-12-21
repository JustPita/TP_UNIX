#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid();
    printf("PID: %d\n", pid);

    pid_t ppid = getppid();
    printf("PID du père: %d\n", ppid);

    uid_t uid = getuid();
    uid_t euid = geteuid();
    printf("Utilisateur Propriétaire réel: %d, Propriétaire effectif: %d\n", uid, euid);

    gid_t gid = getgid();
    gid_t egid = getegid();
    printf("Groupes Propriétaire réel: %d, Propriétaire effectif: %d\n", gid, egid);
}
