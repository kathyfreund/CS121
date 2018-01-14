#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//Initial Menu stuff
int print_game_menu(void);
void print_game_rules(void);

//Roll Die Stuff
int roll_die(void);
int roll_all_dice(int dice_values[5], int roll_values[5]);
int re_roll_dice(int roll_values[5]);

//Stuff to determine points
void get_faces(int dice_values[5], int faces[7]);
int get_combo(int faces[7], int combinations[13], int dice_values[5]);
int test_straight(int faces[7], int straight_size);

//New game, Play again?
int ask_new_game(void);
void reset_combinations(int combinations[13]);
