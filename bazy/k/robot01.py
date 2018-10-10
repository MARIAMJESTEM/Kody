#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rg


class Robot:

    def act(self, game):
        def czy_wejscie(poz):
            if 'spawn' in rg.loc_types(poz):
                return True
            return False
        #rg.loc_types()                    zwraca typ pola na danej pozycji: 'spawn'; 'normal'; 'obstacle'; 'invalid'
        
        def czy_wrog(poz):
            if game.robots.get(poz) is not  None:
                if game.robots[poz].player_id != self.player_id:
                    return True
            return False
            
        # funkcja zwróci prawdę, jeżeli w odległości 2 kroków z przodu jest wróg
        def zprzodu(l1, l2):
            if rg.wdist(l1, l2) == 2:
                if abs(l1[0] - l2[0]) == 1:
                    return False
                else:
                    return True
            return False
            
        def miedzypole(p1, p2):
            return (int((p1[0]+p2[0]) / 2), int((p1[1]+p2[1]) / 2))
            
        for poz, robot in game.get('robots').items():
            if czy_wrog(poz):
                if rg.wdist(poz, self.location) == 2:
                    if zprzodu(poz, self.location):
                        return ['attack', miedzypole(poz, self.location)]
                    if rg.wdist(rg.toward(poz, rg.CENTER_POINT), self.location) == 1:
                        return ['attack', rg.toward(poz, rg.CENTER_POINT)]
                    else:
                        return ['attack', (self.location[0], poz[1])]

        lista_wrogow = [] #lista wrogich robotów
        wrogowie_obok = []
        
        for poz in rg.locs_around(self.location):
            if czy_wrog(poz):
                wrogowie_obok.append(poz)

        print rg.locs_around(self.location)
        
        #print game
        #print game.robots
        
        dystans = rg.dist(self.location, rg.CENTER_POINT)
        
        if dystans >= 7:
            return ['move', rg.toward(self.location, rg.CENTER_POINT)]
        
        if czy_wejscie(self.location):
            return ['move', rg.toward(self.location, rg.CENTER_POINT)]
        
        for poz, robot in game.robots.iteritems():
            if robot.player_id != self.player_id:
                #~if rg.dist(poz, self.location) <= 1:
                lista_wrogow.append(poz)
                    #return ['attack', poz]
                    
        if len(wrogowie_obok) > 2 and self.hp <= 30:
            return ['suicide']
        elif len(wrogowie_obok):
            return ['attack', wrogowie_obok[0]]
        
        return ['guard']
        
        #return ['move', rg.toward(self.location, rg.CENTER_POINT)]
        
        
