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

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        auto *p = new ArcNode;
        p->adjvex = y;
        p->next = G[x].firstarc;
        G[x].firstarc = p;
        u[x]++, v[y]++;
    }

    stack<int> s;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 0)
        {
            s.push(i);
            visit[i] = true;
        }
    }

    int cnt = 0;
    queue<int> q;
    while (!s.empty())
    {
        int x = s.top();
        s.pop();
        q.push(x);
        cnt++;
        for (auto p = G[x].firstarc; p; p = p->next)
        {
            if (!visit[p->adjvex])
            {
                v[p->adjvex]--;
                if (v[p->adjvex] == 0)
                {
                    s.push(p->adjvex);
                    visit[p->adjvex] = true;
                }
            }
        }
    }

    if (cnt < n)
    {
        cerr << "NOT DAG" << endl;
    }
    else
    {
        while (!q.empty())
        {
            cout << "v" << q.front() << " ";
            q.pop();
        }
    }

    return 0;
}