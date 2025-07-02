/*
*@author lucida
*description 选择排序
*@date 2025-06-26
*/
#include<iostream>

class Selection{
public:
    Selection(int* array, int size)
    {
        m_array = array;
        m_size = size;
    }

    ~Selection()
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
        for(int i = 0; i < m_size; i++){
            int min = m_array[i];
            for(int j = i + 1; j < m_size; j++){
                if(m_array[j] < min){
                    min = m_array[j];
                    m_array[j] = m_array[i];
                    m_array[i] = min;
                }
            }
            print();
        }
    }

    void print()
    {
        for(int i = 0; i < m_size; i++){
            std::cout << m_array[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    int* m_array;
    int m_size;
};
