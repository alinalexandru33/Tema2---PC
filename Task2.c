#include "utils.h"

/* Function used to swap two strings */
void swap(char str1[MAX_LENGTH], char str2[MAX_LENGTH]) {
    char *aux = calloc(MAX_LENGTH, sizeof(char));
    
    strcpy(aux, str1);
    strcpy(str1, str2);
    strcpy(str2, aux);

    free(aux);
}

/* Functions used to reverse a string */
void reverse(char *str) {
    int i, len = strlen(str), aux;

    for (i = 0; i < len / 2; i++) {
        aux = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = aux;
    }
}

/* Function that computes the sum of two big numbers */
char* sum(char N1[MAX_LENGTH], char N2[MAX_LENGTH]) {
    char *ret = calloc(MAX_LENGTH, sizeof(char));
    int i, idx = 0, n1, n2, diff, carry = 0, s;

    /* Make the second number the longest */
    if (strlen(N1) > strlen(N2)) {
        swap(N1, N2);
    }

    n1 = strlen(N1); n2 = strlen(N2);
    diff = n2 - n1;

    /* Sum for the same length */
    for (i = n1 - 1; i >= 0; i--) {
        s = (N1[i] - '0') + (N2[i + diff] - '0') + carry;
        ret[idx] = s % 10 + '0';
        idx++;

        carry = s / 10;
    }

    /* Add the rest, if one number is longer */
    for (i = n2 - n1 - 1; i >= 0; i--) {
        s = (N2[i] - '0') + carry;
        ret[idx] = s % 10 + '0';
        idx++;

        carry = s / 10;
    }

    /* Add the last carry */
    if (carry) {
        ret[idx] = carry + '0';
    }

    /* We have computed the number from end to beginning
    so we need to reverse it */
    reverse(ret);

    /* Delete 0's at the beginning of the number */
    while (ret[0] == '0' && strlen(ret) > 0) {
        strcpy(ret, ret + 1);
    }

    return ret;
} 

/* Function used to rotate a position of the encrypted text */
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

/* Function used to decrypt using Caesar */
void caesar(int K, char S[MAX_LENGTH]) {
    int i, leftMargin, rightMargin;

    for (i = 0; i < strlen(S); i++) {

        /* Number */
        if (S[i] >= '0' && S[i] <= '9') {
            leftMargin = '0'; rightMargin = '9';

        /* Upper case letter */
        } else if (S[i] >= 'A' && S[i] <= 'Z') {
            leftMargin = 'A'; rightMargin = 'Z';

        /* Lower case letter */
        } else if (S[i] >= 'a' && S[i] <= 'z') {
            leftMargin = 'a'; rightMargin = 'z';
        }

        S[i] = rotate(S[i], leftMargin, rightMargin, K);
    }

    return;
}

/* Function used to decrypt using Vigenere */
void vigenere(char K[MAX_LENGTH], char S[MAX_LENGTH], char extendedKey[MAX_LENGTH]) {
    int i, j = 0, leftMargin, rightMargin;

    for (i = 0; i < strlen(S); i++) {
        
        /* Number */
        if (S[i] >= '0' && S[i] <= '9') {
            leftMargin = '0'; rightMargin = '9';

        /* Upper case letter */
        } else if (S[i] >= 'A' && S[i] <= 'Z') {
            leftMargin = 'A'; rightMargin = 'Z';

        /* Lower case letter */
        } else if (S[i] >= 'a' && S[i] <= 'z') {
            leftMargin = 'a'; rightMargin = 'z';
        }

        S[i] = rotate(S[i], leftMargin, rightMargin, extendedKey[i] - 'A');
    }

    return;
}

void SolveTask2() {
    char S[MAX_LENGTH], K[MAX_LENGTH], N1[MAX_LENGTH],N2[MAX_LENGTH], 
        method[MAX_LENGTH], extendedKey[MAX_LENGTH];

    scanf("%s", method);

    /* Decrypt using Caesar */
    if (strcmp(method, "caesar") == 0) {
        scanf("%s", K);
        scanf("%s", S);
        
        caesar(atoi(K), S);

    /* Decrypt using Vigenere */
    } else if (strcmp(method, "vigenere") == 0) {
        scanf("%s", K);
        scanf("%s", S);

        strcpy(extendedKey, K);
        while (strlen(extendedKey) < strlen(S)) {
            strcat(extendedKey, K);
        }

        vigenere(K, S, extendedKey);

    /* Decrypt using Addition */
    } else if (strcmp(method, "addition") == 0) {
        scanf("%s", K);
        scanf("%s", N1);
        scanf("%s", N2);

        caesar(atoi(K), N1);
        caesar(atoi(K), N2);

        strcpy(S, sum(N1, N2));
    }

    printf("%s\n", S);

    return;
}
