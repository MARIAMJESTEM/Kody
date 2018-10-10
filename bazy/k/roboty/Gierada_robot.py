#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#				****WIP****
#
#dostępne działania:
#   -znajdowanie najbezpieczniejszego miejsca (zainteplementowany częściowo)
#	błędy:
#		*od drugiego wywołania safeSpace jest obliczanie podwójnie 
#		*nie uwzględnia nowych wrogów
#
#   -poruszanie się do najbezpieczniejszego miejsca

import rg

R_MAX_SEARCH = 6
R_MAX_FROM_CENTER = 5
MIN = {'x': 0, 'y': 0}
MAX = {'x': 19, 'y': 19}

shared = {
    'waitingRobots': {},
    'enemyList': [],
    'genPlaces': [],
    'commands': {},
    'safeSpace': (),
    'theSameTurn': False,
    'turn': 0
}

class Robot:
    def act(self, game):
	def robotIsntWaiting():
	    del shared['waitingRobots'][self.robot_id]
		
	def checkTurn():
	    if game.turn != shared['turn']:
		shared['turn'] = game.turn
		shared['theSameTurn'] = False
		shared['enemyList'] = []
	    else:
		shared['theSameTurn'] = True
		    
	
	def getEnemies():
	    for location, robot in game.robots.iteritems():
		if self.player_id != robot.player_id:
			shared['enemyList'].append(robot.location)
				
	def getFriends():
	    for location, robot in game.robots.iteritems():
		if self.player_id == robot.player_id:
			shared['waitingRobots'][self.robot_id] = robot.location

	def genPlacesToCheck():
	    listToCheck = []
	    for x in range(MIN['x'], MAX['x'] + 1):
		for y in range(MIN['y'], MAX['y'] + 1):
		    if rg.dist((x, y), rg.CENTER_POINT) <= R_MAX_FROM_CENTER and ((x, y) not in shared['enemyList']) and rg.locs_around((x, y), filter_out = ('invalid', 'obstacle', 'spawn')):
			listToCheck.append((x, y))
								
	    shared['genPlaces'] = listToCheck
				
	def rmEnemyLoc():
	    toCheck = shared['genPlaces']
	    
	    for enemy in shared['enemyList']:
		if enemy in toCheck:
		    toCheck.remove(enemy)
	    return toCheck
				
	def checkPos():
		r = 0
		searched = []
		newReqiured = False
		#print(shared['enemyList'])
		for pos in rmEnemyLoc():
		    #print(1)
		    if len(shared['enemyList']) > 0:
			#print(2)
			for posEnemy in shared['enemyList']:
			    #print(3)
			    for r_searched in range(1, R_MAX_SEARCH + 1):
				#print(4)
				if rg.dist(pos, posEnemy) <= r_searched:
				    #print(5)
				    if r_searched - 1 >= 0:
					searched.append({'loc': pos, 'r': r_searched - 1})
					#print(6)
				    break
		    else:
			searched.append({'loc': pos, 'r': R_MAX_SEARCH})
				
		for pos in searched:
		    if pos['r'] > r:
			    r = pos['r']
						
		for pos in searched:
		    if pos['r'] < r:
			searched = [x for x in searched if x['r'] >= r]
				
		safePosDist = rg.dist(self.location, searched[0]['loc'])
		safePos = searched[0]['loc']
		
		if len(shared['safeSpace']):
		    for pos in searched:
			if shared['safeSpace'] == pos['loc']:
			    print('#' + str(shared['safeSpace']))
			    return 0
		
		for pos in searched:
		    if safePosDist > rg.dist(self.location, pos['loc']):
			safePosDist = rg.dist(self.location, pos['loc'])
			safePos = pos['loc']
		
		#print(safePos)
		print(safePos)
		shared['safeSpace'] = safePos
	
	checkTurn()

	if len(shared['enemyList']) == 0:
	    getEnemies()
	    
	if len(shared['waitingRobots']) == 0:
	    getFriends()

	if (shared['turn']%5 == 0 and shared['theSameTurn'] is False) or game.turn == 1:
	    checkPos()
		
	if game.turn == 1:
	    genPlacesToCheck()
		
	robotIsntWaiting()
	
	if self.location != shared['safeSpace']:
	    return ['move', rg.toward(self.location, shared['safeSpace'])]
	return ['guard']
