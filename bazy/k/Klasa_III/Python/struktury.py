#!/usr/bin/env python
# -*- coding: utf-8 -*-
import csv


def osoba(imie, nazwisko, wiek):
    return {'imie': imie, 'nazwisko': nazwisko, 'wiek': wiek}


def pobierzDane(lista, n):
    for i in range(0, n):
    	imie = input('Podaj imie: ')
    	nazwisko = input('Podaj nazwisko: ')
    	wiek = int(input('Podaj wiek: '))
    	lista.append(osoba(imie, nazwisko, wiek))
    return lista


def wyswietlDane(lista, n):
    for i in lista:
        print('Imie: {:20}'.format(i['imie']))
        print('Nazwisko: {:20}'.format(i['nazwisko']))
        print('Wiek: {:20}'.format(i['wiek']))
        
    
def zapiszDane(lista):
    with open('baza.txt', 'w') as file:
        for i in lista:
            file.write(i['imie'] + ', ' + i['nazwisko'] + ', ' + str(i['wiek']) + ';\n')
            
            
def zapiszDaneCsv(lista):
    with open('baza.csv', 'w') as file:
        tresc = csv.writer(file, delimiter = ';')
        for i in lista:
            tresc.writerow(i.values())
            
def czytajDane(nazwa):
    with open(nazwa, newline='') as file:
        tresc = csv.reader(file, delimiter=';')
        for i in tresc:
            print(i)

def main(args):
    #osoba1 = osoba('Jan', 'Kowalski', 23)
    #print(osoba1['imie'], osoba1['nazwisko'])
    #lista = []
    #~ile = int(input('Ile osób chcesz wprowadzić? '))
    #~lista = pobierzDane(lista, ile)
    #~wyswietlDane(lista, ile)
    #~zapiszDaneCsv(lista)
    czytajDane('baza.csv')
    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
