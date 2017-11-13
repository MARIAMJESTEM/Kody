/*
 * zadanie2.cpp

 * 
 */


#include <iostream>
using namespace std ;

int main(int argc, char **argv)
{
	int m;
    int n;
    cout << "Podaj m (10-99)" << endl;
    cin >> m;
    cout <<"Podaj n (11-99)"<< endl ;
    cin >> n;
    while (m>n ||m<10 ||n<10 || n>99)
          {
           cout << "Podaj m (10-99)" << endl;
           cin >> m;
           cout <<"Podaj n (11-99)"<< endl ;
           cin >> n;
          }
    while ( m<= n)
          {
        if (m % 3== 0)
            {
                cout << m << endl;
                }
                else if ((m +1)% 3 == 0)
                {
                    cout < m+1 << endl ;
                    }
                    
            }
    return 0;
    
}

