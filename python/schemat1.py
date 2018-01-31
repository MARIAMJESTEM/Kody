#!/usr/bin/env python
# -*- coding: utf-8 -*-
# input pobiera od użytkownika liczbę
# lista(range(2,101,4)) wydrukuj liste zacznij od 2aż do 101 z wartościami co 4
# pass oznacza, że w tym miejscu w przyszłości pojawi się jakiś kod


def main(args):
    a = 0
    while a < 1 or a > 99:  # wyznaczam poprawny zakres a
        a = int(input("Podaj liczbę: "))
    for i in range(2, a + 1, 2):
        print(i)
        if a == i:
            print("Liczba jest parzysta:)")
            return 0
    print("Liczba jest nieparzysta:(")
    # i = 2
    # while i < 100:
    #     if a == i:
    #         print("Parzysta")
    #         return 0
    #     i = i + 2
    # print("Nieparzysta ")
    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
