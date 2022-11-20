//
// Created by sfc9982 on 2022/11/20.
//

#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>

using namespace std;

typedef struct node {
    char data;
    node *lchild, *rchild;
} Node, *Tree;
map<char, char> fa;


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
    Tree deepestNode = t;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto p = q.front();
            q.pop();
            if (p->rchild)
            {
                q.push(p->rchild);
                fa[p->rchild->data] = p->data;
            }
            if (p->lchild)
            {
                q.push(p->lchild);
                fa[p->lchild->data] = p->data;
            }
        }
        if (!q.empty())
            deepestNode = q.back();
    }

    vector<char> path;

    for (char i = deepestNode->data;; i = fa[i])
    {
        path.push_back(i);
        if (i == t->data)
            break;
    }

    cout << path.size() << " ";
    for (auto i = path.rbegin(); i != path.rend(); i++)
    {
        if (i != path.rbegin())
            cout << " ";
        cout << *i;
    }
    cout.flush();

    return 0;
}