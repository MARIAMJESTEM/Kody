/*
 * petla.cpp
 */


#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    //iteracja -powtarzanie czegoś
    int i;
    // inkrementacja i +1 lub i ++ czyli wartośc zmiennej zostaje zwiększona o jeden
    //dekrementacja i-- wartość zostaje zmniejszona o jeden 
    for (i = 0; i <= 100; i++)
    // zwiększ wartość 'i' o dwa 
     {  
         if (i % 10 ==0) 
         {
             cout << i << endl ;
         }
         //cout << '*' << endl; 
         // % dzielenie modulo czyli z resztą
         //<> różne od lub !=
     }
    
    return 0;
}

//ctrl+ c przerywa warunek
