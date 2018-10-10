#include <iostream>
#include <string>

using namespace std;

// Wyrazy. Napisz program zliczający w podanym tekście wyrazy i drukujący je w nowych wierszach.

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
                cout << tekst.substr(poz, z) << endl;
                poz = i + 1;
                z = 0;
            }
    }

    cout << "Wyrazów z zdaniu: " << ile << endl;
}
