//
// Created by sfc9982 on 2022/10/16.
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

class Stack {
public:
    int n = 0;
    int a[1000];

    int size()
    {
        return n;
    }

    void insert(int x)
    {
        a[++n] = x;
    }

    void pop()
    {
        --n;
    }

    int top()
    {
        return a[n];
    }

    bool empty()
    {
        return n == 0;
    }
};

int main()
{
    Stack S;
    int n;

    while (cin >> n && n)
    {
        S.insert(n);
    }

    while (!S.empty())
    {
        cout << S.top() << " ";
        S.pop();
    }

    return 0;
}