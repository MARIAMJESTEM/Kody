/*
 * zlozonosc2.cpp
 */

using namespace std;
#include <iostream>

int main(int argc, char **argv)
{
	int a =0;
    cout << "Podaj a: " << endl;
    cin >> a;
    
    for (int i= 1; i <=a; i+=2)
    {
            cout << i << " ";
    }
	return 0;
}

