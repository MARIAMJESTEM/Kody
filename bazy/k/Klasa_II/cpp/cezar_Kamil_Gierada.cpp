#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

char lower(char a)
{
	return char((int)a + 32);
}

void szyfruj(string tekst, int klucz)
{
    int i = 0;
    klucz = klucz % 26;
	while (tekst[i] != '\0')
	{
		if (tekst[i] == ' ')
			continue;

		if ((int)tekst[i] >= 65 && (int)tekst[i] <= 90)
			tekst[i] = lower(tekst[i]);

		if ((int)tekst[i] + klucz > 122)
			tekst[i] = char((int)tekst[i] - 26 + klucz);
		else
			tekst[i] = char((int)tekst[i] + klucz);
		i++;
	}
	cout << tekst << endl;
}

int main()
{
    string tekst;
    int klucz = 3;
    cout << "Podaj tekst do zaszyfrowania: ";
	getline(cin, tekst);
    cout << "Podaj klucz: ";
	cin >> klucz;

    szyfruj(tekst, klucz);
	system("Pause");
}