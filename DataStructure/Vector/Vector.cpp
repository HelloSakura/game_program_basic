template<typename T>
class Vector{
public:
    Vector(){
        //allocate
        reAlloc(2);
    }
    void push_back(T value){ 
    }

private:
    reAlloc(size_t newCapacity)
    {
        //1. alloc a new block of memory
        //2. copy/move all exsiting elements to the new block
        //3. delete old
        T* newBlock = new T[newCapacity];
        for(sizre i = 0; i < m_size; i++){
            newBlock[i] = m_data[i];    //不直接用memory，而是使用for copy是为了触发拷贝构造函数，处理一些复杂类型时需要
        }
    }

private:
    T* m_data = nullptr;
    size_t m_size = 0;  //number of elements actually inside the vector
    size_t m_capacity = 0;  //memory of elements allocated
};