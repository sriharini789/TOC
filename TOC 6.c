#include <stdio.h>
#include <string.h>

int checkString(const char *str, int *index) {
    if (str[*index] == '\0') {
        return 1; // e production
    }
    
    if (str[*index] == '0') {
        (*index)++;
        if (checkString(str, index)) {
            if (str[*index] == '1') {
                (*index)++;
                return 1;
            }
        }
        return 0;
    }
    return 0;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    
    int index = 0;
    if (checkString(str, &index) && index == strlen(str)) {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }
    
    return 0;
}
