#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LENGTH 1000

/* Task 1 */
int isPalindrome(int n);
int isPrime(int n);
void solveA(char *p, int mat[MAX_LENGTH][MAX_LENGTH], int *i, int *j, int *moveNr);
void solveB(char *p, int mat[MAX_LENGTH][MAX_LENGTH], int *i, int *j, int *moveNr);
void solveC(char *p, int mat[MAX_LENGTH][MAX_LENGTH], int *i, int *j, int *moveNr);

/* Task2 */
void swap(char str1[MAX_LENGTH], char str2[MAX_LENGTH]);
void reverse(char *str);
char* sum(char N1[MAX_LENGTH], char N2[MAX_LENGTH]);
char rotate(char S, int leftMargin, int rightMargin, int K);
void caesar(int K, char S[MAX_LENGTH]);
void vigenere(char K[MAX_LENGTH], char S[MAX_LENGTH], char extendedKey[MAX_LENGTH]);

/* Main */
void SolveTask1();
void SolveTask2();
void SolveTask3();
