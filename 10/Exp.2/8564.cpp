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

struct Node {
    int data;
    Node *next;
};

class Queue {
private:
    Node *head, *tail;
    int size;

public:
    Queue()
    {
        head = tail = nullptr;
        size = 0;
    }

    void push(int x)
    {
        Node *p = new Node;
        p->data = x;
        p->next = nullptr;
        if (head == nullptr)
            head = tail = p;
        else
            tail->next = p, tail = p;
        size++;
    }

    void pop()
    {
        Node *p = head;
        head = head->next;
        delete p;
        size--;
    }

    int front()
    {
        return head->data;
    }

    int back()
    {
        return tail->data;
    }

    bool empty()
    {
        return size == 0;
    }
};

int main()
{
    Queue Q;
    int n;
    while (cin >> n && n)
        Q.push(n);
    while (!Q.empty())
    {
        cout << Q.front() << " ";
        Q.pop();
    }
    return 0;
}