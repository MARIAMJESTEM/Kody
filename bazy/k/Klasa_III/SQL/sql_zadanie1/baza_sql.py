#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  baza_sql.py

import sqlite3
from dane import *


def main(args):
    con = sqlite3.connect(':memory:')
    cur = con.cursor()  # utworzenie kursora
    
    with open('pracownicy.sql', 'r') as f;
	cur.executescript(f.read())
	
    premia = daneZPliku('premia.txt')
    premia = wyczyscDane(premia, 1)
    
    pracownicy = daneZPliku('pracownicy.txt')
    pracownicy = wyczyscDane(pracownicy, 5)
    
    dzial = daneZPliku('dzial.txt')
    dzial = wyczyscDane(dzial, 1)
    
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
