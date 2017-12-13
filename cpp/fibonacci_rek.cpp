

#include <iostream>
using namespace std;
 

int fib_rek(int n)
{
    if(n<2)
    {
        return 1;
    }
    else return fib_rek(n-2) + fib_rek(n-1);
}



 void fib_iter(int n)
 {
     int a = 0;
     int b = 1;
     int tmp = 0; 
     if (n == 0) 
     {
         cout << 0;
     }
     cout << a;
     for (int i=1; i<n; i++) {
         tmp = b;
         b = a + b;
         a = tmp;
         cout<<"Wyraz nr."<<i+1<<": "<<a<<endl;
         cout<<"Zlota liczba: "<<float(b)/float(a)<<endl;
         }
 }
 int main(int argc, char **argv)
 {
 	int ile = 0;
     cout<<"Podaj liczbe: ";
     cin>>ile;
    fib_iter(ile);
    for(int i=0;i<ile;i++)
    {
        cout<<i+1<<" wyraz ciagu to: "<<fib_rek(i)<<endl;
    }
 	return 0;
 }
