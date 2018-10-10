#include "tree.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	srand(time(NULL));
	Tree t1;
	for (int i = 0; i < 25; i++){
		t1.dodaj(rand()%100 + 1);
	}
	t1.wyswietl();
	
	return 0;
}