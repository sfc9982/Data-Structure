//
// Created by sfc9982 on 2022/10/16.
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
    int n;
    auto head = new LinkList;
    LinkList *p, *q;
    q = head;
    while (cin >> n && n)
    {
        p = new LinkList;
        p->next = nullptr;
        p->data = n;
        q->next = p;
        q = p;
    }
    auto head1 = new LinkList, head2 = new LinkList;
    head1->next = head2->next = nullptr;
    auto *p1 = head1, *p2 = head2;
    for (p = head->next; p; p = p->next)
    {
        if (p->data % 2)
        {
            p1->next = p;
            p1 = p;
        }
        else
        {
            p2->next = p;
            p2 = p;
        }
    }
    p1->next = p2->next = nullptr;
    for (p = head1->next; p; p = p->next)
        cout << p->data << " ";
    cout << endl;
    for (p = head2->next; p; p = p->next)
        cout << p->data << " ";
    cout << flush;
    return 0;
}