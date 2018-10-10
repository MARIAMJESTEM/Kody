#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  bez nazwy.py


def suma(a, b):
    wynik = a+b
    return wynik
    
    
def roznica(a, b):
    wynik = a-b
    return wynik
    
    
def iloczyn(a, b):
    wynik = a*b
    return wynik
    
    
def iloraz(a, b):
    wynik = a/b
    return wynik



def main(args):
    a = int(input("Podaj 1. liczbę: "))
    print (a)
    b = int(input("Podaj 2. liczbę: "))
    print (b)
    
    print("Suma: ", suma(a, b))
    print("Różnica:",roznica(a, b ))
    print("Iloczyn: ",iloczyn(a,b))
    print("Iloraz: ", iloraz(a, b))
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
