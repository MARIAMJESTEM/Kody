/*
 * main.cpp
 *p
 * petla zaporowa
 */


#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    char zn= 't'; // musi być inicjacja jakimś znakiem 
    
     while (zn== 't' || zn == 'n' || zn== 'T' || zn == 'N')
    {
       cout << "Podaj znak" << endl;
       cin >> zn;
    };
    //switch (zn)
    //{
        //case't' :
        //case 'T':
        //case 'N':
        //case'n':
           //cout << "Poprawna" << endl;
        //}
	return 0;
}

