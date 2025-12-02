#include <stdio.h>
#include <stdlib.h>

#define MAX_STATES 100
#define MAX_TRANSITIONS 100

typedef struct {
    int state;
    int epsilonTransitions[MAX_STATES];
    int epsilonCount;
} NFAState;

NFAState nfa[MAX_STATES];
int stateCount;

void addEpsilonTransition(int fromState, int toState) {
    nfa[fromState].epsilonTransitions[nfa[fromState].epsilonCount++] = toState;
}

void epsilonClosure(int state, int *closure, int *closureCount) {
    closure[(*closureCount)++] = state;
    for (int i = 0; i < nfa[state].epsilonCount; i++) {
        int nextState = nfa[state].epsilonTransitions[i];
        int alreadyInClosure = 0;
        for (int j = 0; j < *closureCount; j++) {
            if (closure[j] == nextState) {
                alreadyInClosure = 1;
                break;
            }
        }
        if (!alreadyInClosure) {
            epsilonClosure(nextState, closure, closureCount);
        }
    }
}

int main() {
    int transitions, fromState, toState;

    printf("Enter the number of states: ");
    scanf("%d", &stateCount);

    printf("Enter the number of epsilon transitions: ");
    scanf("%d", &transitions);

    for (int i = 0; i < transitions; i++) {
        printf("Enter epsilon transition (from to): ");
        scanf("%d %d", &fromState, &toState);
        addEpsilonTransition(fromState, toState);
    }

    for (int i = 0; i < stateCount; i++) {
        int closure[MAX_STATES];
        int closureCount = 0;
        epsilonClosure(i, closure, &closureCount);
        printf("Epsilon-closure(%d) = { ", i);
        for (int j = 0; j < closureCount; j++) {
            printf("%d ", closure[j]);
        }
        printf("}\n");
    }

    return 0;
}
