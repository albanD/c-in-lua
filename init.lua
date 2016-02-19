local clua = {} -- This module


-- Add the lua wrapper around the C functions to the main module
local lua_functions = require 'clua.src'
for k,v in pairs(lua_functions) do
    clua[k] = v
end

-- Optionnaly you can add the C functions to the main module
clua.c = require "libclua"

return clua
