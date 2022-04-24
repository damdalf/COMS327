//
// Created by Devin Amdahl on 3/29/22.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include <stdint.h>

#include "poke327.h"

typedef enum __attribute__((__packed__)) movement_type
{
  move_hiker,
  move_rival,
  move_pace,
  move_wander,
  move_sentry,
  move_walk,
  move_pc,
  num_movement_types
} movement_type_t;

typedef enum __attribute__((__packed__)) character_type
{
  char_pc,
  char_hiker,
  char_rival,
  char_other,
  num_character_types
} character_type_t;

extern const char *char_type_name[num_character_types];

extern int32_t move_cost[num_character_types][num_terrain_types];

class NPC : public Character
{
public:
  character_type_t ctype;
  movement_type_t mtype;
  int defeated;
  pair_t dir;

  NPC()
  {

  }

  NPC(character_type_t ctype, movement_type_t mtype, int defeated, pair_t pos, char symbol, int next_turn)
  {
    Character(pos, symbol, next_turn);
    this->ctype = ctype;
    this->mtype = mtype;
    this->defeated = defeated;
    this->dir[dim_y] = 0;
    this->dir[dim_x] = 0;
  }

  virtual ~NPC() {}
};

// class PC : public Character
// {
//   public:
//     PC(pair_t pos, char symbol, int next_turn)
//     {
//       Character(pos, symbol, next_turn);
//     }

//     virtual ~PC() {}
// };

/* character is defined in poke327.h to allow an instance of character
 * in world without including character.h in poke327.h                 */

int32_t cmp_char_turns(const void *key, const void *with);
void delete_character(void *v);
void pathfind(map_t *m);

extern void (*move_func[num_movement_types])(character_t *, pair_t);

int pc_move(char);

#endif
