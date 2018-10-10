#!/usr/bin/env python
# -*- coding: utf-8 -*-
from peewee import *
from dane import *

bazaPlik = SqliteDatabase('baza.db')

class BaseModel(Model):
    class Meta:
        database = bazaPlik

class Premia(BaseModel):
    id = CharField(primary_key = True)
    premia = DecimalField()

class Dzial(BaseModel):
    id = IntegerField(primary_key = True)
    nazwa = CharField()
    siedziba = CharField()

class Pracownik(BaseModel):
    id = CharField(primary_key = True)
    nazwisko = CharField()
    imie = CharField()
    stanowisko = ForeignKeyField(Premia)
    data_zatr = DateField()
    placa = DecimalField(decimal_places = 2)
    id_dzial = ForeignKeyField(Dzial)
    premia = DecimalField(decimal_places = 2, default = 0)

bazaPlik.connect()
#bazaPlik.create_tables([Premia, Dzial, Pracownik], True)

#~dane = [
    #~{'id': 'Kierowca', 'premia': '0.2'},
    #~{'id': 'Dyrektor', 'premia': '0.7'},
    #~{'id': 'Inżynier', 'premia': '0.4'}
#~]

#~for rekord in dane:
    #~Premia.create(id = rekord['id'], premia = rekord['premia'])

premia =  daneZPliku('premia.txt')
premia = wyczyscDane(premia, 1)

premia = [dict(zip(Premia._meta.sorted_field_names, rekord)) for rekord in premia]

pracownicy = daneZPliku('pracownicy.txt')
pracownicy = wyczyscDane(pracownicy, 5)

pracownicy = [dict(zip(Pracownik._meta.sorted_field_names, rekord)) for rekord in pracownicy]
dzial = daneZPliku('dzial.txt')
dzial = [dict(zip(Dzial._meta.sorted_field_names, rekord)) for rekord in dzial]

with bazaPlik.atomic():
    Premia.insert_many(premia).execute()
    Dzial.insert_many(dzial).execute()
    Pracownik.insert_many(pracownicy).execute()


bazaPlik.commit()
bazaPlik.close()

def main(args):

    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
