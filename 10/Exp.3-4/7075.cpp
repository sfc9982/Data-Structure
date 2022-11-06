//
// Created by sfc9982 on 2022/11/6.
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

typedef struct node {
    char data;
    node *lchild, *rchild;
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

void AfterOrder(Tree t)
{
    if (t == nullptr)
        return;
    AfterOrder(t->lchild);
    AfterOrder(t->rchild);
    cout << t->data;
}

int main()
{
    Tree t = new Node;
    CreateTree(t);
    AfterOrder(t);
    return 0;
}