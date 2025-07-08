/*
*@author lucida
*description 冒泡排序
*@date 2025-07-08
*/

#include "Sort.hpp"

class BubbleSort: public Sort {

public:
    BubbleSort(int size):Sort(size) 
    {}
    ~BubbleSort() 
    {}

    /**
     * @brief 冒泡排序
     * 1.从头到尾遍历数组，比较相邻的元素，如果
     * 前一个元素大于后一个元素，则交换它们的位置。
     * 2.重复上述过程，直到没有元素需要交换为止。
     * 时间复杂度：O(N^2)
     * 空间复杂度：O(1)
     */
    void sort() override
    {
        for(int i = 0; i < m_size; i++) {
            for(int j = 0; j < m_size - i; j++){
                if(m_array[j + 1] < m_array[j]) {
                    swap(m_array[j], m_array[j+1]);
                }
            }
        }
        print();
    }

};