//
// Created by sfc9982 on 2022/11/20.
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

int main()
{
    string s, t;
    cin >> s >> t;


    int len1 = s.length(), len2 = t.length();
    int maxx = 0, index = 0;
    int **dp = new int *[len1];
    for (int i = 0; i < len1; i++)
    {
        dp[i] = new int[len2];
    }
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (s[i] == t[j])
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
            if (dp[i][j] > maxx)
            {
                maxx = dp[i][j];
                index = i;
            }
        }
    }
    cout << s.substr(index - maxx + 1, maxx);
    cout.flush();

    return 0;
}