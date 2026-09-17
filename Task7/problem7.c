#include <stdio.h>

#define MAX_LEN 300

void joinStrings(char *first, const char *second)
{
    int endPos = 0;

    while (first[endPos] != '\0')
        endPos++;

    int idx = 0;
    while (second[idx] != '\0')
    {
        first[endPos] = second[idx];
        endPos++;
        idx++;
    }

    first[endPos] = '\0';
}

int main()
{
    char strA[MAX_LEN], strB[MAX_LEN];

    printf("Enter first string  : ");
    scanf(" %[^\n]", strA);

    printf("Enter second string : ");
    scanf(" %[^\n]", strB);

    joinStrings(strA, strB);

    printf("\nAfter joining      : %s\n", strA);

    return 0;
}