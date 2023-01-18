//
// Created by sfc9982 on 2023/1/17.
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

struct StructHash {
    int key;
    char *otherInfo;
};

using Record = struct StructHash;
using hashtable = struct StructHash *;

int max_prime(int m)
{
    int i, j, t;
    t = 0;
    for (i = m; i > 1; i--)
    {
        for (j = 2; j <= i - 1; j++)
            if (i % j == 0)
            {
                t = 1;
                break;
            }
        if (t == 0)
            return i;
        t = 0;
    }
}

int hash_address(int key, int p)
{
    return key % p;
}

void create_hash(hashtable &ht, int m, int p)
{
    int key, adress, newadress;
    int k;
    ht = (Record *) malloc(m * sizeof(Record));
    for (int i = 0; i < m; i++)
        ht[i].key = -1;
    cin >> key;
    while (key)
    {
        adress = hash_address(key, p);
        if (ht[adress].key == -1)
            ht[adress].key = key;
        else
        {
            k = 1;
            newadress = (adress + k) % m;
            while (ht[newadress].key != -1 && k < m - 1)
            {
                k++;
                newadress = (adress + k) % m;
            }
            ht[newadress].key = key;
        }
        cin >> key;
    }
}

void Print(hashtable ht, int m)
{
    int i;
    for (i = 0; i < m; i++)
        printf("%d  ", i);
    printf("\n");
    for (i = 0; i < m; i++)
        printf("%d  ", ht[i].key);
    printf("\n");
}

int ht_serch(hashtable ht, int key, int m, int p, int &address, int &current)
{
    int new_address;
    int k, flag;
    flag = 0;
    address = hash_address(key, p);
    new_address = address;
    k = 1;
    while (ht[new_address].key != key && new_address != m - 1)
    {
        new_address = (address + k) % m;
        k++;
    }
    if (ht[new_address].key == key)
    {
        flag = 1;
        current = new_address;
    }
    return flag;
}

void ht_delete(hashtable ht, int key, int m, int p)
{
    int address, new_address, current;
    int i, j, k, flag, d;
    flag = ht_serch(ht, key, m, p, address, current);
    if (flag)
    {
        ht[current].key = -1;
        i = current + 1;
        while (i < m && ht[i].key != -1)
        {
            d = hash_address(ht[i].key, p);
            if (i == d)
            {
                i++;
                continue;
            }
            else if (d == address)
            {
                ht[current] = ht[i];
                current++;
                ht[i].key = -1;
            }
            else if (d < address)
            {
                ht[current] = ht[i];
                current++;
                ht[i].key = -1;
            }
            else if (d < current)
            {
                ht[current] = ht[i];
                current++;
                ht[i].key = -1;
            }
            i++;
        }
    }
    else
    {
        printf("%s\n", "No");
    }
}

int main()
{
    int m;
    int p, n;
    hashtable ht;
    cin >> m;
    p = max_prime(m);
    create_hash(ht, m, p);
    printf("建立的哈希表如下：\n");
    Print(ht, m);
    scanf("%d", &n);
    ht_delete(ht, n, m, p);
    printf("%s%d%s\n", "删除关键字", n, "后的哈希表如下：");
    Print(ht, m);
    return 0;
}