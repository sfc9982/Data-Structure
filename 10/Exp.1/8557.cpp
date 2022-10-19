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
    int n;
    auto *head1 = new LinkList;
    auto *head2 = new LinkList;
    LinkList *q, *r;
    LinkList *p = head1;
    while (cin >> n && n)
    {
        auto *node = new LinkList;
        node->data = n;
        p->next = node;
        p = node;
    }
    p->next = nullptr;
    p = head2;
    while (cin >> n && n)
    {
        auto *node = new LinkList;
        node->data = n;
        p->next = node;
        p = node;
    }
    p->next = nullptr;
    auto *head = new LinkList;
    p = head;
    auto *p1 = head1->next;
    auto *p2 = head2->next;
    while (p1 && p2)
    {
        if (p1->data < p2->data)
        {
            p->next = p1;
            p1 = p1->next;
        }
        else
        {
            p->next = p2;
            p2 = p2->next;
        }
        p = p->next;
    }
    if (p1)
        p->next = p1;
    else
        p->next = p2;
    for (r = nullptr, p = head->next; p; r = p, p = q)
    {
        q = p->next;
        p->next = r;
    }
    head->next = r;


    for (bool order = false; !order;)
    {
        order = true;
        for (p = head; p->next->next; p = p->next)
        {
            if (p->next->next->data > p->next->data)
            {
                r = p->next->next->next;
                p->next->next->next = p->next;
                p->next = p->next->next;
                p->next->next->next = r;
                order = false;
            }
        }
    }

    for (p = head->next; p; p = p->next)
        cout << p->data << " ";
    return 0;
}