#include <stdio.h>
int linearSearch(int arr[], int n, int target)
{
    for (int cur = 0; cur < n; cur++)
    {
        if (arr[cur] == target)
            return cur;   
    }
    return -1;  
}

int main()
{
    int size, target;

    printf("Array size        : ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d elements : ", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Element to search : ");
    scanf("%d", &target);

    int foundAt = linearSearch(arr, size, target);

    if (foundAt != -1)
        printf("\n>>> %d found at index %d (position %d).\n",
               target, foundAt, foundAt + 1);
    else
        printf("\n>>> %d is not present in the array.\n", target);

    return 0;
}