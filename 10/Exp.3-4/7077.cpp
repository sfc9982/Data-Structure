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

typedef struct node {
    char data;
    struct node *lchild, *rchild;
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

void levelTraverse(Tree t)
{
    queue<Tree> q;
    q.push(t);
    while (!q.empty())
    {
        Tree p = q.front();
        cout << p->data;
        if (p->lchild != nullptr)
            q.push(p->lchild);
        if (p->rchild != nullptr)
            q.push(p->rchild);
        q.pop();
    }
}

int main()
{
    Tree t = new Node;
    CreateTree(t);
    levelTraverse(t);
    return 0;
}