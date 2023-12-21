


#include <iostream>
#include <iomanip>
using namespace std;
#include <stdlib.h>
#include "degre.h"
void menu()
{	
	// déclarations diverses
	int chx;                            // choix du menu
	float celsius, fahrenheit;          // températures °C et °F
	float mini, maxi, pas;	// variables de la table
	float resultat;

	// Affichage du menu et choix de l'option
	system("clear");
	cout << "\t\t1 -> Conversion °C vers °F" << endl;
	cout << "\t\t2 -> Conversion °F vers °C" << endl;
	cout << "\t\t3 -> Table de conversion" << endl;
	cout << "\t\t4 -> Quitter" << endl << endl;
	cout << "\t\t1     Votre choix SVP -> ";
	cin >> chx;
	cout << endl << endl;

	// traitement de l'option choisie
	switch(chx)
	{
	case 1:
	cout << "Entrez la température en °C: ";
	cin >> celsius;
	fahrenheit=c2f(celsius);
	cout << "  " << celsius << "°C = " << setprecision(8) << setw(2) << fahrenheit << "°F" << endl;
		break;
	case 2: 
		cout << "Entrez la température en °F: ";
		cin >> fahrenheit;
		celsius=f2c(fahrenheit);
	cout << "  " << fahrenheit << "°F = " << setprecision(8) << celsius << "°C" << endl;
		break;
	case 3: cout << "Entrez la température mini °C: ";
		cin >> mini;
		cout << "Entrez la température maxi °C: ";
		cin >> maxi;
		cout << "Entrez le pas d'incrémentation en °C: ";
		cin >> pas;
		table(mini,maxi,pas);
		break;
	}
}
