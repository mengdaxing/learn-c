
#include <stdio.h>

int Partition(int A[], int low, int high)
{
    int pivot = A[low];
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
};

void QuickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int piot = Partition(A, low, high);
        QuickSort(A, low, piot - 1);
        QuickSort(A, piot + 1, high);
    }
};
int main()
{
    int A[] = {46, 79, 56, 38, 40, 84};

    QuickSort(A, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        printf("%d\n", A[i]);
    }

    /* 我的第一个 C 程序 */
    printf("Hello, World! \n");

    return 0;
}
