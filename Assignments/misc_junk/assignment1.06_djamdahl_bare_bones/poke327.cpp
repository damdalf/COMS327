#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <sys/time.h>
#include <assert.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "heap.h"
#include "poke327.h"
#include "character.h"
#include "io.h"

using namespace std;

class Pokemon
{
public:
    int id;
    string identifier;
    int species_id;
    int height;
    int weight;
    int base_experience;
    int order;
    int is_default;

    Pokemon(int id, string identifier, int species_id, int height, int weight, int base_experience, int order, int is_default)
    {
        this->id = id;
        this->identifier = identifier;
        this->species_id = species_id;
        this->height = height;
        this->weight = weight;
        this->base_experience = base_experience;
        this->order = order;
        this->is_default = is_default;
    }
};

class Move
{
public:
    int id;
    string identifier;
    int generation_id;
    int type_id;
    int power;
    int pp;
    int accuracy;
    int priority;
    int target_id;
    int damage_class_id;
    int effect_id;
    int effect_chance;
    int contest_type_id;
    int contest_effect_id;
    int super_contest_effect_id;
    
    Move(int id, string identifier, int generation_id, int type_id, int power, int pp, int accuracy, int priority, int target_id, int damage_class_id, int effect_id, int effect_chance, int contest_type_id, int contest_effect_id, int super_contest_effect_id)
    {
        this->id = id;
        this->identifier = identifier;
        this->generation_id = generation_id;
        this->type_id = type_id;
        this->power = power;
        this->pp = pp;
        this->accuracy = accuracy;
        this->priority = priority;
        this->target_id = target_id;
        this->damage_class_id = damage_class_id;
        this->effect_id = effect_id;
        this->effect_chance = effect_chance;
        this->contest_type_id = contest_type_id;
        this->contest_effect_id = contest_effect_id;
        this->super_contest_effect_id = super_contest_effect_id;
    }
};

class Pokemon_Move
{
public:
    int pokemon_id;
    int version_group_id;
    int move_id;
    int pokemon_move_method_id;
    int level;
    int order;

    Pokemon_Move(int pokemon_id, int version_group_id, int move_id, int pokemon_move_method_id, int level, int order)
    {
        this->pokemon_id = pokemon_id;
        this->version_group_id = version_group_id;
        this->move_id = move_id;
        this->pokemon_move_method_id = pokemon_move_method_id;
        this->level = level;
        this->order = order;
    }
};

class Pokemon_Species
{
public:
    int id;
    string identifier;
    int generation_id;
    int evolves_from_species_id;
    int evolution_chain_id;
    int color_id;
    int shape_id;
    int habitat_id;
    int gender_rate;
    int capture_rate;
    int base_happiness;
    int is_baby;
    int hatch_counter;
    int has_gender_differences;
    int growth_rate_id;
    int forms_switchable;
    int is_legendary;
    int is_mythical;
    int order;
    int conquest_order;

    Pokemon_Species(int id, string identifier, int generation_id, int evolves_from_species_id, int evolution_chain_id, int color_id, int shape_id, int habitat_id,
                    int gender_rate, int capture_rate, int base_happiness, int is_baby, int hatch_counter, int has_gender_differences, int growth_rate_id,
                    int forms_switchable, int is_legendary, int is_mythical, int order, int conquest_order)
    {
        this->id = id;
        this->identifier = identifier;
        this->generation_id = generation_id;
        this->evolves_from_species_id = evolves_from_species_id;
        this->evolution_chain_id = evolution_chain_id;
        this->color_id = color_id;
        this->shape_id = shape_id;
        this->habitat_id = habitat_id;
        this->gender_rate = gender_rate;
        this->capture_rate = capture_rate;
        this->base_happiness = base_happiness;
        this->is_baby = is_baby;
        this->hatch_counter = hatch_counter;
        this->has_gender_differences = has_gender_differences;
        this->growth_rate_id = growth_rate_id;
        this->forms_switchable = forms_switchable;
        this->is_legendary = is_legendary;
        this->is_mythical = is_mythical;
        this->order = order;
        this->conquest_order = conquest_order;
    }
};

class Experience
{
public:
    int growth_rate_id;
    int level;
    int experience;

    Experience(int growth_rate_id, int level, int experience)
    {
        this->growth_rate_id = growth_rate_id;
        this->level = level;
        this->experience = experience;
    }
};

class Type_Name
{
public:
    int type_id;
    int local_language_id;
    string name;

    Type_Name(int type_id, int local_language_id, string name)
    {
        this->type_id = type_id;
        this->local_language_id = local_language_id;
        this->name = name;
    }
};

void parsePokemonList(vector<Pokemon> &pokemonList)
{
    ifstream in_file;
    vector<string> row;
    string line, token;

    int id, species_id, height, weight, base_experience, order, is_default;
    string identifier;

    in_file.open("pokemon.csv");

    if (!in_file.is_open())
    {
        cout << "ERROR: POKEMON.CSV COULD NOT BE OPENED!";
        return;
    }

    getline(in_file, line);
    line = "";

    // file ensured to be open at this point, so begin reading from file.
    while (!in_file.eof())
    {
        row.clear();
        // get line of input from csv file
        getline(in_file, line);
        // associate string with a stream.
        stringstream s(line);

        // tokenize stream based on ',' and then fill with data
        while (getline(s, token, ','))
        {
            row.push_back(token);
        }

        if (row[0] == "") id = -1;
        else id = stoi(row[0]);
        if (row[1] == "") identifier = "-1";
        else identifier = row[1];
        if (row[2] == "") species_id = -1;
        else species_id = stoi(row[2]);
        if (row[3] == "") height = -1;
        else height = stoi(row[3]);
        if (row[4] == "") weight = -1;
        else weight = stoi(row[4]);
        if (row[5] == "") base_experience = -1;
        else base_experience = stoi(row[5]);
        if (row[6] == "") order = -1;
        else order = stoi(row[6]);
        if (row[7] == "") is_default = -1;
        else is_default = stoi(row[7]);

        pokemonList.push_back(Pokemon(id, identifier, species_id, height, weight, base_experience, order, is_default));
    }

    // close the file
    in_file.close();
}

void printPokemonList(vector<Pokemon> &pokemonList)
{
    int i;
    cout << "PRINTING POKEMON LIST:" << endl;

    for (i = 0; i < pokemonList.size() - 1; i++)
    {
        cout << "ID: " << pokemonList[i].id << endl;
        cout << "IDENTIFIER: " << pokemonList[i].identifier << endl;
        cout << "HEIGHT: " << pokemonList[i].height << endl;
        cout << "WEIGHT: " << pokemonList[i].weight << endl;
        cout << "BASE EXPERIENCE: " << pokemonList[i].base_experience << endl;
        cout << "ORDER: " << pokemonList[i].order << endl;
        cout << "IS DEFAULT: " << pokemonList[i].is_default << endl;
        cout << endl;
    }
}

void parseMovesList(vector<Move> &movesList)
{
    ifstream in_file;
    vector<string> row;
    string line, token;

    int id, generation_id, type_id, power, pp, accuracy, priority, target_id, damage_class_id, effect_id, effect_chance, contest_type_id, contest_effect_id, super_contest_effect_id;
    string identifier;

    in_file.open("moves.csv");

    if (!in_file.is_open())
    {
        cout << "ERROR: MOVES.CSV COULD NOT BE OPENED!";
        return;
    }

    // skip the first line
    getline(in_file, line);
    line = "";

    // file ensured to be open at this point, so begin reading from file.
    while (!in_file.eof())
    {
        row.clear();
        // get line of input from csv file
        getline(in_file, line);
        // associate string with a stream.
        stringstream s(line);

        // tokenize stream based on ',' and then fill with data
        while (getline(s, token, ','))
        {
            row.push_back(token);
        }

        if (row[0] == "") id = -1;
        else id = stoi(row[0]);
        if (row[1] == "") identifier = "-1";
        else identifier = row[1];
        if (row[2] == "") generation_id = -1;
        else generation_id = stoi(row[2]);
        if (row[3] == "") type_id = -1;
        else type_id = stoi(row[3]);
        if (row[4] == "") power = -1;
        else power = stoi(row[4]);
        if (row[5] == "") pp = -1;
        else pp = stoi(row[5]);
        if (row[6] == "") accuracy = -1;
        else accuracy = stoi(row[6]);
        if (row[7] == "") priority = -1;
        else priority = stoi(row[7]);
        if (row[8] == "") target_id = -1;
        else target_id = stoi(row[8]);
        if (row[9] == "") damage_class_id = -1;
        else damage_class_id = stoi(row[9]);
        if (row[10] == "") effect_id = -1;
        else effect_id = stoi(row[10]);
        if (row[11] == "") effect_chance = -1;
        else effect_chance = stoi(row[11]);
        if (row[12] == "") contest_type_id = -1;
        else contest_type_id = stoi(row[12]);
        if (row[13] == "") contest_effect_id = -1;
        else contest_effect_id = stoi(row[13]);
        if (row[14] == "" || row[14] == "\n") super_contest_effect_id = -1;
        else super_contest_effect_id = stoi(row[14]);

        movesList.push_back(Move(id, identifier, generation_id, type_id, power, pp, accuracy, priority, target_id, damage_class_id, effect_id, effect_chance, contest_type_id, contest_effect_id, super_contest_effect_id));
    }

    // close the file
    in_file.close();
}

void printMovesList (vector<Move> &movesList)
{
    int i;
    cout << "PRINTING MOVE LIST:" << endl;

    for (i = 0; i < movesList.size() - 1; i++)
    {
        cout << "ID: " << movesList[i].id << endl;
        cout << "IDENTIFIER: " << movesList[i].identifier << endl;
        cout << "GENERATION ID: " << movesList[i].generation_id << endl;
        cout << "TYPE ID: " << movesList[i].type_id << endl;
        cout << "POWER: " << movesList[i].power << endl;
        cout << "PP: " << movesList[i].pp << endl;
        cout << "ACCURACY: " << movesList[i].accuracy << endl;
        cout << "PRIORITY: " << movesList[i].priority << endl;
        cout << "TARGET ID: " << movesList[i].target_id << endl;
        cout << "DAMAGE CLASS ID: " << movesList[i].damage_class_id << endl;
        cout << "EFFECT ID: " << movesList[i].effect_id << endl;
        cout << "EFFECT CHANCE: " << movesList[i].effect_chance << endl;
        cout << "CONTEST TYPE ID: " << movesList[i].contest_type_id << endl;
        cout << "CONTEST EFFECT ID: " << movesList[i].contest_effect_id << endl;
        cout << "SUPER CONTEST EFFECT ID: " << movesList[i].super_contest_effect_id << endl;
        cout << endl;
    }
}

void parsePokemonMovesList(vector<Pokemon_Move> &pokemonMovesList)
{
    ifstream in_file;
    vector<string> row;
    string line, token;

    int pokemon_id, version_group_id, move_id, pokemon_move_method_id, level, order;

    in_file.open("pokemon_moves.csv");

    if (!in_file.is_open())
    {
        cout << "ERROR: POKEMON_MOVES.CSV COULD NOT BE OPENED!";
        return;
    }

    getline(in_file, line);
    line = "";

    // file ensured to be open at this point, so begin reading from file.
    while (!in_file.eof())
    {
        row.clear();
        // get line of input from csv file
        getline(in_file, line);
        // associate string with a stream.
        stringstream s(line);

        // tokenize stream based on ',' and then fill with data
        while (getline(s, token, ','))
        {
            row.push_back(token);
        }

        if (row[0] == "") pokemon_id = -1;
        else pokemon_id = stoi(row[0]);
        if (row[1] == "") version_group_id = -1;
        else version_group_id = stoi(row[1]);
        if (row[2] == "") move_id = -1;
        else move_id = stoi(row[2]);
        if (row[3] == "") pokemon_move_method_id = -1;
        else pokemon_move_method_id = stoi(row[3]);
        if (row[4] == "") level = -1;
        else level = stoi(row[4]);
        if (row[5] == "" || row[5] == "\n") order = -1;
        else order = stoi(row[5]);

        pokemonMovesList.push_back(Pokemon_Move(pokemon_id, version_group_id, move_id, pokemon_move_method_id, level, order));
    }

    // close the file
    in_file.close();
}

void printPokemonMovesList(vector<Pokemon_Move> &pokemonMovesList)
{
    int i;
    cout << "PRINTING POKEMON MOVE LIST:" << endl;

    for (i = 0; i < pokemonMovesList.size() - 1; i++)
    {
        cout << "POKEMON ID: " << pokemonMovesList[i].pokemon_id << endl;
        cout << "VERSION GROUP ID: " << pokemonMovesList[i].version_group_id << endl;
        cout << "MOVE ID: " << pokemonMovesList[i].move_id << endl;
        cout << "POKEMON MOVE METHOD ID: " << pokemonMovesList[i].pokemon_move_method_id << endl;
        cout << "LEVEL: " << pokemonMovesList[i].level << endl;
        cout << "ORDER: " << pokemonMovesList[i].order << endl;
        cout << endl;
    }
}

void parsePokemonSpeciesList(vector<Pokemon_Species> &pokemonSpeciesList)
{
    ifstream in_file;
    vector<string> row;
    string line, token;

    int id ,generation_id, evolves_from_species_id, evolution_chain_id, color_id, shape_id, habitat_id, gender_rate, capture_rate, base_happiness, is_baby,
    hatch_counter, has_gender_differences, growth_rate_id, forms_switchable, is_legendary, is_mythical, order, conquest_order;
    string identifier;

    in_file.open("pokemon_species.csv");

    if (!in_file.is_open())
    {
        cout << "ERROR: POKEMON_SPECIES.CSV COULD NOT BE OPENED!";
        return;
    }

    // skip the first line
    getline(in_file, line);
    line = "";

    // file ensured to be open at this point, so begin reading from file.
    while (!in_file.eof())
    {
        row.clear();
        // get line of input from csv file
        getline(in_file, line);
        // associate string with a stream.
        stringstream s(line);

        // tokenize stream based on ',' and then fill with data
        while (getline(s, token, ','))
        {
            row.push_back(token);
        }

        if (row[0] == "") id = -1;
        else id = stoi(row[0]);
        if (row[1] == "") identifier = "-1";
        else identifier = row[1];
        if (row[2] == "") generation_id = -1;
        else generation_id = stoi(row[2]);
        if (row[3] == "") evolves_from_species_id = -1;
        else evolves_from_species_id = stoi(row[3]);
        if (row[4] == "") evolution_chain_id = -1;
        else evolution_chain_id = stoi(row[4]);
        if (row[5] == "") color_id = -1;
        else color_id = stoi(row[5]);
        if (row[6] == "") shape_id = -1;
        else shape_id = stoi(row[6]);
        if (row[7] == "") habitat_id = -1;
        else habitat_id = stoi(row[7]);
        if (row[8] == "") gender_rate = -1;
        else gender_rate = stoi(row[8]);
        if (row[9] == "") capture_rate = -1;
        else capture_rate = stoi(row[9]);
        if (row[10] == "") base_happiness = -1;
        else base_happiness = stoi(row[10]);
        if (row[11] == "") is_baby = -1;
        else is_baby = stoi(row[11]);
        if (row[12] == "") hatch_counter = -1;
        else hatch_counter = stoi(row[12]);
        if (row[13] == "") has_gender_differences = -1;
        else has_gender_differences = stoi(row[13]);
        if (row[14] == "") growth_rate_id = -1;
        else growth_rate_id = stoi(row[14]);
        if (row[15] == "") forms_switchable = -1;
        else forms_switchable = stoi(row[15]);
        if (row[16] == "") is_legendary = -1;
        else is_legendary = stoi(row[16]);
        if (row[17] == "") is_mythical = -1;
        else is_mythical = stoi(row[17]);
        if (row[18] == "") order = -1;
        else order = stoi(row[18]);
        if (row[19] == "" || row[19] == "\n") conquest_order = -1;
        else conquest_order = stoi(row[19]);

        pokemonSpeciesList.push_back(Pokemon_Species(id, identifier, generation_id, evolves_from_species_id, evolution_chain_id, color_id, shape_id, habitat_id, gender_rate, capture_rate, base_happiness, is_baby,
                                          hatch_counter, has_gender_differences, growth_rate_id, forms_switchable, is_legendary, is_mythical, order, conquest_order));
    }

    // close the file
    in_file.close();
}

void printPokemonSpeciesList(vector<Pokemon_Species> &pokemonSpeciesList)
{
    int i;
    cout << "PRINTING POKEMON SPECIES LIST:" << endl;

    for (i = 0; i < pokemonSpeciesList.size() - 1; i++)
    {
        cout << "ID: " << pokemonSpeciesList[i].id << endl;
        cout << "IDENTIFIER: " << pokemonSpeciesList[i].identifier << endl;
        cout << "GENERATION ID: " << pokemonSpeciesList[i].generation_id << endl;
        cout << "EVOLVES FROM SPECIES ID: " << pokemonSpeciesList[i].evolves_from_species_id << endl;
        cout << "EVOLUTION CHAIN ID: " << pokemonSpeciesList[i].evolution_chain_id << endl;
        cout << "COLOR ID: " << pokemonSpeciesList[i].color_id << endl;
        cout << "SHAPE ID: " << pokemonSpeciesList[i].shape_id << endl;
        cout << "HABITAT ID: " << pokemonSpeciesList[i].habitat_id << endl;
        cout << "GENDER RATE: " << pokemonSpeciesList[i].gender_rate << endl;
        cout << "CAPTURE RATE: " << pokemonSpeciesList[i].capture_rate << endl;
        cout << "BASE HAPPINESS: " << pokemonSpeciesList[i].base_happiness << endl;
        cout << "IS BABY: " << pokemonSpeciesList[i].is_baby << endl;
        cout << "HATCH COUNTER: " << pokemonSpeciesList[i].hatch_counter << endl;
        cout << "HAS GENDER DIFFERENCES: " << pokemonSpeciesList[i].has_gender_differences << endl;
        cout << "GROWTH RATE ID: " << pokemonSpeciesList[i].growth_rate_id << endl;
        cout << "FORMS SWITCHABLE: " << pokemonSpeciesList[i].forms_switchable << endl;
        cout << "IS LEGENDARY: " << pokemonSpeciesList[i].is_legendary << endl;
        cout << "IS MYTHICAL: " << pokemonSpeciesList[i].is_mythical << endl;
        cout << "ORDER: " << pokemonSpeciesList[i].order << endl;
        cout << "CONQUEST ORDER: " << pokemonSpeciesList[i].conquest_order << endl;
        cout << endl;
    }
}

void parseExperienceList(vector<Experience> &experienceList)
{
    ifstream in_file;
    vector<string> row;
    string line, token;

    int growth_rate_id, level, experience;

    in_file.open("experience.csv");

    if (!in_file.is_open())
    {
        cout << "ERROR: EXPERIENCE.CSV COULD NOT BE OPENED!";
        return;
    }

    getline(in_file, line);
    line = "";

    // file ensured to be open at this point, so begin reading from file.
    while (!in_file.eof())
    {
        row.clear();
        // get line of input from csv file
        getline(in_file, line);
        // associate string with a stream.
        stringstream s(line);

        // tokenize stream based on ',' and then fill with data
        while (getline(s, token, ','))
        {
            row.push_back(token);
        }

        if (row[0] == "") growth_rate_id = -1;
        else growth_rate_id = stoi(row[0]);
        if (row[1] == "") level = -1;
        else level = stoi(row[1]);
        if (row[2] == "" || row[2] == "\n") experience = -1;
        else experience = stoi(row[2]);

        experienceList.push_back(Experience(growth_rate_id, level, experience));
    }

    // close the file
    in_file.close();
}

void printExperienceList(vector<Experience> &experienceList)
{
    int i;
    cout << "PRINTING EXPERIENCE LIST:" << endl;

    for (i = 0; i < experienceList.size() - 1; i++)
    {
        cout << "GROWTH RATE ID: " << experienceList[i].growth_rate_id << endl;
        cout << "LEVEL: " << experienceList[i].level << endl;
        cout << "EXPERIENCE: " << experienceList[i].experience << endl;
        cout << endl;
    }
}

void parseTypeNameList(vector<Type_Name> &typeNameList)
{
    ifstream in_file;
    vector<string> row;
    string line, token;

    int type_id, local_language_id;
    string name;

    in_file.open("type_names.csv");

    if (!in_file.is_open())
    {
        cout << "ERROR: TYPE_NAMES.CSV COULD NOT BE OPENED!";
        return;
    }

    getline(in_file, line);
    line = "";

    // file ensured to be open at this point, so begin reading from file.
    while (!in_file.eof())
    {
        row.clear();
        // get line of input from csv file
        getline(in_file, line);
        // associate string with a stream.
        stringstream s(line);

        // tokenize stream based on ',' and then fill with data
        while (getline(s, token, ','))
        {
            row.push_back(token);
        }

        if (row[0] == "") type_id = -1;
        else type_id = stoi(row[0]);
        if (row[1] == "") local_language_id = -1;
        else local_language_id = stoi(row[1]);
        if (row[2] == "" || row[2] == "\n") name = -1;
        else name = row[2];

        typeNameList.push_back(Type_Name(type_id, local_language_id, name));
    }

    // close the file
    in_file.close();
}

void printTypeNameList(vector<Type_Name> &typeNameList)
{
    int i;
    cout << "PRINTING EXPERIENCE LIST:" << endl;

    for (i = 0; i < typeNameList.size() - 1; i++)
    {
        if (typeNameList[i].local_language_id == 9)
        {
            cout << "TYPE ID: " << typeNameList[i].type_id << endl;
            cout << "LOCAL LANGUAGE ID: " << typeNameList[i].local_language_id << endl;
            cout << "NAME: " << typeNameList[i].name << endl;
            cout << endl;
        }
    }
}

void askUserForFile()
{
    vector<Pokemon> pokemonList;
    vector<Move> movesList;
    vector<Pokemon_Move> pokemonMovesList;
    vector<Pokemon_Species> pokemonSpeciesList;
    vector<Experience> experienceList;
    vector <Type_Name> typeNameList;

    string file_name;

    // get file name from user, and try to open
    cout << "Please enter the file's name that you would like to parse: ";
    // if this doesn't work just use cin >> and then cin.ignore
    getline(cin, file_name);
    cout << endl;

    if (file_name == "pokemon")
    {
        parsePokemonList(pokemonList);
        printPokemonList(pokemonList);
    }
    
    else if (file_name == "moves")
    {
        parseMovesList(movesList);
        printMovesList(movesList);
    }
    else if (file_name == "pokemon_moves")
    {
        parsePokemonMovesList(pokemonMovesList);
        printPokemonMovesList(pokemonMovesList);
    }
    else if (file_name == "pokemon_species")
    {
        parsePokemonSpeciesList(pokemonSpeciesList);
        printPokemonSpeciesList(pokemonSpeciesList);
    }
    else if (file_name == "experience")
    {
        parseExperienceList(experienceList);
        printExperienceList(experienceList);
    }
    else if (file_name == "type_names")
    {
        parseTypeNameList(typeNameList);
        printTypeNameList(typeNameList);
    }
    else cout << "ERROR: FILE COULD NOT BE FOUND!" << endl;
}

typedef struct queue_node {
  int x, y;
  struct queue_node *next;
} queue_node_t;

world_t world;

pair_t all_dirs[8] = {
  { -1, -1 },
  { -1,  0 },
  { -1,  1 },
  {  0, -1 },
  {  0,  1 },
  {  1, -1 },
  {  1,  0 },
  {  1,  1 },
};

static int32_t path_cmp(const void *key, const void *with) {
  return ((path_t *) key)->cost - ((path_t *) with)->cost;
}

static int32_t edge_penalty(int8_t x, int8_t y)
{
  return (x == 1 || y == 1 || x == MAP_X - 2 || y == MAP_Y - 2) ? 2 : 1;
}

static void dijkstra_path(map_t *m, pair_t from, pair_t to)
{
  static path_t path[MAP_Y][MAP_X], *p;
  static uint32_t initialized = 0;
  heap_t h;
  uint32_t x, y;

  if (!initialized) {
    for (y = 0; y < MAP_Y; y++) {
      for (x = 0; x < MAP_X; x++) {
        path[y][x].pos[dim_y] = y;
        path[y][x].pos[dim_x] = x;
      }
    }
    initialized = 1;
  }
  
  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      path[y][x].cost = INT_MAX;
    }
  }

  path[from[dim_y]][from[dim_x]].cost = 0;

  heap_init(&h, path_cmp, NULL);

  for (y = 1; y < MAP_Y - 1; y++) {
    for (x = 1; x < MAP_X - 1; x++) {
      path[y][x].hn = heap_insert(&h, &path[y][x]);
    }
  }

  while ((p = (path_t*)heap_remove_min(&h))) {
    p->hn = NULL;

    if ((p->pos[dim_y] == to[dim_y]) && p->pos[dim_x] == to[dim_x]) {
      for (x = to[dim_x], y = to[dim_y];
           (x != from[dim_x]) || (y != from[dim_y]);
           p = &path[y][x], x = p->from[dim_x], y = p->from[dim_y]) {
        mapxy(x, y) = ter_path;
        heightxy(x, y) = 0;
      }
      heap_delete(&h);
      return;
    }

    if ((path[p->pos[dim_y] - 1][p->pos[dim_x]    ].hn) &&
        (path[p->pos[dim_y] - 1][p->pos[dim_x]    ].cost >
         ((p->cost + heightpair(p->pos)) *
          edge_penalty(p->pos[dim_x], p->pos[dim_y] - 1)))) {
      path[p->pos[dim_y] - 1][p->pos[dim_x]    ].cost =
        ((p->cost + heightpair(p->pos)) *
         edge_penalty(p->pos[dim_x], p->pos[dim_y] - 1));
      path[p->pos[dim_y] - 1][p->pos[dim_x]    ].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y] - 1][p->pos[dim_x]    ].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y] - 1]
                                           [p->pos[dim_x]    ].hn);
    }
    if ((path[p->pos[dim_y]    ][p->pos[dim_x] - 1].hn) &&
        (path[p->pos[dim_y]    ][p->pos[dim_x] - 1].cost >
         ((p->cost + heightpair(p->pos)) *
          edge_penalty(p->pos[dim_x] - 1, p->pos[dim_y])))) {
      path[p->pos[dim_y]][p->pos[dim_x] - 1].cost =
        ((p->cost + heightpair(p->pos)) *
         edge_penalty(p->pos[dim_x] - 1, p->pos[dim_y]));
      path[p->pos[dim_y]    ][p->pos[dim_x] - 1].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y]    ][p->pos[dim_x] - 1].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y]    ]
                                           [p->pos[dim_x] - 1].hn);
    }
    if ((path[p->pos[dim_y]    ][p->pos[dim_x] + 1].hn) &&
        (path[p->pos[dim_y]    ][p->pos[dim_x] + 1].cost >
         ((p->cost + heightpair(p->pos)) *
          edge_penalty(p->pos[dim_x] + 1, p->pos[dim_y])))) {
      path[p->pos[dim_y]][p->pos[dim_x] + 1].cost =
        ((p->cost + heightpair(p->pos)) *
         edge_penalty(p->pos[dim_x] + 1, p->pos[dim_y]));
      path[p->pos[dim_y]    ][p->pos[dim_x] + 1].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y]    ][p->pos[dim_x] + 1].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y]    ]
                                           [p->pos[dim_x] + 1].hn);
    }
    if ((path[p->pos[dim_y] + 1][p->pos[dim_x]    ].hn) &&
        (path[p->pos[dim_y] + 1][p->pos[dim_x]    ].cost >
         ((p->cost + heightpair(p->pos)) *
          edge_penalty(p->pos[dim_x], p->pos[dim_y] + 1)))) {
      path[p->pos[dim_y] + 1][p->pos[dim_x]    ].cost =
        ((p->cost + heightpair(p->pos)) *
         edge_penalty(p->pos[dim_x], p->pos[dim_y] + 1));
      path[p->pos[dim_y] + 1][p->pos[dim_x]    ].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y] + 1][p->pos[dim_x]    ].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y] + 1]
                                           [p->pos[dim_x]    ].hn);
    }
  }
}

static int build_paths(map_t *m)
{
  pair_t from, to;

  /*  printf("%d %d %d %d\n", m->n, m->s, m->e, m->w);*/

  if (m->e != -1 && m->w != -1) {
    from[dim_x] = 1;
    to[dim_x] = MAP_X - 2;
    from[dim_y] = m->w;
    to[dim_y] = m->e;

    dijkstra_path(m, from, to);
  }

  if (m->n != -1 && m->s != -1) {
    from[dim_y] = 1;
    to[dim_y] = MAP_Y - 2;
    from[dim_x] = m->n;
    to[dim_x] = m->s;

    dijkstra_path(m, from, to);
  }

  if (m->e == -1) {
    if (m->s == -1) {
      from[dim_x] = 1;
      from[dim_y] = m->w;
      to[dim_x] = m->n;
      to[dim_y] = 1;
    } else {
      from[dim_x] = 1;
      from[dim_y] = m->w;
      to[dim_x] = m->s;
      to[dim_y] = MAP_Y - 2;
    }

    dijkstra_path(m, from, to);
  }

  if (m->w == -1) {
    if (m->s == -1) {
      from[dim_x] = MAP_X - 2;
      from[dim_y] = m->e;
      to[dim_x] = m->n;
      to[dim_y] = 1;
    } else {
      from[dim_x] = MAP_X - 2;
      from[dim_y] = m->e;
      to[dim_x] = m->s;
      to[dim_y] = MAP_Y - 2;
    }

    dijkstra_path(m, from, to);
  }

  if (m->n == -1) {
    if (m->e == -1) {
      from[dim_x] = 1;
      from[dim_y] = m->w;
      to[dim_x] = m->s;
      to[dim_y] = MAP_Y - 2;
    } else {
      from[dim_x] = MAP_X - 2;
      from[dim_y] = m->e;
      to[dim_x] = m->s;
      to[dim_y] = MAP_Y - 2;
    }

    dijkstra_path(m, from, to);
  }

  if (m->s == -1) {
    if (m->e == -1) {
      from[dim_x] = 1;
      from[dim_y] = m->w;
      to[dim_x] = m->n;
      to[dim_y] = 1;
    } else {
      from[dim_x] = MAP_X - 2;
      from[dim_y] = m->e;
      to[dim_x] = m->n;
      to[dim_y] = 1;
    }

    dijkstra_path(m, from, to);
  }

  return 0;
}

static int gaussian[5][5] = {
  {  1,  4,  7,  4,  1 },
  {  4, 16, 26, 16,  4 },
  {  7, 26, 41, 26,  7 },
  {  4, 16, 26, 16,  4 },
  {  1,  4,  7,  4,  1 }
};

static int smooth_height(map_t *m)
{
  int32_t i, x, y;
  int32_t s, t, p, q;
  queue_node_t *head, *tail, *tmp;
  /*  FILE *out;*/
  uint8_t height[MAP_Y][MAP_X];

  memset(&height, 0, sizeof (height));

  /* Seed with some values */
  for (i = 1; i < 255; i += 20) {
    do {
      x = rand() % MAP_X;
      y = rand() % MAP_Y;
    } while (height[y][x]);
    height[y][x] = i;
    if (i == 1) {
      head = tail = (queue_node_t*)malloc(sizeof (*tail));
    } else {
      tail->next = (queue_node_t*)malloc(sizeof (*tail));
      tail = tail->next;
    }
    tail->next = NULL;
    tail->x = x;
    tail->y = y;
  }

  /*
  out = fopen("seeded.pgm", "w");
  fprintf(out, "P5\n%u %u\n255\n", MAP_X, MAP_Y);
  fwrite(&height, sizeof (height), 1, out);
  fclose(out);
  */
  
  /* Diffuse the vaules to fill the space */
  while (head) {
    x = head->x;
    y = head->y;
    i = height[y][x];

    if (x - 1 >= 0 && y - 1 >= 0 && !height[y - 1][x - 1]) {
      height[y - 1][x - 1] = i;
      tail->next = (queue_node_t*)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x - 1;
      tail->y = y - 1;
    }
    if (x - 1 >= 0 && !height[y][x - 1]) {
      height[y][x - 1] = i;
      tail->next = (queue_node_t*)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x - 1;
      tail->y = y;
    }
    if (x - 1 >= 0 && y + 1 < MAP_Y && !height[y + 1][x - 1]) {
      height[y + 1][x - 1] = i;
      tail->next = (queue_node_t*)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x - 1;
      tail->y = y + 1;
    }
    if (y - 1 >= 0 && !height[y - 1][x]) {
      height[y - 1][x] = i;
      tail->next = (queue_node_t*)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x;
      tail->y = y - 1;
    }
    if (y + 1 < MAP_Y && !height[y + 1][x]) {
      height[y + 1][x] = i;
      tail->next = (queue_node_t*)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x;
      tail->y = y + 1;
    }
    if (x + 1 < MAP_X && y - 1 >= 0 && !height[y - 1][x + 1]) {
      height[y - 1][x + 1] = i;
      tail->next = (queue_node_t*)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x + 1;
      tail->y = y - 1;
    }
    if (x + 1 < MAP_X && !height[y][x + 1]) {
      height[y][x + 1] = i;
      tail->next = (queue_node_t*)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x + 1;
      tail->y = y;
    }
    if (x + 1 < MAP_X && y + 1 < MAP_Y && !height[y + 1][x + 1]) {
      height[y + 1][x + 1] = i;
      tail->next = (queue_node_t*)malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x + 1;
      tail->y = y + 1;
    }

    tmp = head;
    head = head->next;
    free(tmp);
  }

  /* And smooth it a bit with a gaussian convolution */
  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      for (s = t = p = 0; p < 5; p++) {
        for (q = 0; q < 5; q++) {
          if (y + (p - 2) >= 0 && y + (p - 2) < MAP_Y &&
              x + (q - 2) >= 0 && x + (q - 2) < MAP_X) {
            s += gaussian[p][q];
            t += height[y + (p - 2)][x + (q - 2)] * gaussian[p][q];
          }
        }
      }
      m->height[y][x] = t / s;
    }
  }
  /* Let's do it again, until it's smooth like Kenny G. */
  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      for (s = t = p = 0; p < 5; p++) {
        for (q = 0; q < 5; q++) {
          if (y + (p - 2) >= 0 && y + (p - 2) < MAP_Y &&
              x + (q - 2) >= 0 && x + (q - 2) < MAP_X) {
            s += gaussian[p][q];
            t += height[y + (p - 2)][x + (q - 2)] * gaussian[p][q];
          }
        }
      }
      m->height[y][x] = t / s;
    }
  }

  /*
  out = fopen("diffused.pgm", "w");
  fprintf(out, "P5\n%u %u\n255\n", MAP_X, MAP_Y);
  fwrite(&height, sizeof (height), 1, out);
  fclose(out);

  out = fopen("smoothed.pgm", "w");
  fprintf(out, "P5\n%u %u\n255\n", MAP_X, MAP_Y);
  fwrite(&m->height, sizeof (m->height), 1, out);
  fclose(out);
  */

  return 0;
}

static void find_building_location(map_t *m, pair_t p)
{
  do {
    p[dim_x] = rand() % (MAP_X - 5) + 3;
    p[dim_y] = rand() % (MAP_Y - 10) + 5;

    if ((((mapxy(p[dim_x] - 1, p[dim_y]    ) == ter_path)     &&
          (mapxy(p[dim_x] - 1, p[dim_y] + 1) == ter_path))    ||
         ((mapxy(p[dim_x] + 2, p[dim_y]    ) == ter_path)     &&
          (mapxy(p[dim_x] + 2, p[dim_y] + 1) == ter_path))    ||
         ((mapxy(p[dim_x]    , p[dim_y] - 1) == ter_path)     &&
          (mapxy(p[dim_x] + 1, p[dim_y] - 1) == ter_path))    ||
         ((mapxy(p[dim_x]    , p[dim_y] + 2) == ter_path)     &&
          (mapxy(p[dim_x] + 1, p[dim_y] + 2) == ter_path)))   &&
        (((mapxy(p[dim_x]    , p[dim_y]    ) != ter_mart)     &&
          (mapxy(p[dim_x]    , p[dim_y]    ) != ter_center)   &&
          (mapxy(p[dim_x] + 1, p[dim_y]    ) != ter_mart)     &&
          (mapxy(p[dim_x] + 1, p[dim_y]    ) != ter_center)   &&
          (mapxy(p[dim_x]    , p[dim_y] + 1) != ter_mart)     &&
          (mapxy(p[dim_x]    , p[dim_y] + 1) != ter_center)   &&
          (mapxy(p[dim_x] + 1, p[dim_y] + 1) != ter_mart)     &&
          (mapxy(p[dim_x] + 1, p[dim_y] + 1) != ter_center))) &&
        (((mapxy(p[dim_x]    , p[dim_y]    ) != ter_path)     &&
          (mapxy(p[dim_x] + 1, p[dim_y]    ) != ter_path)     &&
          (mapxy(p[dim_x]    , p[dim_y] + 1) != ter_path)     &&
          (mapxy(p[dim_x] + 1, p[dim_y] + 1) != ter_path)))) {
          break;
    }
  } while (1);
}

static int place_pokemart(map_t *m)
{
  pair_t p;

  find_building_location(m, p);

  mapxy(p[dim_x]    , p[dim_y]    ) = ter_mart;
  mapxy(p[dim_x] + 1, p[dim_y]    ) = ter_mart;
  mapxy(p[dim_x]    , p[dim_y] + 1) = ter_mart;
  mapxy(p[dim_x] + 1, p[dim_y] + 1) = ter_mart;

  return 0;
}

static int place_center(map_t *m)
{  pair_t p;

  find_building_location(m, p);

  mapxy(p[dim_x]    , p[dim_y]    ) = ter_center;
  mapxy(p[dim_x] + 1, p[dim_y]    ) = ter_center;
  mapxy(p[dim_x]    , p[dim_y] + 1) = ter_center;
  mapxy(p[dim_x] + 1, p[dim_y] + 1) = ter_center;

  return 0;
}

static int map_terrain(map_t *m, int8_t n, int8_t s, int8_t e, int8_t w)
{
  int32_t i, x, y;
  queue_node_t *head, *tail, *tmp;
  //  FILE *out;
  int num_grass, num_clearing, num_mountain, num_forest, num_total;
  terrain_type_t type;
  int added_current = 0;
  
  num_grass = rand() % 4 + 2;
  num_clearing = rand() % 4 + 2;
  num_mountain = rand() % 2 + 1;
  num_forest = rand() % 2 + 1;
  num_total = num_grass + num_clearing + num_mountain + num_forest;

  memset(&m->map, 0, sizeof (m->map));

  /* Seed with some values */
  for (i = 0; i < num_total; i++) {
    do {
      x = rand() % MAP_X;
      y = rand() % MAP_Y;
    } while (m->map[y][x]);
    if (i == 0) {
      type = ter_grass;
    } else if (i == num_grass) {
      type = ter_clearing;
    } else if (i == num_grass + num_clearing) {
      type = ter_mountain;
    } else if (i == num_grass + num_clearing + num_mountain) {
      type = ter_forest;
    }
    m->map[y][x] = type;
    if (i == 0) {
      head = tail = (queue_node_t*)malloc(sizeof (*tail));
    } else {
      tail->next = (queue_node_t*)malloc(sizeof (*tail));
      tail = tail->next;
    }
    tail->next = NULL;
    tail->x = x;
    tail->y = y;
  }

  /*
  out = fopen("seeded.pgm", "w");
  fprintf(out, "P5\n%u %u\n255\n", MAP_X, MAP_Y);
  fwrite(&m->map, sizeof (m->map), 1, out);
  fclose(out);
  */

  /* Diffuse the vaules to fill the space */
  while (head) {
    x = head->x;
    y = head->y;
    i = m->map[y][x];
    
    if (x - 1 >= 0 && !m->map[y][x - 1]) {
      if ((rand() % 100) < 80) {
        m->map[y][x - 1] = (terrain_type_t)i;
        tail->next = (queue_node_t*)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x - 1;
        tail->y = y;
      } else if (!added_current) {
        added_current = 1;
        m->map[y][x] = (terrain_type_t)i;
        tail->next = (queue_node_t*)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x;
        tail->y = y;
      }
    }

    if (y - 1 >= 0 && !m->map[y - 1][x]) {
      if ((rand() % 100) < 20) {
        m->map[y - 1][x] = (terrain_type_t)i;
        tail->next = (queue_node_t*)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x;
        tail->y = y - 1;
      } else if (!added_current) {
        added_current = 1;
        m->map[y][x] = (terrain_type_t)i;
        tail->next = (queue_node_t*)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x;
        tail->y = y;
      }
    }

    if (y + 1 < MAP_Y && !m->map[y + 1][x]) {
      if ((rand() % 100) < 20) {
        m->map[y + 1][x] = (terrain_type_t)i;
        tail->next = (queue_node_t*)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x;
        tail->y = y + 1;
      } else if (!added_current) {
        added_current = 1;
        m->map[y][x] = (terrain_type_t)i;
        tail->next = (queue_node_t*)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x;
        tail->y = y;
      }
    }

    if (x + 1 < MAP_X && !m->map[y][x + 1]) {
      if ((rand() % 100) < 80) {
        m->map[y][x + 1] = (terrain_type_t)i;
        tail->next = (queue_node_t*)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x + 1;
        tail->y = y;
      } else if (!added_current) {
        added_current = 1;
        m->map[y][x] = (terrain_type_t)i;
        tail->next = (queue_node_t*)malloc(sizeof (*tail));
        tail = tail->next;
        tail->next = NULL;
        tail->x = x;
        tail->y = y;
      }
    }

    added_current = 0;
    tmp = head;
    head = head->next;
    free(tmp);
  }

  /*
  out = fopen("diffused.pgm", "w");
  fprintf(out, "P5\n%u %u\n255\n", MAP_X, MAP_Y);
  fwrite(&m->map, sizeof (m->map), 1, out);
  fclose(out);
  */
  
  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      if (y == 0 || y == MAP_Y - 1 ||
          x == 0 || x == MAP_X - 1) {
        mapxy(x, y) = ter_boulder;
      }
    }
  }

  m->n = n;
  m->s = s;
  m->e = e;
  m->w = w;

  if (n != -1) {
    mapxy(n,         0        ) = ter_exit;
    mapxy(n,         1        ) = ter_path;
  }
  if (s != -1) {
    mapxy(s,         MAP_Y - 1) = ter_exit;
    mapxy(s,         MAP_Y - 2) = ter_path;
  }
  if (w != -1) {
    mapxy(0,         w        ) = ter_exit;
    mapxy(1,         w        ) = ter_path;
  }
  if (e != -1) {
    mapxy(MAP_X - 1, e        ) = ter_exit;
    mapxy(MAP_X - 2, e        ) = ter_path;
  }

  return 0;
}

static int place_boulders(map_t *m)
{
  int i;
  int x, y;

  for (i = 0; i < MIN_BOULDERS || rand() % 100 < BOULDER_PROB; i++) {
    y = rand() % (MAP_Y - 2) + 1;
    x = rand() % (MAP_X - 2) + 1;
    if (m->map[y][x] != ter_forest && m->map[y][x] != ter_path) {
      m->map[y][x] = ter_boulder;
    }
  }

  return 0;
}

static int place_trees(map_t *m)
{
  int i;
  int x, y;
  
  for (i = 0; i < MIN_TREES || rand() % 100 < TREE_PROB; i++) {
    y = rand() % (MAP_Y - 2) + 1;
    x = rand() % (MAP_X - 2) + 1;
    if (m->map[y][x] != ter_mountain && m->map[y][x] != ter_path) {
      m->map[y][x] = ter_tree;
    }
  }

  return 0;
}

void rand_pos(pair_t pos)
{
  pos[dim_x] = (rand() % (MAP_X - 2)) + 1;
  pos[dim_y] = (rand() % (MAP_Y - 2)) + 1;
}

void new_hiker()
{
  pair_t pos;
  character_t *c;

  do {
    rand_pos(pos);
  } while (world.hiker_dist[pos[dim_y]][pos[dim_x]] == INT_MAX ||
           world.cur_map->cmap[pos[dim_y]][pos[dim_x]]         ||
           pos[dim_x] < 3 || pos[dim_x] > MAP_X - 4            ||
           pos[dim_y] < 3 || pos[dim_y] > MAP_Y - 4);

  world.cur_map->cmap[pos[dim_y]][pos[dim_x]] = c = (character_t*)malloc(sizeof (*c));
  c->npc = (npc_t*)malloc(sizeof (*c->npc));
  c->pos[dim_y] = pos[dim_y];
  c->pos[dim_x] = pos[dim_x];
  c->npc->ctype = char_hiker;
  c->npc->mtype = move_hiker;
  c->npc->dir[dim_x] = 0;
  c->npc->dir[dim_y] = 0;
  c->npc->defeated = 0;
  c->pc = NULL;
  c->symbol = 'h';
  c->next_turn = 0;
  heap_insert(&world.cur_map->turn, c);

  //  printf("Hiker at %d,%d\n", pos[dim_x], pos[dim_y]);
}

void new_rival()
{
  pair_t pos;
  character_t *c;

  do {
    rand_pos(pos);
  } while (world.rival_dist[pos[dim_y]][pos[dim_x]] == INT_MAX ||
           world.rival_dist[pos[dim_y]][pos[dim_x]] < 0        ||
           world.cur_map->cmap[pos[dim_y]][pos[dim_x]]         ||
           pos[dim_x] < 3 || pos[dim_x] > MAP_X - 4            ||
           pos[dim_y] < 3 || pos[dim_y] > MAP_Y - 4);

  world.cur_map->cmap[pos[dim_y]][pos[dim_x]] = c = (character_t*)malloc(sizeof (*c));
  c->npc = (npc_t*)malloc(sizeof (*c->npc));
  c->pos[dim_y] = pos[dim_y];
  c->pos[dim_x] = pos[dim_x];
  c->npc->ctype = char_rival;
  c->npc->mtype = move_rival;
  c->npc->dir[dim_x] = 0;
  c->npc->dir[dim_y] = 0;
  c->npc->defeated = 0;
  c->pc = NULL;
  c->symbol = 'r';
  c->next_turn = 0;
  heap_insert(&world.cur_map->turn, c);
}

void new_char_other()
{
  pair_t pos;
  character_t *c;

  do {
    rand_pos(pos);
  } while (world.rival_dist[pos[dim_y]][pos[dim_x]] == INT_MAX ||
           world.rival_dist[pos[dim_y]][pos[dim_x]] < 0        ||
           world.cur_map->cmap[pos[dim_y]][pos[dim_x]]         ||
           pos[dim_x] < 3 || pos[dim_x] > MAP_X - 4            ||
           pos[dim_y] < 3 || pos[dim_y] > MAP_Y - 4);

  world.cur_map->cmap[pos[dim_y]][pos[dim_x]] = c = (character_t*)malloc(sizeof (*c));
  c->npc = (npc_t*)malloc(sizeof (*c->npc));
  c->pos[dim_y] = pos[dim_y];
  c->pos[dim_x] = pos[dim_x];
  c->npc->ctype = char_other;
  switch (rand() % 4) {
  case 0:
    c->npc->mtype = move_pace;
    c->symbol = 'p';
    break;
  case 1:
    c->npc->mtype = move_wander;
    c->symbol = 'w';
    break;
  case 2:
    c->npc->mtype = move_sentry;
    c->symbol = 's';
    break;
  case 3:
    c->npc->mtype = move_walk;
    c->symbol = 'n';
    break;
  }
  rand_dir(c->npc->dir);
  c->npc->defeated = 0;
  c->pc = NULL;
  c->next_turn = 0;
  heap_insert(&world.cur_map->turn, c);
}

void place_characters()
{
  world.cur_map->num_trainers = 2;

  //Always place a hiker and a rival, then place a random number of others
  new_hiker();
  new_rival();
  do {
    //higher probability of non- hikers and rivals
    switch(rand() % 10) {
    case 0:
      new_hiker();
      break;
    case 1:
     new_rival();
      break;
    default:
      new_char_other();
      break;
    }
  } while (++world.cur_map->num_trainers < MIN_TRAINERS ||
           ((rand() % 100) < ADD_TRAINER_PROB));
}

void init_pc()
{
  int x, y;

  do {
    x = rand() % (MAP_X - 2) + 1;
    y = rand() % (MAP_Y - 2) + 1;
  } while (world.cur_map->map[y][x] != ter_path);

  world.pc.pos[dim_x] = x;
  world.pc.pos[dim_y] = y;
  world.pc.symbol = '@';
  world.pc.pc = (pc_t*)malloc(sizeof (*world.pc.pc));
  world.pc.npc = NULL;

  world.cur_map->cmap[y][x] = &world.pc;
  world.pc.next_turn = 0;

  heap_insert(&world.cur_map->turn, &world.pc);
}

void place_pc()
{
  character_t *c;

  if (world.pc.pos[dim_x] == 1) {
    world.pc.pos[dim_x] = MAP_X - 2;
  } else if (world.pc.pos[dim_x] == MAP_X - 2) {
    world.pc.pos[dim_x] = 1;
  } else if (world.pc.pos[dim_y] == 1) {
    world.pc.pos[dim_y] = MAP_Y - 2;
  } else if (world.pc.pos[dim_y] == MAP_Y - 2) {
    world.pc.pos[dim_y] = 1;
  }

  world.cur_map->cmap[world.pc.pos[dim_y]][world.pc.pos[dim_x]] = &world.pc;

  if ((c = (character_t*)heap_peek_min(&world.cur_map->turn))) {
    world.pc.next_turn = c->next_turn;
  } else {
    world.pc.next_turn = 0;
  }
}

// New map expects cur_idx to refer to the index to be generated.  If that
// map has already been generated then the only thing this does is set
// cur_map.
int new_map(int teleport)
{
  int d, p;
  int e, w, n, s;
  int x, y;
  
  if (world.world[world.cur_idx[dim_y]][world.cur_idx[dim_x]]) {
    world.cur_map = world.world[world.cur_idx[dim_y]][world.cur_idx[dim_x]];
    place_pc();

    return 0;
  }

  world.cur_map                                             =
    world.world[world.cur_idx[dim_y]][world.cur_idx[dim_x]] =
    (map_t*)malloc(sizeof (*world.cur_map));

  smooth_height(world.cur_map);
  
  if (!world.cur_idx[dim_y]) {
    n = -1;
  } else if (world.world[world.cur_idx[dim_y] - 1][world.cur_idx[dim_x]]) {
    n = world.world[world.cur_idx[dim_y] - 1][world.cur_idx[dim_x]]->s;
  } else {
    n = 3 + rand() % (MAP_X - 6);
  }
  if (world.cur_idx[dim_y] == WORLD_SIZE - 1) {
    s = -1;
  } else if (world.world[world.cur_idx[dim_y] + 1][world.cur_idx[dim_x]]) {
    s = world.world[world.cur_idx[dim_y] + 1][world.cur_idx[dim_x]]->n;
  } else  {
    s = 3 + rand() % (MAP_X - 6);
  }
  if (!world.cur_idx[dim_x]) {
    w = -1;
  } else if (world.world[world.cur_idx[dim_y]][world.cur_idx[dim_x] - 1]) {
    w = world.world[world.cur_idx[dim_y]][world.cur_idx[dim_x] - 1]->e;
  } else {
    w = 3 + rand() % (MAP_Y - 6);
  }
  if (world.cur_idx[dim_x] == WORLD_SIZE - 1) {
    e = -1;
  } else if (world.world[world.cur_idx[dim_y]][world.cur_idx[dim_x] + 1]) {
    e = world.world[world.cur_idx[dim_y]][world.cur_idx[dim_x] + 1]->w;
  } else {
    e = 3 + rand() % (MAP_Y - 6);
  }
  
  map_terrain(world.cur_map, n, s, e, w);
     
  place_boulders(world.cur_map);
  place_trees(world.cur_map);
  build_paths(world.cur_map);
  d = (abs(world.cur_idx[dim_x] - (WORLD_SIZE / 2)) +
       abs(world.cur_idx[dim_y] - (WORLD_SIZE / 2)));
  p = d > 200 ? 5 : (50 - ((45 * d) / 200));
  //  printf("d=%d, p=%d\n", d, p);
  if ((rand() % 100) < p || !d) {
    place_pokemart(world.cur_map);
  }
  if ((rand() % 100) < p || !d) {
    place_center(world.cur_map);
  }

  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      world.cur_map->cmap[y][x] = NULL;
    }
  }

  heap_init(&world.cur_map->turn, cmp_char_turns, delete_character);

  if ((world.cur_idx[dim_x] == WORLD_SIZE / 2) &&
      (world.cur_idx[dim_y] == WORLD_SIZE / 2)) {
    init_pc();
  } else {
    place_pc();
  }

  pathfind(world.cur_map);
  if (teleport) {
    do {
      world.cur_map->cmap[world.pc.pos[dim_y]][world.pc.pos[dim_x]] = NULL;
      world.pc.pos[dim_x] = rand_range(1, MAP_X - 2);
      world.pc.pos[dim_y] = rand_range(1, MAP_Y - 2);
    } while (world.cur_map->cmap[world.pc.pos[dim_y]][world.pc.pos[dim_x]] ||
             (move_cost[char_pc][world.cur_map->map[world.pc.pos[dim_y]]
                                                   [world.pc.pos[dim_x]]] ==
              INT_MAX)                                                      ||
             world.rival_dist[world.pc.pos[dim_y]][world.pc.pos[dim_x]] < 0);
    world.cur_map->cmap[world.pc.pos[dim_y]][world.pc.pos[dim_x]] = &world.pc;
    pathfind(world.cur_map);
  }
  
  place_characters();

  return 0;
}

/*
static void print_map()
{
  int x, y;
  int default_reached = 0;

  printf("\n\n\n");

  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      if (world.cur_map->cmap[y][x]) {
        putchar(world.cur_map->cmap[y][x]->symbol);
      } else {
        switch (world.cur_map->map[y][x]) {
        case ter_boulder:
        case ter_mountain:
          putchar('%');
          break;
        case ter_tree:
        case ter_forest:
          putchar('^');
          break;
        case ter_path:
          putchar('#');
          break;
        case ter_mart:
          putchar('M');
          break;
        case ter_center:
          putchar('C');
          break;
        case ter_grass:
          putchar(':');
          break;
        case ter_clearing:
          putchar('.');
          break;
        default:
          default_reached = 1;
          break;
        }
      }
    }
    putchar('\n');
  }

  if (default_reached) {
    fprintf(stderr, "Default reached in %s\n", __FUNCTION__);
  }
}
*/

// The world is global because of its size, so init_world is parameterless
void init_world()
{
  world.quit = 0;
  world.cur_idx[dim_x] = world.cur_idx[dim_y] = WORLD_SIZE / 2;
  new_map(0);
}

void delete_world()
{
  int x, y;

  //Only correct because current game never leaves the initial map
  //Need to iterate over all maps in 1.05+
  heap_delete(&world.cur_map->turn);

  for (y = 0; y < WORLD_SIZE; y++) {
    for (x = 0; x < WORLD_SIZE; x++) {
      if (world.world[y][x]) {
        free(world.world[y][x]);
        world.world[y][x] = NULL;
      }
    }
  }
}

void print_hiker_dist()
{
  int x, y;

  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      if (world.hiker_dist[y][x] == INT_MAX) {
        printf("   ");
      } else {
        printf(" %5d", world.hiker_dist[y][x]);
      }
    }
    printf("\n");
  }
}

void print_rival_dist()
{
  int x, y;

  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      if (world.rival_dist[y][x] == INT_MAX || world.rival_dist[y][x] < 0) {
        printf("   ");
      } else {
        printf(" %02d", world.rival_dist[y][x] % 100);
      }
    }
    printf("\n");
  }
}

void leave_map(pair_t d)
{
  if (d[dim_x] == 0) {
    world.cur_idx[dim_x]--;
  } else if (d[dim_y] == 0) {
    world.cur_idx[dim_y]--;
  } else if (d[dim_x] == MAP_X - 1) {
    world.cur_idx[dim_x]++;
  } else {
    world.cur_idx[dim_y]++;
  }
  new_map(0);
}

void game_loop()
{
  character_t *c;
  pair_t d;
  
  while (!world.quit) {
    c = (character_t*)heap_remove_min(&world.cur_map->turn);

    move_func[c->npc ? c->npc->mtype : move_pc](c, d);

    world.cur_map->cmap[c->pos[dim_y]][c->pos[dim_x]] = NULL;
    if (c->pc && (d[dim_x] == 0 || d[dim_x] == MAP_X - 1 ||
                  d[dim_y] == 0 || d[dim_y] == MAP_Y - 1)) {
      leave_map(d);
      d[dim_x] = c->pos[dim_x];
      d[dim_y] = c->pos[dim_y];
    }
    world.cur_map->cmap[d[dim_y]][d[dim_x]] = c;

    if (c->pc) {
      // Performance bug - pathfinding runs twice after generating a new map
      pathfind(world.cur_map);
    }

    c->next_turn += move_cost[c->npc ? c->npc->ctype : char_pc]
                             [world.cur_map->map[d[dim_y]][d[dim_x]]];

    c->pos[dim_y] = d[dim_y];
    c->pos[dim_x] = d[dim_x];

    heap_insert(&world.cur_map->turn, c);
  }
}

int main(int argc, char *argv[])
{
  struct timeval tv;
  uint32_t seed;
  string file_name;
  //  char c;
  //  int x, y;

  if (argc == 2) 
  {
    file_name = argv[1];

    if (file_name == "pokemon")
    {
      vector<Pokemon> pokemonList;
      parsePokemonList(pokemonList);
      printPokemonList(pokemonList);
    }
    
    else if (file_name == "moves")
    {
      vector<Move> movesList;
      parseMovesList(movesList);
      printMovesList(movesList);
    }
    else if (file_name == "pokemon_moves")
    {
      vector<Pokemon_Move> pokemonMovesList;
      parsePokemonMovesList(pokemonMovesList);
      printPokemonMovesList(pokemonMovesList);
    }
    else if (file_name == "pokemon_species")
    {
      vector<Pokemon_Species> pokemonSpeciesList;
      parsePokemonSpeciesList(pokemonSpeciesList);
      printPokemonSpeciesList(pokemonSpeciesList);
    }
    else if (file_name == "experience")
    {
      vector<Experience> experienceList;
      parseExperienceList(experienceList);
      printExperienceList(experienceList);
    }
    else if (file_name == "type_names")
    {
      vector <Type_Name> typeNameList;
      parseTypeNameList(typeNameList);
      printTypeNameList(typeNameList);
    }
    else cout << "ERROR: FILE COULD NOT BE FOUND!" << endl;
  }
  else
  {
    cout << "NO FILE NAME WAS ENTERED THROUGH THE COMMAND LINE PARAMETERS... STARTING GAME AS NORMAL:" << endl;

  gettimeofday(&tv, NULL);
  seed = (tv.tv_usec ^ (tv.tv_sec << 20)) & 0xffffffff;

  printf("Using seed: %u\n", seed);
  srand(seed);

  io_init_terminal();
  
  init_world();

  /* print_hiker_dist(); */
  
  /*
  do {
    print_map();  
    printf("Current position is %d%cx%d%c (%d,%d).  "
           "Enter command: ",
           abs(world.cur_idx[dim_x] - (WORLD_SIZE / 2)),
           world.cur_idx[dim_x] - (WORLD_SIZE / 2) >= 0 ? 'E' : 'W',
           abs(world.cur_idx[dim_y] - (WORLD_SIZE / 2)),
           world.cur_idx[dim_y] - (WORLD_SIZE / 2) <= 0 ? 'N' : 'S',
           world.cur_idx[dim_x] - (WORLD_SIZE / 2),
           world.cur_idx[dim_y] - (WORLD_SIZE / 2));
    scanf(" %c", &c);
    switch (c) {
    case 'n':
      if (world.cur_idx[dim_y]) {
        world.cur_idx[dim_y]--;
        new_map();
      }
      break;
    case 's':
      if (world.cur_idx[dim_y] < WORLD_SIZE - 1) {
        world.cur_idx[dim_y]++;
        new_map();
      }
      break;
    case 'e':
      if (world.cur_idx[dim_x] < WORLD_SIZE - 1) {
        world.cur_idx[dim_x]++;
        new_map();
      }
      break;
    case 'w':
      if (world.cur_idx[dim_x]) {
        world.cur_idx[dim_x]--;
        new_map();
      }
      break;
     case 'q':
      break;
    case 'f':
      scanf(" %d %d", &x, &y);
      if (x >= -(WORLD_SIZE / 2) && x <= WORLD_SIZE / 2 &&
          y >= -(WORLD_SIZE / 2) && y <= WORLD_SIZE / 2) {
        world.cur_idx[dim_x] = x + (WORLD_SIZE / 2);
        world.cur_idx[dim_y] = y + (WORLD_SIZE / 2);
        new_map();
      }
      break;
    case '?':
    case 'h':
      printf("Move with 'e'ast, 'w'est, 'n'orth, 's'outh or 'f'ly x y.\n"
             "Quit with 'q'.  '?' and 'h' print this help message.\n");
      break;
    default:
      fprintf(stderr, "%c: Invalid input.  Enter '?' for help.\n", c);
      break;
    }
  } while (c != 'q');

  */

  game_loop();
  
  delete_world();

  io_reset_terminal();

  }
  
  return 0;
}
