// CSCI41Lab8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

void generateArray(int array[])
{
    for (int c = 0; c < 10; c++)
        array[c] = rand() % 100 + 1;
}

void selectionSort(int array[])
{
    for (int i = 0; i < 10 - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < 10; j++)

            if (array[j] < array[minIndex])
                minIndex = j;

        int temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
}

void insertionSort(int array[])
{
    for (int c = 1; c < 10; ++c)
    {
        int key = array[c];
        int d = c - 1;
        while (d >= 0 && array[d] > key)
        {
            array[d + 1] = array[d];
            d = d - 1;
        }
        array[d + 1] = key;
    }
}

void shellSort(int array[])
{
    for (int i = 10 / 2; i > 0; i /= 2)
    {
        for (int j = i; j < 10; j++)
        {
            for (int k = j - i; k >= 0; k -= i)
            {
                if (array[k + i] >= array[k])
                    break;
                
                else
                {
                  
                    int temp = array[k];
                    array[k] = array[k + i];
                    array[k + i] = temp;
                }
            }
        }
    }
}

int main()
{
    srand(time(0));

    int ascArray[] = { 10, 12, 25, 29, 32, 45, 55, 59, 61, 67 };
    int desArray[] = { 10, 12, 25, 29, 32, 45, 55, 59, 61, 67 };
    int randArray[10];

    clock_t start, end;

    start = clock();
    for (int c = 0; c < 20; c++)
        selectionSort(ascArray);

    for (int c = 0; c < 20; c++)
        selectionSort(desArray);

    for (int c = 0; c < 20; c++)
        selectionSort(randArray);

    end = clock();

    double timeTaken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Average time taken by selection sort on (Ascending, Descending and Random Array) 20 times each: "
        << fixed << setprecision(2) << timeTaken << " seconds " << endl;

    start = clock();
    for (int c = 0; c < 20; c++)
        insertionSort(ascArray);

    for (int c = 0; c < 20; c++)
        insertionSort(desArray);

    for (int c = 0; c < 20; c++)
        insertionSort(randArray);

    end = clock();

    timeTaken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Average time taken by insertionSort sort on (Ascending, Descending and Random Array) 20 times each: "
        << fixed << setprecision(2) << timeTaken << " seconds " << endl;

    start = clock();
    for (int c = 0; c < 20; c++)
        shellSort(ascArray);

    for (int c = 0; c < 20; c++)
        shellSort(desArray);

    for (int c = 0; c < 20; c++)
        shellSort(randArray);

    end = clock();

    timeTaken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Average time taken by insertionSort sort on (Ascending, Descending and Random Array) 20 times each: "
        << fixed << setprecision(2) << timeTaken << " seconds " << endl;
}