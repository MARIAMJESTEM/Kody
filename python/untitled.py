#!/usr/bin/env python
# -*- coding: utf-8 -*-

from random import randint

def main(args):
    ileliczb = int(input("Ile liczb chcesz zgadnąć ?"))
    maksliczb = int(input("Podaj górny zakres. "))

    liczby = []
    for i in range(ileliczb):
        liczba = randint(0, maksliczb)
        if liczby.count(liczba) ==0:
            liczby.append(liczba)
    print (liczby)

    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
