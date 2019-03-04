#include <iostream>
#include <cstdlib>

#ifndef __CAR_H_
#define __CAR_H_
class Car{
     private:
        string marka;
        string model;
        int rocznik;
        int przebieg;
     public:
         Car(); //konstruktor
         Car(string, string, int, int); //konstruktor
         void dodaj();
         void dane();
    
}
#endif
