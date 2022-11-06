//
// Created by sfc9982 on 2022/10/13.
//

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int coeff;
    int pow;
    struct Node *next;

    Node(int c, int p)
    {
        coeff = c;
        pow = p;
        next = nullptr;
    }
};
void append(struct Node **head_ref, struct Node **tail_ref,
            int new_data, int new_data1)
{
    auto *new_node = new Node(new_data, new_data1);

    if (*head_ref == nullptr)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
void printList(struct Node *head)
{
    struct Node *temp = head;

    while (temp != nullptr)
    {
        printf("%d %d ", temp->coeff, temp->pow);
        temp = temp->next;
    }
}
Node *addPolynomial(Node *p1, Node *p2);
void create_node(int x, int y, struct Node **temp)
{
    struct Node *r, *z;
    z = *temp;
    if (z == nullptr)
    {
        r = new Node(x, y);
        *temp = r;
        r->next = nullptr;
    }
    else
    {
        r->next = new Node(x, y);
        r = r->next;
        r->next = nullptr;
    }
}

class Solution {
public:
    Node *addPolynomial(Node *p1, Node *p2)
    {
        Node *res = new Node(
                0, 0);
        Node *prev = res;
        while (p1 != nullptr and p2 != nullptr)
        {
            if (p1->pow < p2->pow)
            {
                prev->next = p2;
                prev = p2;
                p2 = p2->next;
            }
            else if (p1->pow > p2->pow)
            {
                prev->next = p1;
                prev = p1;
                p1 = p1->next;
            }
            else
            {
                p1->coeff = p1->coeff + p2->coeff;
                prev->next = p1;
                prev = p1;
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        if (p1 != nullptr)
        {
            prev->next = p1;
        }
        if (p2 != nullptr)
        {
            prev->next = p2;
        }
        return res->next;
    }
};

int main()
{
    struct Node *poly1 = nullptr, *poly2 = nullptr, *poly = nullptr;
    struct Node *tail1 = nullptr, *tail2 = nullptr;
    int a, x, T;
    char comma;
    cin >> T;
    while (T--)
    {
        cin >> a >> comma >> x;
        append(&poly1, &tail1, a, x);
    }

    cin >> T;
    while (T--)
    {
        cin >> a >> comma >> x;
        append(&poly2, &tail2, a, x);
    }

    int bucket[1001] = {0};

    Solution obj;
    Node *sum = obj.addPolynomial(poly1, poly2);
    for (Node *ptr = sum; ptr; ptr = ptr->next)
        if (ptr->coeff)
            bucket[ptr->pow] += ptr->coeff;

    for (int i = 0; i <= 1000; ++i)
        if (bucket[i])
            cout << bucket[i] << "*x^" << i << " ";
    cout << endl;
}
