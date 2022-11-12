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

    for (int i = 1; i <= n; i++)
    {
        if (!visit[i])
        {
            visit[i] = true;
            cout << "v" << G[i].data << " " << flush;
            for (auto *p = G[i].firstarc; p != nullptr; p = p->next)
            {
                auto *q = p;
                while (q != nullptr && !visit[q->adjvex])
                {
                    visit[q->adjvex] = true;
                    cout << "v" << G[q->adjvex].data << " " << flush;
                    q = G[q->adjvex].firstarc;
                    while (q != nullptr && visit[q->adjvex])
                    {
                        q = q->next;
                    }
                }
            }
        }
    }

    return 0;
}