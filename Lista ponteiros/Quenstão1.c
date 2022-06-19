#include <stdio.h>

int main()
{
    int x, y, *p;
    y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    (*p) += x;
    printf("%d ",y);
}
