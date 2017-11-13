/*
 * funkcje.cpp
 * po nazwie funkcji zawsze występują nawiasy np: dodaj ()
 * funkcja będzie pbierać dwie liczby i 
 * void - to funkcja nie zwraca wyniku 
 * zmienna globalna jest zdefiniowana w zasięgu pliku i jest dostępna w każdej napisanej funcji lub w funkcji którą mamy napisaną
 * & - operator pobierania adresu jak w ten sposób pobiore coś do fukcji to będzie ona dziaóać nie na kopiach tylko oryginałach
 * += liczba = liczba + krok(zwiększenie wartości liczba o krok)
 */


#include <iostream>

using namespace std;


//void zwieksz1 ()
//{
    //liczba += krok;   
//}
void zwieksz2 (int liczba, int krok) // przekazywanie przez wartość 
{
    cout << & liczba << " " << &krok << endl;
    liczba += krok;  
    cout  << "Liczba: " << liczba << endl ;
}
void zwieksz3 (int &liczba, int &krok) 
{
    liczba += krok;  
    cout  << "Liczba: " << liczba << endl ;
}

int main(int argc, char **argv)
{
    int liczba, krok ; // zmienne lokalne
    cout << "Podaj liczbę i krok" << endl;
    cin >> liczba >> krok;
    
    cout << & liczba << " " << &krok << endl;
    
   zwieksz2 (liczba , krok);
   zwieksz2 (liczba , krok);
   

   
    
    cout << "Liczba: " << liczba << endl ;
    cout  <<  "Krok : " << krok << endl;
    
    return 0;
}

