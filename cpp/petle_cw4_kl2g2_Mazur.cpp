<<<<<<< HEAD
/*
 * praca_domowa.cpp
 * //w rob przechowujemy wartość bezwzględną z n
 //(ponieważ liczba mogłabyć ujemna, a suma cyfr jest liczbą dodatnią)
 */


#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char **argv)

{

int n;
		cout << "Podaj liczbe calkowita";
		cin >> n;
 int rob=abs(n); 
 int s=0; 
		while(rob > 0) 
 {
		s += rob % 10; 
		rob /= 10; 
 }
		cout << "Suma cyfr liczby " << n << "wynosi" << s << endl;

		return 0;
}
=======
/*
 * praca_domowa.cpp
 * //w rob przechowujemy wartość bezwzględną z n
 //(ponieważ liczba mogłabyć ujemna, a suma cyfr jest liczbą dodatnią)
 */


#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char **argv)

{

int n;
		cout << "Podaj liczbe calkowita";
		cin >> n;
 int rob=abs(n); 
 int s=0; 
		while(rob > 0) 
 {
		s += rob % 10; 
		rob /= 10; 
 }
		cout << "Suma cyfr liczby " << n << "wynosi" << s << endl;

		return 0;
}
>>>>>>> 2e98207021d6588667f9941ef8191b224409cff4
