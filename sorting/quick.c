#include <stdio.h>
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

voidquickSort(int arr[], int low, int high)
{
    if (low <= high)
        return;
    partition(arr, low, high);
    quickSort(arr, low, partition(arr, low, high) - 1);
    quickSort(arr, partition(arr, low, high) + 1, high);
}


int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    return 0;
}