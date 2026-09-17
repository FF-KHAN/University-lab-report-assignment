#include <stdio.h>
int findFirstOccurrence(int arr[], int size, int key)
{
    int low = 0, high = size - 1;
    int resultIndex = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            resultIndex = mid;      
            high = mid - 1;         
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return resultIndex;
}


int findLastOccurrence(int arr[], int size, int key)
{
    int low = 0, high = size - 1;
    int resultIndex = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            resultIndex = mid;      
            low = mid + 1;          
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return resultIndex;
}

int main()
{
    int arr[100], n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements in sorted (ascending) order:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int first = findFirstOccurrence(arr, n, key);

    if (first == -1) {
        printf("\nElement %d is not present in the array.\n", key);
    }
    else {
        int last = findLastOccurrence(arr, n, key);
        int count = last - first + 1;

        printf("\nFirst Occurrence Index : %d\n", first);
        printf("Last Occurrence Index  : %d\n", last);
        printf("Total Count            : %d\n", count);
    }

    return 0;
}