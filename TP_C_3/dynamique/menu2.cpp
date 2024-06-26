#include <iostream>
#include <iomanip>
using namespace std;
#include <stdlib.h>
#include "degre.h"
void menu(int chx)
{
	// déclarations diverses
	// choix du menu
	float celsius, kelvin;          // températures °C et °F
	float mini, maxi, pas;	// variables de la table


	// traitement de l'option choisie
	switch(chx)
	{
	case 1:
	cout << "Entrez la température en °C: ";
	cin >> celsius;
	kelvin=c2k(celsius);
	cout << "  " << celsius << "°C = " << setprecision(8) << setw(2) << kelvin << "°K" << endl;
		break;
	case 2:
		cout << "Entrez la température en °F: ";
		cin >> kelvin;
		celsius=k2c(kelvin);
	cout << "  " << kelvin << "°F = " << setprecision(8) << celsius << "°C" << endl;
		break;
	case 3: cout << "Entrez la température mini °C: ";
		cin >> mini;
		cout << "Entrez la température maxi °C: ";
		cin >> maxi;
		cout << "Entrez le pas d'incrémentation en °C: ";
		cin >> pas;
		table(mini,maxi,pas);
		break;

	case 9:
	// Affichage du menu et choix de l'option
	#ifdef _WIN32
	system("cls");
	#endif
	#ifdef linux
	system("clear");
	#endif
	cout << "\t\t1 -> Conversion °C vers °K" << endl;
	cout << "\t\t2 -> Conversion °K vers °C" << endl;
	cout << "\t\t3 -> Table de conversion" << endl;
	cout << "\t\t4 -> Quitter" << endl << endl;
	cout << "\t\t1     Votre choix SVP -> ";
	cin >> chx;
	cout << endl << endl;
	break;
	}
}
