//
// Created by sfc9982 on 2022/9/29.
//

// insertion sort

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int x = a[i];
        while (j > -1 && a[j] > x)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

int main()
{
    int x;
    vector<int> a;
    while (cin >> x && x != 0)
        a.push_back(x);
    insertionSort(a);
    for (int i: a)
        cout << i << " ";
    cout << endl;
    return 0;
}