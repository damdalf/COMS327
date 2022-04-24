//
// Created by Devin Amdahl on 3/29/22.
//

#include <unistd.h>
#include <ncurses.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <cmath>

#include "file_reader.h"
#include "io.h"
#include "character.h"
#include "poke327.h"

#define COLOR_GRAY 8

typedef struct io_message
{
  /* Will print " --more-- " at end of line when another message follows. *
   * Leave 10 extra spaces for that.                                      */
  char msg[71];
  struct io_message *next;
} io_message_t;

static io_message_t *io_head, *io_tail;

void io_init_terminal(void)
{
  initscr();
  raw();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);

  // if (can_change_color())
  // {
  //   init_color(COLOR_GRAY, 245, 245, 245);
  //   init_color(COLOR_RED, 255, 168, 0);
  //   init_color(COLOR_BLUE, 102, 178, 255);
  //   init_color(COLOR_YELLOW, 255, 255, 0);
  // }

  start_color();
  init_pair(COLOR_GRAY, COLOR_GRAY, COLOR_BLACK);
  init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
  init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
  init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
  init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
  init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
  init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
  init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
  init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
}

void io_reset_terminal(void)
{
  endwin();

  while (io_head)
  {
    io_tail = io_head;
    io_head = io_head->next;
    free(io_tail);
  }
  io_tail = NULL;
}

void io_queue_message(const char *format, ...)
{
  io_message_t *tmp;
  va_list ap;

  if (!(tmp = (io_message_t *)malloc(sizeof(*tmp))))
  {
    perror("malloc");
    exit(1);
  }

  tmp->next = NULL;

  va_start(ap, format);

  vsnprintf(tmp->msg, sizeof(tmp->msg), format, ap);

  va_end(ap);

  if (!io_head)
  {
    io_head = io_tail = tmp;
  }
  else
  {
    io_tail->next = tmp;
    io_tail = tmp;
  }
}

static void io_print_message_queue(uint32_t y, uint32_t x)
{
  while (io_head)
  {
    io_tail = io_head;
    attron(COLOR_PAIR(COLOR_CYAN));
    mvprintw(y, x, "%-80s", io_head->msg);
    attroff(COLOR_PAIR(COLOR_CYAN));
    io_head = io_head->next;
    if (io_head)
    {
      attron(COLOR_PAIR(COLOR_CYAN));
      mvprintw(y, x + 70, "%10s", " --more-- ");
      attroff(COLOR_PAIR(COLOR_CYAN));
      refresh();
      getch();
    }
    free(io_tail);
  }
  io_tail = NULL;
}

/**************************************************************************
 * Compares trainer distances from the PC according to the rival distance *
 * map.  This gives the approximate distance that the PC must travel to   *
 * get to the trainer (doesn't account for crossing buildings).  This is  *
 * not the distance from the NPC to the PC unless the NPC is a rival.     *
 *                                                                        *
 * Not a bug.                                                             *
 **************************************************************************/
static int compare_trainer_distance(const void *v1, const void *v2)
{
  const character_t *const *c1 = (const character_t *const *)v1;
  const character_t *const *c2 = (const character_t *const *)v2;

  return (world.rival_dist[(*c1)->pos[dim_y]][(*c1)->pos[dim_x]] -
          world.rival_dist[(*c2)->pos[dim_y]][(*c2)->pos[dim_x]]);
}

static character_t *io_nearest_visible_trainer()
{
  character_t **c, *n;
  uint32_t x, y, count;

  // TODO
  // c = (character_t **)malloc(world.cur_map->num_trainers * sizeof(*c));
  c = (character_t **)(new Character());

  /* Get a linear list of trainers */
  for (count = 0, y = 1; y < MAP_Y - 1; y++)
  {
    for (x = 1; x < MAP_X - 1; x++)
    {
      if (world.cur_map->cmap[y][x] && world.cur_map->cmap[y][x] !=
                                           &world.pc)
      {
        c[count++] = world.cur_map->cmap[y][x];
      }
    }
  }

  /* Sort it by distance from PC */
  qsort(c, count, sizeof(*c), compare_trainer_distance);

  n = c[0];

  delete(c);

  return n;
}

void io_display()
{
  uint32_t y, x;
  character_t *c;

  clear();
  for (y = 0; y < MAP_Y; y++)
  {
    for (x = 0; x < MAP_X; x++)
    {
      if (world.cur_map->cmap[y][x])
      {
        if (world.cur_map->cmap[y][x]->symbol == '@')
        {
        attron(A_BOLD);
        mvaddch(y + 1, x, world.cur_map->cmap[y][x]->symbol);
        attroff(A_BOLD);
        }
        else
        {
        mvaddch(y + 1, x, world.cur_map->cmap[y][x]->symbol);
        }
      }
      else
      {
        switch (world.cur_map->map[y][x])
        {
        case ter_boulder:
        case ter_mountain:
          attron(A_BOLD);
          attron(COLOR_PAIR(COLOR_MAGENTA));
          mvaddch(y + 1, x, '%');
          attroff(COLOR_PAIR(COLOR_MAGENTA));
          attroff(A_BOLD);
          break;
        case ter_tree:
        case ter_forest:
          attron(A_BOLD);
          attron(COLOR_PAIR(COLOR_GREEN));
          mvaddch(y + 1, x, '^');
          attroff(COLOR_PAIR(COLOR_GREEN));
          attroff(A_BOLD);
          break;
        case ter_path:
        case ter_exit:
          attron(COLOR_PAIR(COLOR_YELLOW));
          mvaddch(y + 1, x, '#');
          attroff(COLOR_PAIR(COLOR_YELLOW));
          break;
        case ter_mart:
          attron(A_BOLD);
          attron(COLOR_PAIR(COLOR_BLUE));
          mvaddch(y + 1, x, 'M');
          attroff(COLOR_PAIR(COLOR_BLUE));
          attroff(A_BOLD);
          break;
        case ter_center:
          attron(A_BOLD);
          attron(COLOR_PAIR(COLOR_RED));
          mvaddch(y + 1, x, 'C');
          attroff(COLOR_PAIR(COLOR_RED));
          attroff(A_BOLD);
          break;
        case ter_grass:
          attron(COLOR_PAIR(COLOR_GREEN));
          mvaddch(y + 1, x, ':');
          attroff(COLOR_PAIR(COLOR_GREEN));
          break;
        case ter_clearing:
          attron(COLOR_PAIR(COLOR_GREEN));
          mvaddch(y + 1, x, '.');
          attroff(COLOR_PAIR(COLOR_GREEN));
          break;
        default:
          /* Use zero as an error symbol, since it stands out somewhat, and it's *
           * not otherwise used.                                                 */
          attron(COLOR_PAIR(COLOR_CYAN));
          mvaddch(y + 1, x, '0');
          attroff(COLOR_PAIR(COLOR_CYAN));
        }
      }
    }
  }

  mvprintw(23, 1, "PC position is (%2d,%2d) on map %d%cx%d%c.",
           world.pc.pos[dim_x],
           world.pc.pos[dim_y],
           abs(world.cur_idx[dim_x] - (WORLD_SIZE / 2)),
           world.cur_idx[dim_x] - (WORLD_SIZE / 2) >= 0 ? 'E' : 'W',
           abs(world.cur_idx[dim_y] - (WORLD_SIZE / 2)),
           world.cur_idx[dim_y] - (WORLD_SIZE / 2) <= 0 ? 'N' : 'S');
  mvprintw(22, 1, "%d known %s.", world.cur_map->num_trainers,
           world.cur_map->num_trainers > 1 ? "trainers" : "trainer");
  mvprintw(22, 30, "Nearest visible trainer: ");
  if ((c = io_nearest_visible_trainer()))
  {
    attron(COLOR_PAIR(COLOR_RED));
    mvprintw(22, 55, "%c at %d %c by %d %c.",
             c->symbol,
             abs(c->pos[dim_y] - world.pc.pos[dim_y]),
             ((c->pos[dim_y] - world.pc.pos[dim_y]) <= 0 ? 'N' : 'S'),
             abs(c->pos[dim_x] - world.pc.pos[dim_x]),
             ((c->pos[dim_x] - world.pc.pos[dim_x]) <= 0 ? 'W' : 'E'));
    attroff(COLOR_PAIR(COLOR_RED));
  }
  else
  {
    attron(COLOR_PAIR(COLOR_BLUE));
    mvprintw(22, 55, "NONE.");
    attroff(COLOR_PAIR(COLOR_BLUE));
  }

  io_print_message_queue(0, 0);

  refresh();
}

uint32_t io_teleport_pc(pair_t dest)
{
  /* Just for fun. And debugging.  Mostly debugging. */

  do
  {
    dest[dim_x] = rand_range(1, MAP_X - 2);
    dest[dim_y] = rand_range(1, MAP_Y - 2);
  } while (world.cur_map->cmap[dest[dim_y]][dest[dim_x]] ||
           move_cost[char_pc][world.cur_map->map[dest[dim_y]]
                                                [dest[dim_x]]] == INT_MAX ||
           world.rival_dist[dest[dim_y]][dest[dim_x]] < 0);

  return 0;
}

static void io_scroll_trainer_list(char (*s)[40], uint32_t count)
{
  uint32_t offset;
  uint32_t i;

  offset = 0;

  while (1)
  {
    for (i = 0; i < 13; i++)
    {
      mvprintw(i + 6, 19, " %-40s ", s[i + offset]);
    }
    switch (getch())
    {
    case KEY_UP:
      if (offset)
      {
        offset--;
      }
      break;
    case KEY_DOWN:
      if (offset < (count - 13))
      {
        offset++;
      }
      break;
    case 27:
      return;
    }
  }
}

static void io_list_trainers_display(NPC **c,
                                     uint32_t count)
{
  uint32_t i;
  char (*s)[40]; /* pointer to array of 40 char */

  s = (char (*)[40]) malloc(count * sizeof (*s));

  mvprintw(3, 19, " %-40s ", "");
  /* Borrow the first element of our array for this string: */
  snprintf(s[0], 40, "You know of %d trainers:", count);
  mvprintw(4, 19, " %-40s ", s[0]);
  mvprintw(5, 19, " %-40s ", "");

  for (i = 0; i < count; i++) {
    snprintf(s[i], 40, "%16s %c: %2d %s by %2d %s",
             char_type_name[c[i]->ctype],
             c[i]->symbol,
             abs(c[i]->pos[dim_y] - world.pc.pos[dim_y]),
             ((c[i]->pos[dim_y] - world.pc.pos[dim_y]) <= 0 ?
              "North" : "South"),
             abs(c[i]->pos[dim_x] - world.pc.pos[dim_x]),
             ((c[i]->pos[dim_x] - world.pc.pos[dim_x]) <= 0 ?
              "West" : "East"));
    if (count <= 13) {
      /* Handle the non-scrolling case right here. *
       * Scrolling in another function.            */
      mvprintw(i + 6, 19, " %-40s ", s[i]);
    }
  }

  if (count <= 13) {
    mvprintw(count + 6, 19, " %-40s ", "");
    mvprintw(count + 7, 19, " %-40s ", "Hit escape to continue.");
    while (getch() != 27 /* escape */)
      ;
  } else {
    mvprintw(19, 19, " %-40s ", "");
    mvprintw(20, 19, " %-40s ",
             "Arrows to scroll, escape to continue.");
    io_scroll_trainer_list(s, count);
  }

  free(s);
}

static void io_list_trainers()
{
  character_t **c;
  uint32_t x, y, count;

  // TODO
  // c = (character_t **)malloc(world.cur_map->num_trainers * sizeof(*c));
  c = (character_t **)new Character();

  /* Get a linear list of trainers */
  for (count = 0, y = 1; y < MAP_Y - 1; y++)
  {
    for (x = 1; x < MAP_X - 1; x++)
    {
      if (world.cur_map->cmap[y][x] && world.cur_map->cmap[y][x] !=
                                           &world.pc)
      {
        c[count++] = world.cur_map->cmap[y][x];
      }
    }
  }

  /* Sort it by distance from PC */
  qsort(c, count, sizeof(*c), compare_trainer_distance);

  /* Display it */
  io_list_trainers_display((NPC **)(c), count);
  delete(c);

  /* And redraw the map */
  io_display();
}

void io_pokemart()
{
  mvprintw(0, 0, "Welcome to the Pokemart.  Could I interest you in some Pokeballs?");
  refresh();
  getch();
}

void io_pokemon_center()
{
  mvprintw(0, 0, "Welcome to the Pokemon Center.  How can Nurse Joy assist you?");
  refresh();
  getch();
}

void io_battle(character_t *aggressor, character_t *defender)
{
  NPC *npc;

  io_display();
  mvprintw(0, 0, "Aww, how'd you get so strong?  You and your pokemon must share a special bond!");
  refresh();
  getch();
  io_display();
  mvprintw(0, 0, "Aww, how'd you get so strong?  You and your pokemon must share a special bond!");
  refresh();
  getch();
  if (!(npc = dynamic_cast<NPC *>(aggressor))) {
    npc = dynamic_cast<NPC *>(defender);
  }
  
  npc->defeated = 1;
  if (npc->ctype == char_hiker || npc->ctype == char_rival) {
    npc->mtype = move_wander;
  }
}

// my own function
int manhattan_dist(int y, int x)
{
  int manY = abs(y - 200);
  int manX = abs(x - 200);

  return (manY + manX);
}

//my own function
int calculate_level(int base, int iv, int level)
{
  return ((((base + iv) * 2) * level) / 100) + level + 10;
}

// my own function
int calculate_hp(int base, int iv, int level)
{
  return ((((base + iv) * 2) * level) / 100) + 5;
}

// my own function
void capitalize_name(string &name)
{
  char last = ' ';
  for (string :: iterator i = name.begin(); i != name.end(); i++)
  {
    if (isspace(last) || last == '-')
    {
      *i = toupper(*i);
    }
    else
    {
      *i = tolower(*i);
    }

    last = *i;
  }
}

// my own function, to be modulated later
void generate_pokemon()
{
  int i, j, dist, min_lvl, max_lvl, id, 
  p_level, p_base_hp, p_base_attack, p_base_defense, p_base_special_attack, p_base_special_defense, p_base_speed,
  p_hp_iv, p_attack_iv, p_defense_iv, p_special_attack_iv, p_special_defense_iv, p_speed_iv,
  p_hp, p_attack, p_defense, p_special_attack, p_special_defense, p_speed;
  string p_name, p_move_one_name, p_move_two_name;
  bool p_gender, p_shiny;
  // randomly decide gender
  if (rand() % 2 == 0) p_gender = false; // boy
  else p_gender = true; // girl
  // calculate if Pokemon is shiny
  if (rand() % 8192 == 0) p_shiny = true;
  else p_shiny = false;
  // calculate manhattan distance
  dist = manhattan_dist(world.cur_idx[dim_y], world.cur_idx[dim_x]);
  // calculate minimum and maximum levels
  if (dist <= 200)
  {
    min_lvl = 1;
    max_lvl = abs(dist / 2) + min_lvl;
  }
  else
  {
    min_lvl = abs((dist - 200) / 2);
    max_lvl = 100;
  }
  // check if either min or max level is 0
  if (min_lvl <= 0) min_lvl = 1;
  if (max_lvl <= 0) max_lvl = 1;
  // caluclate level of the pokemon, add one when using modulo to prevent a modulo by 0
  p_level = (rand() % (max_lvl - min_lvl + 1)) + min_lvl;
  // one more than the number of pokemon because of how modulo works
  id = rand() % 807;
  // acquire name of the pokemon
  p_name = world.pokemonList[id].getIdentifier();
  capitalize_name(p_name);
  // acquire all six stats of the pokemon, can't be this simple. do more, lol.
  p_base_hp = world.pokemonStatsList.at(id * 6).getBaseStat();
  p_base_attack = world.pokemonStatsList.at((id  * 6) + 1).getBaseStat();
  p_base_defense = world.pokemonStatsList.at((id * 6) + 2).getBaseStat();
  p_base_special_attack = world.pokemonStatsList.at((id * 6) + 3).getBaseStat();
  p_base_special_defense = world.pokemonStatsList.at((id * 6) + 4).getBaseStat();
  p_base_speed = world.pokemonStatsList.at((id * 6) + 5).getBaseStat();
  // calculate iv levels of the pokemon
  p_hp_iv = rand() % 16;
  p_attack_iv = rand() % 16;
  p_defense_iv = rand() % 16;
  p_special_attack_iv = rand() % 16;
  p_special_defense_iv = rand() % 16;
  p_speed_iv = rand() % 16;
  // calculate levels of the pokemon
  p_hp = calculate_hp(p_base_hp, p_hp_iv, p_level);
  p_attack = calculate_level(p_base_attack, p_attack_iv, p_level);
  p_defense = calculate_level(p_base_defense, p_defense_iv, p_level);
  p_special_attack = calculate_level(p_base_special_attack, p_special_attack_iv, p_level);
  p_special_defense = calculate_level(p_base_special_defense, p_special_defense_iv, p_level);
  p_speed = calculate_level(p_base_speed, p_speed_iv, p_level);
  string valid_moves[1000];
  // iterate through all pokemon moves
  j = 0;
  for(int i = 0; i < 1000; i++)
    {
      // check if version group id is equal to 19, if pokemonMoveID is equal to SpeciesID, and if pokemonMoveMethodID is equal to 1.
      if (world.pokemonMovesList[i].getPokemonID() == world.pokemonList[id].getSpeciesID() && world.pokemonMovesList[i].getVersionGroupID() == 18)
      {
        if (world.pokemonMovesList[i].getPokemonMoveMethodID() == 1)
        {
          valid_moves[j] = world.movesList[i].getIdentifier();
          j++;
        }
      }
    }
  do i = rand() % 1000;
  while (valid_moves[i].empty());
  p_move_one_name = valid_moves[i];
  capitalize_name(p_move_one_name);
  do j = rand() % 1000;
  while (valid_moves[j].empty() || j == i);
  p_move_two_name = valid_moves[j];
  capitalize_name(p_move_two_name);
  // create new window the same size of the map
  WINDOW *p_encounter = newwin(24, 80, 0, 0);
  // enable the keypad
  keypad(p_encounter, true);
  // outline the window
  box(p_encounter, 0, 0);
  // print the window's title
  string s = "You have encountered a wild " + p_name + "!";
  mvwprintw(p_encounter, 1, 1, s.c_str());
  wmove(p_encounter, 2, 1);
  whline(p_encounter, '-', 78);
  // print the Pokemon's stats: HP, Gender, Level, Move One, Move Two
  s = p_name + "'s HP: " + to_string(p_hp) + "/" + to_string(p_hp);
  mvwprintw(p_encounter, 3, 1, s.c_str()); // hp
  if (!p_gender) s = p_name + "'s gender: Male";
  else s = p_name + "'s gender: Female";
  mvwprintw(p_encounter, 4, 1, s.c_str()); // gender
  s = p_name + "'s level: " + to_string(p_level);
  mvwprintw(p_encounter, 5, 1, s.c_str()); // level
  s = p_name + "'s first move: " + p_move_one_name;
  mvwprintw(p_encounter, 6, 1, s.c_str()); // move one
  s = p_name + "'s second move: " + p_move_two_name;
  mvwprintw(p_encounter, 7, 1, s.c_str()); // move two
  // print escape queue
  mvwprintw(p_encounter, 22, 28, "Press 'esc' to run away!");
  // refresh the window
  wrefresh(p_encounter);
  while (getch() != 27) // 'esc'
   ; 
  // close the window
  endwin();
  // redraw the map
  io_display();
}

uint32_t move_pc_dir(uint32_t input, pair_t dest)
{
  dest[dim_y] = world.pc.pos[dim_y];
  dest[dim_x] = world.pc.pos[dim_x];

  switch (input)
  {
  case 1:
  case 2:
  case 3:
    dest[dim_y]++;
    break;
  case 4:
  case 5:
  case 6:
    break;
  case 7:
  case 8:
  case 9:
    dest[dim_y]--;
    break;
  }
  switch (input)
  {
  case 1:
  case 4:
  case 7:
    dest[dim_x]--;
    break;
  case 2:
  case 5:
  case 8:
    break;
  case 3:
  case 6:
  case 9:
    dest[dim_x]++;
    break;
  case '>':
    if (world.cur_map->map[world.pc.pos[dim_y]][world.pc.pos[dim_x]] ==
        ter_mart)
    {
      io_pokemart();
    }
    if (world.cur_map->map[world.pc.pos[dim_y]][world.pc.pos[dim_x]] ==
        ter_center)
    {
      io_pokemon_center();
    }
    break;
  }

  if ((world.cur_map->map[dest[dim_y]][dest[dim_x]] == ter_exit) &&
      (input == 1 || input == 3 || input == 7 || input == 9))
  {
    // Exiting diagonally leads to complicated entry into the new map
    // in order to avoid INT_MAX move costs in the destination.
    // Most easily solved by disallowing such entries here.
    return 1;
  }

  // check if cmap is populated at said location
  if (world.cur_map->cmap[dest[dim_y]][dest[dim_x]]) {
    if (dynamic_cast<NPC *>(world.cur_map->cmap[dest[dim_y]][dest[dim_x]]) &&
        ((NPC *) world.cur_map->cmap[dest[dim_y]][dest[dim_x]])->defeated) {
      // Some kind of greeting here would be nice
      return 1;
  // trigger trainer
    } else if (dynamic_cast<NPC *>
               (world.cur_map->cmap[dest[dim_y]][dest[dim_x]])) {
      io_battle(&world.pc, world.cur_map->cmap[dest[dim_y]][dest[dim_x]]);
      // Not actually moving, so set dest back to PC position
      dest[dim_x] = world.pc.pos[dim_x];
      dest[dim_y] = world.pc.pos[dim_y];
    }
  }
  // todo check if terrain is grass 
  else if (world.cur_map->map[dest[dim_y]][dest[dim_x]] == ter_grass)
      {
        if (rand() % 10 == 0) generate_pokemon();
      }

  if (move_cost[char_pc][world.cur_map->map[dest[dim_y]][dest[dim_x]]] ==
      INT_MAX)
  {
    return 1;
  }

  return 0;
}

void io_teleport_world(pair_t dest)
{
  int x, y;
  char str[3] = "%d";

  world.cur_map->cmap[world.pc.pos[dim_y]][world.pc.pos[dim_x]] = NULL;

  mvprintw(0, 0, "Enter x [-200, 200]: ");
  refresh();
  echo();
  curs_set(1);
  mvscanw(0, 21, str, &x);
  mvprintw(0, 0, "Enter y [-200, 200]:          ");
  refresh();
  mvscanw(0, 21, str, &y);
  refresh();
  noecho();
  curs_set(0);

  if (x < -200)
  {
    x = -200;
  }
  if (x > 200)
  {
    x = 200;
  }
  if (y < -200)
  {
    y = -200;
  }
  if (y > 200)
  {
    y = 200;
  }

  x += 200;
  y += 200;

  world.cur_idx[dim_x] = x;
  world.cur_idx[dim_y] = y;

  new_map(1);
  io_teleport_pc(dest);
}

void io_handle_input(pair_t dest)
{
  uint32_t turn_not_consumed;
  int key;

  do
  {
    switch (key = getch())
    {
    case '7':
    case 'y':
    case KEY_HOME:
      turn_not_consumed = move_pc_dir(7, dest);
      break;
    case '8':
    case 'k':
    case KEY_UP:
      turn_not_consumed = move_pc_dir(8, dest);
      break;
    case '9':
    case 'u':
    case KEY_PPAGE:
      turn_not_consumed = move_pc_dir(9, dest);
      break;
    case '6':
    case 'l':
    case KEY_RIGHT:
      turn_not_consumed = move_pc_dir(6, dest);
      break;
    case '3':
    case 'n':
    case KEY_NPAGE:
      turn_not_consumed = move_pc_dir(3, dest);
      break;
    case '2':
    case 'j':
    case KEY_DOWN:
      turn_not_consumed = move_pc_dir(2, dest);
      break;
    case '1':
    case 'b':
    case KEY_END:
      turn_not_consumed = move_pc_dir(1, dest);
      break;
    case '4':
    case 'h':
    case KEY_LEFT:
      turn_not_consumed = move_pc_dir(4, dest);
      break;
    case '5':
    case ' ':
    case '.':
    case KEY_B2:
      dest[dim_y] = world.pc.pos[dim_y];
      dest[dim_x] = world.pc.pos[dim_x];
      turn_not_consumed = 0;
      break;
    case '>':
      turn_not_consumed = move_pc_dir('>', dest);
      break;
    case 'Q':
      dest[dim_y] = world.pc.pos[dim_y];
      dest[dim_x] = world.pc.pos[dim_x];
      world.quit = 1;
      turn_not_consumed = 0;
      break;
      break;
    case 't':
      /* Teleport the PC to a random place in the map.              */
      io_teleport_pc(dest);
      turn_not_consumed = 0;
      break;
    case 'T':
      /* Teleport the PC to any map in the world.                   */
      io_teleport_world(dest);
      turn_not_consumed = 0;
      break;
    case 'm':
      io_list_trainers();
      turn_not_consumed = 1;
      break;
    case 'q':
      /* Demonstrate use of the message queue.  You can use this for *
       * printf()-style debugging (though gdb is probably a better   *
       * option.  Not that it matters, but using this command will   *
       * waste a turn.  Set turn_not_consumed to 1 and you should be *
       * able to figure out why I did it that way.                   */
      io_queue_message("This is the first message.");
      io_queue_message("Since there are multiple messages, "
                       "you will see \"more\" prompts.");
      io_queue_message("You can use any key to advance through messages.");
      io_queue_message("Normal gameplay will not resume until the queue "
                       "is empty.");
      io_queue_message("Long lines will be truncated, not wrapped.");
      io_queue_message("io_queue_message() is variadic and handles "
                       "all printf() conversion specifiers.");
      io_queue_message("Did you see %s?", "what I did there");
      io_queue_message("When the last message is displayed, there will "
                       "be no \"more\" prompt.");
      io_queue_message("Have fun!  And happy printing!");
      io_queue_message("Oh!  And use 'Q' to quit!");

      dest[dim_y] = world.pc.pos[dim_y];
      dest[dim_x] = world.pc.pos[dim_x];
      turn_not_consumed = 0;
      break;
    default:
      /* Also not in the spec.  It's not always easy to figure out what *
       * key code corresponds with a given keystroke.  Print out any    *
       * unhandled key here.  Not only does it give a visual error      *
       * indicator, but it also gives an integer value that can be used *
       * for that key in this (or other) switch statements.  Printed in *
       * octal, with the leading zero, because ncurses.h lists codes in *
       * octal, thus allowing us to do reverse lookups.  If a key has a *
       * name defined in the header, you can use the name here, else    *
       * you can directly use the octal value.                          */
      mvprintw(0, 0, "Unbound key: %#o ", key);
      turn_not_consumed = 1;
    }
    refresh();
  } while (turn_not_consumed);
}