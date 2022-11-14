//
// Created by sfc9982 on 2022/11/14.
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

const int MAXN = 13;

typedef struct LinkList {
    int data;
    LinkList *next;
} * HashList, List;

typedef struct HashTable {
    HashList head;
    int length;

    HashTable()
    {
        head = new List;
        head->next = nullptr;
        length = 0;
    }
} * Link;

auto a = new HashTable[MAXN];

inline int Hash(const int &key)
{
    return key % 13;
}

void Insert(const int &key)
{
    int h = Hash(key);
    auto *p = new List;
    p->data = key;
    p->next = a[h].head;
    a[h].head = p;
    a[h].length++;
}

void Print()
{
    for (int i = 0; i < 13; i++)
    {
        cout << i << ":";
        List *p = a[i].head;
        // while (p->next != nullptr)
        for (int j = 0; j < a[i].length; j++)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        Insert(n);
    }
    Print();

    return 0;
}