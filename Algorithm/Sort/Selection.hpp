/*
*@author lucida
*description 选择排序
*@date 2025-06-26
*/
#include "Sort.hpp"


class Selection:public Sort {
public:
    Selection(int size):Sort(size)
    {}

    ~Selection()
    {}

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
};
