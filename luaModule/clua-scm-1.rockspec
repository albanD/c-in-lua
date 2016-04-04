package = "clua"
version = "scm-1"

source = {
   url = "git://github.com/albanD/c-in-lua"
}

description = {
   summary = "A simple example on how to embed in lua for Torch",
   detailed = [[
   ]],
   homepage = "https://github.com/albanD/c-in-lua",
   license = "BSD"
}

dependencies = {
   "torch >= 7.0",
}

build = {
   type = "command",
   build_command = [[cmake -E make_directory build && cd build && cmake .. -DLUALIB=$(LUALIB) -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH="$(LUA_BINDIR)/.." -DCMAKE_INSTALL_PREFIX="$(PREFIX)" && $(MAKE)]],
   install_command = "cd build && $(MAKE) install"
}