#!/usr/bin/env python
# -*- coding: utf-8 -*-
# range (0,7) - [0,1,2,3,4,5,6,]
# metoda dziel i zwyciężaj - polega na tym, że można problemy dizleić na mniejsze cżęści a sposób ich rozwiązywania jest taki sam jak w małych częściach i dużych


def wyszukaj_liniowo(l, el):
    for i in range(0, len(l)):
        if l[i] == el:
            return i
    return -1

# int wyszukaj liniowo(int l[], int n, int el)
# {
#     for(int i = 0; i < n; i++)
#     {
#         if (l[i] == el)
#         return i;
#     }
# }
def wyszukaj_binarnie(lista, el):
    lewy, prawy = 0, len(lista) -1
    while


def main(args):
    lista = [4, 3, 7, 0, 2, 3, 1, 9, -4]
    lista.sort()
    el = 3
    print(wyszukaj_liniowo(lista, el))
    assert(wyszukaj_liniowo(lista, 8)) == -1
    wyszukaj_binarnie(lista, el)
    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
