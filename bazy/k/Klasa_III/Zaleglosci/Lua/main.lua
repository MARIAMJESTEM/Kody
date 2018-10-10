tree = require 'tree'
require 'math'

function main()
  math.randomseed(os.time())
  t = tree.new()
  
  for i = 1, 25 do
    t:add(math.random(1, 100))
  end
  
  t:printT()
  t:deleteTree()
end

main()