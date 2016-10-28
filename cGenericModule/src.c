#include <lua.h>
#include <lauxlib.h>

#include "cScale.h"

// This function should be called "luaopen_libmodule" for a module called "module", here "clua"
int luaopen_libclua(lua_State *L)
{
  // Create a new table
  lua_newtable(L);
  // Call the init for cScale functions
  torch_FloatTensor_cScale_init(L);
  torch_DoubleTensor_cScale_init(L);

  // This function returns one element (the table containing the functions)
  return 1;
}