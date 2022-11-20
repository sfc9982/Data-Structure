//
// Created by sfc9982 on 2022/11/20.
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

int main()
{
    Tree t;
    CreateTree(t);
    queue<Tree> q;
    q.push(t);
    while (!q.empty())
    {
        int size = q.size();
        int width = 0;
        for (int i = 0; i < size; i++)
        {
            auto p = q.front();
            q.pop();
            if (p->lchild)
                q.push(p->lchild);
            if (p->rchild)
                q.push(p->rchild);
            width++;
        }
        cout << width << " ";
    }

    return 0;
}