#!/usr/bin/env python
# -*- coding: utf-8 -*-
from urllib.request import urlopen
from bs4 import BeautifulSoup
import os
import time
START = 1901
END = 10029
ADR = 'http://www.mspaintadventures.com/?s=6&p=00'

def generate():
	return random.randint(START, END)

def url(number):
	if number >= 10000:
		ad = ADR[:-1] + str(number)
	else:
		ad = ADR + str(number)
	return ad

def switcher(works):
	while(works):
		if time()%30 == 0:
			t = ''
	return 0
		

def main(args):
	
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
