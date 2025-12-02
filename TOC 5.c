#include <stdio.h>
#include <string.h>

int checkCFG(char *str, int start, int end) {
    if (start > end) return 0;
    if (start == end) return str[start] == '1';

    if (str[start] == '0' && str[end] == '0') {
        return checkCFG(str, start + 1, end - 1);
    }
    return checkCFG(str, start, end - 1) || checkCFG(str, start + 1, end);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    
    int length = strlen(str);
    if (checkCFG(str, 0, length - 1)) {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }
    
    return 0;
}
