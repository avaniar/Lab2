#include "Header1.h"
#include<iostream>
#include <ctime>
#include <iomanip>
using namespace std;
int BinarySearch(int size,int *array,int key)
{
    int left = 0;int mid;
    int right = size - 1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (array[mid] == key)
            return mid;
        if (key < array[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

void QuickSort(int *array,int low,int high)
{
    if (low < high)
    {
        int pivot, pointer, secondpointer, i, helper;
        pivot = array[high];
        pointer = high;
        i = low;
        while ((pivot >= array[i])&&(i<high))// Find the first element larger than Pivot.
        {
            i++;
        }
        secondpointer = i;
        for (i = secondpointer + 1;i < high;i++)
        {
            if (array[i] <= pivot)//Replacement of elements.
            {
                helper = array[secondpointer];
                array[secondpointer] = array[i];
                array[i] = helper;
                secondpointer++;
            }
        }
        helper = array[secondpointer];
        array[secondpointer] = array[pointer];
        array[pointer] = helper;
        pointer = secondpointer;
        QuickSort(array, low, pointer-1);
        QuickSort(array, pointer + 1,high);
    }
}

void BubbleSort(int* array,int size)
{
    int left, counter;
    left = size - 1;
    do
    {
        counter = 0;
        for (int i=0;i<left;i++)
            if (array[i] > array[i+1])
            {
                int help = array[i];
                array[i] = array[i + 1];
                array[i + 1] = help;
                counter++;
            }
        left--;
    } while (counter);
}

void BogoSort(int* array, int size)
{
    srand(time(0));
    bool flag=1;
    int i = 0;
    while ((flag)&&(i<size-1))//Checking an array
    {
        if (array[i] > array[i + 1])
            flag = 0;
        else 
            i++;
    }
    while (!flag)
    {
        for (int i = 0;i < size;i++)
        {
            int indexrand = rand() % size;
            int help = array[i];
            array[i] = array[indexrand];
            array[indexrand] = help;
        }
        flag = 1;
        i = 0;
        while ((flag) && (i < size - 1))//Checking an array
        {
            if (array[i] > array[i + 1])
                flag = 0;
            else
                i++;
        }
    }
}

void CountingSort(char* array, int size)
{
    int max = 0;
    int help= 0;
    for (int i = 0;i < size;i++)// Find the maximum element.
    {
        if (array[i] > max)
            max = array[i];
    }
    int* newarray = new int[max+1];// create a new array.
    for (int i = 0;i < max +1;i++)
        newarray[i] = 0;
    for (int i = 0;i < size;i++)
    {
        newarray[array[i]]++;
    }
    for (int i = 0;i < max+1;i++)
        cout << newarray[i] << " ";
    cout << endl;
    for(int i=0;i<max+1;i++)
        for (int j = 0;j < newarray[i];j++)
        {
            array[help] = i;
            help++;
        }
}
void Comparison()
{
    srand(time(0));
    int size = 10;
    double timeQS = 0, timeBS = 0;
    cout.setf(ios::fixed);
    cout.precision(4);
    cout << "Size\\Kind ||  QickSort  || BubbleSort " << endl;
    cout << "-------------------------------------" << endl;
    for (int i = 1;i != 100000;i *= 10)
    {
        int* array = new int[size * i];
        for (int launch = 0;launch < 10;launch++)
        {
            for (int j = 0;j < size * i;j++)
            {
                array[j] = rand() % 100;
            }
            clock_t start = clock();
            QuickSort(array, 0, size * i-1);
            clock_t end = clock();
            timeQS += (end - start);
            for (int j = 0;j < size * i;j++)
            {
                array[j] = rand() % 100;
            }
            start = clock();
            BubbleSort(array, size * i);
            end = clock();
            timeBS += (end - start);
        }
        timeQS /= 10;
        timeBS /= 10;
        cout << setw(10) << size * i << "||" << setw(7) << timeQS / CLOCKS_PER_SEC << " sec " << "||" << setw(7) << timeBS / CLOCKS_PER_SEC << " sec" << endl;
        timeQS = 0; timeBS = 0;
    }
}


