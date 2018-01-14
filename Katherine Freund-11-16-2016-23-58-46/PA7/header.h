#pragma once



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct stats
{
	char initials[4];
	int score;
} Stats;

int print_menu(void);
void print_rules(void);
void get_initials(Stats player);
int get_difficulty(void);
void write_stats(Stats player, FILE *infile);
int get_number(int level);
int get_operator(int level);
int ask_problem(int level);
void print_problem(int set[7], int temp);
int solve_problem(int set[7], int temp);
int order_helper(int n);
int solve_helper(int set[7], int order[3], int temp);
int simple_problem(int a, int op, int b);
