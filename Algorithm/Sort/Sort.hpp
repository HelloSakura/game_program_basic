/*
*@author lucida
*description xxx
*@date 2025-06-26
*/
#include<iostream>
#include<cstdlib>
#include<ctime>

class Sort{
public:
    Sort(int size)
    {
        m_array = getRandomArray(size);
        m_size = size;
    }

    virtual ~Sort()
    {
        delete[] m_array;
        m_array = nullptr;
        m_size = 0;
    }
    
    void print()
    {
        for(int i = 0; i < m_size; i++){
            std::cout << m_array[i] << " ";
        }
        std::cout << std::endl;
    }

    
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    virtual void sort() = 0;

protected:
    int* getRandomArray(int& size)
    {
        if(size <= 0){
            std::cout << "size error" << std::endl;
            return;
        }

        srand(time(NULL));
        int* array = new int[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = rand() % 100 + 1;
        }
        return array;
    }


protected:
    int* m_array;
    int m_size;
};
