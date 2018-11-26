#!/usr/bin/env python
# -*- coding: utf-8 -*-
# import * - gwiazdka importuje wszystko 
# słownik to baza danych która składa się z kluczy i wartości
# cały prosec tworzenia bazy --> baza.connect() --> baza.create_tables() --> baza.commit() --> baza.close()
# pola.pop(x) - : x to numer wierasza który chcemy usunąć 
#  klasa_uczen.py
import os
from uczniowie_model import *
from baza import czy_jest, czytaj_dane


def dodaj_dane(dane):
    
    for model, plik in dane.items():
        pola = [pole for pole in model._meta.fields]
        pola.pop(0) # usuwanie pola  id 
        print (pola)
        wpisy = czytaj_dane(plik + '.csv')
        model.insert_many(wpisy, fields=pola).execute()
        
        
def main(args):
    if os.path.exists(baza_plik):
        os.remove(baza_plik)
    baza.connect()  # połączenei z bazą 
    baza.create_tables([Klasa, Uczen, Przedmiot, Ocena])  # tworzymy tabele
    
    dane = {
        Klasa: 'klasy',
        Uczen: 'uczniowie',
        Przedmiot: 'przedmioty',
        Ocena: 'oceny'
    }
    
    dodaj_dane(dane)
    baza.commit()
    baza.close()
    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
