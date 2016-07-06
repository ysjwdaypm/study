
function main(  )
	print("start")
	coroutine.yield()
	print("end")
end

co = coroutine.create(main)
coroutine.resume(co)
print("s")

-- 在这个流程的第一步的时候，resume的参数会传递给function,作为参数(具体如上)；
-- 到了第三步的时候，yield的参数会作为resume返回值的一部分；
-- 而第二次resume(第五步)的时候，resume的参数的作用发生了改变，
-- resume的参数会传递给yield,做为yield的返回值。

-- 这个过程很精巧，在coroutine执行的过程中返回，必然需要告诉外部现在coroutine这个时候的内部的的情况，
-- 通过唯一的接口yield的参数作为resume的返回值，高；
-- 到了第二次resume的时候，外部的环境必然发生了改变， 怎么通知coroutine内部呢，
-- 同样的想法，将唯一的接口resume的参数通过yield的返回的途径返回到coroutine内部，一样的高明。

function foo (a)  
    print("foo", a)  -- foo 2  
    return coroutine.yield(2 * a) -- return: a , b  
end  
   
local check = 1  
local s = 1 
co = coroutine.create(function (a , b)  
    print("co-body", a, b) -- co-body 1 10  
    local r = foo(a + 1)  
       
    print("co-body2", r)  
    check, s = coroutine.yield(a + b, a - b)  
       
    print("co-body3", check, s)  
    return b, "end"  
end)  
          
print("main", coroutine.resume(co, 1, 10)) -- true, 4  
print("------")  
print("main", coroutine.resume(co, "r")) -- true 11 -9  
print("check = ",check)
print("------")  
print("main", coroutine.resume(co, "x", "y")) -- true 10 end  
print("check = ",check)
print("------")  
print("main", coroutine.resume(co, "x", "y")) -- false cannot resume dead coroutine  
print("------")