/*
*@author lucida
*description 整理测试
*@date 2025-07-02
*/
#include<cstdlib>
#include<ctime>
#include"ShellSort.hpp"
#include"Insertion.hpp"
#include"Selection.hpp"


int* getRandomArray(int& size);

int main()
{
    int size = 20;
    int* array = getRandomArray(size);

    ShellSort shellSort(array, size);
    shellSort.sort();

    return 0;
}


int* getRandomArray(int& size)
{
    srand(time(NULL));
    int* array = new int[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 100 + 1;
    }
    return array;
}
