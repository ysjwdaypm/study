
 // #include "stdafx.h"

extern "C"

{

                #include "lua.h"

                #include "lauxlib.h"

                #include "lualib.h"

};

static int c_plus(lua_State *L)

{

                //Open all standard libraries for current lua_State

                luaL_openlibs(L);

                int p1 = luaL_checknumber(L,1);

                int p2 = luaL_checknumber(L,2);

                //pop two parameters from stack

                lua_pop(L,2);

                int r;

                r = p1 + p2;

                cout<<p1<<" + "<<p2<<" = "<<r<<endl;

                lua_pushnumber(L,r);

                return 1;

}

int main()

{

                lua_State *L = luaL_newstate();

                lua_pushcfunction(L,c_plus);

                lua_setglobal(L,"myPlus");

               

                if( luaL_loadfile(L,"t.lua") || lua_pcall(L,0,0,0) )

                {

                                cout<<"luaL_dofile() exception:"<<lua_tostring(L, -1)<<endl;

                }

                lua_close(L);

                int i;

                cin>>i;

                return 0;

}