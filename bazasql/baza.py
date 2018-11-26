#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  baza.py
import csv
import sqlite3
import os.path


def czy_jest(plik):
    if not os.path.isfile(plik):
        print("Plik {} nie istnieje!".format(plik))
        return False
    return True


def czytaj_dane(plik, separator=","):
    dane = []  # pusta lista na rekordy
    
    if not czy_jest(plik):
        return dane
    
    with open(plik, newline='', encoding='utf-8') as plikcsv:
        tresc = csv.reader(plikcsv, delimiter=separator, skipinitialspace=True)
        for rekord in tresc:
            dane.append(tuple(rekord))
    
    return dane


def ile_kolumn(cur, tab):
    """zlicza i zwraca liczbę kolumn w podanej tabeli"""
    i = 0
    for kol in cur.execute("PRAGMA table_info('" + tab + "')"):
        i += 1
    return i


def main(args):
    ### KONFIGURACJA ###
    baza_nazwa = 'uczniowie'
    tabele = ['uczniowie', 'klasy', 'przedmioty', 'oceny']
    roz = '.csv'
    naglowki = False
    ####################
    
    con = sqlite3.connect(baza_nazwa + '.db')
    cur = con.cursor()  # obiekt tzw. kursora
    
    if not czy_jest(baza_nazwa + '.sql'):
        return
    
    with open(baza_nazwa + '.sql', 'r') as plik:
        cur.executescript(plik.read())
    
    for tab in tabele:
        ile = ile_kolumn(cur, tab)  # liczba kolumn w tabeli
        dane = czytaj_dane(tab + roz, separator=',')
        ile_d = len(dane[0])
        
        if ile > ile_d:
            dane2 = []  # tymczasowa lista
            for r in dane:
                r.insert(0, None)
                dane2.append(r)
            dane = dane2

        if naglowki:
            dane.pop(0)  # usuwamy rekord z nagłówkami kolumn

        ile = len(dane[0])
        cur.executemany('INSERT INTO ' +
                        tab +
                        ' VALUES(' +
                        ','.join(['?'] * ile) +
                        ')', dane)

    con.commit()
    con.close()
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
