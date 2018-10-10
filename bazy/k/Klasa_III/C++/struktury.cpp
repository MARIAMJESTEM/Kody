#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct osoba {
    string imie;
    string nazwisko;
    int wiek;
};

/*void pobierzInfo(osoba o)
{
    cout << "Podaj imie: ";
    cin >> o.imie;
    cout << "Podaj nazwisko: ";
    cin >> o.nazwisko;
    cout << "Podaj wiek: ";
    cin >> o.wiek;
}

void wyswietlInfo(osoba o)
{
    cout << "Imie:" << setw(15) << setfill('_') << o.imie << endl;
    cout << "Nazwisko:" << setw(13) << o.nazwisko << endl;
    cout << "Wiek:" << setw(12) << o.wiek << endl;
}*/

void pobierzDane(osoba o[], int ile)
{
    for (int i = 0; i < ile; i++){
        cout << "Podaj imie: ";
        cin >> o[i].imie;
        cout << "Podaj nazwisko: ";
        cin >> o[i].nazwisko;
        cout << "Podaj wiek: ";
        cin >> o[i].wiek;
        cin.ignore(1);
    }
}

void wyswietlDane(osoba o[], int ile)
{
    for(int i = 0; i < ile; i++){
        cout << "Imie:" << setw(15) << setfill('_') << o[i].imie << endl;
        cout << "Nazwisko:" << setw(13) << o[i].nazwisko << endl;
        cout << "Wiek:" << setw(12) << o[i].wiek << endl << endl;
    }
}

void zapiszDane(osoba o[], int ile)
{
    fstream file("baza.txt", ios::app);

    if(!file.is_open()){
        cout << "Błąd otwarcia pliku!" << endl;
    }else{
        for(int i = 0; i < ile; i++){
            file << o[i].imie << ", " << o[i].nazwisko << ", " << o[i].wiek << ';' << endl;
        }
    }

    file.close();
}

void czytajDane(osoba o[])
{
    ifstream file("baza.txt");

    if(file.is_open())
    {
        int i = 0;
        string linia;
        while(getline(file, linia)){
            cout << linia << endl;
            i++;
        }
    }else{
        ;
    }
    file.close();
}

int main(int argc, char **argv)
{
    int ile = 0;
    cout << "Ile osób chcesz wprowadzić: ";
    cin >> ile;
    cin.ignore(1);
    osoba uczen[ile];
	pobierzDane(uczen, ile);
    wyswietlDane(uczen, ile);
    zapiszDane(uczen, ile);

    osoba dane[ile];
    czytajDane(dane);
	return 0;
}