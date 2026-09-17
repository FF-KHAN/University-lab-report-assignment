#include <stdio.h>

void optimized_bubble_sort(int DataList[], int length) {
    int pass, idx;
    int is_swapped;

    for (pass = 0; pass < length - 1; pass++) {
        is_swapped = 0; 

        for (idx = 0; idx < length - pass - 1; idx++) {
            if (DataList[idx] > DataList[idx + 1]) {
                int temp_val = DataList[idx];
                DataList[idx] = DataList[idx + 1];
                DataList[idx + 1] = temp_val;

                is_swapped = 1; 
            }
        }

        if (is_swapped == 0) {
            break; 
        }
    }
}

int main() {
    int total_elements, i;

    printf("=== Bubble Sort Program ===\n");
    printf("Enter the number of elements: ");
    scanf("%d", &total_elements);

    int numbers_array[total_elements];

    printf("Enter %d integers:\n", total_elements);
    for (i = 0; i < total_elements; i++) {
        printf("Element [%d]: ", i + 1);
        scanf("%d", &numbers_array[i]);
    }

    printf("\nOriginal Array : ");
    for (i = 0; i < total_elements; i++) {
        printf("%d ", numbers_array[i]);
    }
    optimized_bubble_sort(numbers_array, total_elements);

    printf("\nSorted Array   : ");
    for (i = 0; i < total_elements; i++) {
        printf("%d ", numbers_array[i]);
    }
    printf("\n");

    return 0;
}