#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    int len, i, j, k, *c;
    len = r - l + 1;
    c = (int *)malloc(sizeof(int) * len);
    i = 0;
    j = l;
    k = m + 1;
    while (j <= m && k <= r)
    {
        if (arr[j] < arr[k])
        {
            c[i++] = arr[j++];
        }
        else
        {
            c[i++] = arr[k++];
        }
    }

    while (j <= m)
    {
        c[i++] = arr[j++];
    }

    while (k <= r)
    {
        c[i++] = arr[k++];
    }
    i = 0;
    while (l <= r)
    {
        arr[l++] = c[i++];
    }
}

void mergesort1(int arr[], int l, int r)
{
    int m = (l + r) / 2;
    if (l < r)
    {
        mergesort1(arr, l, m);
        mergesort1(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int l, int r)
{
    int j = l + 1, k = r, temp;
    int num = arr[l];
    while (k >= j)
    {
        while (arr[j] < num)
            j++;
        while (arr[k] > num)
            k--;

        if (k > j)
        {
            temp = arr[j];
            arr[j] = arr[k];
            arr[k] = temp;
        }
    }
    temp = arr[k];
    arr[k] = arr[l];
    arr[l] = temp;
    return k;
}

void quicksort(int arr[], int l, int r)
{
    int m;
    if (r > l)
    {
        m = partition(arr, l, r);
        quicksort(arr, l, m - 1);
        quicksort(arr, m + 1, r);
    }
}

int main()
{
    int i, n, *arr, choice;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    printf("\nEnter %d elements : ", n);
    arr = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    while (choice != 0)
    {
        printf("\n\n\tMenu\n---------------------------");
        printf("\n1 : Merge Sort");
        printf("\n2 : Quick Sort");
        printf("\n0 : Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            mergesort1(arr, 0, n - 1);
            break;
        case 2:
            quicksort(arr, 0, n - 1);
            break;
        case 0:
            exit(0);
        }

        printf("\n\tSorted Numbers:\n-----------------------------\n");
        for (i = 0; i < n; i++)
            printf("%d\t", arr[i]);
    }

    return 0;
}