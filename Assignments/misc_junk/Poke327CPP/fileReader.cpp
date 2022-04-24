//
// Created by Devin Amdahl on 3/29/22.
//

// Must create classes to hold the data of each file, which will then be held in a vector of those types.
//  * Use a value of -1 as a placeholder for empty cells in the CSV files.
//  * type_names.csv contains some non-English words, which can be resolved by checking if the line's 'local_language_id' is equal to 9.
//  * The final version must be able to take a single line command line parameter 'pokemon, moves, pokemon_moves' and so on.
//  * Program should parse all of the files, filling up the contents of their assoicated vectors, and then printing out all of their contents into the standard terminal.
//      * NOT WITH NCURSES
/*
* pokemon.csv
* moves.csv
* pokemon_moves.csv
* pokemon_species.csv
* experience.csv
* type_names.csv
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// so we don't have to constantly write 'std::'
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

    Pokemon()
    {
        id = -1;
        species_id = -1;
        height = -1;
        weight = -1;
        base_experience = -1;
        order = -1;
        identifier = "-1";
        is_default = -1;
    }

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

void parseMoves(vector<Move> &movesList)
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

void parsePokemonMoves(vector<Pokemon_Move> &pokemonMovesList)
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

int main (int argc, char *argv[])
{
    // check for command line parameters
    // TODO

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
        parseMoves(movesList);
        printMovesList(movesList);
    }
    else if (file_name == "pokemon_moves")
    {
        parsePokemonMoves(pokemonMovesList);
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