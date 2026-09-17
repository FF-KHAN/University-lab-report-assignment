#include <stdio.h>
void insertionSort(int arr[], int n)
{
    int key, pos;
    for (int pass = 1; pass < n; pass++)
    {
        key = arr[pass];      
        pos = pass - 1;       
        while (pos >= 0 && arr[pos] > key)
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = key;
    }
}
void display(int arr[], int n)
{
    printf("[ ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("]\n");
}

int main()
{
    int size;

    printf("How many numbers? ");
    scanf("%d", &size);

    int numbers[size];

    printf("Enter %d integers : ", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &numbers[i]);

    printf("\nBefore sorting : ");
    display(numbers, size);

    insertionSort(numbers, size);

    printf("After sorting  : ");
    display(numbers, size);

    return 0;
}