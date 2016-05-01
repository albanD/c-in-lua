#ifndef CSCALE_H
#define CSCALE_H

#include "lua.h"
#include <lauxlib.h>
#include "TH.h"
#include "luaT.h"

#define torch_Tensor_(NAME) TH_CONCAT_4(torch_,Real,Tensor_,NAME)
#define torch_Tensor TH_CONCAT_STRING_3(torch.,Real,Tensor)
#define str(s) #s

#define TH_GENERIC_FILE "generic/cScale.h"
#include "THGenerateFloatTypes.h"

#endif