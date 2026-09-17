
#include <stdio.h>
#include <string.h>

int locatePattern(const char *source, const char *target)
{
    int srcLen = strlen(source);
    int patLen = strlen(target);

    
    if (patLen > srcLen)
        return -1;

    
    for (int start = 0; start <= srcLen - patLen; start++)
    {
        int matchFlag = 1;   

        for (int k = 0; k < patLen; k++)
        {
            if (source[start + k] != target[k])
            {
                matchFlag = 0;  
                break;
            }
        }

        if (matchFlag)
            return start;   
    }

    return -1;   
}

int main()
{
    char text[200], pattern[100];

    printf("Enter the main string : ");
    scanf(" %[^\n]", text);

    printf("Enter the pattern     : ");
    scanf(" %[^\n]", pattern);

    int position = locatePattern(text, pattern);

    if (position != -1)
        printf("\nPattern found at index: %d\n", position);
    else
        printf("\nPattern not present in the given string.\n");

    return 0;
}