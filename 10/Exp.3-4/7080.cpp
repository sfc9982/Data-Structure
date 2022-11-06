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

int CountLeaf(Tree t)
{
    if (t == nullptr)
        return 0;
    if (t->lchild == nullptr)
        return CountLeaf(t->rchild) + 1;
    return CountLeaf(t->lchild) + CountLeaf(t->rchild);
}

int main()
{
    Tree t = new Node;
    CreateTree(t);
    cout << CountLeaf(t) << endl;
    return 0;
}