#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LENGTH 1000

int isPalindrome(int n);
int isPrime(int n);
void solveA(char *p, int mat[MAX_LENGTH][MAX_LENGTH],
            int *i, int *j, int *moveNr);
void solveB(char *p, int mat[MAX_LENGTH][MAX_LENGTH],
            int *i, int *j, int *moveNr);
void solveC(char *p, int mat[MAX_LENGTH][MAX_LENGTH],
            int *i, int *j, int *moveNr);
void SolveTask1();
void SolveTask2();
void SolveTask3();
