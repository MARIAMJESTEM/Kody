#include <iostream>
#include "ul_ulamek.hpp"
using namespace std;

Ulamek::Ulamek()        {}

Ulamek::Ulamek(int l, int m){
	licznik = l;
	
	if(m != 0)
		mianownik = m;
	else{
		cout << "Mianownik nie może być ZEREM!" << endl;
		exit(1);
	}
}

Ulamek::~Ulamek()       {}


void Ulamek::zapisz(int l, int m){
	licznik = l;
	
	if(m != 0)
		mianownik = m;
	else{
		cout << "Mianownik nie może być ZEREM!" << endl;
		exit(1);
	}
}

void Ulamek::skracaj_It(){
	int l = licznik;
	int m = mianownik;
	int p;					//zmienna pomocnicza
	
	while(m != 0){
		p = m;
		m = l%m;
		l = p;
	}
	
	licznik /= l;
	mianownik /= l;
}

void Ulamek::skracaj_Re(){
	int a = Euk(licznik, mianownik);
	licznik /= a;
	mianownik /= a;
}

int Ulamek::Euk(int l, int m){
    if(m != 0) return Euk(m, l%m);
    return l;
}

void Ulamek::wypisz(){
    cout << licznik << "/" << mianownik << endl;
}

int Ulamek::get_L(){
    return licznik;
}

int Ulamek::get_M(){
    return mianownik;
}
