CMAKE_MINIMUM_REQUIRED(VERSION 2.6 FATAL_ERROR)
CMAKE_POLICY(VERSION 2.6)

FIND_PACKAGE(Torch REQUIRED)

# Specify your C code
file(GLOB c_files *.c)
SET(src "${c_files}")
# Specify your lua code (all lua files here)
file(GLOB lua_files *.lua)
SET(luasrc "${lua_files}")

# Create the "clua" module containing your table returned by "init.lua"
# Create also the "libclua" module containing you C functions
ADD_TORCH_PACKAGE(clua "${src}" "${luasrc}")

# Link with the appropriate libraries for the C code
# TH because we use Tensors in our code
TARGET_LINK_LIBRARIES(clua TH)
