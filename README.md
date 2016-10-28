## c in lua

This repo presents a simple example on how to embed c code in lua/[torch](https://github.com/torch/torch7).

To do so we will present how to create a new Torch layer that will just multiply the input by a constant. This repository contains 3 different implementation:
* [`luaModule`](luaModule/) shows how to create the module with only lua code.
* [`cModule`](cModule/) shows how to create the module with some functions implemented in C. Here C functions are implemented for a fixed tensor type.
* [`cGenericModule`](cGenericModule/) shows how to create the module with some functions implemented in C. Here we use the macro tricks fom `TH` to generate the functions for all needed types (Float and Double).


It also contains [`test.lua`](test.lua) that is a simple example that will load the custom module and try to use it with both FloatTensor and DoubleTensor and verify that the outputs are correct.