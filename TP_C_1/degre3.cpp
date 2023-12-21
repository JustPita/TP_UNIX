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
float c2f(float celsius);
float f2c(float fahrenhiet);
void table(float mini, float maxi, float pas);
void menu();
int main()
{
	menu();
	exit(0);
}


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
float c2f(float celsius)
{
	float fahrenheit;
	fahrenheit = (9.0/5.0)*celsius + 32.0;
	return fahrenheit;
}
float f2c(float fahrenheit)
{
	float celsius;
	celsius = (5.0/9.0)*(fahrenheit - 32.0);
	return celsius;	
}
void table(float mini,float maxi,float pas)
{

	float fahrenheit, celsius;
		for (celsius=mini; celsius<=maxi; celsius+=pas)
		{
		    fahrenheit = (9.0/5.0)*celsius + 32.0;
		    cout << "  " << celsius << "°C = " << fahrenheit << "°F" << endl;
		}
}

