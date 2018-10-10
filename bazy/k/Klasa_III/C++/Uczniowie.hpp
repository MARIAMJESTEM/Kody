#ifndef UCZNIOWIE_HPP
#define UCZNIOWIE_HPP
#include <string>
#include <vector>
using namespace std;

class Uczniowie{
private:
    string imie;
    string nazwisko;
    string klasa;
    vector <int> oceny;
    
public:
    
    Uczniowie();
    Uczniowie(string, string);
    Uczniowie(string, string, string);
    ~Uczniowie();
    
    void ustawDaneUcznia(string, string);
    void ustawKlase(string);
    void wypiszOceny();
    void dodajOcene(int);

    float srednia();
    
    string zwrocNazwe();
};

#endif
