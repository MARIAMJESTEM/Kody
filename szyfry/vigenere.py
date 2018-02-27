#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  szyfr_vigenere.py
#  
#  

def szyfruj(tekst, haslo):
    szyfrogram = []
    litery = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

    litera_hasla = 0

    for i in tekst:
        index = litery.find(i)
        if index != -1:
            index += litery.find(haslo[litera_hasla])
            index %= 26

            szyfrogram.append(litery[index])
            litera_hasla += 1
            if litera_hasla == len(haslo):
                litera_hasla = 0
        else:
            szyfrogram.append(i)

    return "".join(szyfrogram)
    


def deszyfruj(szyfrogram, haslo):
    tekst = []
    litery = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    litera_hasla = 0

    for i in szyfrogram:
        index = litery.find(i)
        if index != -1:
            index -= litery.find(haslo[litera_hasla])
            index %= 26

            tekst.append(litery[index])
            litera_hasla += 1
            if litera_hasla == len(haslo):
                litera_hasla = 0
        else:
            tekst.append(i)

    return "".join(tekst)



def main(args):
    tekst = input("Podaj tekst: ")
    haslo = input("Podaj hasło: ")
    tekst = tekst.upper()
    haslo = haslo.upper()

    szyfrogram = szyfruj(tekst, haslo)

    print("Zaszyfrowane: ", szyfrogram)
    print("Deszyfrowane: ", deszyfruj(szyfrogram, haslo))
    
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
