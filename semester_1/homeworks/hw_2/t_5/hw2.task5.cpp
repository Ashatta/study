#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void heapify(int heap[], int i)
{
    int left = 2 * i;
    int right = left + 1;
    int max = 0;
    
    if (left <= heap[0] && heap[left] > heap[i])
        max = left;
    else
        max = i;
    if (right <= heap[0] && heap[right] > heap[max])
        max = right;

    if (max != i)
    {
        swap(heap[i], heap[max]);
        heapify(heap, max);
    }
} 

void buildHeap(int heap[])
{
    for (int i = heap[0] / 2; i > 0; --i)
        heapify(heap, i);
}

void heapSort(int a[], int size)
{
    buildHeap(a);
    
    for (int i = size; i > 0; --i)
    {
        swap(a[1], a[i]);
        --a[0];
        heapify(a, 1);
    }
}

int main()
{
    int size = 0;
    clog << "The program sorts an array\nEnter it's size ";
    cin >> size;

    int * array = new int[size + 1];
    array[0] = size;
    clog << "Enter the elements of the array" << endl;
    for (int i = 1; i <= size; ++i)
        cin >> array[i];
    
    heapSort(array, size);

    clog << "This is the sorted array" << endl;
    for (int i = 1; i <= size; ++i)
        cout << array[i] << " ";
    cout << endl;

    delete[] array;

    return 0;
}

