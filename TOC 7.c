#include <stdio.h>
#include <string.h>

int isValidString(const char *str) {
    int len = strlen(str);
    if (len < 5 || str[len - 3] != '1' || str[len - 2] != '0' || str[len - 1] != '1') {
        return 0;
    }

    int mid = len - 3;
    for (int i = 0; i < mid; i++) {
        if (str[i] != '0' && str[i] != '1') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isValidString(str)) {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }

    return 0;
}
