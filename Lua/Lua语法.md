# Lua语法

[词法约定](#词法约定)
[变量](#变量)
[语句](#语句)
[表达式](#表达式)


## 词法约定

Lua 是一种自由格式语言。它忽略词法元素（标记）之间的空格和注释，但作为两个标记之间的分隔符除外；
Lua 中的名称（也称为标识符）可以是拉丁字母、阿拉伯-印度数字和下划线的任何字符串，不能以数字开头，也不能是保留字。标识符用于命名变量、表字段和标签；
Lua 是一种大小写敏感的语言
关于字符串书写的规则：
一个短字面字符串可以用匹配的单引号或双引号分隔；
可以使用转义符号，可以通过其数值指定短字面字符串中的任何字节，通过转义序列来完成；
字面字符串也可以使用长括号括起来的长格式定义；

注释以双连字符 (--) 开头，位于字符串外部的任何位置

## 变量
Lua 中有三种类型的变量：全局变量、局部变量和表字段。
任何变量名称都假定为全局变量，除非明确声明为局部变量

定义：var ::= Name | prefixexp '.' Name | prefixexp '[' exp ']'
表示 var 可以是：
一个简单的变量名（Name），如 x；
一个表的字段访问（t.key 或 t["key"]）

## 语句

### 块

块是按顺序执行的一系列语句；
Lua 的编译单元称为块。在语法上，块只是一个块；Lua 将块作为具有可变数量参数的匿名函数的主体
块可以存储在文件中或宿主程序中的字符串中。要执行块，Lua 首先加载它，将块的代码预编译为虚拟机的指令，然后 Lua 使用虚拟机的解释器执行编译后的代码；
块也可以预编译成二进制模式

### 赋值

允许多重赋值
如果一个变量在多重赋值中既被赋值又读取，Lua**确保所有读取都获取赋值前的变量值**
```lua
b = {};
a, b[1] = 1, 2;
```

### 控制结构
#### if-stat

```lua
if i < 10 then
  print("i < 10")
elseif i > 20 and i < 30 then
  print("i > 20")
else
  print("i > 30")
end
```

#### while-stat

```lua
while i < 10 do
  print(i)
end
```

#### repeat-stat
```lua
let i = 1;
repeat
    print(i)
    i = i + 1;
until i > 10;
```

#### for-stat
```lua
-- for数值循环，步长为1
for i = 1, 10 do
  print(i)
end

-- 步长为2
for i = 1, 10, 2 do
  print(i)
end
```

#### for-in-stat
泛型循环
```lua
-- 遍历数组
local t = {'holly', 2, 'kick', 4, 5}
-- ipair表示增序，pair表示降序
for k, v in ipairs(t) do
    print(k, v)
end

-- 遍历表
local t = {name = 'holly', age = 18}
for k, v in pairs(t) do
    print(k, v)
end
```

#### goto-stat
跳转语句
```lua
local i = 1;
::start::
if  i < 10 then
  print(i);
  i  = i + 1;
  goto start;
end
```

### 待关闭变量

指定close方法，退出块会自动关闭（回收），适用于资源管理

```lua
local function create_resource(name)
    local resource = {name = name}
    setmetatable(resource, {
        __close = function(self, err)
            print("Closing resource:", self.name)
            if err then
                print("With error:", err)
            end
        end
    })
    return resource
end

do
    local res1 <close> = create_resource("Res1")
    local res2 <close> = create_resource("Res2")
    print("Using resources...")
    -- 当退出这个块时，res2 会先关闭，然后是 res1
end
```


## 表达式

连接：..
长度运算符：#

### 算术运算符
+: 加法
-: 减法
*: 乘法
/: 浮点除法
//: 取整除法
%: 取模
^: 求幂
-: 一元减号

### 按位运算符
&: 按位 AND
|: 按位 OR
~: 按位异或
>>: 右移
<<: 左移
~: 一元按位 NOT

### 关系运算符
==: 相等
~=: 不等
<: 小于
>: 大于
<=: 小于或等于
>=: 大于或等于

### 逻辑运算符

**注意只有not返回值是true和false，其他俩返回是对应的表达式的值**

and：返回第一个价值，或最后一个真值
or：返回第一个真值，或最后一个假值
not：返回一个布尔值（true 或 false），表示操作数的逻辑非


### 函数

函数是第一公民
基本定义
```lua
function f(a, b)
  return a + b
end
```

可以使用匿名函数；
可以使用可变参数；
表的方法调用，使用冒号 or 点；
可以返回多个值；
函数可以作为参数传递和返回；

## 堆栈

Lua 使用虚拟堆栈（stack）作为与 C 语言交互的核心机制；
需要自己手动压入函数，压入参数，手动调用，最后从栈中取返回结果；