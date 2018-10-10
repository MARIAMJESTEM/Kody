#!/usr/bin/env python
# -*- coding: utf-8 -*-
import csv

def daneZPliku(plik):
    dane = []
    with open(plik, newline = '', encoding = 'utf-8') as plik_csv:
        tresc = csv.reader(plik_csv, delimiter = '\t')
        for rekord in tresc:
            dane.append(rekord)
        plik_csv.close()
    return dane

def wyczyscDane(dane, pole):
    for i, rekord in enumerate(dane):
        element = rekord[pole]
        element = element.replace(" ", "")
        element = element.replace(",", ".")
        element = element.replace("zł", "")
        rekord[pole] = element
        dane[i] = rekord
    return dane
    
def main(args):
    premia =  daneZPliku('premia.txt')
    premia = wyczyscDane(premia, 1)
    
    print(premia)
    
    pracownicy = daneZPliku('pracownicy.txt')
    pracownicy = wyczyscDane(pracownicy, 5)
    
    print(pracownicy)
    
    dzial = daneZPliku('dzial.txt')
    
    print(dzial)
    
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
