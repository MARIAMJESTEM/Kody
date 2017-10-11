/*
 * petla.cpp
 */


#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    
    int i; // zmienna iteracyjna
    int suma = 0 ; 
    int ile_razy =0;
    int liczba =0 ; 
    cout << "Ile liczb podasz? " ;
    cin >> ile_razy;
    
    for (i = 0; i <  ile_razy ; i++)
   
     {  
       cout << "Podaj liczbę : " << endl; 
         cin >> liczba ;  
         //suma = suma + liczba ;
         suma += liczba ;
     }
    cout << "Suma " << suma << endl ;
    return 0;
}

//ctrl+ c przerywa warunek
