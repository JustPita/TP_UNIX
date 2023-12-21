#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    uint id;
    id = gethostid();
    cout<< "HostID : " <<std::hex<<id<<endl;
}
