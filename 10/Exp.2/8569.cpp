//
// Created by sfc9982 on 2022/10/17.
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

#define op_left_assoc(c) (c == '+' || c == '-' || c == '/' || c == '*' || c == '%')
#define is_operator(c) (c == '+' || c == '-' || c == '/' || c == '*' || c == '!' || c == '%' || c == '=')
#define is_function(c) (c >= 'A' && c <= 'Z')
#define is_ident(c) ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'))

int op_preced(const char c)
{
    switch (c)
    {
        case '!':
            return 4;
        case '*':
        case '/':
        case '%':
            return 3;
        case '+':
        case '-':
            return 2;
        case '=':
            return 1;
    }
    return 0;
}

unsigned int op_arg_count(const char c)
{
    switch (c)
    {
        case '*':
        case '/':
        case '%':
        case '+':
        case '-':
        case '=':
            return 2;
        case '!':
            return 1;
        default:
            return c - 'A';
    }
    return 0;
}

bool shunting_yard(const char *input, char *output)
{
    const char *strpos = input, *strend = input + strlen(input);
    char c, stack[32], sc, *outpos = output;
    unsigned int sl = 0;
    while (strpos < strend)
    {
        c = *strpos;
        if (c != ' ')
        {
            if (c == '(')
            {
                stack[sl] = c;
                ++sl;
            }
            else if (is_ident(c))
            {
                *outpos = c;
                ++outpos;
            }
            else if (is_function(c))
            {
                stack[sl] = c;
                ++sl;
            }
            else if (c == ',')
            {
                bool pe = false;
                while (sl > 0)
                {
                    sc = stack[sl - 1];
                    if (sc == '(')
                    {
                        pe = true;
                        break;
                    }
                    else
                    {
                        *outpos = sc;
                        ++outpos;
                        sl--;
                    }
                }
                if (!pe)
                {
                    printf("Error: separator or parentheses mismatched\n");
                    return false;
                }
            }
            else if (is_operator(c))
            {
                while (sl > 0)
                {
                    sc = stack[sl - 1];
                    if (is_operator(sc) && ((op_left_assoc(c) && (op_preced(c) <= op_preced(sc))) ||
                                            (!op_left_assoc(c) && (op_preced(c) < op_preced(sc)))))
                    {
                        *outpos = sc;
                        ++outpos;
                        sl--;
                    }
                    else
                    {
                        break;
                    }
                }
                stack[sl] = c;
                ++sl;
            }

            else if (c == ')')
            {
                bool pe = false;
                while (sl > 0)
                {
                    sc = stack[sl - 1];
                    if (sc == '(')
                    {
                        pe = true;
                        break;
                    }
                    else
                    {
                        *outpos = sc;
                        ++outpos;
                        sl--;
                    }
                }
                sl--;
                if (sl > 0)
                {
                    sc = stack[sl - 1];
                    if (is_function(sc))
                    {
                        *outpos = sc;
                        ++outpos;
                        sl--;
                    }
                }
            }
        }
        ++strpos;
    }
    while (sl > 0)
    {
        sc = stack[sl - 1];
        *outpos = sc;
        ++outpos;
        --sl;
    }
    *outpos = 0;
    return true;
}

int main()
{
    char input[256], output[256];
    cin >> input;
    //    printf("input: %s\n", input);
    shunting_yard(input, output);
    //    printf("output: %s\n", output);
    stack<char> op;
    stack<int> val;
    for (int i = 0; i < strlen(output); ++i)
    {
        if (is_ident(output[i]))
        {
            val.push(output[i] - '0');
        }
        else if (is_operator(output[i]))
        {
            int a = val.top();
            val.pop();
            int b = val.top();
            val.pop();
            if (output[i] == '+')
                val.push(b + a);
            else if (output[i] == '-')
                val.push(b - a);
            else if (output[i] == '*')
                val.push(b * a);
            else if (output[i] == '/')
                val.push(b / a);
        }
    }
    cout << val.top() << endl;
    return 0;
}