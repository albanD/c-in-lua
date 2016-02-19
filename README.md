## c in lua

This repo presents a simple example on how to embed c code in lua/[torch](https://github.com/torch/torch7).

The goal is to present the most basic steps needed if you want to use some C functions in lua code.

You will find:
* `clua-scm-1.rockspec` a regular rockspec that defines a module. It will be build with a custom cmake command.
* `CMakeLists.txt` the cmake script used to build this module.
* `init.lua` the file called when you do `require "clua"` it returns a table containing all the functions of the `clua` module.
* `src.lua` more lua source code (that can use the C code directly). This will be accessible after installation with `require "clua.src"`.
* `src.c` the C file containing your C functions.