/*
*@author lucida
*description 归并排序
*@date 2025-07-03
*/
#include<iostream>

class MergeSort{
public:
    MergeSort(int* array, int size)
    {
        m_array = array;
        m_buffer = new int[size];
        m_size = size;
    }

    ~MergeSort()
    {
        delete[] m_array;
        delete[] m_buffer;
        m_array = nullptr;
        m_buffer = nullptr;
        m_size = 0;
    }

    /**
     * @brief 
     * 将一个数组排序，可以先递归地将它分成两半分别排序，然后将结果归并起来
     * 自顶向下归并
     * 时间复杂度：O(NLogN)
     * 空间复杂度：O(1)
     */
    void sort()
    {
        sortUB(0, m_size - 1);
        print();
    }

    void sortUB(int low, int high)
    {
        if(low >= high) return;
        int mid = low + (high - low) / 2;
        sortUB(low, mid);
        sortUB(mid + 1, high);
        merge(low, mid, high);
    }

    void merge(int low, int mid, int high)
    {
        int i = low, j = mid + 1;
        for(int k = low; k <= high; k++){
            m_buffer[k] = m_array[k];
        }
        
        for(int k = low; k <= high; k++){
            if(i > mid){
                m_array[k] = m_buffer[j++];
            }
            else if(j > high){
                m_array[k] = m_buffer[i++];
            }
            else if(m_buffer[i] < m_buffer[j]){
                m_array[k] = m_buffer[i++];
            }
            else{
                m_array[k] = m_buffer[j++];
            }
        }
        
    }

    void print()
    {
        for(int i = 0; i < m_size; i++){
            std::cout << m_array[i] << " ";
        }
    }

private:
    int* m_array;
    int* m_buffer;
    int m_size;
};
