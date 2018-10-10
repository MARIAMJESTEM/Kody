#include <iostream>
#include "Uczniowie.hpp"

using namespace std;

int main(){
    Uczniowie u1("Karol", "Bogdanski", "3A");
    u1.dodajOcene(1);
    u1.dodajOcene(5);
    u1.dodajOcene(2);
    u1.dodajOcene(1);
    u1.dodajOcene(6);
    u1.dodajOcene(3);
    
    cout << "Oceny ucznia " << u1.zwrocNazwe() << ": " << endl;
    u1.wypiszOceny();
    
    cout << "Srednia ocen ucznia " << u1.zwrocNazwe() << ": " << u1.srednia() << endl;
    return 0;
}
