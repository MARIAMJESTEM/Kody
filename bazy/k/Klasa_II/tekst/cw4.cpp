#include <iostream>
#include <string>

using namespace std;

//Anagram, miniszyfr. Napisz program drukujacy wprowadzone wyrazy od tyłu zgodnie z kolejnością wprowadzania.

string ana(string tekst)
{
    string anag = " ";

    anag.resize(tekst.length(), ' ');

    for (unsigned int i = 1; i <= tekst.length(); i++)
        anag[i - 1] = tekst[tekst.length() - i];

    return anag;
}

int main()
{
    string tekst;
    int ile = 0;

    getline(cin, tekst);

    size_t poz = 0;

    int z = 0;

    for (unsigned int i = 0; i <= tekst.length(); i++)
    {
        z++;
        if(tekst[i] == ' ' || tekst[i] == '\0')
            {
                ile++;
                cout << ana(tekst.substr(poz, z)) << ' ';
                poz = i + 1;
                z = 0;
            }
    }
}
