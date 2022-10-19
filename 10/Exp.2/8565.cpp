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

int main()
{
    queue<int> Q;
    int n;
    while (cin >> n && n)
        Q.push(n);
    while (!Q.empty())
        cout << Q.front() << " ", Q.pop();
    return 0;
}