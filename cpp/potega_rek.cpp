/*
 * potega.cpp
 * 
 */


#include <iostream>

using namespace std;

float potega_rek(float a, float n)
{
	if(n == 0)
		return 1;
	return potega_rek(a, n-1) * a;
}



float potega_it(float podstawa, float wykladnik)
{
    float wynik = 1;
    for (int i = 1; i<= wykladnik; i++)
    {
        wynik = wynik * podstawa;
    }
    return wynik;
}

int main(int argc, char **argv)
{
	float podstawa;
    float wykladnik;
    
    cout<<"Podaj podstawe potegi: ";
    cin>> podstawa;
    cout<<"Podaj wykladnik potegi: ";
    cin>> wykladnik;
    cout<<"Wynik: " << potega_rek(podstawa, wykladnik) << endl;
    
	return 0;
}
