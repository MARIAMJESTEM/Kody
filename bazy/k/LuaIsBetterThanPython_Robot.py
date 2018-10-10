#!/usr/bin/env python
# -*- coding: utf-8 -*-

from rgkit import rg
from random import randint
#########################################################################
#Robot porusza się do wylosowanego pola, a jeżeli wrogi robot znajduje się za blisko
#sojusznicze roboty spieszą mu z pomocą (nie do końca to działa, a ja
#już mam dość próbowania,aby to naprawić, bo żaden debbuger nie chce działać
#i nie pozwala mi to na zaglądanie do aktualnych zmiennych) oraz atakuje go
#########################################################################


class Dotable(dict):
    #########################################################################
    #https://hayd.github.io/2013/dotable-dictionaries
    #Licencja:
    #Copyright (c) 2013 Andy Hayden
    #
    # Permission is hereby granted, free of charge, to any person obtaining a copy
    # of this software and associated documentation files (the "Software"), to deal
    # in the Software without restriction, including without limitation the rights
    # to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    # copies of the Software, and to permit persons to whom the Software is
    # furnished to do so, subject to the following conditions:
    #
    # The above copyright notice and this permission notice shall be included in all
    # copies or substantial portions of the Software.
    #
    # THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    # IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    # FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    # AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    # LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    # OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    # SOFTWARE.
    #
    #Zastosowanie:
    #Umożliwia stosowanie notacji kropkowej do wywoływania danych ze słownika
    #########################################################################
    __getattr__ = dict.__getitem__

    def __init__(self, d):
        self.update(**dict((k, self.parse(v))
                           for k, v in d.iteritems()))

    @classmethod
    def parse(cls, v):
        if isinstance(v, dict):
            return cls(v)
        elif isinstance(v, list):
            return [cls.parse(i) for i in v]
        else:
            return v

#########################################################################
#Stałe wartości
#########################################################################
R_MAX_FROM_CENTER = 8
R_FROM_ENEMY = 2
X = {'min': 0 + R_MAX_FROM_CENTER, 'max': 19 - R_MAX_FROM_CENTER}
Y = {'min': 0 + R_MAX_FROM_CENTER, 'max': 19 - R_MAX_FROM_CENTER}

#########################################################################
#Wartości dzielone pomiędzy wszystkie sojusznicze roboty
#########################################################################
values = {
    'enemies': [],
    'commands': {},
    'safeSpace': (),
    'config': False,
    'turn': 0
}

values = Dotable.parse(values)


class Robot:
    def robotPosByID(self, game, id):
        #########################################################################
        #Zwraca lokację robota po jego 'robot_id'
        #########################################################################
        for robot in game.robots.keys():
            if self.player_id == game.robots[robot].player_id and game.robots[
                robot].robot_id == id:
                return game.robots[robot].location

    #########################################################################

    def checkTurn(self, game):
        #########################################################################
        #Przy następnej turze usuwa sojusznicze
        #roboty z słownika, jeżeli już nie istnieją
        #########################################################################
        if game.turn != values.turn:
            values.turn = game.turn
            if len(values.commands):
                for robot in values.commands.keys():
                    if self.robotPosByID(game, robot) not in game.robots:
                        del values.commands[robot]

    #########################################################################

    def getEnemies(self, game):
        #########################################################################
        #Czyści listę wrogów i zapełnia ją aktualnymi pozycjami wrogów
        #########################################################################
        values.enemies = []
        for location, robot in game.robots.iteritems():
            if self.player_id != robot.player_id:
                values.enemies.append(robot.location)

    #########################################################################

    def genSafePlace(self):#, r=True):
        #########################################################################
        #Metoda losuje pozycję do 'obrony', do której roboty będą się poruszały;
        #########################################################################
        while True:
            values.safeSpace = (
            randint(X['min'], X['max']), randint(Y['min'], Y['max']))
            if 'normal' in rg.loc_types(values.safeSpace):
                break

        #########################################################################
        #Jeżeli r == False, metoda losuje pozycję do której dobot będzie się poruszał
        #########################################################################
        # if r:
        #     while True:
        #         values.safeSpace = (
        #         randint(X['min'], X['max']), randint(Y['min'], Y['max']))
        #         if 'normal' in rg.loc_types(values.safeSpace):
        #             break
        # else:
        #     while True:
        #         ret = (randint(X['min'], X['max']), randint(Y['min'], Y['max']))
        #         if 'normal' in rg.loc_types(values.safeSpace):
        #             return ret

    #########################################################################

    def config(self, game):
        #########################################################################
        #Na początku rozgrywki generuje pozycję do której roboty będą się poruszały.
        #########################################################################
        values.config = True
        self.genSafePlace()

    #########################################################################

    def alarm(self, game):
        #########################################################################
        #Robot idzie do swojego sojusznika, jeżeli wrogi robot jest za blisko
        #(tylko, że nie działa to do końca poprawnie
        #########################################################################
        for _, robot in game.robots.iteritems():
            if self.player_id == robot.player_id and len(
                    set(values.commands[robot.robot_id]['action']) & set(['attack', 'guard', 'suicide'])) and values.commands[robot.robot_id]['status'] != 'alarm':
                values.commands[robot.robot_id]['action'] = 'move'
                values.commands[robot.robot_id]['status'] = 'alarm'
                values.commands[robot.robot_id]['destination'] = self.location

    #########################################################################

    def commandGuard(self, game):
        #########################################################################
        #Ustawia status 'alarm' jeżeli wrogi robot jest za blisko
        #########################################################################
        if values.commands[self.robot_id]['action'] == 'nil':
            for bots in values.enemies:
                if rg.wdist(self.location, bots) == R_FROM_ENEMY:
                    values.commands[self.robot_id]['action'] = 'guard'
                    values.commands[self.robot_id]['status'] = 'alarm'
                    self.alarm(game)
                    break
        #########################################################################
        #Jeżeli w pobliżu nie ma wrogów, a robot ma status 'alarm', zmienia jego status na 'calm'
        #########################################################################
        if values.commands[self.robot_id]['action'] == 'alarm':
            sEnemies = set(values.enemies)

            for loc in rg.locs_around(self.location):
                sEnemies -= set(loc)

            if len(sEnemies) == len(values.enemies):
                values.commands[self.robot_id]['action'] = 'nil'
                values.commands[self.robot_id]['status'] = 'calm'
                values.commands[self.robot_id]['destination'] = values.safeSpace

    #########################################################################

    def commandAttack(self, game):
        #########################################################################
        #Jeżeli wrogi robot znajduje się obok, ustawia status 'atack', aby go atakować
        #########################################################################
        for bots in values.enemies:
            if rg.wdist(self.location, bots) == 1:
                values.commands[self.robot_id]['action'] = 'attack'
                values.commands[self.robot_id]['stauts'] = 'attack'
                values.commands[self.robot_id]['destination'] = bots
                break

        #########################################################################
        #Jeżeli w pobliżu nie ma wrogów, a robot ma status 'atack', zmienia jego status na 'calm'
        #########################################################################
        if len(set(values.enemies) - set(rg.locs_around(self.location))) == len(
                values.enemies):
            values.commands[self.robot_id]['action'] = 'nil'
            values.commands[self.robot_id]['status'] = 'calm'
            values.commands[self.robot_id]['destination'] = values.safeSpace

    #########################################################################

    def commandMove(self, game):
        #########################################################################
        #Jeżeli kilka z sojuszniczych robotów chce wejść na to samo pole,
        #wszystkie opróch jednego mają ustawiony status 'guard'
        #########################################################################
        values.commands[self.robot_id]['toward'] = rg.toward(self.location, values.commands[self.robot_id]['destination'])

        for _, bots in game.robots.iteritems():
            if self.player_id == bots.player_id:
                if bots.robot_id == self.robot_id:
                    continue

                if len(values.commands[bots.robot_id]['toward']) != 0:
                    if values.commands[bots.robot_id]['toward'] == \
                            values.commands[self.robot_id]['toward']:
                        values.commands[self.robot_id]['action'] = 'guard'

                #########################################################################
                #Poprzednio załorzeniem było, że roboty się wyminą, ale kod, który miał to umożliwić nie działał poprawnie
                #########################################################################
                # if rg.dist(self.location, bots.location) <= 2 and values.commands[self.robot_id]['toward'] == \
                #         values.commands[bots.robot_id]['toward']:
                #     # print(3)
                #     locs = set(rg.locs_around(self.robotPosByID(game, self.robot_id))) - set(
                #         values.commands[self.robot_id]['toward']) - set(bots.location)
                #     if len(locs):
                #         print(4)
                #         pom = {}
                #
                #         for loc in locs:
                #             print(5)
                #             pom[loc] = rg.dist(values.commands[self.robot_id]['destination'], loc)
                #
                #         pSmall, dSmall = pom.iteritems().next()
                #
                #         for p, d in pom.items():
                #             print(6)
                #             if dSmall > d:
                #                 print(7)
                #                 dSmall = d
                #                 pSmall = p
                #
                #         del pom
                #         print (rg.toward(self.location, pSmall))
                #         values.commands[self.robot_id]['toward'] = rg.toward(self.location, pSmall)
                #     else:
                #         values.commands[self.robot_id]['action'] = 'guard'

    #########################################################################

    def commandSuicide(self, game):
        #########################################################################
        #Jeżeli ilość punktów życia jest mniejsza od liczby punktów obrażeń,
        #które może zebrać od wrogów obok niego, popełnia samobójstwo
        #########################################################################
        ene = set(values.enemies) & set(rg.locs_around(self.location))
        if self.hp >= len(ene) * 8 and self.hp <= len(ene) * 10:
            values.commands[self.robot_id]['action'] = 'suicide'
            values.commands[self.robot_id]['status'] = 'suicide'

    #########################################################################

    def act(self, game):
        if not values.config:   #Konfigurowanie rozgrywki
            self.config(game)

        if self.robot_id not in values.commands.keys():     #Jeżeli robota nie ma w słowniku sojuszniczych robotów, dodaj go
            values.commands[self.robot_id] = {'action': 'nil', 'status': 'calm', 'destination': values.safeSpace, 'toward': ()}

        self.commandSuicide(game)
        if values.commands[self.robot_id]['status'] == 'suicide':   #Zwraca 'suicide'
            return ['suicide']

        self.checkTurn(game)
        self.getEnemies(game)

        self.commandGuard(game)
        self.commandAttack(game)

        if values.commands[self.robot_id]['action'] == 'attack':    #Jeżeli status robota to 'attack', atakuje podaną mu pozycję
            return ['attack', values.commands[self.robot_id]['destination']]
        if self.location != values.commands[self.robot_id]['destination'] and (values.commands[self.robot_id]['status'] == 'alarm' or values.commands[self.robot_id]['action'] == 'nil'):  #Jeżeli robot nie dotarł do celu oraz jego status to 'alarm' lub jego akcja to 'nil', zwraca się do swojego celu
            self.commandMove(game)
            return ['move', values.commands[self.robot_id]['toward']]
        return ['guard']    #Zabezpieczenie, jeżeli poprzednie warunki nie zostaną spełnione

        #########################################################################
        #'Poprawiony' kod do zwracania działań robota
        #(tyle, że działa trochę gorzej, niż ten stworzony pierwotnie)
        #########################################################################
        # if rg.loc_types(self.location):
        #     return ['move', rg.toward(self.location, self.genSafePlace(game, False))]
        # if values.commands[self.robot_id]['status'] == 'attack':
        #     return ['attack', values.commands[self.robot_id]['destination']]
        # if  self.location != values.commands[self.robot_id]['destination'] and (values.commands[self.robot_id]['action'] == 'nil' or values.commands[self.robot_id]['status'] == 'alarm'):
        #     self.commandMove(game)
        #     if values.commands[self.robot_id]['status'] is 'guard' or self.location == values.commands[self.robot_id]['toward']:
        #         return ['guard']
        #     return ['move', values.commands[self.robot_id]['toward']]
        # if values.commands[self.robot_id]['status'] is 'guard':
        #     return ['guard']
        # return ['guard']
