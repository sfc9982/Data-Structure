//
// Created by sfc9982 on 2022/12/1.
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

const int INF = 0x3f3f3f3f;
const int MAXN = 1000;

int n, m;
int G2[MAXN][MAXN], G1[MAXN][MAXN];
int vis2[MAXN], vis1[MAXN];
int sr[MAXN], br[MAXN];
int path[MAXN];

int Dij(int v0)
{
    for (int i = 0; i < n; i++)
    {
        sr[i] = G1[v0][i];
        br[i] = G2[v0][i];
        if (sr[i] < INF)
        {
            path[i] = sr[i];
            sr[i] *= sr[i];
        }
        else
            path[i] = INF;
    }
    vis1[v0] = vis2[v0] = 1;
    while (true)
    {
        int minn = INF, flag = 0, v = -1;
        for (int j = 0; j < n; j++)
        {
            if (!vis2[j] && br[j] < minn)
            {
                flag = 0;
                v = j;
                minn = br[j];
            }
            if (!vis1[j] && sr[j] < minn)
            {
                flag = 1;
                v = j;
                minn = sr[j];
            }
        }
        if (v == -1)
            break;
        if (flag)
            vis1[v] = 1;
        else
            vis2[v] = 1;
        for (int j = 0; j < n; j++)
        {
            if (!vis1[j] && G1[v][j] < INF)
            {
                if (flag)
                {
                    int tmp = sr[v] - path[v] * path[v] + (path[v] + G1[v][j]) * (path[v] + G1[v][j]);
                    if (sr[j] > tmp || (sr[j] == tmp && path[j] > path[v] + G1[v][j]))
                    {
                        sr[j] = tmp;
                        path[j] = path[v] + G1[v][j];
                    }
                }
                else
                {
                    int tmp = br[v] + G1[v][j] * G1[v][j];
                    if (sr[j] > tmp || (sr[j] == tmp && path[j] > G1[v][j]))
                    {
                        sr[j] = tmp;
                        path[j] = G1[v][j];
                    }
                }
            }
            if (!vis2[j] && G2[v][j] < INF)
            {
                if (flag)
                {
                    int tmp = sr[v] + G2[v][j];
                    br[j] = min(tmp, br[j]);
                }
                else
                {
                    int tmp = br[v] + G2[v][j];
                    br[j] = min(tmp, br[j]);
                }
            }
        }
    }
    return min(br[n - 1], sr[n - 1]);
}

int main()
{

    int t, a, b, c;
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                G2[i][j] = G2[j][i] = INF;
                G1[i][j] = G1[j][i] = INF;
            }
        }
        memset(vis1, 0, sizeof(vis1));
        memset(vis2, 0, sizeof(vis2));
        for (int i = 0; i < m; i++)
        {
            cin >> t >> a >> b >> c;
            a--, b--;
            if (t == 1)
                G1[a][b] = G1[b][a] = min(c, G1[a][b]);
            else
                G2[a][b] = G2[b][a] = min(c, G2[a][b]);
        }
        cout << Dij(0) << endl;
    }

    return 0;
}

//6 7
//1 1 2 3
//1 2 3 2
//0 1 3 30
//0 3 4 20
//0 4 5 30
//1 3 5 6
//1 5 6 1