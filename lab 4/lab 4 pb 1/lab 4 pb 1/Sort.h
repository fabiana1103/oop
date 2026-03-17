#pragma once
#include <initializer_list>
#include <string>
#include <cstdarg>

class Sort
{
    int* lista;// add data members
    int nr_elem;
    void QuickSortR(int low, int high, bool ascendent);
    int Partition(int low, int high, bool ascendent);
public:
    // add constuctors
    Sort(int n, int mini, int maxi);
    Sort(std::initializer_list<int> initList); 
    Sort(int* lista, int n);
    Sort(int n, ...);
    Sort(const std::string& sir);
    ~Sort();
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
