//
// Created by sfc9982 on 2022/11/24.
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

typedef struct BSTNode {
    int key;
    struct BSTNode *left, *right;
} BSTNode, *BSTree;

BSTNode *pre = nullptr;

void InOrder(BSTree t)
{
    if (t)
    {
        InOrder(t->left);
        cout << t->key << " ";
        InOrder(t->right);
    }
}

void InsertBST(BSTree &t, int e)
{
    if (!t)
    {
        BSTree S = new BSTNode;
        S->key = e;
        S->left = S->right = nullptr;
        t = S;
    }
    else if (e < t->key)
    {
        InsertBST(t->left, e);
    }
    else
    {
        InsertBST(t->right, e);
    }
}
void CreateBST(BSTree &t)
{
    t = nullptr;
    int x;
    while (cin >> x, x)
    {
        InsertBST(t, x);
    }
}

void DeleteBST(BSTree &t, int del)
{
    BSTree p = t, fa = nullptr;
    while (p)
    {
        if (p->key == del)
            break;
        fa = p;
        if (p->key > del)
            p = p->left;
        else
            p = p->right;
    }
    if (!p)
        return;
    BSTree q = p;
    if (p->left && p->right)
    {
        BSTree s = p->left;
        while (s->right)
        {
            q = s;
            s = s->right;
        }
        p->key = s->key;
        if (q != p)
            q->right = s->left;
        else
            q->left = s->left;
        delete s;
        return;
    }
    else if (!p->right)
    {
        p = p->left;
    }
    else if (!p->left)
    {
        p = p->right;
    }

    if (!fa)
        t = p;
    else if (q == fa->left)
        fa->left = p;
    else
        fa->right = p;
    delete q;
}

BSTree SearchBST(BSTree t, int e)
{
    if (!t || t->key == e)
        return t;
    else if (e < t->key)
        return SearchBST(t->left, e);
    else
        return SearchBST(t->right, e);
}

int main()
{
    BSTree t;
    CreateBST(t);
    InOrder(t);
    puts("");
    int find;
    cin >> find;
    if (SearchBST(t, find) != nullptr)
        puts("该数存在");
    else
        puts("该数不存在");
    int del;
    cin >> del;
    DeleteBST(t, del);
    InOrder(t);
    return 0;
}