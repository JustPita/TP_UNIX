


#include <iostream>
#include <iomanip>
using namespace std;
#include <stdlib.h>
#include "degre.h"
void table(float mini,float maxi,float pas)
{

	float fahrenheit, celsius;
		for (celsius=mini; celsius<=maxi; celsius+=pas)
		{
		    fahrenheit = (9.0/5.0)*celsius + 32.0;
		    cout << "  " << celsius << "°C = " << fahrenheit << "°F" << endl;
		}
}

