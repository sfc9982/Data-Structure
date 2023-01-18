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
    if (t == nullptr)
    {
        f = nullptr;
        p = nullptr;
        return 0;
    }
    p = t;
    while (p != nullptr)
    {
        if (p->data == key)
        {
            return 1;
        }
        else if (p->data > key)
        {
            f = p;
            p = p->lchild;
        }
        else if (p->data < key)
        {
            f = p;
            p = p->rchild;
        }
    }
    return 0;
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

void CreateBST(bstree &t)
{
    bstree p, f, q;
    int x;
    f = nullptr;
    cin >> x;
    if (!BST_Search(t, x, f, q))
    {
        p = new BSTNode;
        p->data = x;
        p->lchild = nullptr;
        p->rchild = nullptr;
        t = p;
    }
    else
    {
        return;
    }
    cin >> x;
    while (x != 0)
    {
        p = new BSTNode;
        p->data = x;
        p->lchild = nullptr;
        p->rchild = nullptr;
        if (!BST_Search(t, x, f, q))
        {
            if (f != nullptr)
            {
                if (f->data > x)
                {
                    f->lchild = p;
                }
                else
                {
                    f->rchild = p;
                }
            }
        }
        else
        {
            break;
        }
        cin >> x;
    }
}

void out_large_x(bstree t, int x)
{
    bstree f, p;
    f = nullptr;
    if (BST_Search(t, x, f, p))
    {
        if (f->lchild == p)
        {
            cout << p->data << " ";
            InOrder(p->rchild);
            cout << f->data << " ";
        }
        else
        {
            cout << p->data << " ";
            InOrder(p->rchild);
        }
    }
}

int main()
{
    bstree t, f, p;
    int x;
    t = nullptr;
    f = nullptr;
    CreateBST(t);
    cin >> x;
    out_large_x(t, x);
    cout << endl;
    return EXIT_SUCCESS;
}
