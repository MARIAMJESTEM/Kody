

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




int main(int argc, char **argv)

{    
    
    int ile = 0;
     cout<<"Podaj liczbe: ";
     cin>>ile;
    fib_iter(int ile);
    for(int i=0;i<ile;i++)
    {
        cout<<i+1<<" wyraz ciagu to: "<<fib_rek(i)<<endl;
    }
 	

 return 0;
}
