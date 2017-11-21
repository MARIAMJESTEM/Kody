/*
 * silnia.cpp
 */


#include <iostream>

using namespace std;

int silnia_it(int liczba)
{
    int wynik = 1;
    int i = 1;
    while (i <= liczba)
    {
        wynik = wynik * i;
        i = i + 1;
    }
    return wynik;
}   

int main(int argc, char **argv)
{
    int liczba = 0;
    
    cout << "Podaj liczbę: " ;
    cin >> liczba ; 
    
    cout << "Wynik: " << silnia_it(liczba) << endl;
    
    return 0;
}
