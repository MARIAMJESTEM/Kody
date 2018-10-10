#include <iostream>
#include "ul_ulamek.hpp"
using namespace std;

int main(){
    Ulamek t1(4, 8);
	Ulamek t2(4, 8);
	Ulamek t3(9139, 34220);

	t1.wypisz();
	t2.wypisz();

	t1.skracaj_It();
	t2.skracaj_Re();
    t3.skracaj_Re();

	cout << endl << "Po skroceniu: " << endl;
	
	t1.wypisz();
	t2.wypisz();
	t3.wypisz();

    return 0;
}
