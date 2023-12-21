#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    char name[256];
    if (gethostname(name, sizeof(name)) == 0){
        cout<< "Nom réseau de la machine locale : " <<name<<endl;
    }
    else{
        cerr << "Erreur lors de la récupération du nom réseau." <<endl;
    }
    return 0;
}