## cModule

This module presents how to create a Torch module with the core implemented in C.
Note that using this module, the test will fail for FloatTensor since the implementation in `src.c` has been done only for DoubleTensor.

## How to read

This is an extension of the [luaModule](../luaModule) and most files are unchanged. For clarity, the comments on unchanged part of the code have been removed.

What changed:
* [`MyModule.lua`](MyModule.lua) In the `updateOutput` function, we now only call a function in `clua.c` called `cScale`
* [`init.lua`](init.lua) We see here that `clua.c` is actually the content of the `libclua` package.
* [`CMakeLists.txt`](CMakeLists.txt) We see that we now have our `src.c` source file added to the package. This will induce the creation of both the `clua` and `libclua` packages.
* [`src.c`](src.c) The C code contains two main parts: the plain C function that will be called from lua and the `libclua` package setup.
