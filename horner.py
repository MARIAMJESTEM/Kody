#!/usr/bin/env python
# -*- coding: utf-8 -*-


def horner(k, tb, x):
	wynik = tb[0]
	for i in range(1, k + 1):
		wynik = wynik * x + tb[i]
		
	return wynik

def horner_rek(k, tb, x):
	
	if k == 0:
		return tb[0]
	return horner_rek(k-1,tb,x)*x + tb[k]

def main(args):
	tb = []
	k = 3
	x = int(input("Podaj wartość argumentu: "))
	for i in range(0, 4):
		tmp = int(input("podaj wartości indeksów: "))
		tb.append(tmp)
	print("wynik wielomianu wynosi: ", horner_rek(k, tb, x))
	return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
