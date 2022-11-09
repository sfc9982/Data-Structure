//
// Created by sfc9982 on 2022/11/9.
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

typedef enum PointerTag {
    Link,
    Thread
} PointerTag;

typedef struct node {
    char data;
    struct node *lchild, *rchild;
    PointerTag ltag = Link, rtag = Link;
} Node, *Tree;

void CreateTree(Tree &t)
{
    char ch;
    cin >> ch;
    if (ch == '@')
    {
        t = nullptr;
    }
    else
    {
        t = new Node;
        t->data = ch;
        CreateTree(t->lchild);
        CreateTree(t->rchild);
    }
}

void InThread(Tree &p, Tree &pre)
{
    if (p != nullptr)
    {
        InThread(p->lchild, pre);
        if (p->lchild == nullptr)
        {
            p->lchild = pre;
            p->ltag = Thread;
        }
        if (pre != nullptr && pre->rchild == nullptr)
        {
            pre->rchild = p;
            pre->rtag = Thread;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}

void CreateInThread(Tree &t)
{
    Tree pre = nullptr;
    if (t != nullptr)
    {
        InThread(t, pre);
        pre->rchild = nullptr;
        pre->rtag = Thread;
    }
}

void InOrderTraverse(Tree t)
{
    Tree p = t;
    while (p != nullptr)
    {
        while (p->ltag == Link)
            p = p->lchild;
        cout << p->data;
        while (p->rtag == Thread && p->rchild != nullptr)
        {
            p = p->rchild;
            cout << p->data;
        }
        p = p->rchild;
    }
}

int main()
{
    Tree t = new Node;
    CreateTree(t);
    CreateInThread(t);
    InOrderTraverse(t);

    return 0;
}