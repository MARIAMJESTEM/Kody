#include <iostream>
#include "lista.hpp"

using namespace std;

Lista::Lista() {
    head = NULL;
    tail = NULL;
    i = 0;
}

Lista::~Lista() {
    while(Usun())   {;};
}

void Lista::Dodaj(int a) {
    ELEMENT *el = new ELEMENT;
    el -> wartosc = a;
    el -> wskaznik = NULL;
    
    if (head == NULL){
        head = el;
        tail = el;
        i = 1;
    } else {
        tail -> wskaznik = el;      // ustawienie wskaźnika do dotychczasowego ostatniego elementu na adres nowego elementu
        tail = el;
        i++;
    }
}

void Lista::Wyswietl() {
    ELEMENT *el = head;
    
    while (el != NULL) {
        cout << el -> wartosc << " ";
        el = el -> wskaznik;
    }
    
    cout << endl;
}

bool Lista::Usun(){
    if(head != NULL) {              // lista zawiera elementy
        if (tail == head) {
            delete head;            // usuwamy zmienną wskazywaną przez head
            head = NULL;
            tail = NULL;
        } else {
            ELEMENT *el = head;
            while(el -> wskaznik != tail) {
                el = el -> wskaznik;
            }
            delete el -> wskaznik;
            el -> wskaznik = NULL;
            tail = el;              // aktualizacja wskaznika ostatniego elementu
            i--;
        }
        return true;
    }
    return false;
}

void Lista::Wstaw(int poz, int war){
	if (poz < 0)	poz *= (-1);	// wartość bezwzględna
    if(poz != 0){
		if(poz > i){
			Dodaj(war);				// jeżeli pozycja na którą chcemy wstawić nową wartość jest większa od rozmiaru listy, to nowa wartość jest dodawana na końcu listy
		}
		else if (poz == 1) {		// jeżeli pozycja nowej wartości jest równa 1, zmień adres w 'head'
			ELEMENT *el = new ELEMENT;
			el -> wartosc = war;
			el -> wskaznik = head;
			head = el;
			i++;
		} else {
			ELEMENT *el = new ELEMENT;
			el -> wartosc = war;	// przypisanie nowej wartości
			
			ELEMENT *p = head;		// wskaźnik pomocniczy

			for (int j = 1; j != poz - 1; j++)
				p = p -> wskaznik;	// dotarcie do pozycji o jeden wcześniejszej aby przepisać adres, który oswołuje się do następnej wartości do nowej wartości

			el -> wskaznik = p -> wskaznik;
			p -> wskaznik = el;
			
			i++;
		}
	}
}
