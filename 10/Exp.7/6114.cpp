//
// Created by sfc9982 on 2022/11/24.
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

const int N = 15;

vector<int> HashTable(N, 0);

inline int Hash(const int &key)
{
    return key % 13;
}

void Print()
{
    for (auto it = HashTable.begin(); it != HashTable.end(); it++)
    {
        cout << it - HashTable.begin() << " ";
        if (*it == 0)
            cout << "-1";
        else
            cout << *it;
        cout << endl;
    }
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        int h = Hash(n);
        while (HashTable[h] != 0)
        {
            h = (h + 1) % 13;
        }
        HashTable[h] = n;
    }
    Print();

    return 0;
}