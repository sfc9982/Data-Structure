//
// Created by sfc9982 on 2022/10/17.
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

int n;
int cnt = 17;

void printQueue(queue<int> Q)
{
    for (int i = 0; i < cnt; ++i)
    {
        putchar(' ');
    }
    cnt -= 2;
    while (!Q.empty())
    {
        if (Q.front())
            cout << Q.front() << "   ";
        Q.pop();
    }
    cout << endl;
}

int main()
{
    cin >> n;
    queue<int> Q; // 不重复造轮子了
    Q.push(0), Q.push(1), Q.push(0);

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        printQueue(Q);
        for (int j = 1; j <= i + 1; ++j)
        {
            int frt = Q.front();
            Q.pop();
            Q.push(frt + Q.front());
        }
        Q.push(0);
    }
    return 0;
}