//
// Created by sfc9982 on 2022/10/22.
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

int a[1000];

int main()
{
    int x, i, cnt = 0;
    for (i = 0, x = 0; cin >> x && x; i++)
        a[i] = x;
    sort(a, a + i);
    // binary search
    int n;
    cin >> n;
    cout << find() << endl;
    return 0;
}