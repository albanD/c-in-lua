
// This file will be include with 
static int torch_Tensor_(cScale)(lua_State *L) {
  // The first argument is a THTensor
  THTensor* output = luaT_toudata(L, 1, torch_Tensor);
  if(!output) {
    luaL_error(L, "cScale takes a "torch_Tensor" as first argument.");
  }
  // The second argument is a THTensor
  THTensor* input = luaT_toudata(L, 2, torch_Tensor);
  if(!input) {
    luaL_error(L, "cScale takes a "torch_Tensor" as second argument.");
  }
  // The third argument is a number
  double scale = lua_tonumber(L, 3);

  // Regular C code
  // Here we can use the TH library to work with Tensors
  THTensor_(resizeAs)(output, input);
  THTensor_(zero)(output);
  THTensor_(mul)(output, input, scale);

  // This function return nothing since we changed the output inplace
  return 0; 
}

// Create a table containing all the C function you want to expose
// Each entry contains the name as used on the lua side and the corresponding C function.
static const struct luaL_Reg torch_Tensor_(routines) [] = {
  {TH_CONCAT_STRING_2(cScale_, real), torch_Tensor_(cScale)},
  {NULL, NULL}
};

void torch_Tensor_(cScale_init)(lua_State *L) {
  // Assume that the `clua` table is on top of the stack
  luaL_register(L, NULL, torch_Tensor_(routines));
}
