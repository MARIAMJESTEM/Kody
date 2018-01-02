#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  horner.py
#


def horner_it(k, tbwsp, x):
    wynik = tbwsp[0]
    for i in range(1, k + 1):
        wynik = wynik * x + tbwsp[i]


    return wynik

def main(args):
    tbwsp = []
    stopien = 3
    x = int(input("Podaj wartość argumentu: "))
    for i in range(0, 4):
        tmp = int(input("Podaj współczynnik wielomianu: "))
        tbwsp.append(tmp)

    print("Wynik wielomianu wynosi: ", horner_it(stopien, tbwsp, x))


    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
