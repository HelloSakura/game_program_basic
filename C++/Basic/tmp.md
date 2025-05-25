
存储任意变量std::any

低于32位，使用联合体，小存储；
高于32位，使用new，分配新内存，大存储；

关于性能：
std:async future
并行最难的是要找出彼此的依赖关系
同时处理越多越快
常见场景：资源加载


让字符串更快：
看数据就能找到优化方法
string_view：不分配内存，使用窗口，本质上一个指向现有内存的指针加上串大小size
```C++
//0 memory allocate
void* operator new (size_t size) {
    static count size = 0;
    std::cout<<"Allocate "<<size<<" bytes"<<std::endl;
    return malloc(size);
}

void printString(std::string_view str) {
    std::cout << str << std::endl;
}

const c_str = "hello world";
std::string_view first(c_str, 5);
std::string_view second(c_str + 6, 5);
```


可视化基准测试




