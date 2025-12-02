#include <stdio.h>
#include <string.h>

int isInLanguage(const char *str, int start, int end) {
    if (start > end) return 0;
    if (start == end) return str[start] == '0' || str[start] == '1';

    if (str[start] == '0' && str[end] == '0') {
        return isInLanguage(str, start + 1, end - 1);
    }
    if (str[start] == '1' && str[end] == '1') {
        return isInLanguage(str, start + 1, end - 1);
    }
    return 0;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    
    if (isInLanguage(str, 0, strlen(str) - 1)) {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }
    
    return 0;
}
