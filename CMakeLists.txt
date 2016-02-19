CMAKE_MINIMUM_REQUIRED(VERSION 2.6 FATAL_ERROR)
CMAKE_POLICY(VERSION 2.6)

FIND_PACKAGE(Torch REQUIRED)

# Specify your C code
SET(src src.c)
# Specify your lua code
SET(luasrc init.lua src.lua)

# Create the "clua" module containing your table returned by "init.lua"
# Create also the "libclua" module containing you C functions
ADD_TORCH_PACKAGE(clua "${src}" "${luasrc}")

# Link with the appropriate libraries for the C code
# TH because we use Tensors in our code
TARGET_LINK_LIBRARIES(clua TH)
# The lua version we use if we need to use a custom one
IF(LUALIB)
  TARGET_LINK_LIBRARIES(sys ${LUALIB})
ENDIF()