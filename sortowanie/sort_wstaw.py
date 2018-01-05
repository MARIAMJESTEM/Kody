#!/usr/bin/env python
# -*- coding: utf-8 -*-


def sort_wstaw(lista):
    """ wersja liniowa"""
    for i in range(1, len(lista)):
        el = lista[i]
        k = i - 1
        while k >= 0 and lista[k] > el:  # wyszukuje pozycje do wstawienia
            lista[k + 1] = lista[k]  # przesuwanie elementów
            k -= 1
        lista[k + 1] = el  # wstawianie elementu
    return lista


def wyszukaj_binarnie_it(lista, el):
    lewy, prawy = 0, len(lista) - 1
    while lewy < prawy:
        srodek = floor((lewy + prawy) / 2)
        if el <= lista[srodek]:
            prawy = srodek
        else:
            lewy = srodek + 1
    if lista[lewy] == el:
        return lewy
# for (int 1=0; i < n)
# n - to ilość elementów w tablicy

def sort_wstaw_bin(lista):
    """ wersja binarna """
    for i in range(1, len(lista)):
        el = lista[i]
        k = wyszukaj_bin(lewy, prawy, lista, el)
        # tworzenie listy z wstawionym elementem
        # todo
        lista =





def main(args):
    lista = [4, 3, 7, 0, 2, 3, 1, 9, -4]
    print(lista)
    # f[3, 4, 7, 0, 2, 3, 1, 9]
    # s[3, 4, 7, 0, 2, 3, 1, 9]
    # t[ 0, 3, 4, 7, 2, 3, 1, 9]
    print(sort_wstaw(lista))
    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
