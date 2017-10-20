/*
 * funkcje.cpp
 * po nazwie funkcji zawsze występują nawiasy np: dodaj ()
 * funkcja będzie pbierać dwie liczby i 
 * void - to funkcja nie zwraca wyniku 
 * zmienna globalna jest zdefiniowana w zasięgu pliku i jest dostępna w każdej napisanej funcji lub w funkcji którą mamy napisaną
 * 
 * += liczba = liczba + krok(zwiększenie wartości liczba o krok)
 */


#include <iostream>

using namespace std;

//int liczba =0; // zmienne o zasięgu pliku tzw. zmienne globalne
//int krok =0; // -"-
void zwieksz1 ()
{
    liczba += krok;   
}

int main(int argc, char **argv)
{
    cout << "Podaj liczbę i krok" << endl;
    cin >> liczba >> krok;
    
   zwieksz1 ();
    
    cout << "Liczba: " << liczba << endl ;
    cout  <<  "Krok : " << krok << endl;
    
    return 0;
}

