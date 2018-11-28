#!/usr/bin/env python
# -*- coding: utf-8 -*-
# import * - gwiazdka importuje wszystko 
# słownik to baza danych która składa się z kluczy i wartości
# cały prosec tworzenia bazy --> baza.connect() --> baza.create_tables() --> baza.commit() --> baza.close()
# pola.pop(x) - : x to numer wierasza który chcemy usunąć 
#order_by porządkujemy dane 
# desc porządkujemy dane malejąco
# asc to porządkujemy dane rosnąco 
#jak select jest pusty to wybiera wszystkie dostępne pola
#jak pobieramy dane z wielu tabel to uzywamy join 
#.group_by to grupuje
#  klasa_uczen.py
import os
from uczniowie_model import *

def kw09():
    """lista klas i ilość uczniów"""
    query = (Uczen
        .select(fn.Count(Uczen.id).allias('ilu'),Uczen.klasa.klasa)
        .join(Klasa)
        .group_by(Klasa)
        .order_by(SQL('ilu').asc())
    
    )
    for obj in query:
        print(obj.klasa.klasa, obj.ilu)
    
def kw08():
    """lista nazwisk uczniów i nazw klas"""
    query = (Uczen
        .select(Uczen.nazwisko, Uczen.klasa.klasa)
        .join(Klasa)
        
    
    )
    for obj in query:
        print(obj.nazwisko, obj.klasa.klasa)
        
        
def kw10():
    """lista przedmiotów i ilość ocen """
    query = (Ocena 
        .select(fn.Count(Ocena.id).allias('ile'), Ocena.przedmiot.przedmiot)
        .join(Przedmiot)
        .group_by(Przedmiot)
        .order_by(SQL('ile').asc())
    
    )
    for obj in query:
        print(obj.przedmiot.przedmiot, obj.ile)
        
def kw11():
    """suma wszystkich ocen """
def main(args):
    baza.connect()  # połączenei z bazą 
   
    kwerendy = [
      "Uczen.select()",
      "Uczen.select().where(Uczen.imie=='Rafał')",
      "Uczen.select().where(Uczen.imie.startswith('G'))",
      "Uczen.select().where(Uczen.egz_mat.between(20,40))",
      "Uczen.select().where((Uczen.nazwisko=='Piasecki') & (Uczen.imie=='Rafał'))"
      "Uczen.select().order_by(Uczen.egz_mat.desc())"
      "Uczen.select().where(Uczen.plec==1).order_by(Uczen.egz_mat)"
   ]
   #for obj in eval(kwerendy[0]):
    #  print(obj.nazwisko, obj.imie)
   
    baza.commit()
    baza.close()
    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
