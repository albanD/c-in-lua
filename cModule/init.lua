-- The package table
local clua = require 'clua.clua'

-- For the class system
local torch = require "torch"

-- Add the c functions to the package
clua.c = require 'libclua'

-- Add our module to our package
torch.include("clua", "MyModule.lua")

return clua
