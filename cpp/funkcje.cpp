/*
 * funkcje.cpp
 * po nazwie funkcji zawsze występują nawiasy np: dodaj ()
 * funkcja będzie pbierać dwie liczby i 
 * void - to funkcja nie zwraca wyniku 
 */


#include <iostream>

using namespace std;
void  dodaj(int a , int b) // deklaracja funkcji
{
       cout << "Suma:  " << a+b << endl ;
}
int odejmij (int l1 , int l2)
{
      return l1 -l2;
}
int mnoz (int k1 , int k2)
{
      return k1 * k2  ;
}
int dziel (int j1 , int j2)
{
      if (j2 == 0 )
      {
          cout <<"Nie dzieli sie przez zero"<< endl ;
          return 0;
          }
      return j1/ j2 ;    
}
int main(int argc, char **argv)
{
    int a, b ;
    a = b = 0;
    cout << "Podaj dwie liczby " << endl;
    cin >> a >> b;
    dodaj(a, b); //wywołanie funkcji
    cout << "Różnica :  " << odejmij (a , b) << endl;
    cout << "Iloczyn :"<< mnoz (a , b) << endl;
    cout << "Iloraz : " << dziel (a , b ) << endl;
    return 0;
}
// monz nie zwraca 
