#ifndef CSCALE_H
#define CSCALE_H

// Include all the libraries
#include "lua.h"
#include <lauxlib.h>
#include "TH.h"
#include "luaT.h"

// Define some useful macro for naming
// Transforms "torch_Tensor_(foo)" in "torch_RealTensor_foo"
// Note that the transformed element is a symbol and is usually a function name
#define torch_Tensor_(NAME) TH_CONCAT_4(torch_,Real,Tensor_,NAME)
// Transforms "torch_Tensor" in ""torch_RealTensor""
// Note that the transformed element is a string
#define torch_Tensor TH_CONCAT_STRING_3(torch.,Real,Tensor)

// "THGenerateFloatTypes.h" is provided by the TH library
// It requires the TH_GENERIC_FILE variable to be set
// and it will generate this file with different types.
// Here float types are FloatTensor and DoubleTensor
#define TH_GENERIC_FILE "generic/cScale.h"
#include "THGenerateFloatTypes.h"

#endif