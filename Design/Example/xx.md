
# 单例模式
:smile:

## 三要素

1. 私有化构造函数、删除拷贝和赋值：防止外部创建和复制实例
2. 静态成员变量：保存唯一实例
3. 静态方法提供访问：获取唯一实例


## 要点

不要在栈上创建，空间不够，特别大的时候效率低（属于设计问题）
懒汉式注意线程安全

懒汉模式 :vs: 饿汉模式：区别在于首次调用是否生成单例
饿汉：第一次调用前就创建了单例
懒汉：第一次调用过程中创建了单例

## 如何创建

![](./Image/2025-08-17-17-09-52.png){: width="50%" height="auto"}





## 饿汉模式

用到的时候再创建单例，多线程不安全
加锁带来一个问题时，只会在创建的时候发挥作用，但是在后续运行的时候，每次只有一个线程访问，无法同时获取

### 基本写法
```C++
Singleton{
    static Singleton& _instance = nullptr;
    static std::mutex _mutex;
    static Singleton& Instance(){
        //多线程加锁
        std::lock_guard<std::mutex> lock(_mutex);
        if(_instance == nullptr){
            _instance = new Singleton();
        }
        return _instance;
    }
}
```

### 完善写法
```C++
Singleton{
    static Singleton& _instance = nullptr;
    static std::once_flag _once_flag;

    static Singleton& Instance(){
       std::call_once(once_flag, initInstance);
       return _instance;
    }

    static void initInstance(){
        _instance = new Singleton();
    }

}

```

