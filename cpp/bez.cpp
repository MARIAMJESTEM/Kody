#A52A2A/*
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
         if (a > b && a > c)
     {
                cout << "Najiększe a" << a; 
     }
        if ( b > a && b > c)
     {
                cout << "Największe b" << b; 
     }
        if ( c > a && c > b)
     {
                cout << "Największe c" << c; 
     }
        if (a == b && a > c)
     {
                cout << "największe a i b" << a ;
     }
    
        if (a == c && a > b )
     {
                cout << "największe a = c " << a ;
     }
        if (c == b && b > a)
     {
                cout << "największe b=c " << b ;
     }
        if (a == b && a == c)
     {
                cout << "liczby równe" ;
     }
    return 0;
    
}

