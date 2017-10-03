/*
 * kalkulator.cpp
 */
 


#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char **argv)
{  char znak; 
    int a , b ;
    
    cout << "Podaj znak " << endl;
    cin >> znak ;
    
    cout << "Podaj dwie liczby " ;
    cin >> a >> b;

     // + ,- , *, /
    if (znak == '+')
    { cout << "Suma" << a+ b ;
    }
        else  if (znak == '-')
    { cout << "Różnica" << a - b ;
    }
        else if (znak == '/')
    { cout << "Iloraz" << a /b ;
    }
        else if (znak == '*')
    { cout << "Iloczyn" << a * b ;
    }
        
        


    return 0;
}

