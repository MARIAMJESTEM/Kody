#include <iostream>
#include <string>

using namespace std;

// Zamiana znaków. Napisz program zamieniający w podanym tekście małe litery na duże i odwrotnie.

char zmiana(char a)
{
    if(a >= 'a' && a <= 'z')
        a -= 32;
    else if(a >= 'A' && a <= 'Z')
        a += 32;
    return a;
}

int main()
{
    string tekst, zmieniony;

    getline(cin, tekst);

    zmieniony.resize(tekst.length(), ' ');

    for(unsigned int i = 0; i < tekst.length(); i++)
        zmieniony[i] = zmiana(tekst[i]);

    cout << zmieniony << endl;
}
