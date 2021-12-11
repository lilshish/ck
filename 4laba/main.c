#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    scanf ("%d", &a);
    printf ((a >= 1000) && (a <= 10000)? "true\n" : "false\n");

    int b;
    scanf("%o", &b);
    printf("%d", ((b>>23)%2) == 1 ? 1:0);
}


