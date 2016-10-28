CMAKE_MINIMUM_REQUIRED(VERSION 2.6 FATAL_ERROR)
CMAKE_POLICY(VERSION 2.6)

FIND_PACKAGE(Torch REQUIRED)

# Specify your C code (all c files here)
file(GLOB c_files *.c)
SET(src "${c_files}")

file(GLOB lua_files *.lua)
SET(luasrc "${lua_files}")

# Create the "clua" package
# "require 'libclua'" will call the "luaopen_libclua" function in the c library
ADD_TORCH_PACKAGE(clua "${src}" "${luasrc}")
