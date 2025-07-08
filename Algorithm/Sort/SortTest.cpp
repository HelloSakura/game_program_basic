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
    ShellSort shellSort(size);
    shellSort.sort();

    return 0;
}

int* getRandomArray(int& size)
{
    if(size <= 0){
        std::cout << "size error" << std::endl;
        return;
    }

    srand(time(NULL));
    int* array = new int[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 100 + 1;
    }
    return array;
}

