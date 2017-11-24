#!/usr/bin/env python
# -*- coding: utf-8 -*-
# for i in range(len(lista)/2):
# print(lista[indeks], lista[indeks + 1])
# indeks += 2
from random import randint


def minmax(lista):
    lmin = lista[0]
    lmax = lista1[0]
    for i in range(len(lista) / 2):


def minimum(lista):
    min = lista[0]
    for i in lista:
        if i < min:
            min = i
    return min


def maksimum(lista):
    max = lista[0]
    for i in lista:
        if i > max:
            max = i
    return max


def losuj(ile, zakres):
    lista = []
    for i in range(ile):
        lista.append(randint(0, zakres))
    return lista


def main(args):
    ile = 20
    zakres = 50
    lista = losuj(ile, zakres)
    assert minimum([7, 4, 9, 1, 3, 0]) == 0
    assert maksimum([7, 4, 9, 1, 3, 0]) == 9
    print(lista)
    print("Minimum: ", minimum(lista))
    print("Maksimum: ", maksimum(lista))
    return 0


if __name__ == '__main__':
    import sys
sys.exit(main(sys.argv))
