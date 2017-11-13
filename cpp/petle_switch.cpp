/*
 * main.cpp
 *pobiera numer miesiaca i wyświetla jego nazwę 
 * petla zaporowa
 */


#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int m = 0;
    //while (true)
    //{
       //cout << "Podaj miesiąc" << endl;
       //cin >> m;
       //if (m<13 && m>0)
          //break;
    //};
    
     while (m>12 || m <1)
    {
       cout << "Podaj miesiąc" << endl;
       cin >> m;
       
          
    };
    //if (m ==1)
        //{cout << "Styczeń "  << endl;
        //}
    //else if (m ==2)
        //{cout << "Luty "  << endl;
        //}
    //else if (m ==3)
        //{cout << "Marzec "  << endl;
        //}
     switch (m) // sprawd czy w pudełku m ma wartośc
     {
         case 1:
             cout << "Styczeń";
         break;
         case 2:
             cout << "Luty";
         break;
         case  3 :
             cout << "Marzec";
         break;
         case 4:
             cout << "Kwiecie”";
         break;        
     }    
	
	return 0;
}

