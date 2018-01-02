/*
 * zadanie.cpp
 * program wypisuje wszystkie dwucyfrowe liczby parzyste podzielne prze 3 w zakresie <m;n> podanym przez użytkownika
 * 
 */


#include <iostream>
using namespace std;

int main(int argc, char **argv)
{ int m , n;
	int a = 0;
	
        cout <<"Podaj zakres dolny " << endl ;
        cin >> m ;
        cout << "Podaj górny zakres" << endl ;
        cin >> n;
        while (true)
  if (a > m && a < n && a % 3 == 0 && a % 2== 0)      
  {
	  cout << "liczba "<< a;
	  a = a+ 2 ;
}
	return 0;
}

