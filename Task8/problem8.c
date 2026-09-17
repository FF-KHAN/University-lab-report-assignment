#include <stdio.h>
#include <string.h>

void insertAtPosition(char original[], char insertText[], int position, char finalResult[])
{
    int origLen = strlen(original);
    int insertLen = strlen(insertText);
    int idx = 0;

    if (position < 0 || position > origLen) {
        printf("Invalid position! Insertion not possible.\n");
        strcpy(finalResult, original); 
        return;
    }

    for (idx = 0; idx < position; idx++)
        finalResult[idx] = original[idx];

    int insertIdx;
    for (insertIdx = 0; insertIdx < insertLen; insertIdx++)
        finalResult[idx++] = insertText[insertIdx];

    for (int rest = position; rest < origLen; rest++)
        finalResult[idx++] = original[rest];

    finalResult[idx] = '\0';   
}

int main()
{
    char original[200], insertText[100], finalResult[300];
    int position;

    printf("Enter the original string : ");
    scanf(" %[^\n]", original);

    printf("Enter the text to insert  : ");
    scanf(" %[^\n]", insertText);

    printf("Enter the position (0-based index) : ");
    scanf("%d", &position);

    insertAtPosition(original, insertText, position, finalResult);

    printf("\nString after insertion: %s\n", finalResult);

    return 0;
}