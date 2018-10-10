#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//Anagramy. Napisz program, który drukuje wszystkie anagramy podanego wyrazu 4-znakowego.

int main()
{
    string tekst;

    cin >> tekst;

    if (tekst.length() != 4)
    {
        cout << "Tekst musi mieć 4 znaki!!!" << endl;
        exit(0);
    }

    for(int i = 0; i <
}
