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
    int n;
    LinkList *q;
    for (auto p = head; cin >> n && n; p = q)
    {
        q = new LinkList;
        q->data = n;
        q->next = nullptr;
        p->next = q;
    }
    for (auto p = head->next; p; p = p->next)
        cout << p->data << " ";
    return 0;
}