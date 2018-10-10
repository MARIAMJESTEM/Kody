#!/usr/bin/env python
# -*- coding: utf-8 -*-


def konwertuj(a, b):
    """
    Funkcja konwertuje liczbę dziesiętną na system o podanej podstawie
    a - liczba_10
    b - podstawa
    """

    # słownik ze znakami cyfr większych od 9
    cyfry = {10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}

    reszty = []  # pusta lista na reszty

    while a > 0:
        reszty.append(a % b)
        a = a / b

    reszty.reverse()  # odwrócenie elementów listy

    if b > 10:
        reszty = [cyfry[x] if x > 9 else x for x in reszty]

    return reszty


def kon_10(a, b):
    liczba_10 = 0




def main(args):
    liczba_10 = int(raw_input("Podaj liczbę: "))
    podst = int(raw_input("Podaj podstawę: "))

    print "".join([str(x) for x in konwertuj(liczba_10, podst)])

    podst = int(raw_input("Podaj podstawę: "))
    liczba_podst = raw_input("Podaj liczbę: ")

    print kon_10(liczba_podst, podst)

    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
