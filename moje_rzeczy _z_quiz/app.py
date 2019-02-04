#!/usr/bin/env python
# -*- coding: utf-8 -*-
# g - obiekt g to coś w stylu podręcznego schowka 
# @ dekorator to funkcja która jako argument otrzymuje inna funkcję 
# / - adres główny, główny katalog
# post jak przesyłamy tajne dane które coś modyfikują 
# get =/ do post
#.before - dekorator kótry wykonuje ise jak serwer otrzymuje rządamnie i trzeba coś zrobić
#g. przypisujemy do kontekstu 
#
#  app.py 
#  
from flask import g
from modele import *
from views import *
import os

app.config.update(dict(
    SECRET_KEY='bardzotajnyklucz',
    TITLE='Czat'
))
# DATABASE=os.path.join(app.root_path, baza_nazwa)
@app.before_request
def before_request():
    g.db = baza
    g.db.connect(reuse_if_open=True)

@app.after_request
def after_request(response):
    g.db.close()
    return response

if __name__ == '__main__':
    app.run(debug=True)
    
    

    
