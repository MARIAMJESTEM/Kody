/*
 * petla.cpp
 */


#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int suma = 0 ; 
    int liczba =0 ; 
    
  while (suma <=100 ) // lub 1 (pętla nieskończona)
   
     {  
         cout << "Podaj liczbę : " << endl; 
         cin >> liczba ;  
         suma += liczba ;
     }
    cout << "Suma " << suma << endl ;
    return 0;
}


