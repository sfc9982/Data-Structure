//
// Created by sfc9982 on 2022/10/13.
//

#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int a[10];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    // reverse the array
    for (int i = 0; i < n / 2; i++)
        swap(a[i], a[n - i - 1]);
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}