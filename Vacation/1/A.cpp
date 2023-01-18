//
// Created by sfc9982 on 2023/1/11.
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

using ElemType = char;

typedef struct node {
    ElemType data;
    struct node *lchild, *rchild;
} BiNode, *BiTree;

void CreateTree(BiTree &t)
{
    ElemType ch;
    scanf("%c", &ch);
    if (ch == '#')
        t = nullptr;
    else
    {
        t = new BiNode;
        t->data = ch;
        CreateTree(t->lchild);
        CreateTree(t->rchild);
    }
}

int tag = 1;

void Judge(BiTree t)
{
    if (t)
    {
        if ((t->lchild && !t->rchild) || (!t->lchild && t->rchild))
            tag = 0;
        Judge(t->lchild);
        Judge(t->rchild);
    }
}

int main()
{
    BiTree t;
    int n;
    CreateTree(t);
    Judge(t);
    if (tag == 1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}