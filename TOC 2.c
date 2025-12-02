#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, state = 0; 

    printf("Enter a binary string: ");
    scanf("%s", str);

    for (i = 0; i < strlen(str); i++) {
        char ch = str[i];

        switch (state) {
            case 0:  
                if (ch == '0')
                    state = 1;      
                else
                    state = 3;      
                break;

            case 1:  
                if (ch == '0')
                    state = 1;
                else if (ch == '1')
                    state = 2;      
                break;

            case 2:  
                if (ch == '0')
                    state = 1;
                else if (ch == '1')
                    state = 2;
                break;

            case 3:  
                state = 3;
                break;
        }
    }

    
    if (state == 2)
        printf("ACCEPTED\n");
    else
        printf("REJECTED\n");

    return 0;
}
