/*
 * hello.cpp
 */


#include <iostream> //io  
using namespace std;

int main(int argc, char **argv)
{
    //char imie; // deklaracja zmiennej znakowej 
    //deklaracja tablicy znakowej 
    //int wiek; //deklaracja zmiennej typu całkowitego
    //wiek = 0; // inicjacja zmiennej 
    int bok = 0;
    cout <<"Podaj bok kwadratu : ";	
    //cin >> bok;
    cin >> bok;
    
    cout << "Pole " << bok * bok << endl;
    cout << "Obwód " << bok * 4 << endl;
    
    
	return 0;
}

