/*
 * sort_wyb.cpp
 * srand zwraca czas  /UNIKSOWY/
 */

using namespace std;
#include <iostream>


void wypelnij(int t[], int n, int m)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        t[i]= 1 + rand() % m;//losowanie liczb z zakresu od <0;m> 
    }
}
void drukuj(int t[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        cout << t[i] << " ";
    }
}

void zamien(int&a, int&b)
{
    
}

void sort_wyb(int t[], int n[])
{   int k;
    for (int i = 0; i < n; i++)
    {
        k = i;//zmienna przechowująca indeks/wartość najmniejszego elementu
            
        for (int j= i + 1; j < n; j++ )
        {
            if (t[j] < t[k] )
            k = j ;
        }
        zamien(t[i], t[k]);
        
    }
}



int main(int argc, char **argv)
{
	const int ile = 10;
    int tab[ile];
    wypelnij(tab, ile, 20);
    drukuj(tab, ile);
    
    
    
	return 0;
}

