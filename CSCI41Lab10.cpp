// CSCI41Lab10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

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

void swap(int arr[], int i, int j)
{
    //swap arr[i] with arr[j] elements
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

int partition(int arr[], int first, int last) {
    // pivot (element to be placed at the "middle" position);
    int pivot = arr[last];
    int i = (first - 1);

    // scan array, and swap if current element is smaller than or equal to pivot;
    for (int j = first; j <= last - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, last);
    return (i + 1);
}

void dijkstraPartion(int arr[], int l, int r, int& i, int& j)
{
    i = l - 1, j = r;
    int p = l - 1, q = r;
    int v = arr[r];

    while (true)
    {
        while (arr[++i] < v);

        while (v < arr[--j])
            if (j == l)
                break;

        if (i >= j)
            break;


        swap(arr[i], arr[j]);

        if (arr[i] == v)
        {
            p++;
            swap(arr[p], arr[i]);
        }

        if (arr[j] == v)
        {
            q--;
            swap(arr[j], arr[q]);
        }
    }
}
void quickSortR(int arr[], int first, int last) 
{
    if (first < last)
    {

        int pi = partition(arr, first, last);

        quickSortR(arr, first, pi - 1);
        quickSortR(arr, pi + 1, last);
    }
}

void quicksort(int a[], int l, int r)

{

    if (r <= l) return;
    int i, j;

    dijkstraPartion(a, l, r, i, j);

    quicksort(a, l, j);
    quicksort(a, i, r);
}

int main()
{
    srand(time(NULL));

    int ascArray[] = { 10, 12, 25, 29, 32, 45, 55, 59, 61, 67 };
    int desArray[] = { 67, 61, 59, 55, 45, 32, 29, 25, 12, 10 };
    const int sizeofArray = 10;
    int randArray[sizeofArray];

    for (int i = 0; i < sizeofArray; i++)
    {
        randArray[i] = rand() % 100;
    }

    clock_t start, end;

    start = clock();
        selectionSort(ascArray);

        selectionSort(desArray);

        selectionSort(randArray);

    end = clock();

    double timeTaken = double(end - start);

    cout << "Time taken by selection sort on (Ascending, Descending and Random Array): "
        << fixed << setprecision(5) << timeTaken << " seconds " << endl;

    start = clock();
        insertionSort(ascArray);

        insertionSort(desArray);

        insertionSort(randArray);

    end = clock();

    timeTaken = double(end - start);

    cout << "Time taken by insertionSort sort on (Ascending, Descending and Random Array): "
        << fixed << setprecision(5) << timeTaken << " seconds " << endl;

    start = clock();
        shellSort(ascArray);

        shellSort(desArray);

        shellSort(randArray);

    end = clock();

    timeTaken = double(end - start);

    cout << "Time taken by insertionSort sort on (Ascending, Descending and Random Array): "
        << fixed << setprecision(5) << timeTaken << " seconds " << endl;

    cout << "Quick Sorting" << endl;

    start = clock();
    quickSortR(randArray, 0, 9);

    for (int i = 0; i < 10; i++)
    {
        cout << randArray[i] << " ";
    }
    cout << endl;

    quickSortR(desArray, 0, 9);
    for (int j = 0; j < 10; j++)
    {
        cout << desArray[j] << " ";
    }
    cout << endl ;

    quickSortR(ascArray, 0, 9);
    for (int k = 0; k < 10; k++)
    {
        cout << ascArray[k] << " ";
    }

    end = clock();

    timeTaken = double(end - start);

    cout << endl << "Time take by quickSort sort on (Random, Descnding, and Ascending Array): " << fixed << setprecision(5) << timeTaken << " seconds " << endl;

    cout << "Djikstra 3-way Sorting" << endl;

    start = clock();
    quicksort(randArray, 0, 9);

    for (int i = 0; i < 10; i++)
    {
        cout << randArray[i] << " ";
    }
    cout << endl;

    quicksort(desArray, 0, 9);
    for (int j = 0; j < 10; j++)
    {
        cout << desArray[j] << " ";
    }
    cout << endl;

    quicksort(ascArray, 0, 9);
    for (int k = 0; k < 10; k++)
    {
        cout << ascArray[k] << " ";
    }
    end = clock();

    timeTaken = double(end - start);

    cout << endl << "Time take by Dijkstra 3-way sorting on (Random, Descnding, and Ascending Array): " << fixed << setprecision(5) << timeTaken << " seconds " << endl;
    return 0;
}