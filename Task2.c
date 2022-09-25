#include "utils.h"

/* Function to rotate a position of the encrypted text */
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
void caesar(int K, char S[MAX_LENGTH]) {
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

    return;
}

/* Function user to decript using Vigenere */
void vigenere(char K[MAX_LENGTH], char S[MAX_LENGTH], char extendedKey[MAX_LENGTH]) {
    int i, j = 0, leftMargin, rightMargin;

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

        S[i] = rotate(S[i], leftMargin, rightMargin, extendedKey[i] - 65);
    }

    return;
}

void SolveTask2() {
    char S[MAX_LENGTH], K[MAX_LENGTH], method[10], extendedKey[MAX_LENGTH];

    scanf("%s\n", method);

    if (strcmp(method, "caesar") == 0) {
        scanf("%s\n", K);
        scanf("%s\n", S);
        
        caesar(atoi(K), S);
    } else if (strcmp(method, "vigenere") == 0) {
        scanf("%s\n", K);
        scanf("%s\n", S);

        strcpy(extendedKey, K);
        while (strlen(extendedKey) < strlen(S)) {
            strcat(extendedKey, K);
        }

        vigenere(K, S, extendedKey);

    }

    printf("%s\n", S);
}