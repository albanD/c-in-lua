## c in lua

This repo presents a simple example on how to embed c code in lua/[torch](https://github.com/torch/torch7).

It contain several exemples on how to create simple modules for torch.
* [`test.lua`](test.lua) is a simple example that will load the custom module and try to use it with both FloatTensor and DoubleTensor.
* [`luaModule`](luaModule/) shows how to create a simple module with only lua code.
* [`cModule`](cModule/) shows how to create a simple module with some functions implemented in C. Here each function is created for a single Tensor type.
* [`cGenericModule`](cGenericModule/) shows how to create a simple module with some functions implemented in C. Here we use the macro tricks fom `TH` to generate the functions for all needed types (Float and Double).

