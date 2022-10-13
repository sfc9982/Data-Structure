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
    head->data = -0x3f3f3f3f;
    head->next = nullptr;
    int n;
    LinkList *p, *q, *r;

    while (cin >> n && n)
    {
        q = new LinkList;
        q->data = n;
        q->next = nullptr;
        for (r = head; r; r = r->next)
        {
            if (r->next && r->data <= n && r->next->data > n)
            {
                q->next = r->next;
                r->next = q;
                break;
            }
            else if (r->next == nullptr)
            {
                r->next = q;
                q->next = nullptr;
                break;
            }
        }
    }
    for (p = head->next; p; p = p->next)
        cout << p->data << " ";
    return 0;
}