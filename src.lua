local clua_c = require "libclua" -- The c functions

local lua_functions = {} -- My local functions


function lua_functions.increment(a)
    b = clua_c.increment(a)
    return b
end

return lua_functions
