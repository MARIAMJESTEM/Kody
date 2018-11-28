/*
 * kalkulator2.cxx
 * niedok
 */

using namespace std;
#include <iostream>


int suma(int a, int b)
{   int wynik;
    
    wynik = a + b;
    return wynik;
}
    
int roznica(int a, int b)
{int wynik;
    wynik = a - b;
    return wynik;
}
int iloczyn(int a, int b)
{int wynik;
    wynik = a*b;
    return wynik;
}
float iloraz(int a, int b)
{float wynik;
    wynik = a/b;
    return wynik;
}

int main(int argc, char **argv)
{ int a;
	cout << "Podaj dwie liczby "<< endl;
    cin >> a;
  
    cout << a;
	return 0;
}

