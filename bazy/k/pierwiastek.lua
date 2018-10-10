function main()
  local x, d
  --repeat
  x = tonumber(io.read())
  d = tonumber(io.read())
  --until (x > 0 and d > 0)
  
  local a = x
  
  while (a - x/a > d) do
      a = (a + x/a)/2
  end
  
  print(a)
end

main()