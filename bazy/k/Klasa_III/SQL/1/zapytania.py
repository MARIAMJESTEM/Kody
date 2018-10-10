#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sqlite3

def wys(dane):
    for rekord in dane:
        print(tuple(rekord))

def kw_d(cur):
    parametr = input("Podaj nazwę działu: ")
    #parametr2 = input("Kobiety czy mężczyźni: ")
    
    cur.execute("""
                SELECT dzial.id, dzial.nazwa, nazwisko, imie FROM dzial, pracownicy
                WHERE dzial.id = pracownicy.id_dzial
                AND dzial.nazwa = ?
                AND imie NOT LIKE '%a'
                """, (parametr, ))
    
    wys(cur.fetchall())

def kw_c(cur):    
    cur.execute("""
                SELECT siedziba, SUM(placa) AS pensje
                FROM pracownicy, dzial
                WHERE dzial.id = pracownicy.id_dzial
                GROUP BY siedziba
                ORDER BY pensje ASC
                """)
    
    wys(cur.fetchall())

def kw_e(cur):    
    cur.execute("""
                SELECT nazwisko, stanowisko, (placa*premia.premia)
                FROM pracownicy, premia
                WHERE premia.id = stanowisko
                """)
    
    wys(cur.fetchall())

def kw_e(cur):    
    cur.execute("""
                SELECT nazwisko, stanowisko, (placa*premia.premia)
                FROM pracownicy, premia
                WHERE premia.id = stanowisko
                """)
    
    wys(cur.fetchall())

def kw_f(cur):    
    cur.execute("""
                SELECT AVG(placa)
                FROM pracownicy
                GROUP BY imie LIKE '%a'
                """)
    
    wys(cur.fetchall())

def kw_g(cur):
    cur.execute("""
                SELECT imie, nazwisko, stanowisko, CAST((JulianDay() - JulianDay(data_zatr)) / 365 AS Integer) AS okres
                FROM pracownicy, dzial
                WHERE dzial.id = id_dzial
                ORDER BY okres DESC
                LIMIT 10
                """)
    
    wys(cur.fetchall())

def kw_h(cur):
    par = input("Podaj identyfikator pracownika: ")
    cur.execute("""
                SELECT imie, nazwisko, stanowisko, siedziba
                FROM pracownicy, dzial
                WHERE dzial.id = id_dzial
                AND pracownicy.id = ?
                """, (par,))
    
    wys(cur.fetchall())

def main(args):
    con = sqlite3.connect('pracownicy.sqlite3')
    cur = con.cursor()  #utworzenie kursora
    
    kw_h(cur)
    
    con.close()
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
