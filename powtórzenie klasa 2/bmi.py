#!/usr/bin/env python
# -*- coding: utf-8 -*-


def main(args):
    waga = float(input('Podaj wage: '))
    print (waga)
    wzrost = float(input('podaj wzrost: '))
    print (wzrost)
    bmi = float(waga/(wzrost * wzrost))

    print ( bmi )


    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
