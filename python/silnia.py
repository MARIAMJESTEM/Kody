#!/usr/bin/env python
# -*- coding: utf-8 -*-
#  a0 = 1 dla
#  a1 = a
# an a *... * a (n - czynników) dla N+ - {1}
# list (range(10))
# list (range(1, 10 + 1))
# for i in range(1, n+1):
# cd print(i)
# n! = 1 dla {0,1}
# n! = a * ... * n dla N+ - {0,1}
#  DO DOMU potęga i silnia wersja w c++


def silnia_it(n):
    """Funkcja oblicza iteracyjnie
    psilnię liczby naturalnej"""
    wynik = 1
    for i in range(2, n+1):
        wynik = wynik * i
    return wynik


def main(args):

    a = int(input("Podaj liczbę: "))
    assert type(a) == int

    assert silnia_it(1) == 1
    assert silnia_it(0) == 1
    assert silnia_it(3) == 6

    # print("Potęga: ", potega_it(a, n))

    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
