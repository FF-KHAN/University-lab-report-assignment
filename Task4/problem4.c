
#include <stdio.h>

int LENGTH(char s[])
{
    int i = 0;

    while (s[i] != '\0')
        i++;

    return i;
}

char GETCHAR(char s[], int n)
{
    return s[n];
}

void PUTCHAR(char s[], int n, char c)
{
    s[n] = c;
}

int POS(char s1[], char s2[])
{
    int i, j;

    for (i = 0; s1[i] != '\0'; i++)
    {
        j = 0;

        while (s2[j] != '\0' && s1[i + j] == s2[j])
            j++;

        if (s2[j] == '\0')
            return i;
    }

    return -1;
}

void CONCAT(char s1[], char s2[])
{
    int i = LENGTH(s1);
    int j = 0;

    while (s2[j] != '\0')
    {
        s1[i] = s2[j];
        i++;
        j++;
    }

    s1[i] = '\0';
}

void SUBSTRING(char s1[], int start, int count)
{
    int i;

    for (i = 0; i < count && s1[start + i] != '\0'; i++)
        printf("%c", s1[start + i]);

    printf("\n");
}

void DELETE(char s[], int start, int count)
{
    int i;

    for (i = start; s[i + count] != '\0'; i++)
        s[i] = s[i + count];

    s[i] = '\0';
}

void INSERT(char s1[], char s2[], int pos)
{
    int i, len1, len2;

    len1 = LENGTH(s1);
    len2 = LENGTH(s2);

    for (i = len1; i >= pos; i--)
        s1[i + len2] = s1[i];

    for (i = 0; i < len2; i++)
        s1[pos + i] = s2[i];
}

int COMPARE(char s1[], char s2[])
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];

        i++;
    }

    return s1[i] - s2[i];
}

int main()
{
    char str1[100], str2[100];
    int choice, n, pos, count;
    char ch;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    printf("\n1. GETCHAR");
    printf("\n2. PUTCHAR");
    printf("\n3. LENGTH");
    printf("\n4. POS");
    printf("\n5. CONCAT");
    printf("\n6. SUBSTRING");
    printf("\n7. DELETE");
    printf("\n8. INSERT");
    printf("\n9. COMPARE");

    printf("\n\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter position: ");
            scanf("%d", &n);

            printf("Character = %c\n", GETCHAR(str1, n));
            break;

        case 2:
            printf("Enter position and character: ");
            scanf("%d %c", &n, &ch);

            PUTCHAR(str1, n, ch);
            printf("New string = %s\n", str1);
            break;

        case 3:
            printf("Length = %d\n", LENGTH(str1));
            break;

        case 4:
            pos = POS(str1, str2);

            if (pos == -1)
                printf("String not found.\n");
            else
                printf("Found at position %d\n", pos);
            break;

        case 5:
            CONCAT(str1, str2);
            printf("Concatenated string = %s\n", str1);
            break;

        case 6:
            printf("Enter starting position and number: ");
            scanf("%d %d", &pos, &count);

            printf("Substring = ");
            SUBSTRING(str1, pos, count);
            break;

        case 7:
            printf("Enter starting position and number: ");
            scanf("%d %d", &pos, &count);

            DELETE(str1, pos, count);
            printf("After deletion = %s\n", str1);
            break;

        case 8:
            printf("Enter insertion position: ");
            scanf("%d", &pos);

            INSERT(str1, str2, pos);
            printf("After insertion = %s\n", str1);
            break;

        case 9:
            if (COMPARE(str1, str2) == 0)
                printf("Strings are equal.\n");
            else
                printf("Strings are different.\n");

            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}