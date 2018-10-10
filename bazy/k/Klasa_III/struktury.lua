function read(...)
    io.write(...)
    return io.read()
end

function osoba(i, n, w)
    return {['imie'] = i, ['nazwisko'] = n, ['wiek'] = w}
end
    
function pobierzDane(lista, ile)
    for i = 0, ile do
        im = read('Imie: ')
        n = read('Nazwisko: ')
        w = read('Wiek: ')
        table.insert(lista, osoba(im, n, w))
    end
    return lista
end

function wyswietlDane(lista)
    for k, v in pairs(lista) do
        print(k, v)
    end
end
    
function zapiszDane(lista)
    file = io.open('bazaLua.txt', 'w')
    for k, v in pairs(lista) do
        file:write(string.format('%s,%s,%s;', v.imie, v.nazwisko, v.wiek))
    end
    file.close()
end

function czytajDane(name)
    file = io.open(name, 'r')
    local p = {}
    for i in file:lines() do
        p = osoba(string.match(i, '(%s+),(%s+),(%s+);'))
    end
    file.close()
    return p
end
    
function main()
    local ile = tonumber(read('Ile osob chcesz wprowadzic? '))
    local lista = {}
    lista = pobierzDane(lista, ile)
    wyswietlDane(lista)
    zapiszDane(lista)
end

main()
