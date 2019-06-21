#include <stdio.h>
#include <stdlib.h>

int *B;
void merge(int A[], int low, int mid, int high, int len)
{

    // int B[len];
    for (int i = low; i <= high; i++)
    {
        B[i] = A[i];
    }

    int i = low, j = mid + 1, k = low;
    for (; i <= mid && j <= high;)
    {
        if (B[i] <= B[j])
        {
            A[k++] = B[i++];
        }
        else
        {
            A[k++] = B[j++];
        }
    }

    while (i <= mid)
    {
        A[k++] = B[i++];
    }
    while (j <= high)
    {
        A[k++] = B[j++];
    }
}

void merge_sort(int A[], int low, int high, int len)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(A, low, mid, len);
        merge_sort(A, mid + 1, high, len);
        merge(A, low, mid, high, len);
    }
}

int main()
{
    int A[] = {5, 3, 4, 1, 2, 6, 9, 8, 7, 10};
    int len = sizeof(A) / sizeof(A[0]);
    B = (int *)malloc(len * sizeof(int));

    merge_sort(A, 0, len - 1, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", A[i]);
    }
    return 0;
}