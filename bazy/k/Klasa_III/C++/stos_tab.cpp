#include <iostream>
#include <cstdlib>
using namespace std;

bool czyPusty(int sp){
    if(sp >= 1)
        return true;
    return false;
}

bool czyPelny(int sp, int sr){
    if(sp < sr)
        return true;
    return false;
}

void push(int * s, int d, int sr, int & sp){
    cout << d << " ";
    if(czyPelny(sp, sr)){
        s[sp] = d;
        sp++;
    }else
        cout << "Blad przepelnienia stosu!" << endl;
}

int pop(int * s, int & sp){
    sp--;
    return s[sp];
}

int main(){
    srand(time(NULL));
    
    int *stack;     //wskaźnik
    int sr;         //rozmiar stosu
    int sp = 0;     //wskaźnik stosu
    
    cout << "Podaj rozmiar stosu: ";
    cin >> sr;
    
    stack = new int [sr];
    
    for(int i = 0; i < sr; i++)
        push(stack, rand()%100 + 1, sr, sp);
        
    cout << endl << endl;
    
    for(int i = sp; i > 0; i--)
        cout << pop(stack, sp) << " ";
    
    return 0;
}
