/**
 * @file Singleton.cpp
 * @author Lucida
 * @date 2025-08-17
 * @brief File description
 */


class Singleton{
private:
    Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    ~Singleton() = default;

public:
    static Singleton& Instance(){
        static Singleton instance;
        return instance;
    }

    void doSomething(){

    }
}


class Client{
    void doSomething(){
        Singleton& singleton = Singleton::Instance();
        singleton.doSomething();
    }
}