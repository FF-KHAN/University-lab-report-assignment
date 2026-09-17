#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter the upper limit: ");
    scanf("%d", &n);

    int mark[1000] = {0};  

    mark[0] = 1;
    mark[1] = 1;

    for (i = 2; i <= n; i++) {
        if (mark[i] == 0) {
            
            for (j = i + i; j <= n; j = j + i) {
                mark[j] = 1;
            }
        }
    }

    printf("Prime numbers between 1 to %d are:\n", n);
    for (i = 2; i <= n; i++) {
        if (mark[i] == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}