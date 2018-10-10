function printf(...) return print(string.format(...)) end

function parzyste(n) 
    i = 0
    for i, n, 2 do print(i) end
    return i/2
end


ROK = 2017
ROK_LUA = 1993

print("Witaj!")
imie = io.read("Podaj swoje imie: ")

printf('Witaj %s', imie)

wiek = io.read("Ile masz lat?")

rok_urodzenia = ROK - wiek

printf('Urodziłeś się w %d', rok_urodzenia)

if rok_urodzenia > ROK_LUA then         print('Jestem starszy.') end
elseif  rok_urodzenia < ROK_LUA then    print('Jestem młodszy.') end
else                                    print('Jesteśmy rówieśnikami!') end

n = io.read('Podaj zakres wyświetlanych liczb parzystych: ')

parzyste(n)
