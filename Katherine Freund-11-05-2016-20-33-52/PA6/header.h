#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WATER '~'
#define HIT '@'
#define MISS 'm'

typedef enum boolean
{
	FALSE, TRUE
} Boolean;

typedef struct stats
{
	int shots_hit;
	int shots_miss;
	int shots_total;
	double shots_ratio;
	Boolean is_win;
} Stats;


//Start of game
int print_game_menu(void);
int ask_new_game(void);
void print_game_rules(void);

//Start of NEW game
void init_board(char board[10][10]);
int determine_setup(void);
int first_play(void);

//Ship Placements
void placement_random(char board[10][10], char ship, int size);
void placement_manual(char board[10][10], char ship, int size);

//Actual Game Play
void print_board(char board[10][10]);
void random_shot(char board[10][10], FILE *outfile, Stats p);
int check_over(char board[10][10]);
void make_shot(char board[10][10], FILE *outfile, Stats p);
void print_enemy(char board[10][10]);
int check_sunk(char board[10][10], char ship, int size);
void check_all_sunk(char board[10][10], FILE *outfile);

//Stats
void calc_ratio(Stats p);
void print_stats(FILE *outfile, Stats p1, Stats p2);