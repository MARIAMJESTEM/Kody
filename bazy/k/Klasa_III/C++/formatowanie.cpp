#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
using namespace std;

int li = 52165;
float lf = 165.545;

void f1()
{
    printf("Liczba Pi: %15.4f\n", M_PI);
    printf("Liczba lf: %15.4f\n", lf);
    printf("Liczba li: %-15.4f\n", double(li));
    printf("Liczba li: %15d\n", li);
    printf("Hex li: %#x\n", li);
    printf("Oct li: %#o\n", li);
}

int main(int argc, char **argv)
{
    cout.precision(5);
    cout.width(15);
    cout << lf << endl;
    
    cout << setprecision(3) << setw(20) << M_PI << endl;
    cout << setprecision(3) << setw(20) << left << M_PI << endl;
    cout << setprecision(3) << setw(20) << left << setfill('_') <<M_PI << endl;
    cout << setprecision(3) << setw(20) << right << setfill('_') << M_PI << endl;
    cout << hex << li << endl;
    cout << oct << li << endl;
    return 0;
}

