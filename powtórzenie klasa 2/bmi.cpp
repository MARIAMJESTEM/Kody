/*
 * bmi.cpp

 */


#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    float waga, wzrost, bmi;
    waga = wzrost = bmi = 0;
	cout<< "podaj swoją wagę"<<endl;
    cin >> waga;
    cout<< "podaj swój wzrost"<<endl;
    cin >> wzrost;
    bmi = waga/(wzrost*wzrost);
    cout <<  "Bmi:" << bmi;
    
    if(bmi>=30)
    {
        cout << "otyłość";
    }
    if(bmi>=25)
    {
        cout << "nadwaga";
    }
    if(bmi<18.5)
    {
        cout << "niedowaga";
    }
    if(bmi >18.5 && bmi<24.9)
    {
        cout<< "norma";    
    }
    
	return 0;
}

