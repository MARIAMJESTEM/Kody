#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sqlite3

def wys(dane):
    for rekord in dane:
        print(tuple(rekord))

def dodaj(cur):
    cur.execute("""
    INSERT INTO tbKlasy
    VALUES (?,?,?,?)
    """, [None, '1B', 2017, 2020])
    
    wys(cur.fetchall())
    
def aktualizuj(cur):
    cur.execute("""
    UPDATE tbKlasy
    SET klasa = ?
    WHERE klasa = ? and roknaboru = ?
    """, ['1D', '1B', 2017])
    
    wys(cur.fetchall())    
def main(args):
    con = sqlite3.connect('szkola.db')
    cur = con.cursor()  #utworzenie kursora
    con.row_factory = sqlite3.Row
    
    #dodaj(cur)
    aktualizuj(cur)
    
    con.commit()
    wys(cur.execute('SELECT * FROM tbKlasy'))
    
    con.close()
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
