
local tabFiles = {  
[1] = "ysj",
[3] = "test2",  
[6] = "test3",  
[4] = "test1"  
}  

for i,v in ipairs(tabFiles) do
	print(i,v)
end


-- function showInfo( ... )
-- 	-- body
-- 	for k,v in pairs({...}) do
-- 		print(k,v)
-- 	end
-- end


-- for i,v in pairs(os) do
-- 	print(i,v)
-- end


-- -- 标准库提供了集中迭代器，包括迭代文件每行的(io.lines)，迭代table元素的(pairs)，迭代数组元素的(ipairs)(从1开始遇到nil结束)，迭代字符串中单词的 

-- function inTable(t,k)
-- 	for i,v in pairs(t) do
-- 		if i == k then
-- 			return true
-- 		end
-- 	end

-- 	return false
-- end

-- local m = {c = {}}
-- m.__index = function ( t,k )
-- 	if inTable(t["data"],k) == false then
-- 		return "can't find key "..k.." in table"
-- 	end
-- 	return t["data"][k]
-- end
-- m.__newindex =  function ( t,k,v )
-- 	-- print(t,t.data)
-- 	print(k,v)
-- 	t["data"][k]  = v
-- end


-- local c = {data={}}
-- setmetatable(c,m)
-- print(c.name)
-- c.age = 12
-- print(c.age)
-- showInfo("adada","1313")


-- local a,b,c = 1,2,3
-- a,b,c = c,b,a
-- print(a,b,c)

-- f=io.open("test1.txt","ab")
-- f:write("131312")
-- f:close()





-- local fun=function ( ... )
--   local a=1;
--   print(z+1);
--   return a+1;
-- end

-- tryCatch=function(fun)
--   local ret,errMessage=pcall(fun);
--   print("ret:" .. (ret and "true" or "false" )  .. " \nerrMessage:" .. (errMessage or "null"));
-- end

-- xTryCatchGetErrorInfo=function()
--   print(debug.traceback());
-- end
-- xTryCatch=function(fun)
--   local ret,errMessage=xpcall(fun,xTryCatchGetErrorInfo);
--   print("ret:" .. (ret and "true" or "false" )  .. " \nerrMessage:" .. (errMessage or "null"));
-- end




-- function findStr( str,matchStr )
-- 	index,len = string.find(str,matchStr);
-- 	print(index,len)
-- 	return index and true or false;
-- end

-- if findStr("ysjwda","wd") then
-- 	print("find it ");
-- else
-- 	print("can't find it");
-- end

-- local a = 1

-- print(a>0 and "hao" or "huai")
-- print(a>0 and false or true)