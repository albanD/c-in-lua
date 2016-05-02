## cModule

This module presents how to create a Torch module with the core implemented in C for all Torch types.
Note that using this module, the test will work properly with both FloatTensor and DoubleTensor because the macro will create the implementation for both types.

## How to read

This is an extension of the [cModule](../cModule) and most files are unchanged. For clarity, the comments on unchanged part of the code have been removed.

What changed:
* [`MyModule.lua`](MyModule.lua) This is the only change on the lua side: we now use either a `cScale_float` or `cScale_double` function depending on the input we are presented with.
* [`src.c`](src.c) This now only contains the package creation part and call two init functions.
* [`cScale.h`](cScale.h) This starts as a regular header where we include all required library and ends with some macro magic. You may want to take a look at [this](https://apaszke.github.io/torch-internals.html) blogpost by @apaszke that describes in details how the macro magic works.
* [`generic/cScale.h`](generic/cScale.h) This is the file included by the macro. It will be expanded to generate both init functions used in `src.c`.
* [`cScale.c`](cScale.c) As you would expect, the C file is just expanding the generic version with macro.
* [`generic/cScale.c`](generic/cScale.c) This file contains the main implementations of both the generic `cScale` functions and init functions.