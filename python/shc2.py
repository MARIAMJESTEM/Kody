#!/usr/bin/env python
# -*- coding: utf-8 -*-


def main(args):
    a =0
    a = int(input("Podaj ocene jaką chcesz z inf "))
    if a == 1:
        print ("Bradzo dobrze już ją masz !")
    if a == 2:
        print("troche dużo żądasz")
    if a == 3:
        print("nie masz szans")
    if a == 4:
        print("MOŻESZ POMARZYĆ ")
    if a == 5:
        print("hehe  śmieszki ale żem się uśmiał")


    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
