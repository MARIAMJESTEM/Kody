/*
 * praca_domowa.cpp
 */


#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char **argv)

{
	int a ,b ,c ;
	int obwod = 0;
    float p = 0; 
	
	 while (a + b > c && a + c > b && c +b > a)
{
	cout << "Podaj boki trojkata:  ";
	cin >> a >> b >> c;
	if (true)
	{
	    obwod = a + b + c ;
        cout << "Obwód" << obwod << endl;
        p = 0.5 * obwod;
        cout << "p =" << p << endl;
        cout << "Pole :  " <<  sqrt (p* (p-a) * (p-b) *(p-c)) << endl;
		}
	}
	return 0;
}

