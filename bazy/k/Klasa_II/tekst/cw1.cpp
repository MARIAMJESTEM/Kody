#include <iostream>
#include <string>

using namespace std;

// Anagram. Napisz program drukujący wprowadzony wyraz od tyłu

int main()
{
    string tekst;
    string anag = " ";

    cout << "Podaj tekst do stworzenia anagramu: ";
    getline(cin, tekst);

    anag.resize(tekst.length(), ' ');

    for (unsigned int i = 1; i <= tekst.length(); i++)
        anag[i - 1] = tekst[tekst.length() - i];

    cout << "Powstały anagram to: " << anag << endl;
}
