/*
*@author lucida
*description 快速排序
*@date 2025-07-08
*/

#include "Sort.hpp"

class QuickSort: public Sort {
public:
    QuickSort(int size):Sort(size)
    {}

    ~QuickSort()
    {}

    /**
     * @brief 快速排序
     * 1.选择一个基准元素（通常是数组的第一个元素）;
     * 2.将数组分成两部分，一部分小于基准元素，另一部分大于基准元素;
     * 3.递归地对这两部分进行快速排序。
     * 时间复杂度：平均O(NlogN)，最坏O(N^2)
     * 空间复杂度：O(logN)
     */
    void sort() override
    {
        quickSort(0, m_size - 1);
        print();
    }

    void quickSort(int low, int high)
    {
        if (low < high)
        {
            int pivot = partition(low, high);
            quickSort(low, pivot - 1);
            quickSort(pivot + 1, high);
        }
    }

    int partition(int low, int high)
    {
        int pivot = m_array[low];
        int left = low + 1;
        int right = high;

        while (true)
        {
            while (left <= right && m_array[left] <= pivot) left++;
            while (left <= right && m_array[right] >= pivot) right--;

            if (left > right) break;
            swap(m_array[left], m_array[right]);
        }
        swap(m_array[low], m_array[right]);
        return right;
    }
};