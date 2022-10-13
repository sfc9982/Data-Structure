//
// Created by sfc9982 on 2022/9/29.
//

//heap sort
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &a, int i, int n)
{
    int l = 2 * i + 1, r = 2 * i + 2, largest = i;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, largest, n);
    }
}

void heapSort(vector<int> &a)
{
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, i, n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, 0, i);
    }
}

int main()
{
    int x;
    vector<int> a;
    while (cin >> x && x != 0)
        a.push_back(x);
    heapSort(a);
    for (int i: a)
        cout << i << " ";
    cout << endl;
    return 0;
}