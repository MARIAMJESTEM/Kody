#include <iostream>
#include <string>

using namespace std;

// Zliczanie znaków. Napisz program zliczający w podanym tekście znaki białe, małe, duże litery oraz cyfry.

int main()
{
    string tekst;
    getline(cin, tekst);

    unsigned int b = 0, m = 0, d = 0, c = 0;

    for(int i = 0; i < tekst.length(); i++)
        {
            if(tekst[i] == ' ' || tekst[i] == '\t')
                b++;
            if(tekst[i] >= 'a' && tekst[i] <= 'z')
                m++;
            if(tekst[i] >= 'A' && tekst[i] <= 'Z')
                d++;
            if(tekst[i] >= '0' && tekst[i] <= '9')
                c++;
        }

    cout << "Białe znaki: " << b << "\nMałe znaki: " << m << "\nDuże znaki: " << d << "\nCyfry: " << c;
}
