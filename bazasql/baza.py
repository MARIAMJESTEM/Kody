#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  csv.py
import csv

def czytaj_dane(plik, separator=","):
    dane= [] # pusta lista na rekordy
    with open(plik, 'r', newline='', encoding='utf-8') as plikcsv:
        tresc= csv.reader(plikcsv, delimiter=separator)
        for rekord in tresc:
            dane.append(rekord)
    print(dane)
    return dane
        

def main(args):
    con = sqlite3.connect('bazagus.db')# połączenie
    cur = con.cursor() # obiekt kursora
    
    with open('bazagus.sql', 'r') as plik:
        cur.executescript(plik.read())
    
    #czytaj_dane('miasta.csv')
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
