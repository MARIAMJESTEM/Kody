/*
 * kalkulator.cpp
 */


#include <iostream>
using namespace std;



int main(int argc, char **argv)
{    
    float a, b;
    a = b = 0;
    int dzialanie;
    dzialanie = 0 ;
     
    cout << "podaj  liczbe do działania" << endl;
    cin >> a;
    cout << "podaj drugą liczbę"<<endl;
    cin >> b;
    cout << "podaj cyfre działania(1.dodawanie, 2.odejmowanie, 3.mnozenie, 4.dzielenie)"<<endl;
    cin >> dzialanie;
    if(dzialanie == 1)
    {
        cout << a+b<< endl;
    }
    if(dzialanie == 2)
    {
        cout << a-b << endl;
    }
    if(dzialanie == 3)
    {
        cout << a*b<< endl;
    }
    if(dzialanie == 4)
    {
        cout << a/b<< endl;
    }
        return 0;
}

