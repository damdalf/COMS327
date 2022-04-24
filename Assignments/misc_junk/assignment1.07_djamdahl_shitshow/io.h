//
// Created by Devin Amdahl on 3/29/22.
//

#ifndef IO_H
#define IO_H

#include "file_reader.h"

typedef class Character character_t;
typedef int16_t pair_t[2];

void io_init_terminal(void);
void io_reset_terminal(void);
void io_display(void);
void io_handle_input(pair_t dest);
void io_queue_message(const char *format, ...);
void io_battle(character_t *aggressor, character_t *defender);

// my own function
int manhattan_dist(int, int);
//my own function
int calculate_level(int, int, int);
// my own function
int calculate_hp(int, int, int);
// my own function
void generate_pokemon();


#endif
