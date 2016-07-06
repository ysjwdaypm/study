function allwords (f)
      -- repeat for each line in the file
      for l in io.lines() do
        -- repeat for each word in the line
        local pos = 1
        if l == "exit" then
        	return
        end
        
        local s, e = string.find(l, "%w+", pos)
        while s do
        	f(string.sub(l,s,e))
        	-- print('----------------'..s..'  '..e)
        	pos = e + 1
        	s, e = string.find(l, "%w+", pos)
        end
        
      end
    end
