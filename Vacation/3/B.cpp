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
        p = (ArcNode *) malloc(sizeof(ArcNode));
        p->adjvex = v1;
        p->next = G[v2].firstarc;
        G[v2].firstarc = p;
    }
}

void DFS(VerNode G[MAXNODE], int v, int &vn, int &en)
{
    ArcNode *p;
    visited[v] = 1;
    vn++;
    p = G[v].firstarc;
    while (p != nullptr)
    {
        en++;
        if (visited[p->adjvex] == 0)
            DFS(G, p->adjvex, vn, en);
        p = p->next;
    }
}

int ValidTree(VerNode G[MAXNODE])
{
    int vn = 0, en = 0, i;
    for (i = 1; i <= vexnum; i++)
        visited[i] = 0;
    DFS(G, 1, vn, en);
    if (vn == vexnum && en == 2 * (vexnum - 1))
        return 1;
    else
        return 0;
}

int main()
{
    int k;
    VerNode G[MAXNODE];
    CreatAdjList(G);
    k = ValidTree(G);
    cout << k << endl;
    return EXIT_SUCCESS;
}
