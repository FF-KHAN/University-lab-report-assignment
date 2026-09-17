#include <stdio.h>


int locate_substring(const char *source, const char *target) {
    int src_index = 0;

    
    while (source[src_index] != '\0') {
        int sub_index = 0;
        
        
        while (source[src_index + sub_index] == target[sub_index] && target[sub_index] != '\0') {
            sub_index++;
        }

        
        if (target[sub_index] == '\0') {
            return src_index; 
        }

        src_index++;
    }

    
    return -1; 
}

int main() {
    char main_text[200];
    char sub_text[100];

    
    printf("== Substring Finder Program ==\n");
    printf("Enter the main sentence: ");
    fgets(main_text, sizeof(main_text), stdin);

    printf("Enter the substring to search: ");
    fgets(sub_text, sizeof(sub_text), stdin);

    
    int i = 0;
    while (main_text[i] != '\0') {
        if (main_text[i] == '\n') main_text[i] = '\0';
        i++;
    }
    i = 0;
    while (sub_text[i] != '\0') {
        if (sub_text[i] == '\n') sub_text[i] = '\0';
        i++;
    }

    
    int match_index = locate_substring(main_text, sub_text);

    
    if (match_index != -1) {
        printf("\n[SUCCESS] Substring found!\n");
        printf("-> Starting Position (0-based index) : %d\n", match_index);
        printf("-> Starting Position (1-based index) : %d\n", match_index + 1);
    } else {
        printf("\n[NOT FOUND] Substring does not exist in the main text.\n");
    }

    return 0;
}