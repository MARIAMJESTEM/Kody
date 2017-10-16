/*
 * praca_domowa.cpp
 */


#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char **argv)

{
int liczba = 0 ;
int suma=0;
cout<<"Podaj liczbe: "<<endl;
cin>> liczba;

	while(liczba > 0)
	{
		suma =suma +liczba %10;
		liczba/=10;
		cout<< "Suma : "<< suma <<liczba <<endl;
    }

	return 0;
}

