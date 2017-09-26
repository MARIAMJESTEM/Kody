/*
 * hello.cpp
 */
//pobierz trzy liczy całkowite od użytkownika i wydrukuj największą 

#include <iostream> //io  
using namespace std;


int main(int argc, char **argv)
{
    int a, b, c;
    a = b = c = 0;
    cout << "podaj trzy liczby : ";
    cin >> a >> b >> c;
         if (a > b)
     {
         if (a > c)
                cout << "Najiększe a" << a; 
                else
                cout << "Największe c " << c;
     }
     else if ( b > a )
     {
         if (b > c)
                cout << "Największe b" << b; 
     }
     
    return 0;
}

