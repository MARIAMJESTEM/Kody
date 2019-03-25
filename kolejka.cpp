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


void pop() {
    if (ile==0) {
        cout << "Kolejka jest pusta!";
        head = tail= 0;
    } else {
        cout << dane[head]<< endl;
        tail =head;
        head++;
        ile--;
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
