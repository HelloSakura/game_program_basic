/*
*@author lucida
*description 插入排序
*@date 2025-06-26
*/
#include<iostream>
#include "Sort.hpp"

class Insertion: public Sort{
public:
    Insertion(int size):Sort(size)
    {
    }


    ~Insertion()
    {
        delete[] m_array;
        m_array = nullptr;
        m_size = 0;
    }

    /**
     * @brief 循环遍历，将每一项插入到其它已经有序的牌中的适当位置
     * 时间复杂度：O(N^2)
     * 空间复杂度：O(1)
     */
    void sort()
    {
        for(int i = 1; i < m_size; i++){
            int tmp = m_array[i];
            int j = i - 1;
            while(j >= 0 && m_array[j] > tmp){
                m_array[j + 1] = m_array[j];
                j--;
            }
            m_array[j + 1] = tmp;
            print();
        }
    }
};
