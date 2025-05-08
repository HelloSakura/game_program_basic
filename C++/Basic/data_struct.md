# 数据结构

## 数组Array

同类型的数据集合
注意边界检查，C++在release模式下数组越界可以通过编译
数组在内存上是连续的
"xxx"双引号修饰的字符串，表示是一个const char array，不能被修改

## string

### 使用Char*
C++以Ascii方式存储字符串
0作为字符串的结束符

### 使用String

注意作为参数传递的过程，避免值传递造成的拷贝开销
```C++
void printString(const string& str) {
}

//注意字符串在内存中的存储，放在了只读的常量区
char *str = "hello world";
str[2] = 'a';   //error，无法修改常量区的内存

char str[] = "hello world";
str[2] = 'a';   //ok，实际上是把常量区的字符串拷贝到栈上


```

C++14 引入了string_literal  


### 不同类型的char字串

注意赋值方式的区别
>1. char
>2. wchar_t  //宽字符，大小由编译平台决定
>2. char16_t
>2. char32_t
```C++
wchar_t* wstr = L"hello world";
```