/////////////////////////////////////////////////////////////
// Our function

// Here we allways use the macro version to refer to tensors
// such that the expansion of this function will give two valid
// functions, one for FloatTensor and one for DoubleTensor
static int torch_Tensor_(cScale)(lua_State *L) {
  // THTensor is expanded to THFloatTensor and THDoubleTensor
  // torch_Tensor is expanded to torch.FloatTensor and torch.DoubleTensor
  THTensor* output = luaT_toudata(L, 1, torch_Tensor);
  if(!output) {
    luaL_error(L, "cScale takes a "torch_Tensor" as first argument.");
  }
  THTensor* input = luaT_toudata(L, 2, torch_Tensor);
  if(!input) {
    luaL_error(L, "cScale takes a "torch_Tensor" as second argument.");
  }
  double scale = lua_tonumber(L, 3);

  // Regular C code
  // THTensor_(resizeAs) is expanded to THFloatTensor_resizeAs and THDoubleTensor_resizeAs
  THTensor_(resizeAs)(output, input);
  THTensor_(zero)(output);
  THTensor_(mul)(output, input, scale);

  return 0; 
}

/////////////////////////////////////////////////////////////
// Lua package setup

// Here we want the functions added to the module to be different
// so we use TH_CONCAT_STRING_2(cScale_, real) that will be expanded to
// cScale_float and cScale_double (which are the functions used in MyModule.lua)
static const struct luaL_Reg torch_Tensor_(routines) [] = {
  {TH_CONCAT_STRING_2(cScale_, real), torch_Tensor_(cScale)},
  {NULL, NULL}
};

void torch_Tensor_(cScale_init)(lua_State *L) {
  // Here we assume that this function will be called by the "luaopen_libclua"
  // function and so that the package table will be on top of the stack.
  luaL_register(L, NULL, torch_Tensor_(routines));
}
