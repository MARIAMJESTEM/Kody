/*
 * binarne.cpp
 * 
 */
 
 
#include <iostream>
  
using namespace std;
  

 

int wyszukaj_liniowo(int l[], int n, int el)
  {
      for(int i = 0; i < n; i++)
      {
         if (l[i] == el)
             return i;
     }
     return -1;
 }
  
 int main(int argc, char **argv)
 {
 	
     int ile = 9;
     int l[ile] = {4, 3, 7, 0, 2, 3, 1, 9, -4};
     int el = 3;
     
     cout<<wyszukaj_liniowo(l, el, ile);
 
 	return 0;
 }
 
