//
// Created by sfc9982 on 2022/10/13.
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

struct LinkList {
    int data;
    LinkList *next;
};

int main()
{
    auto head = new LinkList;
    head->next = nullptr;
    LinkList *p, *q;
    int n;
    for (p = head; cin >> n && n; p = q)
    {
        q = new LinkList;
        q->data = n;
        q->next = nullptr;
        p->next = q;
    }
    for (p = head; p->next;)
    {
        q = p->next;
        while (q && q->data % 2 == 0)
        {
            q = q->next;
        }
        p->next = q;
        if (p->next)
            p = p->next;
    }
    for (p = head->next; p; p = p->next)
        cout << p->data << " ";
    return 0;
}