#ifndef ULAMEK_H
#define ULAMEK_H

class Ulamek
{
private:
	int licznik;
	int mianownik;
	
	int Euk(int l, int m);
    	
public:
	Ulamek();
	Ulamek(int, int);
	~Ulamek();
	
	void zapisz(int, int);
	void wypisz();
	void skracaj_It();
	void skracaj_Re();
	
	int get_L();
	int get_M();
};

#endif
