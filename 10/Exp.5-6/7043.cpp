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

bool visit[MAXNODE];

void bfs(int v)
{
    queue<int> q;
    q.push(v);
    visit[v] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << "v" << u << " ";
        ArcNode *p = G[u].firstarc;
        while (p != nullptr)
        {
            if (!visit[p->adjvex])
            {
                visit[p->adjvex] = true;
                q.push(p->adjvex);
            }
            p = p->next;
        }
    }
}

int main()
{
    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> G[i].data;
        G[i].firstarc = nullptr;
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        auto *p = new ArcNode;
        p->adjvex = y;
        p->next = G[x].firstarc;
        G[x].firstarc = p;
        auto *q = new ArcNode;
        q->adjvex = x;
        q->next = G[y].firstarc;
        G[y].firstarc = q;
    }

    bfs(1);

    return 0;
}