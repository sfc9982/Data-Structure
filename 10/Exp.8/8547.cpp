//
// Created by sfc9982 on 2022/9/29.
//

// shell sort
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void shellSort(vector<int> &a)
{
    int n = a.size();
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++)
            for (int j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap)
                swap(a[j], a[j + gap]);
}

int main()
{
    int x;
    vector<int> a;
    while (cin >> x && x != 0)
        a.push_back(x);
    shellSort(a);
    for (int i: a)
        cout << i << " ";
    cout << endl;
    return 0;
}