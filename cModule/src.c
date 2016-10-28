// Lua includes
#include <lua.h>
#include <lauxlib.h>

// For the Tensor functions
#include <TH.h>
#include <luaT.h>

/////////////////////////////////////////////////////////////
// Our function

// Multiply the DoubleTensor in the second argument with the scalar
// in the third argument and store the result in the first argument.
static int cScale(lua_State *L) {
  // The first argument is a DoubleTensor
  THDoubleTensor* output = luaT_toudata(L, 1, "torch.DoubleTensor");
  if(!output) {
    luaL_error(L, "cScale takes a DoubleTensor as first argument.");
  }
  // The second argument is a DoubleTensor
  THDoubleTensor* input = luaT_toudata(L, 2, "torch.DoubleTensor");
  if(!input) {
    luaL_error(L, "cScale takes a DoubleTensor as second argument.");
  }
  // The third argument is a number
  double scale = lua_tonumber(L, 3);

  // Regular C code
  // Here we can use the TH library to work with Tensors
  THDoubleTensor_resizeAs(output, input);
  THDoubleTensor_zero(output);
  THDoubleTensor_mul(output, input, scale);

  // This function return nothing since we changed the output inplace
  return 0; 
}

/////////////////////////////////////////////////////////////
// Lua package setup

// Create a table containing all the C function you want to expose
// Each entry contains the name as used on the lua side and the corresponding C function.
static const struct luaL_Reg routines [] = {
  {"cScale", cScale},
  {NULL, NULL}
};

// This function should be called "luaopen_libfoo" for a module called "foo", here "clua"
int luaopen_libclua(lua_State *L)
{
  // Create a new table
  lua_newtable(L);
  // Add your functions as elements of the table
  luaL_register(L, NULL, routines);

  // This function returns one element (the table containing the functions)
  return 1;
}