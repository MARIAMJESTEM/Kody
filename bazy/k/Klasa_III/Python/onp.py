#!/usr/bin/env python
# -*- coding: utf-8 -*-


def main(args):
    stos = []       #stos jako lista
    
    onp = input("Podaj wyrażenie ONP oddzielając każdy element spacją: \n")
    
    print(onp)
    
    onp = onp.split()
        
    for v in onp:
        if v.isdigit():
            stos.append(v)
        else:
            a = stos.pop()
            b = stos.pop()
            
            stos.append(str(eval(b + v + a)))
        
    print("Wynik: ", stos.pop())
    
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
