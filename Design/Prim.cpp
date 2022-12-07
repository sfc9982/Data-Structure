//
// Created by sfc9982 on 2022/12/7.
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

int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
}

#define inf 0x3f3f3f3f
#define maxn 5005
#define maxm 200005

struct edge {
    int v, w, next;
} e[maxm << 1];

int head[maxn], dis[maxn], cnt, n, m, tot, now = 1, ans;

bool vis[maxn];

void add(int u, int v, int w)
{
    e[++cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void init()
{
    n = read(), m = read();
    for (int i = 1, u, v, w; i <= m; ++i)
    {
        u = read(), v = read(), w = read();
        add(u, v, w), add(v, u, w);
    }
}
int prim()
{
    for (int i = 2; i <= n; ++i)
    {
        dis[i] = inf;
    }
    for (int i = head[1]; i; i = e[i].next)
    {
        dis[e[i].v] = min(dis[e[i].v], e[i].w);
    }
    while (++tot < n)
    {
        int minn = inf;
        vis[now] = true;
        for (int i = 1; i <= n; ++i)
        {
            if (!vis[i] && minn > dis[i])
            {
                minn = dis[i];
                now = i;
            }
        }
        cout << minn << " ";
        ans += minn;
        for (int i = head[now]; i; i = e[i].next)
        {
            int v = e[i].v;
            if (dis[v] > e[i].w && !vis[v])
            {
                dis[v] = e[i].w;
            }
        }
    }
    return ans;
}
int main()
{
    init();
    printf("%d", prim());
    //4 5
    //1 2 2
    //1 3 2
    //1 4 3
    //2 3 4
    //3 4 3
    return 0;
}