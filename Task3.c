#include "utils.h"

/* Function used to remove the punctuation marks from the end of the word */
void format(char *c) {
    if (*c == ',' || *c == '.' || *c == '!' || *c == ';') {
        *c = '\0';
    }

    return;
}

void SolveTask3() {
    char **text, **ret, word[100], aux[100];
    int i, j, k, size = 1, nr = 0, count, OK;

    /* 2D array to store the text in pairs of words */
    text = malloc(MAX_LENGTH * sizeof(char *));
    for (i = 0; i < MAX_LENGTH; i++) {
        text[i] = calloc(MAX_LENGTH, sizeof(char));
    }

    /* 2D array to store the output */
    ret = malloc(MAX_LENGTH * sizeof(char *));
    for (i = 0; i < MAX_LENGTH; i++) {
        ret[i] = calloc(MAX_LENGTH, sizeof(char));
    }

    scanf("%s", word);
    format(&word[strlen(word) - 1]);

    strcat(text[0], word);
    strcat(text[0], " ");

    scanf("%s", aux);
    format(&aux[strlen(aux) - 1]);

    strcat(text[0], aux);

    while(scanf("%s", word) != EOF) {
        strcat(text[size], aux);
        strcat(text[size], " ");

        format(&word[strlen(word) - 1]);
        strcat(text[size], word);

        /* Keep the last words */
        strcpy(aux, word);

        size++;
    }

    for (i = 0; i < size; i++) {

        /* Check if the pair was already counted */
        OK = 1;
        for (j = 0; j < i; j++) {
            if (strcmp(text[i], text[j]) == 0) {
                OK = 0;
                break;
            }
        }

        /* If it was not, count the number of occurences */
        if (OK) {
            count = 1;
            for (j = i + 1; j < size; j++) {
                if (strcmp(text[i], text[j]) == 0) {
                    count++;
                }
            }

            /* Add the pair and the count to the output array */
            strcpy(ret[nr], text[i]);
            strcat(ret[nr], " ");
            sprintf(aux, "%d", count);
            strcat(ret[nr], aux);
            nr++;
        }
    }

    /* Print the output */
    printf("%d\n", nr);
    for (i = 0; i < nr; i++) {
        printf("%s\n", ret[i]);
    }

    /* Free memory */
    for (i = 0; i < MAX_LENGTH; i++) {
        free(text[i]);
        free(ret[i]);
    }

    free(text);
    free(ret);

    return;
}
