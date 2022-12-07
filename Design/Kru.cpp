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

const int N = 100010, M = 200010, INF = 0x3f3f3f3f;

int p[N];
int n, m, w;

struct edge {
    int a, b, w;
    bool operator<(const edge &W) const
    {
        return w < W.w;
    }
} edges[M];

int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{
    int res = 0, cnt = 0;
    sort(edges, edges + m);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (int i = 0; i < m; i++)
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b)
        {
            cnt++;
            cout << w << " ";
            res += w;
            p[a] = b;
        }
    }
    if (cnt < n - 1)
        return INF;
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i].a = a, edges[i].b = b, edges[i].w = w;
    }
    int t = kruskal();
    if (t == INF)
        printf("orz\n");
    else
        printf("%d\n", t);
    //4 5
    //1 2 2
    //1 3 2
    //1 4 3
    //2 3 4
    //3 4 3

    return 0;
}