#!/usr/bin/env python
# -*- coding: utf-8 -*-


def fib_iter(n):
    """Funkcja wyświetla kolejne wyrazy ciągu Fibonacciego.
    Funkcja zwraca n-ty wyraz ciągu
    F(0) = 0
    F(1) = 1
    F(n) = F(n-2) + F(n-1) dla n > 1
    """

    a, b = (0, 1)
    if n == 0:
        print a
        return a
        return 0
    elif n == 1:
        print b
        return b
        return 1
    a, b = (0, 1)
    print(a)

    for i in range(2, n):
    for i in range(1, n):
         b = a + b
         a = b
         print (a, " ", b, " ", b / a)

    return b


def main(args):
    n = int(input("Numer wyrazu w ciągu: "))
    print("Wyraz {:d} = {:d}".format(n, fib_iter(n)))
     return 0

 if __name__ == '__main__':
     import sys
sys.exit(main(sys.argv))
