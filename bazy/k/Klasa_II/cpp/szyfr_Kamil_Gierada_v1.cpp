#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

// V 1.0

using namespace std;

void pobierzDane(string & tekst, unsigned int & w, unsigned int & k)
{
	while (tekst == "")
	{
		cout << "Podaj tekst do obrobki: ";
		getline(cin, tekst);
		tekst.erase(remove_if(tekst.begin(), tekst.end(), isspace), tekst.end());
	}
	while (k <= 0)
	{
		cout << "Podaj ilosc kolum: ";
		cin >> k;
	}
	while (w <= 0)
	{
		cout << "Podaj ilosc wierszy: ";
		cin >> w;
	}
}

void szyfrowanie()
{
	string tekst = "";
	string szyfr = "";
	unsigned int _k = 0;
	unsigned int _w = 0;

	pobierzDane(tekst, _w, _k);

	char tab[100][100];

	int x = 0;

	for (int i = 0; i < _w; i++)
		for (int j = 0; j < _k; j++)
		{
			if (x < tekst.length())
			{
				tab[i][j] = tekst[x];
				x++;
			}
			else
				tab[i][j] = ' ';
		}

	for (int i = 0; i < _k; i++)
		for (int j = 0; j < _w; j++)
		{
			if (tab[j][i] != ' ')
				szyfr += tab[j][i];
		}
	cout << szyfr << endl;
}

int main()
{
	szyfrowanie();

	system("Pause");
}
