/*
 * Mazur_alg1.cpp
 */
// myśle że algorytm jest poprawny chcoicaz to pytanie może być podchwytliwe
using namespace std;
#include <iostream>
int main(int argc, char **argv)
{
	int a=0;
	int i=2;
	do
	{
		cout << "Podaj liczbe : ";
		cin >> a;
	}while(a<=0||a>=100);
	
	while(a!=i)
    {
        if(i==100)
        {
            cout <<"Liczba jest nieparzysta :(";
            break;
        }
        i= i+2;
    }
   if (a==i)
   {
        cout << "Liczba jest parzysta :)";
   }
	return 0;
}
