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

```