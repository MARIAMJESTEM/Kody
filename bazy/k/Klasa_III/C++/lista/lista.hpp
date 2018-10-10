#ifndef LISTA_HPP
#define LISTA_HPP

struct ELEMENT{
    int wartosc;
    ELEMENT *wskaznik;
};

class Lista{
private:
    ELEMENT *head;
    ELEMENT *tail; 
    int i;				  // aktualna liczba elementów na liście
 
public:
    
    Lista();
    ~Lista();
    
    void Dodaj(int);
    void Wyswietl();
    void Wstaw(int, int); // wstawia element na podanej pozycji
    
    
    bool Usun();
};

#endif
