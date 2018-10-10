#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void wprowadz(float *tab, int ile)
{
    for(int i = 0; i < ile; i++)
    {
        cout << "Podaj liczbę: ";
        //cin >> tab[i];
        cin >> *(tab + i);
        cout << "Adres elementu: "<< tab + i << endl;
    }
}

void drukuj(float *tab, int ile)
{
    for(int i = 0; i < ile; i++)
        cout << *(tab + i) << endl;
}

void wypelnij2W(int **tab, int w, int k)
{
    srand(time(NULL));
    for (int i = 0; i < w; i++){
        for (int j = 0; j < k; j++){
            tab[i][j] = rand() % 101;
            cout << setw(4) << tab[i][j];
            }
            cout << "\n";
        }
}

void tabliczka(int **tab, int w, int k){
    cout << "\n";
    for(int i = 0; i < w; i++){
        for(int j = 0; j < k; j++){
            tab[i][j] = (i + 1)*(j + 1);
            cout << setw(6) << tab[i][j];
        }
        cout << "\n";
    }
}

int tab1W()
{
    int ile = 0;
    float * ptab = NULL;
    cout << "Ile podasz liczb? ";
    cin >> ile;
    
    try {
        ptab = new float[ile];              //utworzenie tablicy dynamicznej
        wprowadz(ptab, ile);
        drukuj(ptab, ile);
    }catch(bad_alloc){
        cout << "Brak pamieci" << endl;
        return 1;
    }
    
    return 0;
}

int tab2W()
{
    int w, k;
    cout << "Podaj ilość wierszy i kolumn: ";
    cin >> w >> k;
    
    int **tab = NULL;                        //deklaracja wskaźnika do wskaźnika
    
    try {
        tab = new int *[w];                 //utworzenie tablicy dynamicznej wskaźników
    }catch(bad_alloc){
        cout << "Brak pamieci" << endl;
        return 1;
    }
    
    for (int i = 0; i < w; i++){
        try{
            tab[i] = new int [k];
        }catch(bad_alloc){
            cout << "Brak pamieci" << endl;
            return 1;
        }
    }
    
    //wypelnij2W(tab, w, k);
    tabliczka(tab, w, k);
    
    return 0;
}

int main()
{
    tab2W();
    
    return 0;
}
