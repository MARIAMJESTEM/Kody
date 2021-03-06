#!/usr/bin/env python
# -*- coding: utf-8 -*-
#HiddenField jak chcemy żeby pole się nie wyświetlało 
#blad1 to zmienna
#validator czyli pole musi być uzupełnione 
#  forms.py
#  
from flask_wtf import FlaskForm
from wtforms import HiddenField, StringField, BooleanField
from wtforms import SelectField, FormField, FieldList
from wtforms.validators import Required

blad1 = 'To pole jest wymagane'

class OdpForm(FlaskForm):
    id = HiddenField('OdpowiedĹş id')
    pytanie = HiddenField('Pytanie id')
    odpowiedz = StringField('OdpowiedĹş:',
                             validators=[Required(message=blad1)])
    odpok = BooleanField('Poprawna:')

class DodajForm(FlaskForm):
    id = HiddenField('Pytanie id')
    pytanie = StringField('TreĹÄ pytania:',
                          validators=[Required(message=blad1)])
    kategoria = SelectField('Kategoria', coerce=int)
    odpowiedzi = FieldList(FormField(OdpForm), min_entries=3)
