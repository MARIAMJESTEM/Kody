/*
 * car.cpp
 * *konstruktor służy najczęściej do inicjowania zmiennych
 * '' wtedy char
 * "" wtedy string
 * 
 */


#include <iostream>
#include <cstdlib>
#include "car.h"

using namespace std;

Car::Car(){
    marka=model="";
    rocznik=przebieg=0;
    
}
Car::Car(string mr, string ml, int r, int p){
    marka = mr ;
    model = ml;
    rocznik = r;
    przebieg = p;
    
}
Car::dodaj(){
    cout << "Dodaj samochód: " << endl; 
    cout << "Marka: "; cin >> marka;
    cout << "Model: "; cin >> model;
    cout << "Rocznik: "; cin >> rocznik;
    cout << "Przebieg: "; cin >> przebieg;
}
Car::dane() {
    cout <<"\n Twoje piękne auto:" << endl;
    cout << "Marka" << marka<< endl;
    cout << "Model" << model<< endl;
    
    
}
