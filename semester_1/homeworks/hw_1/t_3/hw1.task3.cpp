#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void reverse(int a[], int left, int right)
{
    for (int i = 0; i < (right - left) / 2; i++)
        swap(a[left + i], a[right - i - 1]);
}

int main()
{
    int m = 0;
    int n = 0;

    clog << "The program swaps two parts of an array x[1]...x[m]...x[m+n]"
         << "\nEnter m and n" << endl;
    cin >> m >> n;

    int * a = new int[m + n];
    clog << "Enter elements of the array" << endl;
    for (int i = 0; i < m + n; i++)
        cin >> a[i];

    reverse(a, 0, m + n);
    reverse(a, 0, n);
    reverse(a, n, m + n);

    clog << "This is the converted array" << endl;
    for (int i = 0; i < m + n; i++)
        cout << a[i] << " ";
    cout << endl;

    delete[] a;

    return 0;
}

