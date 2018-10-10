#include <iostream>
#include <cstdlib>

using namespace std;

//Napisz kalkulator pozwalający na wprowadzenie znaku działania, a następnie jego argumentów.

void dod()
{
    float a, b;
    cin >> a >> b;
    cout << a + b << endl;
}

void min()
{
    float a, b;
    cin >> a >> b;
    cout << a - b << endl;

}

void mno()
{
    float a, b;
    cin >> a >> b;
    cout << a * b << endl;
}

void dziel()
{
    float a, b;
    cin >> a >> b;
    while( b == 0 )
        {
            cout << "Podaj inną wartość!" << endl;
            cin >> b;
        }
    cout << a / b << endl;
}

int main()
{
    char tryb = ' ';

    cout << "Jakie działanie chcesz wykonać?\nDodawanie (+)\nOdejmowanie (-)\nMnożenie (*)\nDzielenie (/)\n";
    cin >> tryb;

    switch(tryb)
    {
        case '+':
            cout << "Podaj dwie liczby" << endl;
            dod();
            break;
        case '-':
            cout << "Podaj dwie liczby" << endl;
            min();
            break;
        case '*':
            cout << "Podaj dwie liczby" << endl;
            mno();
            break;
        case '/':
            cout << "Podaj dwie liczby" << endl;
            dziel();
            break;
        default:
            exit(0);
    }
}
