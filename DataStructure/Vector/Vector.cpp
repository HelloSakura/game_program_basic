#pragma once
template<typename T>
class Vector{
public:
    Vector(){
        //allocate
        reAlloc(2);
    }

    ~Vector()
    {
        clear();
        ::operator delete(m_data, m_capacity * sizeof(T));
        //使用delete[] m_data来释放内存，回依次调用析构函数
        //但是在操作过程中，emplace_back, reAlloc等函数，可能已经调用了析构函数
        //这里使用会报错
    }

    void push_back(const T& value)
    {
        if(m_size >= m_capacity){
            reAlloc(m_capacity + m_capacity / 2);
        }

        m_data[m_size++] = value;
    }

    //移动构造版本，避免在realloc时候反复的创建和析构
    void emplace_back(T&& value)
    {
        if(m_size >= m_capacity){
            reAlloc(m_capacity + m_capacity / 2);
        }
        m_data[m_size++] = std::move(value);
    }

    //接受参数来构造对象T
    template<typename... Args>
    T& emplace_back(Args&&... args)
    {
        if(m_size >= m_capacity){
            reAlloc(m_capacity + m_capacity / 2);
        }
        //m_data[m_size] = T(std::forward<Args>(args)...);
        new (&m_data[m_size]) T(std::forward<Args>(args)...);   //在指定内存上构造
        return m_data[m_size++];
    }


    void pop_back()
    {
        if(m_size > 0){
            m_size--;
            m_data[m_size].~T();
        }
    }

    void clear()
    {
        for(size_t i = 0; i < m_size; i++){
            m_data[i].~T();
        }
        m_size = 0;
    }
    const T& operator[](size_t index) const
    {
        if(index >= m_size){
            __debugbreak();
        }
        return m_data[index];
    }

    T& operator[](size_t index)
    {
        if(index >= m_size){
            __debugbreak();
        }
        return m_data[index];
    }

    size_t size() const
    {
        return m_size;
    }
private:
    reAlloc(size_t newCapacity)
    {
        //1. alloc a new block of memory
        T* newBlock = (T*)::operator new(newCapacity * sizeof(T));
        if(newCapacity < m_size){
            m_size = newCapacity;
        }

        //2. copy/move all exsiting elements to the new block
        for(size_t i = 0; i < m_size; i++){
            newBlock[i] = std::move(m_data[i]);    //不直接用memory，而是使用for copy是为了触发拷贝构造函数，处理一些复杂类型时需要
        }
        
        //3. delete old
        clear();        //注意原内存的销毁方式，不直接使用delete[]
        ::operator delete(m_data, m_capacity * sizeof(T));
        m_data = newBlock;
        m_capacity = newCapacity;
    }

private:
    T* m_data = nullptr;
    size_t m_size = 0;  //number of elements actually inside the vector
    size_t m_capacity = 0;  //memory of elements allocated
};