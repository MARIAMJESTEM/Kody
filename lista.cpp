/*
 * kolejka.cpp
 */

#include <iostream>

using namespace std;

struct wezel {
    int liczba;
    wezel *nast; 
    
};
char czy(){
    
    char odp;
    cout << "Następny element (t/n)? ";
    cin >> odp;
    return odp;
    
}
int getD(){
    
    int d;
    cout<< "Podaj liczbę: ";
    cin>> d;
    return d;
    
}
void delLista(node *glowa){
        node *tmp;
        while(glowa != NULL){
            tmp = glowa;
            glowa = glowa->nast;
            delete tmp;
        }
}

void drukuj(node *glowa){
        node *tmp;
        tmp=glowa;
        while(tmp != NULL){
            cout << tmp->liczba << " ";
            tmp= tmp-> nast;
        }
        cout << endl;
}
int addToB(){
    
    node *glowa = NULL;
    node *nowy;
     while(czy() != 'n'){
         try{
             nowy = new node;
         } catch(bad alloc){
            cout << "Brak pamięci";
            return -1;
           }
         nowy->nast = glowa;
         nowy->liczba = getD();
         glowa = nowy;
    }
    drukuj(glowa);
    delLista(glowa);
    return 0;
    
}

int addToE(){
    
    wezel *glowa = NULL;
    wezel *ogon= NULL;
    wezel *nowy;
    
     while(czy() != 'n'){
         try{
             nowy = new wezel;
         } catch(bad alloc){
            cout << "Brak pamięci";
            return -1;
           }
         nowy->nast = NULL;
         nowy->liczba = getD();
        if (glowa ==NULL) {
            glowa = nowy;
            ogon = glowa;
        }else{
            ogon->nast = nowy;
            ogon = nowy;
            
        }
    }
    drukuj(glowa);
    delLista(glowa);
    return 0;
    
}
int main(int argc, char **argv)
{
    addToB();
    return 0;
}
