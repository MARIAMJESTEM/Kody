/*
 * nieparzyste.cpp
 * 
 * Copyright 2018  <>
 * 
 */


#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int n;
    cout << "Podaj n: " << endl;
    cin >> n;
    for (int i = 1; i < n; i += 2)
    {
        cout << i << endl;

    }

	return 0;
}
