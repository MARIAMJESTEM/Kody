#!/usr/bin/env python
# -*- coding: utf-8 -*-

print "Uruchamianie... poczekaj"

import mcpi.minecraft as minecraft
import mcpi.block as block
import os

os.environ["USERNAME"] = "Steve"
os.environ["COMPUTERNAME"] = "mykomp"
mc = minecraft.Minecraft.create("192.168.3.37")

def jakiBlok():
    x, y, z = mc.player.getPos()
    return mc.getBlock(x, y - 1, z)

pos = mc.player.getPos()

#print(jakiBlok())

kamien = block.STONE
powietrze = block.AIR

#mc.setBlocks(-10, 50, -10, 10, 0, 10, powietrze)
#mc.setBlocks(-10, -1, -10, 10, -1, 10, kamien)
#mc.player.setPos(0, 20, 0)

i = 0
for k in range(0, 10, 1):
    mc.setBlocks(60 - k, 60 - i, 60 - k, 60 + k, 60 - i, 60 + k, 25 + i)
    i += 1

mc.player.setPos(60, 200, 60)
