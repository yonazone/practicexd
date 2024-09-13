vim.g.base46_cache = vim.fn.stdpath "data" .. "/nvchad/base46/"
 2 vim.g.mapleader = " "
 3
 4 -- bootstrap lazy and all plugins
 5 local lazypath = vim.fn.stdpath "data" .. "/lazy/lazy.nvim"
 6
 7 if not vim.uv.fs_stat(lazypath) then
 8   local repo = "https://github.com/folke/lazy.nvim.git"
 9   vim.fn.system { "git", "clone", "--filter=blob:none", repo, "--branch=stable", lazypath }
10 end
11
12 vim.opt.rtp:prepend(lazypath)
13
14 local lazy_config = require "configs.lazy"
15
16 -- load plugins
17 require("lazy").setup({
18   {
19     "NvChad/NvChad",
20     lazy = false,
21     branch = "v2.5",
22     import = "nvchad.plugins",
23   },
24
25   { import = "plugins" },
26 }, lazy_config)
27
28 -- load theme
29 dofile(vim.g.base46_cache .. "defaults")
30 dofile(vim.g.base46_cache .. "statusline")
31
32 require "options"
33 require "nvchad.autocmds"
34
35 vim.schedule(function()
36   require "mappings"
37 end)
38
39 -- init.lua
40
41 vim.cmd [[
42   highlight @punctuation.bracket guifg=white
43   highlight @punctuation.delimiter guifg=white
44 ]]
