tree = {}

function tree:deleteTree()
  self = nil
end

function tree:newNode(value)
  return {add = self.add, newNode = self.newNode, printT = self.printT, value = value}
end

function tree:printT()
  if self.value then
    if self.left then self.left:printT() end
    
    print(self.value)
    
    if self.right then self.right:printT() end
  end
end

function tree:add(value)
  if self.value then
    if value <= self.value then
      if self.left then
        self.left:add(value)
      else
        self.left = self:newNode(value)
      end
    else
      if self.right then
        self.right:add(value)
      else
        self.right = self:newNode(value)
      end
    end
  else
    self.value = value
  end
end

function tree.new(value)
  p = {}
  for k, v in pairs(tree) do
    if k ~= 'new' then
      p[k] = v
    end
  end
  
  if value then
    p:add(value)
  end
  
  return p
end

return tree