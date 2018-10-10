#!/usr/bin/env python
# -*- coding: utf-8 -*-

def main(args):
    li = 100
    lf = 654.6546
    print('Liczba: {}'.format(li))
    print('Liczba: {1}\n{0}'.format(li, lf))
    print('Liczba: {:15}\nLiczba: {:15}'.format(li, lf))
    print('Liczba: {:<15}\nLiczba: {:<15}'.format(li, lf))
    print('Liczba: {:^15}\nLiczba: {:^15}'.format(li, lf))
    print('Liczba: {:_^15}\nLiczba: {:*<15}'.format(li, lf))
    print('Liczba: {:_^15.4}\nLiczba: {:*<15.4}'.format(float(li), lf))
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
