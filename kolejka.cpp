/*
 * kolejka.cpp
 */

#include <iostream>

using namespace std;

int rozmiar = 3;
int dane[3];
int head=0;
int ile =0;
int tail =0;


void empty() {
    if (sp == 0) {
        cout << "Stos pusty" << endl;
    } else {
        cout << "Stos nie jest pusty" << endl;
    }
}

void pop() {
    if (sp-1 < 0) {
        cout << "Stos pusty!";
    } else {
        cout << "POP: " << dane[sp-1] << endl;
        sp--;
    }
}

void push() {
    if (ile >= rozmiar) {
        cout << "Kolejka pełna!" << endl;
    } else if(ile ==0) {
        cout << "Podaj wartość: ";
        cin >> dane[tail];
        tail++;
        ile++;
    }
}

int main(int argc, char **argv)
{
    push();
    push();
    push();
    push();
    
    pop();
    pop();
    pop();
    pop();
    return 0;
}
