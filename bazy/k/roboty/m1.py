#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#dostępne działanie:
#   -znajdowanie najbezpieczniejszego miejsca (zainteplementowany częściowo)

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
	'safeSpaceGenerated': False,
	'turn': 1
}

class Robot:
	def act(self, game):	
			
		def robotIsntWaiting():
			del shared['waitingRobots'][self.robot_id]
			
		def checkTurn():
			if game.turn != shared['turn']:
				shared['turn'] = game.turn
                shared['enemyList'] = []
		
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
					
		def rmELocFromPlaces():
			toCheck = shared['genPlaces']
			
			for enemy in shared['enemyList']:
				if enemy in toCheck:
					toCheck.remove(enemy)
			return toCheck
					
		def checkPos():
			r = 0
			searched = []
			print(shared['enemyList'])
			for pos in rmELocFromPlaces():
				if len(shared['enemyList']) > 0:
					for posEnemy in shared['enemyList']:
						for r_searched in range(1, R_MAX_SEARCH + 1):
							if rg.dist(pos, posEnemy) <= r_searched:
								if r_searched - 1 >= 0:
									searched.append({'loc': pos, 'r': r_searched - 1})
								break
				else:
					searched.append({'loc': pos, 'r': R_MAX_SEARCH})
					
			for pos in searched:
				if pos['r'] > r:
					r = pos['r']
							
			for pos in searched:
				if pos['r'] < r:
					searched = [x for x in searched if x['r'] >= r]
					
			savePosDist = rg.dist(self.location, searched[0]['loc'])
			savePos = searched[0]['loc']
			
			for pos in searched:
				if savePosDist > rg.dist(self.location, pos['loc']):
					savePosDist = rg.dist(self.location, pos['loc'])
					savePos = pos['loc']
			
			#print(savePos)
			shared['safeSpace'] = savePos
			
		checkTurn()
        if len(shared['enemyList']) == 0:
            getEnemies()
        
        if shared['safeSpaceGenerated'] and game.turn%5 == 0:
			shared['safeSpaceGenerated'] = False
		
		if game.turn == 1:
			genPlacesToCheck()

		if len(shared['waitingRobots']) == 0:
			getFriends()
		
		if not shared['safeSpaceGenerated']:
			checkPos()
			shared['safeSpaceGenerated'] = True
		
		robotIsntWaiting()
		
		if self.location != shared['safeSpace']:
			return ['move', rg.toward(self.location, shared['safeSpace'])]
		return ['guard'] 
