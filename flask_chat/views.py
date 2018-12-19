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
from flask import Flask
from flask import render_template, request, redirect, url_for
from modele import *
from forms import *

app = Flask(__name__)


@app.route('/')
def index():
    return render_template('index.html')
    
@app.route('/lista')
def index():
    
    return render_template('lista.html', query = pytania)

# widok QUIZ
@app.route('/quiz', methods = ['GET', 'POST'])
def quiz():
    print(request.form)
    if request.method == 'POST':
        wynik = 0
        for pid, oid in request.form.items():
            odp = Odpowiedz().get(Odpowiedz.id == int(oid)).odpok
            if odp:
                wynik += 1

    pytania = Pytanie.select().join(Odpowiedz).distinct().order_by(Pytanie.id)
    return render_template('quiz.html', query = pytania)


@app.route('/dodaj', methods = ['GET', 'POST'])
def dodaj():
    form = DodajForm()
    form.kategoria.choices = [(k.id, k.kategoria) for k in Kategoria.select()]
    
    if form.validate_on_submit():
        print(form.data)
        p = Pytanie(pytanie= form.pytanie.data)
        p.save()
        for o in form.odpowiedzi.data:
            odp = Opowiedz(odpowiedz=o['odpowiedz'],
                            pytanie= p.id,
                            odpok = int(o['odpok']))
            odp.save()
        return redirect(url_for('index'))
    return render_template('dodaj.html', form = form)

    
    
