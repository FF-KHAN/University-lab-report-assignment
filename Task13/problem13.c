#include <stdio.h>
int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;  

        if (arr[mid] == key)
            return mid;              

        else if (arr[mid] < key)
            low = mid + 1;           

        else
            high = mid - 1;          
    }

    return -1;   
}

int main()
{
    int n, key;

    printf("How many elements? ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d sorted elements : ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Element to find        : ");
    scanf("%d", &key);

    int pos = binarySearch(arr, n, key);

    if (pos != -1)
        printf("\n>>> %d exists at index %d.\n", key, pos);
    else
        printf("\n>>> %d is absent in this array.\n", key);

    return 0;
}