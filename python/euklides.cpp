/*
* euklides.cpp
* 
*/
 
 
 #include <iostream>
 
using namespace std;

int euklides(int a, int b)
 {
     while(a != b)
     {
         if(a > b)
             a = a - b;
         else
             b = b - a;
     }
     return a;
 }
 
int main(int argc, char **argv)
 {
	int a = 0;
    int b = 0;
     
    cout<<"Podaj pierwszą liczbę: ";
    cin>>a;
    cout<<"Podaj drugą liczbę: ";
    cin>>b;
     
     cout<<"NWD wynosi: "<<euklides(a,b);
     
 	return 0;
 }
 
