/*
 * praca_domowa.cpp
 */


#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char **argv)

{
	int a=0; 
	int b =0;
	int c =0;
	int obwod = 0;
    float p = 0; 
	
	 while (true)
        {
	        cout << "Podaj boki trojkata:  "<< endl;
	        cin >> a >> b >> c;
	 if (a + b > c && a + c > b && c +b > a)
	    {
			obwod = a + b + c ;
            p = 0.5 * obwod;
            cout << "Pole :  " <<  sqrt (p* (p-a) * (p-b) *(p-c)) << endl;
	
		break;
	    }
        }
	
	return 0;
}

