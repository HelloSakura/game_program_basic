/*
*@author lucida
*description 快速排序
*@date 2025-07-08
*/
#pragma once
#include "Sort.hpp"

class QuickSort : public Sort {
public:
    QuickSort(int size) :Sort(size)
    {
    }

    QuickSort(int* array, int size) :Sort(array, size)
    {
    }

    ~QuickSort()
    {
    }


    void sort() override
    {
        bestQuick3Sort(0, m_size - 1);
        print();
    }

    void sort(int mode = 1)
    {
        switch (mode)
        {
        case 1:
            quickSort(0, m_size - 1);
            break;
        case 2:
            quick3Sort(0, m_size - 1);
            break;
        case 3:
            bestQuick3Sort(0, m_size - 1);
        default:
            quickSort(0, m_size - 1);
            break;
        }
    }

    /**
     * @brief 快速排序，基本实现
     * 1.选择一个基准元素（通常是数组的第一个元素）;
     * 2.将数组分成两部分，一部分小于基准元素，另一部分大于基准元素;
     * 3.递归地对这两部分进行快速排序。
     * 时间复杂度：平均O(NlogN)，最坏O(N^2)
     * 空间复杂度：O(logN)
     */
    void quickSort(int low, int high)
    {
        if (low < high)
        {
            //分区操作，返回基准元素的最终位置
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

    /**
     * @brief 三路快速排序
     * 1.选择一个基准元素（通常是数组的第一个元素）;
     * 2.将数组分成三部分，一部分小于基准元素，一部分等于基准元素，另一部分大于基准元素;
     * 3.递归地对小于和大于基准元素的两部分进行快速排序。
     * 时间复杂度：平均O(NlogN)，最坏O(N^2)
     * 空间复杂度：O(logN)
     * 效率提升很明显
     */
    void quick3Sort(int low, int high)
    {
        if (high <= low) return;
        int lt = low, i = low + 1, gt = high;
        int pivot = m_array[low];

        while (i <= gt) {
            if (m_array[i] < pivot) {
                swap(m_array[lt++], m_array[i++]);
            }
            else if (m_array[i] > pivot) {
                swap(m_array[i], m_array[gt--]);
            }
            else {
                i++;
            }
        }
        //print();
        quick3Sort(low, lt - 1);
        quick3Sort(gt + 1, high);
    }

    /**
     * 信息量最优版
     * 1.在划分过程中，将等于基准值的元素暂时移动到数组的两端
     * 2.最后将这些元素移回中间区域
     * 3.减少对重复元素的多次交换操作
     */
    void bestQuick3Sort(int low, int high)
    {
        if (high <= low) return;
        int p_l = low;  // 左侧等于pivot游标
        int q_r = high;     // 右侧等于pivot游标
        int lt = low + 1;   // 左侧大于pivot游标
        int gt = high;      // 右侧大于pivot游标
        int pivot = m_array[low];

        /****=pivot***|***<pivot***|***?***|***>pivot***|***=pivot****/
        /*            ^            ^       ^            ^            */
        /*            |            |       |            |            */
        /*           p_l           lt      gt          q_r           */

        while (true) {
            //从左往右扫描，找到大于等于pivot的元素, 将=pivot的值放在数组左侧
            while (lt <= gt && m_array[lt] <= pivot) {
                if (m_array[lt] == pivot) {
                    swap(m_array[p_l], m_array[lt]);
                    p_l++;
                }
                lt++;
            }

            //从右往左扫描，找到小于等于pivot的元素, 将=pivot的值放在数组右侧
            while (lt <= gt && m_array[gt] >= pivot) {
                if (m_array[gt] == pivot) {
                    swap(m_array[q_r], m_array[gt]);
                    q_r--;
                }
                gt--;
            }

            if (gt < lt) break;

            //交换左右不匹配的元素
            //经过以上操作后，此时m_array[lt] > pivot, m_array[gt] < pivot
            //两个元素相对与pivot的位置是错误的，需要纠正
            swap(m_array[lt++], m_array[gt--]);
        }

        //将左侧等于pivot部分移到中间
        int k = low;
        while (k < p_l) {
            swap(m_array[gt--], m_array[k++]);
        }
        //将右侧等于pivot部分移到中间
        k = high;
        while (k > q_r) {
            swap(m_array[lt++], m_array[k--]);
        }
        //print();
        bestQuick3Sort(low, gt);
        bestQuick3Sort(lt, high);
    }

protected:
    int m_sort_mode = 0;    //排序算法选择
};
