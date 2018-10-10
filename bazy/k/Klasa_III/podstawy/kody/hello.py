#!/usr/bin/env python
# -*- coding: utf-8 -*-

ROK_TERAZ = 2017
ROK_PYTHON = 1991

def parzyste(n):
    ile = list(range(0, n+1, 2))
    print(ile)
    return len(ile)


def main(args):
    imie = input("Podaj swoje imie: ")
    print("Witaj ", imie)
    wiek = int(input("Podaj swój wiek: "))
    
    rok_urodzenia = ROK_TERAZ - wiek

    print("Urodziłeś się w ", rok_urodzenia)
    
    if rok_urodzenia > ROK_PYTHON:
        print("Jestem starszy od ciebie.")
    elif (rok_urodzenia < ROK_PYTHON):
        print("Jestem młodszy od ciebie.")
    else:
        print("Jesteśmy rówieśnikami!")
    
    n = int(input("Podaj zakres liczb parzystych: "))
    print('Ilość parzystych: ', parzyste(n))
    
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
