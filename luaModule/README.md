## luaModule

This module presents how to create a Torch module.

## How to read

You should read each files in the following order:
* [`MyModule.lua`](MyModule.lua) Contains the creation and implementation of the module. We implement only the requested methods and keep the default ones from `nn.Module` for the others.
* [`clua.lua`](clua.lua) This is the module that we get when doing `require 'clua.clua'`. This allows us to add our custom module in a local table and allows us not to use any global.
* [`init.lua`](init.lua) This is the module that we get when doing `require 'clua'`. We use this as an initialization, this is where we actually load our custom module.
* [`clua-scm-1.rockspec`](clua-scm-1.rockspec) This is the `luarocks` specification describing the module. We describe the module, its dependencies and explain how to build it. Here we will build using cmake.
* [`CMakeLists.txt`](CMakeLists.txt) This is the script used to build the module