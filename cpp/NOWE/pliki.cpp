/*
 * pliki.cpp
 * 
 * 
 *
 * 
 * 
*/

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


int liczZnaki(char plik[]){
    ifstream wejscie(plik);
    if (!wejscie) {cout << "Błað otwarcia pliku!"; return 0;}
    char plik2[15];
    strcpy(plik2, plik);
    char *wsk;
    wsk = strstr(plik2, ".txt");
    strncpy(wsk, ".bak", 4);
    ofstream wyjscie(plik2);
    if (!wejscie) {cout << "Błað otwarcia pliku!"; return 0;}
     char z; //pojedynczy odczytany znak
     int ile, ileal, ilenum, ilealnum;
     ile = ileal = ilenum = ilealnum = 0;
     
     while(!wejscie.eof()) {
         wejscie.get(z);
         if (wejscie){
             ile++;
             if (isalpha(z)) ileal++;
             if (isdigit(z)) ilenum++;
             if (isalnum(z)) {
                 ilealnum++;
                 wyjscie.put(z);
                 }
             } 
        }
        wejscie.close(); wyjscie.close();
        cout << setw(10) << "Znaków: " << ile << endl;
        cout << setw(10) << "Liter: " << ileal << endl;
        cout << setw(10) << "Cyfr: " << ilenum << endl;
        cout << setw(10) << "Alfnum: " << ilealnum << endl;
        return ile;
        
    }
int main(int argc, char **argv)
{
	char nazwa[15];
    cout << "Podaj nazwę pliku";
    cin>> nazwa;
	return 0;
}

