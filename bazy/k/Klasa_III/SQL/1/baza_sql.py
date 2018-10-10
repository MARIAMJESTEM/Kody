#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sqlite3
from dane import *

def main(args):
    con = sqlite3.connect('pracownicy.sqlite3')
    cur = con.cursor()  #utworzenie kursora
    
    with open('pracownicy.sql', 'r') as f:
        cur.executescript(f.read())
    
    premia = daneZPliku('premia.txt')
    premia = wyczyscDane(premia, 1)
    
    pracownicy = daneZPliku('pracownicy.txt')
    pracownicy = wyczyscDane(pracownicy, 5)
    
    dzial = daneZPliku('dzial.txt')
    
    cur.executemany('INSERT INTO dzial VALUES (?,?,?)', dzial)
    cur.executemany('INSERT INTO premia VALUES (?,?)',  premia)
    
    cur.executemany('INSERT INTO pracownicy (id, nazwisko, imie, stanowisko, data_zatr, placa, id_dzial) VALUES (?,?,?,?,?,?,?)', pracownicy)
    
    con.commit()
    
    return 0

if __name__ == '__main__':
    import sys
sys.exit(main(sys.argv))
