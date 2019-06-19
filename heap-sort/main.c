#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void AdjustDown(int A[], int k, int len)
{
    A[0] = A[k];
    for (int i = k * 2; i <= len; i *= 2)
    {
        if (i < len && A[i] < A[i + 1])
        {
            i++;
        }
        if (A[0] > A[i])
        {
            break;
        }
        else
        {
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}

void BuildMaxHeap(int A[], int len)
{
    for (int i = len / 2; i > 0; i--)
    {
        AdjustDown(A, i, len);
    }
}

void HeapSort(int A[], int len)
{
    BuildMaxHeap(A, len);

    for (int i = len; i > 1; i--)
    {
        Swap(&A[i], &A[1]);
        AdjustDown(A, 1, i - 1);
    }
}

int main()
{
    int A[] = {0, 33, 46, 89, 31, 11, 58, 9, 54, 3};
    int len = sizeof(A) / sizeof(A[0]) - 1;
    HeapSort(A, len);

    for (int i = 1; i < len; i++)
    {
        printf("==%d\n", A[i]);
    };
    return 1;
}
