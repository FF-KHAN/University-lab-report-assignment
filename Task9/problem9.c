#include <stdio.h>

int main()
{
    char str[100];
    int position, count, i;

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Enter the starting position: ");
    scanf("%d", &position);

    printf("Enter number of characters to delete: ");
    scanf("%d", &count);

    for (i = position; str[i + count] != '\0'; i++)
    {
        str[i] = str[i + count];
    }

    str[i] = '\0';

    printf("String after deletion: %s\n", str);

    return 0;
}
