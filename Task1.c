#include "utils.h"

/* Function used to determine if a number is palindrome */
int isPalindrome(int n) {
    int aux, reverese = 0;

    aux = n;
    while (aux != 0) {
        reverese = reverese * 10 + aux % 10;
        aux /= 10;
    }

    if (n == reverese) {
        return 1;
    }

    return 0;
}

/* Function used to determine if a number is prime */
int isPrime(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

/* Function used to solve "a" strating words */
void solveA(char *p, int mat[MAX_LENGTH][MAX_LENGTH], int *i, int *j, int *moveNr) {
    int k, idx;
    char max = '0';

    for (k = 1; k < 5; k++) {
        if (p[k] > max) {
            max = p[k];
            idx = k;
        }
    }

    mat[*i][*j] = *moveNr;
    (*moveNr)++;

    switch (idx) {
        case 1:
            (*j)++;
            break;

        case 2:
            (*i)--;
            break;

        case 3:
            (*j)--;
            break;

        case 4:
            (*i)++;
            break;
    }

    return;
}

/* Function used to solve "b" strating words */
void solveB(char *p, int mat[MAX_LENGTH][MAX_LENGTH], int *i, int *j, int *moveNr) {
    int K, X;

    K = atoi(p + 1);
    X = K % 100;

    mat[*i][*j] = *moveNr;
    (*moveNr)++;

    if (isPalindrome(K) && isPrime(X)) {
        (*j)--;
    } else if (isPalindrome(K) && !isPrime(X)) {
        (*j)++;
    } else if (!isPalindrome(K) && isPrime(X)) {
        (*i)--;
    } else if (!isPalindrome(K) && !isPrime(X)) {
        (*i)++;
    }

    return;
}

/* Function used to solve "c" strating words */
void solveC(char *p, int mat[MAX_LENGTH][MAX_LENGTH], int *i, int *j, int *moveNr) {
    int nr, idx = 0, n, k, S = 0, r;

    n = p[1] - 48;
    k = p[2] - 48;

    for (nr = 0; nr < k; nr ++) {
        if (idx >= n) {
            S += p[3 + (idx % n)] - 48;
        } else {
            S += p[3 + idx] - 48;
        }

        idx += k;
    }

    mat[*i][*j] = *moveNr;
    (*moveNr)++;

    r = S % 4;
    switch (r) {
        case 0:
            (*j)--;
            break;

        case 1:
            (*i)--;
            break;

        case 2:
            (*j)++;
            break;

        case 3:
            (*i)++;
            break;
    }

    return;
}

void SolveTask1() {
    int moveNr = 1, i = 0, j = 0, N, M, mat[MAX_LENGTH][MAX_LENGTH];
    char words[MAX_LENGTH];
    char *p;

    scanf("%d %d\n", &N, &M);
    scanf("%[^\n]s", words);

    /* Divide input into words */
    p = strtok(words, " ");
    while (p != NULL) {
        if (p[0] == 'a') {
            solveA(p, mat, &i, &j, &moveNr);
        } else if (p[0] == 'b') {
            solveB(p, mat, &i, &j, &moveNr);
        } else if (p[0] == 'c') {
            solveC(p, mat, &i, &j, &moveNr);
        }

        p = strtok(NULL, " ");
    }
    mat[i][j] = moveNr;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return;
}
