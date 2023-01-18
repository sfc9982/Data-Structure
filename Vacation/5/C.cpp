//
// Created by sfc9982 on 2023/1/17.
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

struct node {
    int data;
    struct node *lchild, *rchild;
};

using BSTNode = struct node;
using bstree = struct node *;

int BST_Search(bstree t, int key, bstree &f, bstree &p)
{
    bstree q;
    if (t != nullptr)
    {
        if (t->data == key)
        {
            return 1;
        }
        if (t->data > key)
        {
            f = t;
            p = t->lchild;
            return BST_Search(t->lchild, key, f, p);
        }
        if (t->data < key)
        {
            f = t;
            p = t->rchild;
            return BST_Search(t->rchild, key, f, p);
        }
    }
    else
        return 0;
}
void Insert(bstree &t, int x)
{
    if (t == nullptr)
    {
        t = new BSTNode;
        t->data = x;
        t->lchild = nullptr;
        t->rchild = nullptr;
    }
    else if (t != nullptr && t->data > x)
        Insert(t->lchild, x);
    else if (t != nullptr && t->data < x)
        Insert(t->rchild, x);
}

void CreateBST(bstree &t)
{
    int x;
    bstree f, p;
    bstree q;
    f = nullptr;
    t = nullptr;
    cin >> x;
    while (x != 0)
    {
        if (!BST_Search(t, x, f, p))
            Insert(t, x);
        cin >> x;
    }
}

void InOrder(bstree t)
{
    if (t != nullptr)
    {
        InOrder(t->lchild);
        cout << t->data << " ";
        InOrder(t->rchild);
    }
}
int GetHeight(bstree t)
{
    int l, r;
    if (t != nullptr)
    {
        l = GetHeight(t->lchild);
        r = GetHeight(t->rchild);
        if (l > r)
            return l + 1;
        else
            return r + 1;
    }
    else
        return 0;
}

int Judge(bstree t)
{
    int l, r, b;
    if (t != nullptr)
    {
        l = GetHeight(t->lchild);
        r = GetHeight(t->rchild);
        b = l - r;
        if (abs(b) > 1)
            return 0;
        else
            return 1;
        return Judge(t->lchild) && Judge(t->rchild);
    }
    else
        return 1;
}

int main()
{
    bstree t, f, p;
    f = nullptr;
    CreateBST(t);
    if (Judge(t))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}