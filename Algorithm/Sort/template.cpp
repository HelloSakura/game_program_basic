/*
*@author lucida
*description xxx
*@date 2025-06-26
*/
#include<iostream>

class XXXSort{
public:
    XXXSort(int* array, int size)
    {
        m_array = array;
        m_size = size;
    }

    ~XXXSort()
    {
        delete[] m_array;
        m_array = nullptr;
        m_size = 0;
    }

    /**
     * @brief 循环遍历，每次从余下的数组中找到一个最小值，与排序好的部分末尾交换
     * 时间复杂度：O(N^2)
     * 空间复杂度：O(1)
     */
    void sort()
    {

    }

    void print()
    {
        for(int i = 0; i < m_size; i++){
            std::cout << m_array[i] << " ";
        }
    }

private:
    int* m_array;
    int m_size;
};
