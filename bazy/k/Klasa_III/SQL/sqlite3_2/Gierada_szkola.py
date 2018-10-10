#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sqlite3

def wys(dane):
    for rekord in dane:
        print(tuple(rekord))

def kw_a(cur):
    cur.execute("""
    SELECT imie, nazwisko
    FROM tbUczniowie, tbKlasy
    WHERE tbUczniowie.KlasaID = IDKlasy
    AND Klasa LIKE '1A'
    """)
    
    wys(cur.fetchall())

def kw_b(cur):
    cur.execute("""
    SELECT Imie, Nazwisko, MAX(EgzHum)
    FROM tbUczniowie, tbOceny
    WHERE IDUcznia = UczenID
    """)
    
    wys(cur.fetchall())

def kw_c(cur):
    cur.execute("""
    SELECT AVG(EgzMat)
    FROM tbUczniowie, tbOceny, tbKlasy
    WHERE UczenID = IDUcznia AND tbUczniowie.KlasaID = IDKlasy
    AND Klasa LIKE '1A'
    """)
    
    wys(cur.fetchall())

def kw_d(cur):
    cur.execute("""
    SELECT Ocena
    FROM tbUczniowie, tbOceny
    WHERE UczenID = IDUcznia
    AND imie LIKE 'Dorota' AND nazwisko LIKE 'Nowak'
    """)
    
    wys(cur.fetchall())

def kw_e(cur):
    cur.execute("""
    SELECT AVG(Ocena)
    FROM tbUczniowie, tbOceny, tbPrzedmioty
    WHERE PrzedmiotID = IDPrzedmiotu
    AND Przedmiot LIKE 'fizyka'
    AND DataD LIKE '%-10-%'
    """)
    
    wys(cur.fetchall())

def main(args):
    con = sqlite3.connect('szkola.db')
    cur = con.cursor()  #utworzenie kursora
    
    kw_e(cur)
    
    con.close()
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
