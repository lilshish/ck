#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    scanf("%d", &a); // 1

    printf ("%x\n", a); // 2

    printf ("%o\n", a >> 3); // 3

    printf ("%o\n", ~a);

    scanf("%o", &b);
    printf ("%o\n", (b || a));
}
