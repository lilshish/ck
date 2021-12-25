#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

// #define N 9

int main()
{
    int arr[9] = {88, 112, 6467, 325, 878, 3, 77, 8, 99};

    for (int i = 0; i < 9 ; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    int arr1[4] = {2, 5, 2, 2};
    int arr2[4] = {1, 2, 0, 1};

    printf("%d %d\n%d %d\n",
           arr1[0] * arr2[0] + arr1[1] * arr2[2],
           arr1[0] * arr2[1] +arr1[1] * arr2[3],
           arr1[2] * arr2[0] + arr1[3] * arr2[2],
           arr1[2] * arr2[1] + arr1[3] * arr2[3]);
    return 0;
}
