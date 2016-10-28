local clua = require 'clua.clua'

local torch = require "torch"

-- Add the c functions to the package
clua.c = require 'libclua'

torch.include("clua", "MyModule.lua")

return clua
