#include <iostream>
#include "lista.hpp"

using namespace std;

int main()
{
	Lista li;
	for (int i = 1; i <= 10; i++)
		li.Dodaj(i);

	li.Wyswietl();

	li.Usun();

	li.Wyswietl();

	li.Wstaw(8, 19);

	li.Wyswietl();

	li.Wstaw(20, 20);

	li.Wyswietl();

	li.Wstaw(2, 30);

	li.Wyswietl();

	li.Wstaw(1, 40);

	li.Wyswietl();

	return 0;
}
