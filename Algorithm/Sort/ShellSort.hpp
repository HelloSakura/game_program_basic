/*
*@author lucida
*description 希尔排序
*@date 2025-07-01
*/
#pragma once
#include "Sort.hpp"

class ShellSort:public Sort{
public:
    ShellSort(int size):Sort(size)
    {}

    ~ShellSort()
    {}

    /**
     * @brief 
     * 1.选择一个增量序列（通常初始增量为数组长度的一半，然后每次减半）;
     * 2.按照当前增量将数组分为若干子序列;
     * 3.对每个子序列进行插入排序;
     * 4.减小增量，重复上述过程，直到增量为1。
     * 时间复杂度：最坏O(N^2)，最好O(NlogN)，取决于增量序列
     * 空间复杂度：O(1)
     */
    void sort()
    {
        print();
        int gap = m_size / 2;   //组间隔
        while(gap >= 1){
            for(int i = gap; i < m_size; i++){
                for(int j = i; j >= gap && m_array[j] < m_array[j - gap]; j -= gap){     //组内是个插入排序
                    swap(m_array[j], m_array[j - gap]);
                }
            }
            print();
            gap /= 2;
        }
    }
};
