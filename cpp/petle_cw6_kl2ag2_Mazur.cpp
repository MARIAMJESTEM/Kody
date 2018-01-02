<<<<<<< HEAD
/*
  
 */


#include <iostream>
using namespace std;


int main(int argc, char **argv)
{
    int dzielna=0;
    int dzielnik=0;
    int iloraz=0;
    int wynik=0;
    
    while(dzielnik == 0)
    {
        cout<<"Podaj dzielną: ";
        cin >>dzielna;
        cout<<"Podaj dzielnik: ";
        cin >>dzielnik;
    }
        while(true)
        {
            wynik=dzielna-dzielnik;
            if(wynik>=0)
            {
                iloraz++;
                dzielna=0;
                dzielna+=wynik;
            }
            else break;
        }
        cout<<"Iloraz jest równy: "<<iloraz;
	
	return 0;
}
	
	

=======
/*
  
 */


#include <iostream>
using namespace std;


int main(int argc, char **argv)
{
    int dzielna=0;
    int dzielnik=0;
    int iloraz=0;
    int wynik=0;
    
    while(dzielnik == 0)
    {
        cout<<"Podaj dzielną: ";
        cin >>dzielna;
        cout<<"Podaj dzielnik: ";
        cin >>dzielnik;
    }
        while(true)
        {
            wynik=dzielna-dzielnik;
            if(wynik>=0)
            {
                iloraz++;
                dzielna=0;
                dzielna+=wynik;
            }
            else break;
        }
        cout<<"Iloraz jest równy: "<<iloraz;
	
	return 0;
}
	
	

>>>>>>> 2e98207021d6588667f9941ef8191b224409cff4
