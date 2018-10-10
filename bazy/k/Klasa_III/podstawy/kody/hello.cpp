#include <iostream>
#include <cmath>
#include <string>
#include <ctime>

#define ROK 2017

using namespace std;

int parzyste(int n)
    {
        int i = 0;
        
        for(; i <= n; i+=2)
            cout << i << ' ';
        
        return i/2;
    }
    
void pierwsze(int n)
    {
        
    }

int main(int argc, char **argv)
{
    string imie;
    int wiek = 0;
    int n = 0;
    
    const int Rok_cpp = 1983;
    
    cout << "Podaj swoje imię: ";
    cin >> imie;
    cout << "Witaj " << imie << "." << endl;
    
    do{
	cout << "Podaj swoj wiek: ";
    cin >> wiek;
    }while (wiek <= 0);
    
    int rok_urodzenia = ROK - wiek;

    cout << "Urodziles sie w " << rok_urodzenia << endl;
    
    if (rok_urodzenia > Rok_cpp)
        cout << "Jestem starszy od ciebie" << endl;
    else if (rok_urodzenia < Rok_cpp)
        cout << "Jestem mlodszy od cibie." << endl;
    else
        cout << "Jestesmy rowniesnikami!" << endl;
        
    cout << "Podaj zakres wyświetlanych liczb parzystych: ";
    cin >> n;
    cout << "Ilosc parzystych: " << parzyste(n) << endl;
    
    
    int x = 0;
    do
    {
        cout << "Podaj zakres liczb pierwszych: ";
        cin >> x;
    }while(x > 1);
    cout << "Ilosc liczb pierwszych: " << pierwsze(x) << endl;
    return 0;
}
