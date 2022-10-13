//
// Created by sfc9982 on 2022/9/29.
//

// quick sort
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &a, int l, int r)
{
    int pivot = a[r], i = l - 1;
    for (int j = l; j < r; j++)
        if (a[j] < pivot)
            swap(a[++i], a[j]);
    swap(a[++i], a[r]);
    return i;
}

void quickSort(vector<int> &a, int l, int r)
{
    if (l < r)
    {
        int p = partition(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}

int main()
{
    int x;
    vector<int> a;
    while (cin >> x && x != 0)
        a.push_back(x);
    quickSort(a, 0, a.size() - 1);
    for (int i: a)
        cout << i << " ";
    cout << endl;
    return 0;
}