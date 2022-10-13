//
// Created by sfc9982 on 2022/9/29.
//

// bubble sort

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

int main()
{
    int x;
    vector<int> a;
    while (cin >> x && x != 0)
        a.push_back(x);
    bubbleSort(a);
    for (int i: a)
        cout << i << " ";
    cout << endl;
    return 0;
}