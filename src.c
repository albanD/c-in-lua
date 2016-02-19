#include <lua.h>
#include <lauxlib.h>

// For the Tensor functions
#include <TH.h>

// Increment a number by one
static int increment(lua_State *L) {
  // The first argument is a number
  int arg1 = lua_tonumber(L, 1);

  // Regular C code
  arg1++;

  // Push the result to the stack
  lua_pushnumber(L, arg1);
  // Return the number of returned value
  return 1; 
}

// Change all values of a 1D FloatTensor to their exponential
static int expFloat(lua_State *L) {
  // The first argument is a FloatTensor
  THFloatTensor *tensor = luaT_checkudata(L, 1, "torch.FloatTensor");

  // Apply the exp function inplace
  THFloatTensor_exp(tensor, tensor);

  // This function returns nothing
  return 0;
}

// Create a table containing all the C function you want to expose
// Each entry contains the name as used on the lua side and the corresponding C function.
static const struct luaL_Reg routines [] = {
  {"increment", increment},
  {"expFloat", expFloat},
  {NULL, NULL}
};

// This function should be called "luaopen_libmodule" for a module called "module", here "clua"
int luaopen_libclua(lua_State *L)
{
  // Create a new table
  lua_newtable(L);
  // Add your functions as elements of the table
  luaL_register(L, NULL, routines);

  // This function returns one element (the table containing the functions)
  return 1;
}