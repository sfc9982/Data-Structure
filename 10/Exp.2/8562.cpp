//
// Created by sfc9982 on 2022/10/30.
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

class Stack {
private:
    Node *head;
    int n;

public:
    Stack()
    {
        head = nullptr;
        n = 0;
    }

    void push(int x)
    {
        Node *p = new Node;
        p->data = x;
        p->next = head;
        head = p;
        n++;
    }

    void pop()
    {
        Node *p = head;
        head = head->next;
        delete p;
        n--;
    }

    int top()
    {
        return head->data;
    }

    bool empty()
    {
        return n == 0;
    }

    int size()
    {
        return n;
    }
};

int main()
{
    Stack S;
    int n;

    while (cin >> n && n)
    {
        S.push(n);
    }

    while (!S.empty())
    {
        cout << S.top() << " ";
        S.pop();
    }
    return 0;
}