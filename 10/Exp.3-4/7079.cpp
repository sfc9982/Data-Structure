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

void MidOrderTraverse(Tree t)
{
    stack<Tree> s;
    while (t != nullptr || !s.empty())
    {
        while (t != nullptr)
        {
            s.push(t);
            t = t->lchild;
        }
        if (!s.empty())
        {
            t = s.top();
            cout << t->data;
            s.pop();
            t = t->rchild;
        }
    }
}

int main()
{
    Tree t = new Node;
    CreateTree(t);
    MidOrderTraverse(t);

    return 0;
}