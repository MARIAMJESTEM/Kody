#include "tree.hpp"
#include <iostream>

using namespace std;

Tree::Tree() {
	korzen = NULL;
}

Tree::Tree(int war) {
	korzen = new GALAZ;
	korzen -> lewy = NULL;
	korzen -> prawy = NULL;
	korzen -> war = war;
}

Tree::~Tree() {
	czysc(korzen);
}

void Tree::czysc(GALAZ *el) {
	if (el->lewy != NULL) {
		czysc(el->lewy);
	}
	if (el->prawy != NULL) {
		czysc(el->prawy);
	}
	el = NULL;
}

void Tree::dodaj(int war, GALAZ *el) {	
	if (war <= el->war) {
		if (el->lewy != NULL) {
			dodaj(war, el->lewy);
		}
		else {
			el->lewy = new GALAZ;
			el->lewy->lewy = NULL;
			el->lewy->prawy = NULL;
			el->lewy->war = war;
		}
	}
	else {
		if (el->prawy != NULL) {
			dodaj(war, el->prawy);
		}
		else {
			el->prawy = new GALAZ;
			el->prawy->lewy = NULL;
			el->prawy->prawy = NULL;
			el->prawy->war = war;
		}

	}
}

void Tree::dodaj(int war) {	
	if (korzen != NULL){
		dodaj(war, korzen);
	}else{
	korzen = new GALAZ;
	korzen -> lewy = NULL;
	korzen -> prawy = NULL;
	korzen -> war = war;
	}
}

void Tree::wyswietl(GALAZ *el) {
	if (el != NULL) {
		if (el->lewy != NULL) {
			wyswietl(el->lewy);
		}

		cout << el->war << endl;

		if (el->prawy != NULL) {
			wyswietl(el->prawy);
		}
	}
}

void Tree::wyswietl() {
	if (korzen != NULL) {
		if (korzen->lewy != NULL) {
			wyswietl(korzen->lewy);
		}

		cout << korzen->war << endl;

		if (korzen->prawy != NULL) {
			wyswietl(korzen->prawy);
		}
	}
}