#include <iostream>
#include <cstdlib>
using namespace std;

class Ulamek
{
private:
	int licznik;
	int mianownik;
	
	int Euk(int l, int m)	{ if(m != 0) return Euk(m, l%m); return l;}
	
public:
	Ulamek()		{};
	Ulamek(int, int);
	~Ulamek()		{};
	
	void zapisz(int, int);
	void wypisz()			{ cout << licznik << "/" << mianownik << endl; }
	void skracaj_It();
	void skracaj_Re();
	
	int get_L()				{ return licznik; }
	int get_M()				{ return mianownik; }
};

Ulamek::Ulamek(int l, int m){
	licznik = l;
	
	if(m != 0)
		mianownik = m;
	else{
		cout << "Mianownik nie może być ZEREM!" << endl;
		exit(1);
	}
}

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

int main()
{
	Ulamek t1(2, 3);
	Ulamek t2(2, 3);
	Ulamek t3(4, 8);
	Ulamek t4(4, 8);
	
	t1.wypisz();
	t2.wypisz();
	t3.wypisz();
	t4.wypisz();
	
	t1.skracaj_It();
	t2.skracaj_Re();
	t3.skracaj_It();
	t4.skracaj_Re();
	
	cout << endl << "Po skroceniu: " << endl;
	
	t1.wypisz();
	t2.wypisz();
	t3.wypisz();
	t4.wypisz();

	//cout << t1.get_L() << endl << t1.get_M();
	
	//system("PAUSE");
	return 0;
}
