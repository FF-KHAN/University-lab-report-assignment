#include <stdio.h>

int totalPerm = 0;   
void generate(int arr[], int used[], int current[], int depth, int n)
{
    if (depth == n)
    {
        totalPerm++;
        printf("  %2d)  ", totalPerm);
        for (int i = 0; i < n; i++)
            printf("%d ", current[i]);
        printf("\n");
        return;
    }

    
    for (int pick = 0; pick < n; pick++)
    {
        if (used[pick])
            continue;  
        int duplicate = 0;
        for (int prev = 0; prev < pick; prev++)
        {
            if (arr[prev] == arr[pick] && !used[prev])
            {
                duplicate = 1;
                break;
            }
        }
        if (duplicate)
            continue;
        used[pick] = 1;
        current[depth] = arr[pick];

        generate(arr, used, current, depth + 1, n);

        used[pick] = 0;
    }
}

int main()
{
    int n;

    printf("How many elements? ");
    scanf("%d", &n);

    int arr[n], used[n], current[n];

    printf("Enter %d elements  : ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        used[i] = 0;      
    }

    printf("\n===== All Permutations =====\n");
    generate(arr, used, current, 0, n);
    printf("============================\n");
    printf("Total permutations : %d\n", totalPerm);

    return 0;
}