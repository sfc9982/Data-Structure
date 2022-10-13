//
// Created by sfc9982 on 2022/9/29.
//

// selection sort
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        swap(a[i], a[min]);
    }
}

int main()
{
    int x;
    vector<int> a;
    while (cin >> x && x != 0)
        a.push_back(x);
    selectionSort(a);
    for (int i: a)
        cout << i << " ";
    cout << endl;
    return 0;
}