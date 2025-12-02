#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, state = 0;  // start state = 0

    printf("Enter a string over {a,b}: ");
    scanf("%s", str);

    for (i = 0; i < strlen(str); i++) {
        char ch = str[i];

        switch (state) {
            case 0:  // Start state
                if (ch == 'a')
                    state = 1;      // first 'a' seen
                else
                    state = 3;      // goes to dead state
                break;

            case 1:  // Started with a, scanning middle part
                if (ch == 'a')
                    state = 2;      // last seen was a
                else if (ch == 'b')
                    state = 1;      // continue, still valid middle
                break;

            case 2:  // last symbol seen was a
                if (ch == 'a')
                    state = 2;
                else if (ch == 'b')
                    state = 1;
                break;

            case 3:  // dead state
                state = 3;
                break;
        }
    }

    // ACCEPTING STATE = 2 (because last symbol must be 'a')
    if (state == 2)
        printf("ACCEPTED\n");
    else
        printf("REJECTED\n");

    return 0;
}
