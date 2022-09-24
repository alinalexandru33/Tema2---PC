#include "utils.h"

/* Function to rotate for Caesar encription */
char rotate(char S, int leftMargin, int rightMargin, int K) {
    int i;

    for (i = 0; i < K; i++) {
        S--;

        if (S < leftMargin) {
            S = rightMargin;
        }
    }

    return S;
}

/* Function user to decript using Caesar */
void caesar(int K, char S[100]) {
    int i, leftMargin, rightMargin;

    for (i = 0; i < strlen(S); i++) {

        /* Number */
        if (S[i] >= 48 && S[i] <= 57) {
            leftMargin = 48; rightMargin = 57;

        /* Upper case letter */
        } else if (S[i] >= 65 && S[i] <= 90) {
            leftMargin = 65; rightMargin = 90;

        /* Lower case letter */
        } else if (S[i] >= 97 && S[i] <= 122) {
            leftMargin = 97; rightMargin = 122;
        }

        S[i] = rotate(S[i], leftMargin, rightMargin, K);
    }
}

void SolveTask2() {
    int K;
    char S[100], method[10];

    scanf("%s\n", method);
    scanf("%d\n", &K);
    scanf("%s\n", S);

    if (strcmp(method, "caesar") == 0) {
        caesar(K, S);
    }

    printf("%s\n", S);
}