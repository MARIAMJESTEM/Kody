#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys

def f(a, b):
    return (a + b)

def main(args):
    HTML = input('Czy skopiować folder "public_html"? ')
    
    if HTML == 1 or HTML == 'y' or HTML == 'yes' or HTML == 'true':
        if sys.platform == 'linux':
            print(1)
            os.system('cp -r ~/public_html ~/github/Informatyka')
        elif sys.platform == 'win32':
            os.system('cp C:\UwAmp\www D:\github\Informatyka')
    #adr = '/home/kl3ag2/github/Informatyka/'
    #os.system(f('cd %s', adr))
    os.system('git add .')  #always returns 0
    log = os.system('git commit -m .') #error code: 256;    if commited: 0
    if log != 256:
        log = os.system('git push')    #error code: 32768;  if nothing pushed: 0
    else:
        log = os.system('git pull')          #error code:   if nothing pulled: 0
        print('\n\n')
        print(log)
    return 0

if __name__ == '__main__':
    import sys
    import os
    sys.exit(main(sys.argv))
