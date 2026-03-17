#include <iostream>
#include "Sort.h"

using namespace std;

int main() 
{
    cout << "test 1" << endl;
    Sort s1(10, 1, 100);
    s1.Print();
    s1.BubbleSort(true);
    s1.Print();

    cout << "test 2" << endl;
    Sort s2 = { 50, 20, 10, 40, 30 };
    s2.Print();
    s2.InsertSort(false);
    s2.Print();

    cout << "test 3" << endl;
    int arrayExist[] = { 9, 3, 7, 1, 8 };
    Sort s3(arrayExist, 5);
    s3.Print();
    s3.QuickSort(true);
    s3.Print();

    cout << "test 4" << endl;
    Sort s4(6, 100, 200, 50, 10, 300, 20);
    s4.Print();
    s4.BubbleSort(false); 
    s4.Print();

    cout << "test 5" << endl;
    Sort s5("10,40,100,5,70");
    s5.Print();
    s5.QuickSort(false); 
    s5.Print();

    cout << "test 6" << endl;
    cout << "nr elem: " << s5.GetElementsCount() << endl;
    cout << "elem index 2: " << s5.GetElementFromIndex(2) << endl;

    return 0;
}