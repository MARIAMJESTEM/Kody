/*
 * potega.cpp
 */


#include <iostream>

using namespace std;

int potega_it(int podstawa, int wykladnik)
{
    int wynik = 1;
    int i = 1;
    while (i <= wykladnik)
    {
        wynik = wynik * podstawa;
        i = i + 1;
    }
    return wynik;
}   

int main(int argc, char **argv)
{
    int podstawa = 0;
    int wykladnik = 0;
    
    cout << "Podaj podstawę: " ;
    cin >> podstawa ; 
    cout << "Podaj wykładnik: " ;
    cin >> wykladnik ; 
    
    cout << "Wynik: " << potega_it(podstawa, wykladnik) << endl;
    
    return 0;
}
