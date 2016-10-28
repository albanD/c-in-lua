CMAKE_MINIMUM_REQUIRED(VERSION 2.6 FATAL_ERROR)
CMAKE_POLICY(VERSION 2.6)

# Find torch, this will load the ADD_TORCH_PACKAGE function
FIND_PACKAGE(Torch REQUIRED)

# Specify your lua code (all lua files here)
file(GLOB lua_files *.lua)
SET(luasrc "${lua_files}")

# Create the "clua" package
# "require 'clua'" will correspond to the "init.lua" file
# "require 'clua.foo'" will correspond to the "foo.lua" file
ADD_TORCH_PACKAGE(clua "" "${luasrc}")
