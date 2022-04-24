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
};

class Pokemon_Moves
{
    int pokemon_id;
    int version_group_id;
    int move_id;
    int pokemon_move_method_id;
    int level;
    int order;
};

class Pokemon_Species
{
private:
    int id;
    string identifier;
    int generation_id;
    int evolves_from_species;
    int evolution_chain_id;
    int color_id;
    int shape_id;
    int habitat_id;
    int gender_rate;
    int capture_rate;
    int base_happiness;
    bool is_baby;
    int hatch_counter;
    bool has_gender_differences;
    int growth_rate_id;
    int forms_switchable;
    bool is_legendary;
    bool is_mythical;
    int order;
    int conquest_order;
};

class Experience
{
private:
    int growth_rate_id;
    int level;
    int experience;
};

class Type_Names
{
private:
    int type_id;
    int local_language_id;
    string name;
};

void parsePokemon(vector<Pokemon> &pokemonList)
{
    // TODO add the ability to construct with setting empty cells to -1
    // create file variable
    ifstream in_file;
    int num_pokemon;
    vector<string> row;
    string line, token;
    int num_elements;

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

        num_elements = 0;

        // tokenize stream based on ',' and then fill with data
        while (getline(s, token, ','))
        {
            row.push_back(token);
            num_elements++;
        }

        if (num_elements == 8)
        {
            pokemonList.push_back(Pokemon(stoi(row[0]), row[1], stoi(row[2]), stoi(row[3]), stoi(row[4]), stoi(row[5]), stoi(row[6]), stoi(row[7])));
        }

        num_pokemon++;
    }

    // close the file
    in_file.close();
}

void printPokemonList(vector<Pokemon> &pokemonList)
{
    int i;
    cout << "PRINTING POKEMON LIST:" << endl;

    for (i = 0; i < pokemonList.size(); i++)
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

    cout << endl;
}

void parseMoves(vector<Move> &movesList)
{
    // TODO add the ability to construct with setting empty cells to -1
    // create file variable
    ifstream in_file;
    int num_moves = 0;
    vector<string> row;
    string line, token;

    //int id, identifier, type_id, power, pp, accuracy, priority, target_id, damage_class_id, effect_id, effect_chance, contest_type_id, contest_effect_id, super_contest_effect_id;

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
        movesList.push_back(Move());
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


        if (row[0] != "") movesList.at(0).id = stoi(row[0]);
        else movesList.at(0).id = -1;
        if (row[1] != "") movesList.at(0).identifier = stoi(row[1]);
        else movesList.at(0).identifier = -1;
        if (row[2] != "") movesList.at(0).generation_id = stoi(row[2]);
        else movesList.at(0).identifier = -1;
        if (row[3] != "") movesList.at(0).type_id = stoi(row[3]);
        else movesList.at(0).identifier = -1;
        if (row[4] != "") movesList.at(0).power= stoi(row[4]);
        else movesList.at(0).identifier = -1;
        if (row[5] != "") movesList.at(0).pp = stoi(row[5]);
        else movesList.at(0).identifier = -1;
        if (row[6] != "") movesList.at(0).accuracy = stoi(row[6]);
        else movesList.at(0).identifier = -1;
        if (row[7] != "") movesList.at(0).priority = stoi(row[7]);
        else movesList.at(0).identifier = -1;
        if (row[8] != "") movesList.at(0).target_id = stoi(row[8]);
        else movesList.at(0).identifier = -1;
        if (row[9] != "") movesList.at(0).damage_class_id = stoi(row[9]);
        else movesList.at(0).identifier = -1;
        if (row[10] != "") movesList.at(0).effect_id = stoi(row[10]);
        else movesList.at(0).identifier = -1;
        if (row[11] != "") movesList.at(0).effect_chance = stoi(row[11]);
        else movesList.at(0).identifier = -1;
        if (row[12] != "") movesList.at(0).contest_type_id = stoi(row[12]);
        else movesList.at(0).identifier = -1;
        if (row[13] != "") movesList.at(0).contest_effect_id = stoi(row[13]);
        else movesList.at(0).identifier = -1;
        if (row[14] != "") movesList.at(0).super_contest_effect_id = stoi(row[14]);
        else movesList.at(0).identifier = -1;

        num_moves++;
    }

    // close the file
    in_file.close();
}

void printMovesList (vector<Move> &movesList)
{
    int i;
    cout << "PRINTING POKEMON LIST:" << endl;

    for (i = 0; i < movesList.size(); i++)
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

    cout << endl;
}

int main (int argc, char *argv[])
{
    // check for command line parameters
    // TODO

    vector<Pokemon> pokemonList;
    vector<Move> movesList;
    vector<Pokemon_Moves> pokemonMovesList;
    vector<Pokemon_Species> pokemonSpeciesList;
    vector<Experience> experienceList;
    vector <Type_Names> typeNameList;

    string file_name;

    // get file name from user, and try to open
    cout << "Please enter the file's name that you would like to parse: ";
    // if this doesn't work just use cin >> and then cin.ignore
    getline(cin, file_name);

    if (file_name == "pokemon")
    {
        parsePokemon(pokemonList);
        printPokemonList(pokemonList);
    }
    else if (file_name == "moves")
    {
        parseMoves(movesList);
        printMovesList(movesList);
    }
    else cout << "ERROR: FILE COULD NOT BE FOUND!" << endl;
}