/*
 * Horner.cpp
 */


#include <iostream>

using namespace std;
 
// W(x)= 2x^3 + 3x^2 + 5x + 4 (8)
// W(x)= x(2x^2 + 3x + 5) + 4
// W(x)= x(x(2x + 3) + 5) + 4 (3)

float horner_rek(int k , int float tbwsp[], float x)
{
    if (k==0)
        return tbwsp[0] * x;
    return horner_rek(k -1, tbwsp, x) *x + tbwsp[k];
    
    
}

float horner_iter(int k , float ws[], float x)
{    float wynik = ws[0];
     for (int i =1; i < k + 1; i++ )
     { 
         wynik = wynik * x + ws[i]; 
         
     }
    return wynik;
}
int main(int argc, char **argv)
{   
    float x;
    float ws[4];
    int stopien = 3; // stopień wielomianu
    
    cout<<"Podaj wartość argumentu "<<endl;
    cin>> stopien;
    
 
    int i;
    for(i= 0 ; i<4 ;i++)
    {
       cout << "Podaj cztery współczynniki ";
       cin >> ws[i];
    }
 cout << "Wartość wielomianu: " << horner_iter(stopien , ws , x) << endl;
	return 0;
}

