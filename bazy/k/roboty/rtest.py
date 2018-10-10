#! /usr/bin/env python
# -*- coding: utf-8 -*-

import rg


class Robot:

    def act(self, game):
        dystans = rg.dist(self.location, rg.CENTER_POINT)
        
        #print dystans
        
        if dystans >= 7:
            return ['move', rg.toward(self.location, rg.CENTER_POINT)]

        # idź do środka planszy, ruch domyślny
        #return ['move', rg.toward(self.location, rg.CENTER_POINT)]
        return ['guard']
