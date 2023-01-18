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

struct BiNode {
    char data;
    struct BiNode *lchild, *rchild;
};

using BiTNode = struct BiNode;
using BiTree = struct BiNode *;

void CreateBiTree(BiTree &T)
{
    char ch;
    cin >> ch;
    if (ch == '#')
        T = nullptr;
    else
    {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

int Depth(BiTree T)
{
    if (T == nullptr)
        return (0);
    return 1 + (Depth(T->lchild) > Depth(T->rchild) ? Depth(T->lchild) : Depth(T->rchild));
}

void PrintLongestPath(BiTree T)
{
    if (T != nullptr)
    {
        cout << T->data << " ";
        if (Depth(T->lchild) > Depth(T->rchild))
            PrintLongestPath(T->lchild);
        else
            PrintLongestPath(T->rchild);
    }
}

int main()
{
    BiTree tree;
    CreateBiTree(tree);
    cout << "二叉树中第一条最长的路径:";
    PrintLongestPath(tree);
    cout << endl;
    return EXIT_SUCCESS;
}