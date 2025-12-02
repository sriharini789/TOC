#include <stdio.h>
#include <string.h>

#define MAX_STATES 10
#define MAX_INPUT 100

typedef struct {
    int transition[MAX_STATES][2][MAX_STATES]; // transition[state][input][next_state]
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

    // Transitions for 'b' (1) and 'a' (0)
    nfa->transition[0][1][1] = 1; // From state 0 to 1 on 'b'
    nfa->transition[1][0][2] = 1; // From state 1 to 2 on 'a'
    nfa->transition[1][1][1] = 1; // From state 1 to 1 on 'b'
    nfa->transition[2][0][2] = 1; // From state 2 to 2 on 'a'
    nfa->transition[2][1][2] = 1; // From state 2 to 2 on 'b'
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
    int current_states[MAX_STATES] = {0};
    current_states[0] = nfa->start_state;

    for (int i = 0; i < strlen(input); i++) {
        int next_states[MAX_STATES] = {0};
        int next_count = 0;

        for (int j = 0; j < nfa->num_states; j++) {
            if (current_states[j]) {
                int input_symbol = (input[i] == 'a') ? 0 : 1;
                for (int k = 0; k < nfa->num_states; k++) {
                    if (nfa->transition[j][input_symbol][k]) {
                        next_states[next_count++] = k;
                    }
                }
            }
        }

        memset(current_states, 0, sizeof(current_states));
        for (int j = 0; j < next_count; j++) {
            current_states[next_states[j]] = 1;
        }
    }

    for (int i = 0; i < nfa->num_states; i++) {
        if (current_states[i] && is_accepting(nfa, i)) {
            printf("Accepted\n");
            return;
        }
    }
    printf("Rejected\n");
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
