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

char str[100][100];
char s[1000];

int main()
{

    int n;
    char *p[10];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> str[i];
    for (int i = 0; i < n; i++)
        p[i] = str[i];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(p[j], p[j + 1]) >= 0)
            {
                strcpy(s, p[j]);
                strcpy(p[j], p[j + 1]);
                strcpy(p[j + 1], s);
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << p[i] << endl;
    return 0;
}