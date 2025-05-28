
template <typename T, size_t N>
class Array {
public:
    constexpr size_t size() const 
    { 
        return N; 
    }

    T& operator[](size_t index)
    { 
        if (!(index < N)) {
            __debugbreak();
        }

        return m_data[index]; 
    }

    const T& operator[](size_t index) const
    { 
        return m_data[index]; 
    }

    T* Data()
    {
        return m_data;
    }

    const T* Data() const
    {
        return m_data;
    }
private:
    T  m_data[N];
};