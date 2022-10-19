//
// Created by sfc9982 on 2022/10/16.
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

const int maxSize = 1000;

typedef struct stack {
    int array[maxSize];
    int top;
    int bottom;
} Stack;

int a, b;

Stack Init(void);
void Push(Stack *S, int num);
int Pop(Stack *S);
void Treaverse(Stack *S, char *info);

void Change(int num, int w, Stack *S);

int main()
{
    Stack S = Init();
    cin >> a >> b;
    Change(a, b, &S);
    return 0;
}

Stack Init(void)
{
    Stack S;
    S.top = S.bottom = -1;
    return S;
}
void Push(Stack *S, int num)
{
    if (S->top == maxSize - 1)
    {
        printf("full\n");
        return;
    }
    S->top++;
    S->array[S->top] = num;
}
int Pop(Stack *S)
{
    int num;
    if (S->top == S->bottom)
    {
        printf("empty\n");
        return -1;
    }
    num = S->array[S->top];
    S->top--;
    return num;
}
void Treaverse(Stack *S, char *info)
{
    if (S->top == S->bottom)
        return;
    printf("%s", info);
    while (S->top != S->bottom)
    {
        printf("%d", S->array[S->top]);
        S->top--;
    }
    printf("(%d)\n", b);
}

void Change(int num, int w, Stack *S)
{
    int div, remain, n = num;
    char info[50] = "";
    while (1)
    {
        div = n / w;
        remain = n % w;
        if (div != 0)
        {
            //余数入栈,更新num
            Push(S, remain);
            n = div;
        }
        else
        {
            Push(S, remain);
            break;
        }
    }
    sprintf(info, "%d(10)=", num);
    Treaverse(S, info);
}