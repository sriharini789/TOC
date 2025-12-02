#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int len, i;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    
    if (len < 2) {
        printf("REJECTED\n");
        return 0;
    }

   
    if (str[0] != '0') {
        printf("REJECTED\n");
        return 0;
    }

  
    if (str[len - 1] != '1') {
        printf("REJECTED\n");
        return 0;
    }

    
    for (i = 1; i < len - 1; i++) {
        if (str[i] != '0' && str[i] != '1') {
            printf("REJECTED\n");
            return 0;
        }
    }

    printf("ACCEPTED\n");
    return 0;
}
