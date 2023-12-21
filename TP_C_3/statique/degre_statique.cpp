//-------------------------------------------------------------------------
//   Conversion de température entre les échelles Celsius et Fahrenheit
//   On rappelle que les formules de conversion sont les suivantes:
//   T°C->T°F: tf=(9/5)*tc+32     T°F->T°C: tc=(5/9)*(tf-32)
//   Fonctionnalités: proposer par menu les 2 conversions ou l'affichage
//                    d'une table de conversion de mini à maxi avec pas
//-------------------------------------------------------------------------
// FICHIER    : degre.cpp
// DATE       : 16/09/2015
//-------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;
#include <stdlib.h>
#include "degre.h"
int main(int argc,char** argv)
{
	bool question = true;
	if (argc == 1){
		menu(9);
	}
	else{
		if (argc == 2){
			question = false;
		}
		switch(atoi(argv[1])){
			case 1:
				if (question==false){
					menu(1);
				}
				else{
					cout <<c2k(atof(argv[2]))<<endl;

				}
				break;
			case 2:
				if(question==false){
					menu(2);
				}
				else{
					cout <<k2c(atof(argv[2]))<<endl;
				}
				break;
			case 3:
				menu(3);
				break;
		}
	}
	exit(0);
}

