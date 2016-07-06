
function openDialog( ... )
	-- body
end

function NPCDialog(msg)
	print(msg,"sure or cancel")
	local ret =coroutine.yield()
	return ret
	-- body
end

function main()
	if NPCDialog("exit game!") == "OK" then
		print("exit game")
	else
		print("continue")	
	end
end


co = coroutine.create(main)
coroutine.resume(co)
-- t = io.read()
-- print("t = "..t)
-- coroutine.resume(co,t)
local cnt = 1000
print("start time = "..os.time())
while (cnt > 1) do
	cnt = cnt - 1
	print(cnt)
end
print("end time = "..os.time())
coroutine.resume(co,"OK")	
print("---------------------")
os.getenv("PATH")

