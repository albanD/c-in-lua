CMAKE_MINIMUM_REQUIRED(VERSION 2.6 FATAL_ERROR)
CMAKE_POLICY(VERSION 2.6)

FIND_PACKAGE(Torch REQUIRED)

# Specify your lua code (all lua files here)
file(GLOB lua_files *.lua)
SET(luasrc "${lua_files}")

# Create the "clua" module containing your table returned by "init.lua"
ADD_TORCH_PACKAGE(clua "" "${luasrc}")
