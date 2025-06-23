local path = debug.getinfo(2).source:match[[^@?(.*[\\/])]] -- 获取当前文件所在目录
package.path = package.path .. ';' .. path .. '?.lua'  -- 添加到 Lua 模块搜索路径
require('hello') -- 这样就可以正确加载 hello.lua