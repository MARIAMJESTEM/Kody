/*
 * wektor.cpp
 * pobiera od uzytkowmnika współrzędne punktu początkowego i końcowego
 * oblicza współrzędne środka wektora
 * użyj dwóch struktur
 * 1. punkt do przechowywania współrzędnych 
 * 2. wektor do przechowywania współrzędnych i końcowego wektora s
 * 
 * 
 */


#include <iostream>
#include <fstream>
using namespace std;

struct punkt{
    int x;
    int y;
};
struct wektor{
    punkt pp;
    punkt pk;
    
};
punkt wylicz_srodek(wektor){
    punkt ps;
   
    ps.x = w.pk.x + w.pp.x;
    ps.y = w.pp.y + w.pk.y;
    
    return ps;
    
    }
wektor getWektor(){
    wektor w1;
    cout << "Podaj x, y punktu początkowego:";
    cin >> w1.pp.x;
    cin >> w1.pp.y;
    cout << "Podaj x, y punktu końcowego: ";
    cin >> w1.pk.x;
    cin >> w1.pk.y;
    return w1;
    
    
    
    }
int main(int argc, char **argv)
{
	wektor w;
    w = getWektor();
    cout << w.pp.x << " " << w.pp.y << endl;
    cout << w.pk.x << " " << w.pk.y << endl;
    punkt ps;
    ps =wylicz_srodek(w);
    cout << "(" << ps.x << "," << ps.y << ")"<< endl;
	return 0;
}

