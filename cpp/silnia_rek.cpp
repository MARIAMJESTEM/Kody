/*
 * silnia.cpp
 * 
 */


#include <iostream>

using namespace std;

int silnia_rek(int n)
{
	if(n<2)
		return 1;
	return silnia_rek(n-1) * n;
}


int silnia(int n)
{
    int wynik = 1;
    for (int i = 2; i<=n; i++)
    {
        wynik = wynik * i;
    }
    return wynik;
}

int main(int argc, char **argv)
{
	int n;
    cout<<"Podaj liczbe: ";
    cin>>n;
    // cout<<"Silnia jest rowna: "<< silnia(n) << endl;
    cout<<"Silnia jest rowna: "<< silnia_rek(n) << endl;
	return 0;
}
