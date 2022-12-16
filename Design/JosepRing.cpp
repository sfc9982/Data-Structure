//
// Created by sfc9982 on 2022/12/7.
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

typedef struct LNode {
    int data;
    int psw;
    struct LNode *next;
} LNode, *LinkedList;

void createL(LinkedList &l, int num)
{
    LinkedList cur = l;
    for (int i = 1; i <= num; i++)
    {
        if (i == 1)
        {
            l->data = i;
            l->next = l;
        }
        else
        {
            auto tempL = new LNode;
            tempL->data = i;
            tempL->next = l;
            cur->next = tempL;
            cur = cur->next;
        }
    }
}

void PrintMsg(LinkedList &l)
{
    LinkedList cur = l;
    while (true)
    {
        cout << cur->data << endl;
        cur = cur->next;
        if (cur == l)
            break;
    }
}

void Josephu(LinkedList l, int startNo, int countNum)
{
    LinkedList nowCur;
    LinkedList preCur = l;
    while (true)
    {
        preCur = preCur->next;
        if (preCur->next == l)
            break;
    }
    for (int i = 0; i < startNo - 1; i++)
    {
        preCur = preCur->next;
    }
    nowCur = preCur->next;
    while (true)
    {
        for (int i = 0; i < countNum - 1; i++)
        {
            nowCur = nowCur->next;
            preCur = preCur->next;
        }
        cout << "处决：" << nowCur->data << endl;
        preCur->next = nowCur->next;
        nowCur = preCur->next;
        if (preCur == nowCur)
        {
            cout << "存活：" << nowCur->data << endl;
            break;
        }
    }
}

void Josephu(LinkedList l, int countNum)
{
    LinkedList nowCur;
    LinkedList preCur = l;
    while (true)
    {
        preCur = preCur->next;
        if (preCur->next == l)
            break;
    }
    nowCur = preCur->next;
    while (true)
    {
        for (int i = 0; i < countNum - 1; i++)
        {
            nowCur = nowCur->next;
            preCur = preCur->next;
        }
        cout << "处决：" << nowCur->data << endl;
        countNum = nowCur->psw;
        preCur->next = nowCur->next;
        nowCur = preCur->next;
        if (preCur == nowCur)
        {
            cout << "存活：" << nowCur->data << endl;
            break;
        }
    }
}

void inputPssd(LinkedList &l)
{
    LinkedList cur = l;
    while (true)
    {
        int i = 0;
        //        cout << "Please input the password:";
        cin >> i;
        cur->psw = i;
        cur = cur->next;
        if (cur == l)
            break;
    }
}

int main()
{
    LinkedList l = new LNode;
    int n;
    cout << "Joseph环内人数：";
    cin >> n;
    createL(l, n);
    inputPssd(l);
    Josephu(l, 20);
    //7
    //3 1 7 2 4 7 4
    return 0;
}