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

int arr[100];
int ans[100][2];

int main()
{
    int n;
    int tmp, count;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
        {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
        }
    }
    ans[0][0] = arr[0];
    ans[0][1] = 1;
    count = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == ans[count][0])
        {
            ans[count][1]++;
        }
        else
        {
            count++;
            ans[count][0] = arr[i];
            ans[count][1] = 1;
        }
    }
    for (int i = 1; i <= count; i++)
    {
        for (int j = i; j > 0 && ans[j][1] > ans[j - 1][1]; j--)
        {
            tmp = ans[j][0];
            ans[j][0] = ans[j - 1][0];
            ans[j - 1][0] = tmp;
            tmp = ans[j][1];
            ans[j][1] = ans[j - 1][1];
            ans[j - 1][1] = tmp;
        }
    }
    for (int i = 0; i <= count; i++)
    {
        printf("%d %d", ans[i][0], ans[i][1]);
        printf("\n");
    }
    return 0;
}
