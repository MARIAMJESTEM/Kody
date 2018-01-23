#!/usr/bin/env python
# -*- coding: utf-8 -*-


def main(args):
    i = 2
    a = int(input("Podaj liczbę"))

    while a ==i:
        i = i+2
        if i>a:
            print ("Liczba jest nieparzysta")
    print ("liczba jest parzysta")


    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
