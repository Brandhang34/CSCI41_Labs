// CSCI41Lab9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void merge(int A[], int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            c[k] = A[i];
            k++;
            i++;
        }
        else
        {
            c[k] = A[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = A[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        A[i] = c[i];
    }
}
void mergeSortTD(int A[], int low, int high)
{
    if (low < high)
    {
        int mid;
        
        mid = (low + high) / 2;
        mergeSortTD(A, low, mid);
        mergeSortTD(A, mid + 1, high);
        merge(A, low, high, mid);
    }
    return;
}

void mergeSortBU(int A[],int n)
{
    int aux = A[n];
    for (int sz = 1; sz < n; sz = sz+sz)
        for (int lo = 0; lo < n - sz; lo += sz + sz)
        {
            merge(A, lo, lo + sz - 1, min(lo + sz + sz - 1, n - 1));
        }
}
int main()
{
    int arraySize = 10;

    int ascArray[] = { 9, 14, 22, 27, 35, 44, 57, 59, 64, 69 };
    int desArray[] = { 69, 64, 59, 57, 44, 35, 27, 22, 14, 9 };
    int randArray[10];
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        randArray[i] = rand() % 100;
    }

    int low = 0;
    int high = arraySize - 1;

    clock_t start, end;

    start = clock();
    mergeSortTD(ascArray, low, high);
    cout << "Ascending Order Merge Sort Top Down: " << endl;
    for (int c = 0; c < 20; c++)
    for (int i = 0; i < 10; i++)
    {
        cout << ascArray[i] << endl;
    }

    mergeSortTD(desArray, low, high);
    cout << "Descending Order Merge Sort Top Down: " << endl;
    for (int c = 0; c < 20; c++)
    for (int i = 0; i < 10; i++)
    {
        cout << desArray[i] << endl;
    }
   
    mergeSortTD(randArray, low, high);
    cout << "Random Order Merge Sort Top Down: " << endl;
    for (int c = 0; c < 20; c++)
    for (int i = 0; i < 10; i++)
    {
        cout << randArray[i] << endl;
    }
    end = clock();
    double timeTaken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Average time taken mergeSortTD 20 times: " << fixed << setprecision(2) << timeTaken << " seconds " << endl;

    mergeSortBU(ascArray, arraySize);
    cout << "Ascending Order Merge Sort Bottom Up: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << ascArray[i] << endl;
    }

    mergeSortBU(desArray, arraySize);
    cout << "Descending Order Merge Sort Bottom Up: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << desArray[i] << endl;
    }

    mergeSortBU(randArray, arraySize);
    cout << "Random Order Merge Sort Bottom UP: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << randArray[i] << endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
