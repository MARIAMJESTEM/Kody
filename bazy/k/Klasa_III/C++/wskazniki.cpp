#include <iostream>
using namespace std;

int main()
{
    int x = 11;
    cout << x << endl;      //wartość zmiennej
    cout << &x << endl;     //adres zmiennej w pamięci
    cout << * &x << endl;   //wartość zmiennej pod adresem
    
    int * px;               //deklaracja wskaźnika do liczby całkowitej
    px = &x;                //inicjacja wskaźnika
    cout << px << endl;     //adres przypisany do wskaźnika
    cout << *px << endl;    //wartość wskazywana przez wskaźnik
    
    int y = 100;
    px = &y;
    cout << px << endl;     //adres przypisany do wskaźnika
    cout << *px << endl;    //wartość wskazywana przez wskaźnik
    
    int tab = new * [];
    return 0;
}
