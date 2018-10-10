local suit = require 'suit'

local tryb = 'input' --'input' 'wykres' 'reset'
local wygenerowanoRuchy = false
local osie = {}
local podzialka = {}
local numPodzialka = {oX = {}, oY = {}}

local punkty = {}

local numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}

local winWidth, winHeight
local font = love.graphics.newFont('arial.ttf', 12)
local srodek

local ileRuchow = {text = ''}
local krok = {text = ''}

function ruchyBrowna()
    math.randomseed(os.time())
    local x, y = 0, 0
    wygenerowanoRuchy = true
    table.insert(punkty, {x = x, y = y})
    
    for i = 0, ileRuchow do
      local kat = math.rad(math.random(0, 360))
      x = round(x + math.cos(kat) * krok * 10, 2)
      y = round(y + math.sin(kat) * krok * 10, 2)
      print(('Punkt: %d'):format(i), x, y)
      --table.insert(punkty, {x = x + srodek.x, y = y + srodek.y})
      table.insert(punkty, {x = x, y = y})
    end
    s = math.sqrt(x^2 + y^2)
    
    print(('Wektor przesunięcia wynosi %.2f'):format(s))
end

function round(liczba, miejscaPoPrzecinku)
  local zakres = '%.' .. miejscaPoPrzecinku .. 'f'
  return tonumber(zakres:format(liczba))
end

function inside(table, value)
  for k, v in pairs(table) do
    if v == value then
      return true
    end
  end
  return false
end

function love.textedited(text, start, length)
    -- for IME input
    suit.textedited(text, start, length)
end

function love.textinput(t)
	-- forward text input to SUIT
  if inside(numbers, t) then
    suit.textinput(t)
  end
end

function love.keypressed(key)
	-- forward keypresses to SUIT
  if tryb == 'wykres' and key == 'r' or key == 'R' then
    tryb = 'reset'
  end
  suit.keypressed(key)
end

function ustawOsie()
  local promienPodz = 8
  local sX, sY = winWidth/20, winHeight/20
  
  osie.oX = {x0 = 0, y0 = math.floor(winHeight/2), x1 = winWidth, y1 = math.floor(winHeight/2)}
  osie.oY = {x0 = math.floor(winWidth/2), y0 = 0, x1 = math.floor(winWidth/2), y1 = winHeight}
  
  for i = sX, winWidth - sX, sX do
    table.insert(podzialka, {x0 = i, y0 = osie.oX.y0 - promienPodz, x1 = i, y1 = osie.oX.y0 + promienPodz})
    if i ~= winWidth/2 then
      table.insert(numPodzialka.oX, {text = love.graphics.newText(font, i - winWidth/2), x = i, y = osie.oX.y0 + 1.4 * promienPodz})
    end
  end
  
  for i = sY, winHeight - sY, sY do
    table.insert(podzialka, {x0 = osie.oY.x0 - promienPodz, y0 = i, x1 = osie.oY.x0 + promienPodz, y1 = i})
    if i ~= winHeight/2 then
      table.insert(numPodzialka.oY, {text = love.graphics.newText(font, -(i - winHeight/2)), x = osie.oY.x0 - 1.4 * promienPodz, y = i})
    end
  end
  
  promienPodz, sX, sY = nil, nil, nil
end

function rysujOsie()
  love.graphics.setColor(0, 0, 0, 255)
  for k, v in pairs(osie) do
    love.graphics.line(v.x0, v.y0, v.x1, v.y1)
  end
  for k, v in pairs(podzialka) do
    love.graphics.line(v.x0, v.y0, v.x1, v.y1)
  end
  for k, v in pairs(numPodzialka.oX) do
    love.graphics.draw(v.text, v.x - v.text:getWidth()/2, v.y)
  end
  for k, v in pairs(numPodzialka.oY) do
    love.graphics.draw(v.text, v.x - v.text:getWidth(), v.y - v.text:getHeight()/2)
  end
end

function rysujWykres()
  love.graphics.setPointSize(5)
  love.graphics.setColor(205, 0, 133)
  
  if #punkty > 0 then
    --love.graphics.line(punkty)
    for k = 1, #punkty - 1 do
      love.graphics.line(punkty[k].x + srodek.x, punkty[k].y + srodek.y, punkty[k+1].x + srodek.x, punkty[k+1].y + srodek.y)
      --love.graphics.line(punkty[k].x, punkty[k].y, punkty[k+1].x, punkty[k+1].y)
    end
  end
  
  love.graphics.setColor(41, 0, 133)
  if #punkty > 0 then
  for k = 1, #punkty do
    love.graphics.points(punkty[k].x + srodek.x, punkty[k].y + srodek.y)
  end end

  --love.graphics.points(punkty)
end

function love.load()
  local fontSuit = love.graphics.newFont('arial.ttf', 20)

  winWidth, winHeight = love.window.getMode()
  srodek = {x = winWidth/2, y = winHeight/2}
  
  love.graphics.setFont(fontSuit)
  
  for k, v in pairs(suit.theme.color) do
    suit.theme.color[k].bg = v.bg
    suit.theme.color[k].fg = {255, 255, 255}
  end
  
  ustawOsie()
  
  collectgarbage()
end

function trybInput()
  suit.layout:reset(winWidth/2 - 75, winHeight/2 - 85)
  
  suit.Label('Ile ruchów?', {align = 'center'}, suit.layout:row(150, 30))
  suit.Input(ileRuchow, {id = 'ruchy', align = 'center'}, suit.layout:row())
  suit.layout:row(150, 5)
  
  local x, y, w, h = suit.layout:row(200, 30)
  suit.Label('Krok przesunięcia?', {align = 'center'}, x - w/8, y, w, h)
  x, y, w, h = nil, nil, nil, nil
  suit.Input(krok, {id = 'krok', align = 'center'}, suit.layout:row(150, 30))
  
  suit.layout:row(150, 15)

  if suit.Button('Gotowe!', suit.layout:row(150, 30)).hit and ileRuchow.text ~= '0' and ileRuchow.text ~= '' and krok.text ~= '0' and krok.text ~= '' then
    tryb = 'wykres'
    ileRuchow = tonumber(ileRuchow.text)
    krok = tonumber(krok.text)
  else
    if ileRuchow.text == '0' or ileRuchow.text == '' then
      local x, y, w, h = suit.layout:row(390, 30)
      suit.Label('Proszę podać liczbę ruchów do wykonania!', {id = 't1', align = 'center'}, x - w/3.5,y,w,h)
    end
    if krok.text == '0' or krok.text == '' then
      local x, y, w, h = suit.layout:row(290, 30)
      suit.Label('Proszę podać wielkość kroków!', {id = 't2', align = 'center'}, x - w/5,y,w,h)
    end
  end
end

function trybReset()
  ileRuchow = {text = ''}
  krok = {text = ''}
  tryb = 'input'
  wygenerowanoRuchy = false
  punkty = {}
end

function love.update(dt)
  if tryb == 'input' then
    trybInput()
  elseif tryb == 'wykres' and not wygenerowanoRuchy then
    ruchyBrowna()
  elseif tryb == 'reset' then
    trybReset()
  end
end

function love.draw()
  if tryb == 'input' then
    love.graphics.setBackgroundColor(0,0,0)
    suit.draw()
  elseif tryb == 'wykres' then
    love.graphics.setBackgroundColor(0, 255, 133)
    rysujOsie()
    rysujWykres()
  end
end