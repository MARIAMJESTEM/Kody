#include "Uczniowie.hpp"
#include <iostream>

Uczniowie::Uczniowie()
{}

Uczniowie::Uczniowie(string i, string n){
    imie = i;
    nazwisko = n;
}

Uczniowie::Uczniowie(string i, string n, string k){
    imie = i;
    nazwisko = n;
    klasa = k;
}

Uczniowie::~Uczniowie()
{}

void Uczniowie::ustawDaneUcznia(string i, string n){
    imie = i;
    nazwisko = n;
}

void Uczniowie::ustawKlase(string k){
    klasa = k;
}

void Uczniowie::wypiszOceny(){
    if(oceny.size() != 0)
        for(unsigned int i = 0; i < oceny.size(); i++)
            cout << oceny[i] << endl;
}

void Uczniowie::dodajOcene(int o){
    if(o <= 6 && o >= 1)
        oceny.push_back(o);
}

float Uczniowie::srednia()
{
    int p = 0;

    if(oceny.size() != 0){
        for(unsigned int i = 0; i < oceny.size(); i++)
            p += oceny[i];
    }else{
        cout << "Nie podano zadnych ocen!!!" << endl;
        exit(1);
    }
    
    return float(p)/float(oceny.size());
}

string Uczniowie::zwrocNazwe(){
    return (imie + " " + nazwisko);
}
