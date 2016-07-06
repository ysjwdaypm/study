


md = {__add = function(a,b)
	return a.i + b.i;
end,
__sub = function ( a,b )
	-- body
	return a.i - b.i
end,

__len = function()
	return 12
end,
__call = function (func,args)
	print(func,args)
end
}

function create( v )
	local ret = {i=v}
	setmetatable(ret,md)
	return ret
end

a = create(23)

b = create(34)
print(b.i)

print(a+b)
print(a-b)

print(select('#',a))
