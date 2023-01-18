#include <cstdio>

int main()
{
    int i, j;
    char str[] = "\4\63\162";
    i = 0;
    j = 3;
    while (j --> 0)
    {
        printf("%d", (i | j)[str]);
    }
    return 0;
}
