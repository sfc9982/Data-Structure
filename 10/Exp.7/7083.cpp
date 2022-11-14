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

const int MAXN = 100;

int a[MAXN];

int main()
{
    int n, cnt = 0;
    while (cin >> n && n)
    {
        a[cnt++] = n;
    }
    sort(a, a + cnt);

    cin >> n;

    int l = 0, r = cnt - 1;
    int loop = 0;
    while (l < r + 1)
    {
        loop++;
        int mid = (l + r) / 2;
        if (a[mid] == n)
        {
            cout << mid + 1 << " " << loop << endl;
            return 0;
        }
        else if (a[mid] > n)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << 0 << " " << loop << endl;
    return 0;
}