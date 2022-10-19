//
// Created by sfc9982 on 2022/10/19.
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

const int N = 100;


class Queue {
public:
    int a[N];
    int front = 0;
    int rear = 0;

    int size()
    {
        return rear - front;
    }

    void insert(int x)
    {
        a[rear++] = x;
    }

    void pop()
    {
        ++front;
    }

    int top()
    {
        return a[front];
    }

    bool empty()
    {
        return front == rear;
    }
};

int main()
{
    Queue Q;
    int n;

    while (cin >> n && n)
    {
        Q.insert(n);
    }

    while (!Q.empty())
    {
        cout << Q.top() << " ";
        Q.pop();
    }

    return 0;
}