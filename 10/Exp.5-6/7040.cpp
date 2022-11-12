//
// Created by sfc9982 on 2022/11/12.
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

using VertexType = int;

const int MAXNODE = 100;

typedef struct Node {
    int adjvex;
    struct Node *next;
} ArcNode;

typedef struct VNode {
    VertexType data;
    ArcNode *firstarc;
} VertexNode;

VertexNode G[MAXNODE];

int u[MAXNODE], v[MAXNODE];

int main()
{
    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> G[i].data;
        G[i].firstarc = nullptr;
    }

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        auto *p = new ArcNode;
        p->adjvex = y;
        p->next = G[y].firstarc;
        G[x].firstarc = p;
        u[x]++, v[y]++;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << G[i].data << ":" << v[i] << " " << u[i] << " " << u[i] + v[i] << endl;
    }

    return 0;
}