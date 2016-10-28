
// Since this is included with "THGenerateFloatTypes.h" this line
// will be expended to both:
// void torch_FloatTensor_cScale_init(lua_State *L);
// void torch_DoubleTensor_cScale_init(lua_State *L);
void torch_Tensor_(cScale_init)(lua_State *L);
