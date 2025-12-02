#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATES 10
#define MAX_INPUT 100

typedef struct {
    int transitions[MAX_STATES][2][MAX_STATES]; // transitions[state][input][next_state]
    int num_states;
    int start_state;
    int accept_states[MAX_STATES];
    int num_accept_states;
} NFA;

void initialize_nfa(NFA *nfa) {
    nfa->num_states = 3; // States: 0, 1, 2
    nfa->start_state = 0;
    nfa->num_accept_states = 1;
    nfa->accept_states[0] = 2;

    // Transitions for 'o' (0) and '1' (1)
    nfa->transitions[0][0][1] = 1; // State 0 --o--> State 1
    nfa->transitions[1][1][2] = 1; // State 1 --1--> State 2
}

int is_accepting(NFA *nfa, int state) {
    for (int i = 0; i < nfa->num_accept_states; i++) {
        if (nfa->accept_states[i] == state) {
            return 1;
        }
    }
    return 0;
}

void simulate_nfa(NFA *nfa, const char *input) {
    int current_states[MAX_STATES] = {nfa->start_state};
    int next_states[MAX_STATES];
    int num_current_states = 1;

    for (int i = 0; i < strlen(input); i++) {
        int input_symbol = input[i] == 'o' ? 0 : (input[i] == '1' ? 1 : -1);
        int num_next_states = 0;

        for (int j = 0; j < num_current_states; j++) {
            int current_state = current_states[j];
            if (input_symbol != -1) {
                for (int k = 0; k < nfa->num_states; k++) {
                    if (nfa->transitions[current_state][input_symbol][k]) {
                        next_states[num_next_states++] = k;
                    }
                }
            }
        }

        num_current_states = num_next_states;
        memcpy(current_states, next_states, num_next_states * sizeof(int));
    }

    for (int i = 0; i < num_current_states; i++) {
        if (is_accepting(nfa, current_states[i])) {
            printf("The string '%s' is accepted by the NFA.\n", input);
            return;
        }
    }
    printf("The string '%s' is not accepted by the NFA.\n", input);
}

int main() {
    NFA nfa;
    initialize_nfa(&nfa);

    char input[MAX_INPUT];
    printf("Enter a string: ");
    scanf("%s", input);

    simulate_nfa(&nfa, input);
    return 0;
}
