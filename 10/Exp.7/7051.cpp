//
// Created by sfc9982 on 2022/11/24.
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

const int N = 105;

const int null = 0x3f3f3f3f;


int h[N];

int m, p;


bool is_prime(int x)
{
    if (x < 2)
        return 0;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}


void getPrime(int st)
{
    while (st)
    {
        if (is_prime(st))
        {
            p = st;
            return;
        }
        st--;
    }
}


int find(int x)
{
    int t = (x % p + p) % p;
    while (h[t] != null && h[t] != x)
    {
        t++;
        if (t == p)
        {
            t = 0;
        }
    }
    return t;
}


int main()
{
    cin >> m;
    getPrime(m);
    memset(h, 0x3f, sizeof h);

    for (int i = 0; i < m; i++)
        cout << i << "  ";
    cout << endl;
    int x;
    while (cin >> x, x)
    {
        h[find(x)] = x;
    }
    for (int i = 0; i < m; i++)
    {
        if (h[i] == null)
            cout << 0 << "  ";
        else
            cout << h[i] << "  ";
    }

    return 0;
}