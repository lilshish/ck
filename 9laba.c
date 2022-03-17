#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int numbers = 0;
    int upper = 0;
    int lower = 0;
    char str[1000];
    gets(str);
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            numbers++;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            upper++;
        }
        else if (str[i] >= 'a' && str[i] <= 'z') {
            lower++;
        }
    }
    printf("Lower: %d, upper: %d, numbers: %d \n", lower, upper, numbers);

    int k;
    scanf("%d", &k);
    bool flag;
    for(int i = 2; i <= k; i++){
        flag = true;
        for(int j = 2; j < i; j++){
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if(flag)
            printf("%d ",i);
    }

}
