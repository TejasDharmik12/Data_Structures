#include <stdio.h>

void printNGI(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int next = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                next = arr[j];
                break;
            }
        }
        printf("%d--%d", arr[i], next);
    }
}

int main()
{
    int arr[] = {3, 5, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNGI(arr, n);
    return 0;
}