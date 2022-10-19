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


void printQueue(queue<int> Q)
{
    while (!Q.empty())
    {
        if (Q.front())
            cout << Q.front() << " ";
        Q.pop();
    }
    cout << endl;
}

int main()
{
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

    //    cout << R"(              1
    //             1  1
    //            1  2  1
    //          1  3  3  1
    //        1  4  6  4  1
    //      1  5  10  10  5  1
    //    1  6  15  20  15  6  1
    //  1  7  21  35  35  21  7  1
    //1  8  28  56  70  56  28  8  1)";
    return 0;
}