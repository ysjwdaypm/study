

local count = 0;

function han( n,a,b,c )
	if n == 1 then
		print("move "..a.." to "..c)
		count = count + 1;
	else
		han(n-1,a,c,b)
		print("move "..a.." to "..c)
		count = count + 1
		han(n-1,b,a,c)
	end	
	-- body
end

han(10,'A','B','C')
print("count = "..count)