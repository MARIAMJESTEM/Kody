/*
 * formatowanie.cpp
 *
 * 
 
 */


#include <iostream>
#include <iomanip>
#include <cstdio> 
#include <math.h> // stała Pi (M_PI)

 using namespace std;
 
int main(int argc, char **argv)
{   
    int lint = 100;
    float lrze = 12.789;
    
    //ios_base:: fmtflags
    //fx|= cout.hex; // ma za zadanie przekonwertować liczbę na system hexodecymalny (???)
    //fx|= cout.showbase;
    
    // cout.flags(fx);
    cout << oct  << showbase;
    cout << lint << endl;
	
    cout << M_PI << endl;
    cout.precision(3);
    cout << M_PI << endl;
    cout.width(20); // minimalna szerokośc pola
    cout.fill('-'); // wypełnienie pola
    cout << lint << endl;
    cout << setw(20) << lrze << endl;
    
    printf("%12f\n", 10*M_PI); // f - oznacza float czyli liczba rzeczywista 
	return 0;
}

