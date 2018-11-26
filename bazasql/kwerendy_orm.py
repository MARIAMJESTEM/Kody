#!/usr/bin/env python
# -*- coding: utf-8 -*-
# import * - gwiazdka importuje wszystko 
# słownik to baza danych która składa się z kluczy i wartości
# cały prosec tworzenia bazy --> baza.connect() --> baza.create_tables() --> baza.commit() --> baza.close()
# pola.pop(x) - : x to numer wierasza który chcemy usunąć 
#order_by porządkujemy dane 
# desc porządkujemy dane malejąco
# asc to porządkujemy dane rosnąco 
#  klasa_uczen.py
import os
from uczniowie_model import *



        
        
def main(args):
    baza.connect()  # połączenei z bazą 
   
   kwerendy = [
      "Uczen.select()",
      "Uczen.select().where(Uczen.imie=='Rafał')",
      "Uczen.select().where(Uczen.imie.startswith('G'))",
      "Uczen.select().where(Uczen.egz_mat.between(20,40))",
      "Uczen.select().where((Uczen.nazwisko=='Piasecki') & (Uczen.imie=='Rafał'))"
      "Uczen.select().order_by(Uczen.egz_mat.desc())"
      "Uczen.select().where(Uczen.plec==1).order_by(Uczen.egz_mat)""
   ]
   for obj in eval(kwerendy[0]):
       print(obj.nazwisko, obj.imie)
   
    baza.commit()
    baza.close()
    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
