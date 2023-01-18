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

const size_t MAXNODE = 64;

struct ArcNode {
    int adjvex;
    struct ArcNode *next;
};

struct VerNode {
    int data;
    ArcNode *firstarc;
};

using ArcNode = struct ArcNode;
using VerNode = struct VerNode;

int vexnum, arcnum;
int visited[MAXNODE];

void CreatAdjList(VerNode G[MAXNODE])
{
    int n, m = 0;
    ArcNode *p, *q;
    int i, v1, v2;
    cin >> n >> m;
    vexnum = n;
    arcnum = m;
    getchar();
    for (i = 1; i <= n; i++)
    {
        cin >> i;
        G[i].data = i;
        G[i].firstarc = nullptr;
        visited[i] = 0;
    }
    for (i = 1; i <= m; i++)
    {
        cin >> v1 >> v2;
        p = (ArcNode *) malloc(sizeof(ArcNode));
        p->adjvex = v2;
        p->next = G[v1].firstarc;
        G[v1].firstarc = p;
    }
}

void FindPath(VerNode G[MAXNODE], int u, int v, int path[], int d)
{
    int w, i;
    ArcNode *p;
    d++;
    path[d] = u;
    visited[u] = 1;
    if (u == v)
    {
        for (i = 0; i <= d; i++)
            cout << path[i] << " ";
        cout << endl;
    }
    p = G[u].firstarc;
    while (p != nullptr)
    {
        w = p->adjvex;
        if (visited[w] == 0)
            FindPath(G, w, v, path, d);
        p = p->next;
    }
    visited[u] = 0;
}

int main()
{
    int k, u, v;
    int path[MAXNODE];
    VerNode G[MAXNODE];
    CreatAdjList(G);
    cin >> u >> v;
    FindPath(G, u, v, path, -1);
    return 0;
}