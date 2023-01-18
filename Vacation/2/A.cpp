//
// Created by sfc9982 on 2023/1/11.
//

#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

const size_t MAXSZ = 100;

using ElemType = char;

struct tnode {
    ElemType data;
    struct tnode *lchild, *rchild;
};

using BTNode = struct tnode;

void CreateBTree(BTNode *&bt, string str)
{
    BTNode *St[MAXSZ], *p = nullptr;
    int top = -1, k, j = 0;
    char ch;
    bt = nullptr;
    ch = str[static_cast<size_t>(j)];
    while (ch != '\0')
    {
        switch (ch)
        {
            case '(':
                top++;
                St[top] = p;
                k = 1;
                break;
            case ')':
                top--;
                break;
            case ',':
                k = 2;
                break;
            default:
                p = (BTNode *) malloc(sizeof(BTNode));
                p->data = ch;
                p->lchild = p->rchild = nullptr;
                if (bt == nullptr)
                    bt = p;
                else
                {
                    switch (k)
                    {
                        case 1:
                            St[top]->lchild = p;
                            break;
                        case 2:
                            St[top]->rchild = p;
                            break;
                        default:
                            break;
                    }
                }
        }
        j++;
        ch = str[static_cast<size_t>(j)];
    }
}

void InOrderWithBracket(BTNode *bt)
{
    if (bt != nullptr)
    {
        InOrderWithBracket(bt->lchild);
        cout << bt->data << " ";
        InOrderWithBracket(bt->rchild);
    }
}


int main()
{
    string s;
    cin >> s;
    BTNode *bt;
    CreateBTree(bt, s);
    cout << "二叉树中序遍历:";
    InOrderWithBracket(bt);
    cout << endl;
    return EXIT_SUCCESS;
}