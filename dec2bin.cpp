/*
 * dec2bin.cpp
 * pętla do while wykona się przynajmniej raz 
 */

using namespace std;
#include <iostream>

int main(int argc, char **argv)
{   char znakA="A";
    char znakB= "B";
    int l14=14;
    int l15=15;
    cout <<(int)znakA<< (int)znakB<< endl;
    cout << (char)l14 << (char)l15 << endl;
    int reszty[16];
    int liczba =0;
    int podstawa =0;
    int i =0;//indeks tabeli
    //120 -64= 56 ()
    //56-32=24  ()
    //24-16=8 (2^4=16)
    //8-8=0 (2^3=8)
    //111100
    cout << "Podaj liczbę i podstawę ";
    cin>> liczba>> podstawa;
     
    do {
        reszty[i]= liczba%podstawa;
        liczba =liczba/podstawa;
        i++;
    } while (liczba > 0);
    
     //~for(int j=i-1;j>=0;j--){
            //~cout<< reszty[j] << endl;
         //~}
        
    while (i-1>=0)
    {        i--;
            cout<< reszty[i] ;
            //i--;
    }
	
	return 0;
}

