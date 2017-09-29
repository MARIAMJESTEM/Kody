/*
 * trojkat.cpp
 * program pobiera trzy boki trojkata
 * sprawdza czy da sie zbudowac trojkat
 * oblicza obwod i pole (ze wzoru herona)
 * i drukuje na ekranie odpowiedni komunikat 
 */
 


#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char **argv)
{ 
    //float p;
    //float pole;
    //sqrt (); // pierwiastek
    
    int a, b, c;
    int obwod = 0;
    float p = 0; 
    a = b = c = 0;
    cout << "Podaj boki trojkata:  ";
	cin >> a >> b >> c;
    
    if ( a + b > c && a + c > b && c +b > a)
     {
        cout <<"Można zbudować trójkąt. "  ;
        obwod = a + b + c ;
        cout << "Obwód" << obwod << endl;
        p = 0.5 * obwod;
        cout << "p =" << p << endl;
        cout << "Pole :  " <<  sqrt (p* (p-a) * (p-b) *(p-c)) << endl;
    } 
    
	return 0;
}

