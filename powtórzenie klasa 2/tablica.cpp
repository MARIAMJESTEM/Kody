/*
 * tablica.cpp
 */

using namespace std;
#include <iostream>

int main(int argc, char **argv)
{   
    int liczby[20];
    srand(time(NULL)); // INICJACJA GENERATORA LICZB PSEUDOLOSOWYCH
    for(int i =0; i < 20;i ++)
    {
        liczby[i] = rand() % 100;  //zapis do tablicy 
    }
    for(int i =0; i < 20;i ++)
    {
        cout << liczby[i] << " ";
    }
	
	
	return 0;
}

