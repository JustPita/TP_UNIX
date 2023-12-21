


#include <iostream>
#include <iomanip>
using namespace std;
#include <stdlib.h>
#include "degre.h"
void table(float mini,float maxi,float pas)
{

	float kelvin, celsius;
		for (celsius=mini; celsius<=maxi; celsius+=pas)
		{
		    kelvin = celsius + 273.15;
		    cout << "  " << celsius << "°C = " << kelvin << "°K" << endl;
		}
}

