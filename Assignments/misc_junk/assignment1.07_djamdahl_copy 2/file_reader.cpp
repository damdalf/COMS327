//
// Created by Devin Amdahl on 3/29/22.
//

#include "file_reader.h"

Pokemon_DB :: Pokemon_DB(int id, string identifier, int species_id, int height, int weight, int base_experience, int order, int is_default)
{
    this->id = id;
    this->identifier = identifier;
    this->species_id = species_id;
    this->height = height;
    this->weight = weight;
    this->base_experience = base_experience;
    this->order = order;
    this->is_default = is_default;
};

int Pokemon_DB :: getID() const {return id;}
string Pokemon_DB :: getIdentifier() const {return identifier;}
int Pokemon_DB :: getSpeciesID() const {return species_id;}
int Pokemon_DB :: getHeight() const {return height;}
int Pokemon_DB :: getWeight() const {return weight;}
int Pokemon_DB :: getBaseExperience() const {return base_experience;}
int Pokemon_DB :: getOrder() const {return order;}
int Pokemon_DB :: getIsDefault() const {return is_default;}
void Pokemon_DB :: print()
{
    (id != -1) ? cout << "ID: " << id << endl : cout << "ID: " << endl;
    (identifier != "-1") ? cout << "IDENTIFIER: " << identifier << endl : cout << "IDENTIFIER: " << endl;
    (species_id != -1) ? cout << "SPECIES ID: " << species_id << endl : cout << "SPECIES ID: " << endl;
    (height != -1) ? cout << "HEIGHT: " << height << endl : cout << "HEIGHT: " << endl;
    (weight != -1) ? cout << "WEIGHT: " << weight << endl : cout << "WEIGHT" << endl;
    ;
    (base_experience != -1) ? cout << "BASE EXPERIENCE: " << base_experience << endl : cout << "BASE EXPERIENCE: " << endl;
    ;
    (order != -1) ? cout << "ORDER: " << order << endl : cout << "ORDER: " << endl;
    (is_default != -1) ? cout << "IS DEFAULT: " << is_default << endl : cout << "IS DEFAULT: " << endl;
    ;
    cout << endl;
}

Move_DB :: Move_DB(int id, string identifier, int generation_id, int type_id, int power, int pp, int accuracy, int priority, int target_id, int damage_class_id, int effect_id, int effect_chance, int contest_type_id, int contest_effect_id, int super_contest_effect_id)
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
};

int Move_DB ::  getID() const {return id;}
string Move_DB ::  getIdentifier() const {return identifier;}
int Move_DB ::  getGenerationID() const {return generation_id;}
int Move_DB ::  getTypeID() const {return type_id;}
int Move_DB ::  getPower() const {return power;}
int Move_DB ::  getPP() const {return pp;}
int Move_DB ::  getAccuracy() const {return accuracy;}
int Move_DB ::  getPriority() const {return priority;}
int Move_DB ::  getTargetID() const {return target_id;}
int Move_DB ::  getDamageClassID() const {return damage_class_id;}
int Move_DB ::  getEffectID() const {return effect_id;}
int Move_DB ::  getEffectChance() const {return effect_chance;}
int Move_DB ::  getContestTypeID() const {return contest_type_id;}
int Move_DB :: getContestEffectID() const {return contest_effect_id;}
int Move_DB :: getSuperContestEffectID() const {return super_contest_effect_id;}
void Move_DB :: print()
{
    (id != -1) ? cout << "ID: " << id << endl : cout << "ID: " << endl;
    (identifier != "-1") ? cout << "IDENTIFIER: " << identifier << endl : cout << "IDENTIFIER: " << endl;
    (generation_id != -1) ? cout << "GENERATION ID: " << generation_id << endl : cout << "GENERATION ID: " << endl;
    (type_id != -1) ? cout << "TYPE ID: " << type_id << endl : cout << "TYPE ID: " << endl;
    (power != -1) ? cout << "POWER: " << power << endl : cout << "POWER: " << endl;
    (pp != -1) ? cout << "PP: " << pp << endl : cout << "PP: " << endl;
    (accuracy != -1) ? cout << "ACCURACY: " << accuracy << endl : cout << "ACCURACY: " << endl;
    (priority != -1) ? cout << "PRIORITY: " << priority << endl : cout << "PRIORITY: " << endl;
    (target_id != -1) ? cout << "TARGET ID: " << target_id << endl : cout << "TARGET ID: " << endl;
    (damage_class_id != -1) ? cout << "DAMAGE CLASS ID: " << damage_class_id << endl : cout << "DAMAGE CLASS ID: " << endl;
    (effect_id != -1) ? cout << "EFFECT ID: " << effect_id << endl : cout << "EFFECT ID: " << endl;
    (effect_chance != -1) ? cout << "EFFECT CHANCE: " << effect_chance << endl : cout << "EFFECT CHANCE: " << endl;
    (contest_type_id != -1) ? cout << "CONTEST TYPE ID: " << contest_type_id << endl : cout << "CONTEST TYPE ID: " << endl;
    (contest_effect_id != -1) ? cout << "CONTEST EFFECT ID: " << contest_effect_id << endl : cout << "CONTEST EFFECT ID: " << endl;
    (super_contest_effect_id != -1) ? cout << "SUPER CONTEST EFFECT ID: " << super_contest_effect_id << endl : cout << "SUPER CONTEST EFFECT ID: " << endl;
    cout << endl;
}

Pokemon_Move_DB :: Pokemon_Move_DB(int pokemon_id, int version_group_id, int move_id, int pokemon_move_method_id, int level, int order)
{
    this->pokemon_id = pokemon_id;
    this->version_group_id = version_group_id;
    this->move_id = move_id;
    this->pokemon_move_method_id = pokemon_move_method_id;
    this->level = level;
    this->order = order;
};

// Pokemon_Move_DB :: Pokemon_Move_DB(const Pokemon_Move_DB &old)
// {
//     pokemon_id = old.pokemon_id;
//     version_group_id = old.version_group_id;
//     move_id = old.move_id;
//     pokemon_move_method_id = old.pokemon_move_method_id;
//     level = old.level;
//     order = old.order;
//     Pokemon_Move_DB(pokemon_id, version_group_id, move_id, pokemon_move_method_id, level, order);
// }

int Pokemon_Move_DB :: getPokemonID() const {return pokemon_id;}
int Pokemon_Move_DB :: getVersionGroupID() const {return version_group_id;}
int Pokemon_Move_DB :: getMoveID() const {return move_id;}
int Pokemon_Move_DB :: getPokemonMoveMethodID() const {return pokemon_move_method_id;}
int Pokemon_Move_DB :: getLevel() const {return level;}
int Pokemon_Move_DB :: getOrder() const {return order;}
void Pokemon_Move_DB :: print()
{
    (pokemon_id != -1) ? cout << "POKEMON ID: " << pokemon_id << endl : cout << "POKEMON ID: " << endl;
    (version_group_id != -1) ? cout << "VERSION GROUP ID: " << version_group_id << endl : cout << "VERSION GROUP ID: " << endl;
    (move_id != -1) ? cout << "MOVE ID: " << move_id << endl : cout << "MOVE ID: " << endl;
    (pokemon_move_method_id != -1) ? cout << "POKEMON MOVE METHOD ID: " << pokemon_move_method_id << endl : cout << "POKEMON MOVE METHOD ID: " << endl;
    (level != -1) ? cout << "LEVEL: " << level << endl : cout << "LEVEL: " << endl;
    (order != -1) ? cout << "ORDER: " << order << endl : cout << "ORDER: " << endl;
    cout << endl;
}

Pokemon_Species_DB :: Pokemon_Species_DB(int id, string identifier, int generation_id, int evolves_from_species_id, int evolution_chain_id, int color_id,
                                  int shape_id, int habitat_id, int gender_rate, int capture_rate, int base_happiness, int is_baby, int hatch_counter,
                                  int has_gender_differences, int growth_rate_id, int forms_switchable, int is_legendary, int is_mythical, int order, int conquest_order)
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
};

int Pokemon_Species_DB :: getID() const {return id;}
string Pokemon_Species_DB :: getIdentifier() const {return identifier;}
int Pokemon_Species_DB :: getGenerationID() const {return generation_id;}
int Pokemon_Species_DB :: getEvolvesFromSpeciesID() const {return evolves_from_species_id;}
int Pokemon_Species_DB :: getEvolutionCHainID() const {return evolution_chain_id;}
int Pokemon_Species_DB :: colorID() const {return color_id;}
int Pokemon_Species_DB :: getShapeID() const {return shape_id;}
int Pokemon_Species_DB :: getHabitatID() const {return habitat_id;}
int Pokemon_Species_DB :: getGenderRate() const {return gender_rate;}
int Pokemon_Species_DB :: getCaptureRate() const {return capture_rate;}
int Pokemon_Species_DB :: getBaseHappiness() const {return base_happiness;}
int Pokemon_Species_DB :: getIsBaby() const {return is_baby;}
int Pokemon_Species_DB :: getHatchCounter() const {return hatch_counter;}
int Pokemon_Species_DB :: getHasGenderDifferences() const {return has_gender_differences;}
int Pokemon_Species_DB :: getGrowthRateID() const {return growth_rate_id;}
int Pokemon_Species_DB :: getFormsSwitchable() const {return forms_switchable;}
int Pokemon_Species_DB :: getIsLegendary() const {return is_legendary;}
int Pokemon_Species_DB :: getIsMythical() const {return is_mythical;}
int Pokemon_Species_DB :: getOrder() const {return order;}
int Pokemon_Species_DB :: getConquestOrder() const {return conquest_order;}
void Pokemon_Species_DB :: print()
{
    (id != -1) ? cout << "ID: " << id << endl : cout << "ID: " << endl;
    (identifier != "-1") ? cout << "IDENTIFIER: " << identifier << endl : cout << "IDENTIFIER: " << endl;
    (generation_id != -1) ? cout << "GENERATION ID: " << generation_id << endl : cout << "GENERATION ID: " << endl;
    (evolves_from_species_id != -1) ? cout << "EVOLVES FROM SPECIES ID: " << evolves_from_species_id << endl : cout << "EVOLVES FROM SPECIES ID: " << endl;
    (evolution_chain_id != -1) ? cout << "EVOLUTION CHAIN ID: " << evolution_chain_id << endl : cout << "EVOLUTION CHAIN ID: " << endl;
    (color_id != -1) ? cout << "COLOR ID: " << color_id << endl : cout << "COLOR ID: " << endl;
    (shape_id != -1) ? cout << "SHAPE ID: " << shape_id << endl : cout << "SHAPE ID: " << endl;
    (habitat_id != -1) ? cout << "HABITAT ID: " << habitat_id << endl : cout << "HABITAT ID: " << endl;
    (gender_rate != -1) ? cout << "GENDER RATE: " << gender_rate << endl : cout << "GENDER RATE: " << endl;
    (capture_rate != -1) ? cout << "CAPTURE RATE: " << capture_rate << endl : cout << "CAPTURE RATE: " << endl;
    (base_happiness != -1) ? cout << "BASE HAPPINESS: " << base_happiness << endl : cout << "BASE HAPPINESS: " << endl;
    (is_baby != -1) ? cout << "IS BABY: " << is_baby << endl : cout << "IS BABY: " << endl;
    (hatch_counter != -1) ? cout << "HATCH COUNTER: " << hatch_counter << endl : cout << "HATCH COUNTER: " << endl;
    (has_gender_differences != -1) ? cout << "HAS GENDER DIFFERENCES: " << has_gender_differences << endl : cout << "HAS GENDER DIFFERENCES: " << endl;
    (growth_rate_id != -1) ? cout << "GROWTH RATE ID: " << growth_rate_id << endl : cout << "GROWTH RATE ID: " << endl;
    (forms_switchable != -1) ? cout << "FORMS SWITCHABLE: " << forms_switchable << endl : cout << "FORMS SWITCHABLE: " << endl;
    (is_legendary != -1) ? cout << "IS LEGENDARY: " << is_legendary << endl : cout << "IS LEGENDARY: " << endl;
    (is_mythical != -1) ? cout << "IS MYTHICAL: " << is_mythical << endl : cout << "IS MYTHICAL: " << endl;
    (order != -1) ? cout << "ORDER: " << order << endl : cout << "ORDER: " << endl;
    (conquest_order != -1) ? cout << "CONQUEST ORDER: " << conquest_order << endl : cout << "CONQUEST ORDER: " << endl;
    cout << endl;
}

Experience_DB :: Experience_DB(int growth_rate_id, int level, int experience)
{
    this->growth_rate_id = growth_rate_id;
    this->level = level;
    this->experience = experience;
};

int Experience_DB :: getGrowthRateID() const {return growth_rate_id;}
int Experience_DB :: getLevel() const {return level;}
int Experience_DB :: getExperience() const {return experience;}
void Experience_DB :: print()
{
    (growth_rate_id != -1) ? cout << "GROWTH RATE ID: " << growth_rate_id << endl : cout << "GROWTH RATE ID: " << endl;
    (level != -1) ? cout << "LEVEL: " << level << endl : cout << "LEVEL: " << endl;
    (experience != -1) ? cout << "EXPERIENCE: " << experience << endl : cout << "EXPERIENCE: " << endl;
    cout << endl;
}

Type_Name_DB :: Type_Name_DB(int type_id, int local_language_id, string name)
{
    this->type_id = type_id;
    this->local_language_id = local_language_id;
    this->name = name;
};

int Type_Name_DB :: getTypeID() const {return type_id;}
int Type_Name_DB :: getLocalLanguageID() const {return local_language_id;}
string Type_Name_DB :: getName() const {return name;}
void Type_Name_DB :: print()
{
    (type_id != -1) ? cout << "TYPE ID: " << type_id << endl : cout << "TYPE ID: " << endl;
    (local_language_id != -1) ? cout << "LOCAL LANGUAGE ID: " << local_language_id << endl : cout << "LOCAL LANGUAGE ID: " << endl;
    (name != "-1") ? cout << "NAME: " << name << endl : cout << "NAME: " << endl;
    cout << endl;
}

Pokemon_Stat_DB :: Pokemon_Stat_DB(int pokemon_id, int stat_id, int base_stat, int effort)
{
    this->pokemon_id = pokemon_id;
    this->stat_id = stat_id;
    this->base_stat = base_stat;
    this->effort = effort;
};

int Pokemon_Stat_DB :: getPokemonID() const {return pokemon_id;}
int Pokemon_Stat_DB :: getStatID() const {return stat_id;}
int Pokemon_Stat_DB :: getBaseStat() const {return base_stat;}
int Pokemon_Stat_DB :: getEffort() const {return effort;}
void Pokemon_Stat_DB :: print()
{
    (pokemon_id != -1) ? cout << "POKEMON ID: " << pokemon_id << endl : cout << "POKEMON ID: " << endl;
    (stat_id != -1) ? cout << "STAT ID: " << stat_id << endl : cout << "STAT ID: " << endl;
    (base_stat != -1) ? cout << "BASE STAT: " << base_stat << endl : cout << "BASE STAT: " << endl;
    (effort != -1) ? cout << "EFFORT: " << effort << endl : cout << "EFFORT: " << endl;
    cout << endl;
}

void parsePokemonList(vector<Pokemon_DB> *pokemonList)
{
    ifstream in_file;
    vector<string> row;
    string line, token;

    int id, species_id, height, weight, base_experience, order, is_default;
    string identifier;

    in_file.open("share/cs327/pokemon.csv");

    if (!in_file.is_open())
    {
        cout << "ERROR: POKEMON.CSV COULD NOT BE FOUND ON THE PYRITE SERVER!" << endl
             << "SEARCHING ANOTHER LOCATION OF THE SERVER..." << endl
             << endl;
        char *path = getenv("HOME");
        string home(path);
        in_file.open(home + "/.poke327/pokemon.csv");

        if (!in_file.is_open())
        {
            cout << "ERROR: POKEMON.CSV COULD NOT BE FOUND ON THE PYRITE SERVER!" << endl
                 << "SEARCHING LOCALLY..." << endl
                 << endl;
            in_file.open("csv_files/pokemon.csv");

            if (!in_file.is_open())
            {
                cout << "ERROR: POKEMON.CSV COULD NOT BE FOUND LOCALLY..." << endl
                     << "EXITING PROGRAM." << endl;
                return;
            }
        }
    }

    getline(in_file, line);
    line = "";

    // file ensured to be open at this point, so begin reading from file.
    while (!in_file.eof())
    {
        if (row.size() > 1) row.clear();
        // get line of input from csv file
        getline(in_file, line);
        // associate string with a stream.
        stringstream s(line);

        // tokenize stream based on ',' and then fill with data
        while (getline(s, token, ','))
        {
            row.push_back(token);
        }

        if (row[0] == "")
            id = -1;
        else
            id = stoi(row[0]);
        if (row[1] == "")
            identifier = "-1";
        else
            identifier = row[1];
        if (row[2] == "")
            species_id = -1;
        else
            species_id = stoi(row[2]);
        if (row[3] == "")
            height = -1;
        else
            height = stoi(row[3]);
        if (row[4] == "")
            weight = -1;
        else
            weight = stoi(row[4]);
        if (row[5] == "")
            base_experience = -1;
        else
            base_experience = stoi(row[5]);
        if (row[6] == "")
            order = -1;
        else
            order = stoi(row[6]);
        if (row[7] == "")
            is_default = -1;
        else
            is_default = stoi(row[7]);

        pokemonList->push_back(Pokemon_DB(id, identifier, species_id, height, weight, base_experience, order, is_default));
    }

    // close the file
    in_file.close();
}

void printPokemonList(vector<Pokemon_DB> *pokemonList)
{
    cout << "PRINTING POKEMON LIST:" << endl;

    for (int i = 0; i < pokemonList->size() - 1; i++)
    {
        pokemonList->at(i).print();
    }
}

void parseMovesList(vector<Move_DB> *movesList)
{
    ifstream in_file;
    vector<string> row;
    string line, token;

    int id, generation_id, type_id, power, pp, accuracy, priority, target_id, damage_class_id, effect_id, effect_chance, contest_type_id, contest_effect_id, super_contest_effect_id;
    string identifier;

    in_file.open("share/cs327/moves.csv");

    if (!in_file.is_open())
    {
        cout << "ERROR: MOVES.CSV COULD NOT BE FOUND ON THE PYRITE SERVER!" << endl
             << "SEARCHING ANOTHER LOCATION OF THE SERVER..." << endl
             << endl;
        char *path = getenv("HOME");
        string home(path);
        in_file.open(home + "/.poke327/moves.csv");

        if (!in_file.is_open())
        {
            cout << "ERROR: MOVES.CSV COULD NOT BE FOUND ON THE PYRITE SERVER!" << endl
                 << "SEARCHING LOCALLY..." << endl
                 << endl;
            in_file.open("csv_files/moves.csv");

            if (!in_file.is_open())
            {
                cout << "ERROR: MOVES.CSV COULD NOT BE FOUND LOCALLY..." << endl
                     << "EXITING PROGRAM." << endl;
                return;
            }
        }
    }

    // skip the first line
    getline(in_file, line);
    line = "";

    // file ensured to be open at this point, so begin reading from file.
    while (!in_file.eof())
    {
        if (row.size() > 1) row.clear();
        // get line of input from csv file
        getline(in_file, line);
        // associate string with a stream.
        stringstream s(line);
        row.assign(15, "");
        int i = 0;
        // tokenize stream based on ',' and then fill with data
        while (getline(s, token, ','))
        {
            if (token != "") row[i++] = (token);
        }

        if (row[0] == "")
            id = -1;
        else
            id = stoi(row[0]);
        if (row[1] == "")
            identifier = "-1";
        else
            identifier = row[1];
        if (row[2] == "")
            generation_id = -1;
        else
            generation_id = stoi(row[2]);
        if (row[3] == "")
            type_id = -1;
        else
            type_id = stoi(row[3]);
        if (row[4] == "")
            power = -1;
        else
            power = stoi(row[4]);
        if (row[5] == "")
            pp = -1;
        else
            pp = stoi(row[5]);
        if (row[6] == "")
            accuracy = -1;
        else
            accuracy = stoi(row[6]);
        if (row[7] == "")
            priority = -1;
        else
            priority = stoi(row[7]);
        if (row[8] == "")
            target_id = -1;
        else
            target_id = stoi(row[8]);
        if (row[9] == "")
            damage_class_id = -1;
        else
            damage_class_id = stoi(row[9]);
        if (row[10] == "")
            effect_id = -1;
        else
            effect_id = stoi(row[10]);
        if (row[11] == "")
            effect_chance = -1;
        else
            effect_chance = stoi(row[11]);
        if (row[12] == "")
            contest_type_id = -1;
        else
            contest_type_id = stoi(row[12]);
        if (row[13] == "")
            contest_effect_id = -1;
        else
            contest_effect_id = stoi(row[13]);
        if (row[14] == "" || row[14] == "\n")
            super_contest_effect_id = -1;
        else
            super_contest_effect_id = stoi(row[14]);

        movesList->push_back(Move_DB(id, identifier, generation_id, type_id, power, pp, accuracy, priority, target_id, damage_class_id, effect_id, effect_chance, contest_type_id, contest_effect_id, super_contest_effect_id));
    }

    // close the file
    in_file.close();
}

void printMovesList(vector<Move_DB> *movesList)
{
    cout << "PRINTING MOVE LIST:" << endl;

    for (int i = 0; i < movesList->size() - 1; i++)
    {
        movesList->at(i).print();
    }
}

void parsePokemonMovesList(vector<Pokemon_Move_DB> *pokemonMovesList)
{
    ifstream in_file;
    vector<string> row;
    string line, token;

    int pokemon_id, version_group_id, move_id, pokemon_move_method_id, level, order;

    in_file.open("share/cs327/pokemon_moves.csv");

    if (!in_file.is_open())
    {
        cout << "ERROR: POKEMON_MOVES.CSV COULD NOT BE FOUND ON THE PYRITE SERVER!" << endl
             << "SEARCHING ANOTHER LOCATION OF THE SERVER..." << endl
             << endl;
        char *path = getenv("HOME");
        string home(path);
        in_file.open(home + "/.poke327/pokemon_moves.csv");

        if (!in_file.is_open())
        {
            cout << "ERROR: POKEMON_MOVES.CSV COULD NOT BE FOUND ON THE PYRITE SERVER!" << endl
                 << "SEARCHING LOCALLY..." << endl
                 << endl;
            in_file.open("csv_files/pokemon_moves.csv");

            if (!in_file.is_open())
            {
                cout << "ERROR: POKEMON_MOVES.CSV COULD NOT BE FOUND LOCALLY..." << endl
                     << "EXITING PROGRAM." << endl;
                return;
            }
        }
    }

    getline(in_file, line);
    line = "";

    // file ensured to be open at this point, so begin reading from file.
    while (!in_file.eof())
    {
        if (row.size() > 1) row.clear();
        // get line of input from csv file
        getline(in_file, line);
        // associate string with a stream.
        stringstream s(line);
        // NEW
        row.assign(6, "");
        // tokenize stream based on ',' and then fill with data
        int i = 0;
        while (getline(s, token, ','))
        {
            if (token != "") row[i++] = (token);
        }

        if (row[0] == "")
            pokemon_id = -1;
        else
            pokemon_id = stoi(row[0]);
        if (row[1] == "")
            version_group_id = -1;
        else
            version_group_id = stoi(row[1]);
        if (row[2] == "")
            move_id = -1;
        else
            move_id = stoi(row[2]);
        if (row[3] == "")
            pokemon_move_method_id = -1;
        else
            pokemon_move_method_id = stoi(row[3]);
        if (row[4] == "")
            level = -1;
        else
            level = stoi(row[4]);
        if (row[5] == "" || row[5] == "\n")
            order = -1;
        else
            order = stoi(row[5]);

        pokemonMovesList->push_back(Pokemon_Move_DB(pokemon_id, version_group_id, move_id, pokemon_move_method_id, level, order));
    }

    // close the file
    in_file.close();
}

void printPokemonMovesList(vector<Pokemon_Move_DB> *pokemonMovesList)
{
    cout << "PRINTING POKEMON MOVE LIST:" << endl;

    for (int i =  0; i < pokemonMovesList->size() - 1; i++)
    {
        pokemonMovesList->at(i).print();
    }
}

void parsePokemonSpeciesList(vector<Pokemon_Species_DB> *pokemonSpeciesList)
{
    ifstream in_file;
    vector<string> row;
    string line, token;

    int id, generation_id, evolves_from_species_id, evolution_chain_id, color_id, shape_id, habitat_id, gender_rate, capture_rate, base_happiness, is_baby,
        hatch_counter, has_gender_differences, growth_rate_id, forms_switchable, is_legendary, is_mythical, order, conquest_order;
    string identifier;

    in_file.open("share/cs327/pokemon_species.csv");

    if (!in_file.is_open())
    {
        cout << "ERROR: POKEMON_SPECIES.CSV COULD NOT BE FOUND ON THE PYRITE SERVER!" << endl
             << "SEARCHING ANOTHER LOCATION OF THE SERVER..." << endl
             << endl;
        char *path = getenv("HOME");
        string home(path);
        in_file.open(home + "/.poke327/pokemon_species.csv");

        if (!in_file.is_open())
        {
            cout << "ERROR: POKEMON_SPECIES.CSV COULD NOT BE FOUND ON THE PYRITE SERVER!" << endl
                 << "SEARCHING LOCALLY..." << endl
                 << endl;
            in_file.open("csv_files/pokemon_species.csv");

            if (!in_file.is_open())
            {
                cout << "ERROR: POKEMON_SPECIES.CSV COULD NOT BE FOUND LOCALLY..." << endl
                     << "EXITING PROGRAM." << endl;
                return;
            }
        }
    }

    // skip the first line
    getline(in_file, line);
    line = "";

    // file ensured to be open at this point, so begin reading from file.
    while (!in_file.eof())
    {
        if (row.size() > 1) row.clear();
        // get line of input from csv file
        getline(in_file, line);
        // associate string with a stream.
        stringstream s(line);
        // NEW
        row.assign(20, "");
        // tokenize stream based on ',' and then fill with data
        int i = 0;
        while (getline(s, token, ','))
        {
            if (token != "") row[i++] = (token);
        }

        if (row[0] == "")
            id = -1;
        else
            id = stoi(row[0]);
        if (row[1] == "")
            identifier = "-1";
        else
            identifier = row[1];
        if (row[2] == "")
            generation_id = -1;
        else
            generation_id = stoi(row[2]);
        if (row[3] == "")
            evolves_from_species_id = -1;
        else
            evolves_from_species_id = stoi(row[3]);
        if (row[4] == "")
            evolution_chain_id = -1;
        else
            evolution_chain_id = stoi(row[4]);
        if (row[5] == "")
            color_id = -1;
        else
            color_id = stoi(row[5]);
        if (row[6] == "")
            shape_id = -1;
        else
            shape_id = stoi(row[6]);
        if (row[7] == "")
            habitat_id = -1;
        else
            habitat_id = stoi(row[7]);
        if (row[8] == "")
            gender_rate = -1;
        else
            gender_rate = stoi(row[8]);
        if (row[9] == "")
            capture_rate = -1;
        else
            capture_rate = stoi(row[9]);
        if (row[10] == "")
            base_happiness = -1;
        else
            base_happiness = stoi(row[10]);
        if (row[11] == "")
            is_baby = -1;
        else
            is_baby = stoi(row[11]);
        if (row[12] == "")
            hatch_counter = -1;
        else
            hatch_counter = stoi(row[12]);
        if (row[13] == "")
            has_gender_differences = -1;
        else
            has_gender_differences = stoi(row[13]);
        if (row[14] == "")
            growth_rate_id = -1;
        else
            growth_rate_id = stoi(row[14]);
        if (row[15] == "")
            forms_switchable = -1;
        else
            forms_switchable = stoi(row[15]);
        if (row[16] == "")
            is_legendary = -1;
        else
            is_legendary = stoi(row[16]);
        if (row[17] == "")
            is_mythical = -1;
        else
            is_mythical = stoi(row[17]);
        if (row[18] == "")
            order = -1;
        else
            order = stoi(row[18]);
        // todo lldb reported an error here
        if (row[19] == "" || row[19] == "\n")
            conquest_order = -1;
        else
            conquest_order = stoi(row[19]);

        pokemonSpeciesList->push_back(Pokemon_Species_DB(id, identifier, generation_id, evolves_from_species_id, evolution_chain_id, color_id, shape_id, habitat_id, gender_rate, capture_rate, base_happiness, is_baby,
                                                     hatch_counter, has_gender_differences, growth_rate_id, forms_switchable, is_legendary, is_mythical, order, conquest_order));
    }

    // close the file
    in_file.close();
}

void printPokemonSpeciesList(vector<Pokemon_Species_DB> *pokemonSpeciesList)
{
    cout << "PRINTING POKEMON SPECIES LIST:" << endl;

    for (int i =  0; i < pokemonSpeciesList->size() - 1; i++)
    {
        pokemonSpeciesList->at(i).print();
    }
}

void parseExperienceList(vector<Experience_DB> *experienceList)
{
    ifstream in_file;
    vector<string> row;
    string line, token;

    int growth_rate_id, level, experience;

    in_file.open("share/cs327/experience.csv");

    if (!in_file.is_open())
    {
        cout << "ERROR: EXPERIENCE.CSV COULD NOT BE FOUND ON THE PYRITE SERVER!" << endl
             << "SEARCHING ANOTHER LOCATION OF THE SERVER..." << endl
             << endl;
        char *path = getenv("HOME");
        string home(path);
        in_file.open(home + "/.poke327/experience.csv");

        if (!in_file.is_open())
        {
            cout << "ERROR: EXPERIENCE.CSV COULD NOT BE FOUND ON THE PYRITE SERVER!" << endl
                 << "SEARCHING LOCALLY..." << endl
                 << endl;
            in_file.open("csv_files/experience.csv");

            if (!in_file.is_open())
            {
                cout << "ERROR: EXPERIENCE.CSV COULD NOT BE FOUND LOCALLY..."
                     << "EXITING PROGRAM." << endl;
                return;
            }
        }
    }

    getline(in_file, line);
    line = "";

    // file ensured to be open at this point, so begin reading from file.
    while (!in_file.eof())
    {
        if (row.size() > 1) row.clear();
        // get line of input from csv file
        getline(in_file, line);
        // associate string with a stream.
        stringstream s(line);
        row.assign(3, "");
        int i = 0;
        // tokenize stream based on ',' and then fill with data
        while (getline(s, token, ','))
        {
            if (token != "") row[i++] = (token);
        }

        if (row[0] == "")
            growth_rate_id = -1;
        else
            growth_rate_id = stoi(row[0]);
        if (row[1] == "")
            level = -1;
        else
            level = stoi(row[1]);
        if (row[2] == "" || row[2] == "\n")
            experience = -1;
        else
            experience = stoi(row[2]);

        experienceList->push_back(Experience_DB(growth_rate_id, level, experience));
    }

    // close the file
    in_file.close();
}

void printExperienceList(vector<Experience_DB> *experienceList)
{
    cout << "PRINTING EXPERIENCE LIST:" << endl;

    for (int i =  0; i < experienceList->size() - 1; i++)
    {
        experienceList->at(i).print();
    }
}

void parseTypeNamesList(vector<Type_Name_DB> *typeNameList)
{
    ifstream in_file;
    vector<string> row;
    string line, token;

    int type_id, local_language_id;
    string name;

    in_file.open("share/cs327/type_names.csv");

    if (!in_file.is_open())
    {
        cout << "ERROR: TYPE_NAMES.CSV COULD NOT BE FOUND ON THE PYRITE SERVER!" << endl
             << "SEARCHING ANOTHER LOCATION OF THE SERVER..." << endl
             << endl;
        char *path = getenv("HOME");
        string home(path);
        in_file.open(home + "/.poke327/type_names.csv");

        if (!in_file.is_open())
        {
            cout << "ERROR: TYPE_NAMES.CSV COULD NOT BE FOUND ON THE PYRITE SERVER!" << endl
                 << "SEARCHING LOCALLY..." << endl
                 << endl;
            in_file.open("csv_files/type_names.csv");

            if (!in_file.is_open())
            {
                cout << "ERROR: TYPE_NAMES.CSV COULD NOT BE FOUND LOCALLY..." << endl
                     << "EXITING PROGRAM." << endl;
                return;
            }
        }
    }

    getline(in_file, line);
    line = "";

    // file ensured to be open at this point, so begin reading from file.
    while (!in_file.eof())
    {
        if (row.size() > 1) row.clear();
        // get line of input from csv file
        getline(in_file, line);
        // associate string with a stream.
        stringstream s(line);
        row.assign(3, "");
        int i = 0;
        // tokenize stream based on ',' and then fill with data
        while (getline(s, token, ','))
        {
            if (token != "") row[i++] = (token);
        }

        if (row[0] == "")
            type_id = -1;
        else
            type_id = stoi(row[0]);
        if (row[1] == "")
            local_language_id = -1;
        else
            local_language_id = stoi(row[1]);
        if (row[2] == "" || row[2] == "\n")
            name = -1;
        else
            name = row[2];

        typeNameList->push_back(Type_Name_DB(type_id, local_language_id, name));
    }

    // close the file
    in_file.close();
}

void printTypeNamesList(vector<Type_Name_DB> *typeNameList)
{
    cout << "PRINTING TYPE NAME LIST:" << endl;

    for (int i =  0; i < typeNameList->size() - 1; i++)
    {
        typeNameList->at(i).print();
    }
}

void parsePokemonStatsList(vector<Pokemon_Stat_DB> *pokemonStatsList)
{
    ifstream in_file;
    vector<string> row;
    string line, token;

    int pokemon_id, stat_id, base_stat, effort;

    in_file.open("share/cs327/pokemon_stats.csv");

    if (!in_file.is_open())
    {
        cout << "ERROR: POKEMON_STATS.CSV COULD NOT BE FOUND ON THE PYRITE SERVER!" << endl
             << "SEARCHING ANOTHER LOCATION OF THE SERVER..." << endl
             << endl;
        char *path = getenv("HOME");
        string home(path);
        in_file.open(home + "/.poke327/pokemon_stats.csv");

        if (!in_file.is_open())
        {
            cout << "ERROR: POKEMON_STATS.CSV COULD NOT BE FOUND ON THE PYRITE SERVER!" << endl
                 << "SEARCHING LOCALLY..." << endl
                 << endl;
            in_file.open("csv_files/pokemon_stats.csv");

            if (!in_file.is_open())
            {
                cout << "ERROR: POKEMON_STATS.CSV COULD NOT BE FOUND LOCALLY..."
                     << "EXITING PROGRAM." << endl;
                return;
            }
        }
    }

    getline(in_file, line);
    line = "";

    // file ensured to be open at this point, so begin reading from file.
    while (!in_file.eof())
    {
        if (row.size() > 1) row.clear();
        // get line of input from csv file
        getline(in_file, line);
        // associate string with a stream.
        stringstream s(line);
        row.assign(3, "");
        int i = 0;
        // tokenize stream based on ',' and then fill with data
        while (getline(s, token, ','))
        {
            if (token != "") row[i++] = (token);
        }

        if (row[0] == "")
            pokemon_id = -1;
        else
            pokemon_id = stoi(row[0]);
        if (row[1] == "")
            stat_id = -1;
        else
            stat_id = stoi(row[1]);
        if (row[2] == "")
            base_stat = -1;
        else
            base_stat = stoi(row[2]);
        if (row[3] == "" || row[3] == "\n")
            effort = -1;
        else
            effort = stoi(row[3]);

        pokemonStatsList->push_back(Pokemon_Stat_DB(pokemon_id, stat_id, base_stat, effort));
    }

    // close the file
    in_file.close();
}

void printPokemonStatsList(vector<Pokemon_Stat_DB> *pokemonStatsList)
{
    cout << "PRINTING POKEMON STATS LIST:" << endl;

    for (int i = 0; i < pokemonStatsList->size() - 1; i++)
    {
        pokemonStatsList->at(i).print();
    }
}

void askUserForFile()
{
    vector<Pokemon_DB> pokemonList;
    vector<Move_DB> movesList;
    vector<Pokemon_Move_DB> pokemonMovesList;
    vector<Pokemon_Species_DB> pokemonSpeciesList;
    vector<Experience_DB> experienceList;
    vector<Type_Name_DB> typeNameList;
    vector<Pokemon_Stat_DB> pokemonStatsList;

    string file_name;

    // get file name from user, and try to open
    cout << "Please enter the file's name that you would like to parse: ";
    // if this doesn't work just use cin >> and then cin.ignore
    getline(cin, file_name);
    cout << endl;

    if (file_name == "pokemon")
    {
        parsePokemonList(&pokemonList);
        printPokemonList(&pokemonList);
    }

    else if (file_name == "moves")
    {
        parseMovesList(&movesList);
        printMovesList(&movesList);
    }
    else if (file_name == "pokemon_moves")
    {
        parsePokemonMovesList(&pokemonMovesList);
        printPokemonMovesList(&pokemonMovesList);
    }
    else if (file_name == "pokemon_species")
    {
        parsePokemonSpeciesList(&pokemonSpeciesList);
        printPokemonSpeciesList(&pokemonSpeciesList);
    }
    else if (file_name == "experience")
    {
        parseExperienceList(&experienceList);
        printExperienceList(&experienceList);
    }
    else if (file_name == "type_names")
    {
        parseTypeNamesList(&typeNameList);
        printTypeNamesList(&typeNameList);
    }
    if (file_name == "pokemon_stats")
    {
        parsePokemonStatsList(&pokemonStatsList);
        printPokemonStatsList(&pokemonStatsList);
    }
    else
        cout << "ERROR: FILE COULD NOT BE FOUND!" << endl;
}


// Parses all of the required csv files and populates the corresponding vectors.
void parseAll(vector<Pokemon_DB> *pokemonList, vector<Move_DB> *movesList, vector<Pokemon_Move_DB> *pokemonMovesList, vector<Pokemon_Species_DB> *pokemonSpeciesList,
              vector<Experience_DB> *experienceList, vector<Type_Name_DB> *typeNameList, vector<Pokemon_Stat_DB> *pokemonStatsList)
{

    parsePokemonList(pokemonList);
    parseMovesList(movesList);
    parsePokemonMovesList(pokemonMovesList);
    parsePokemonSpeciesList(pokemonSpeciesList);
    parseExperienceList(experienceList);
    parseTypeNamesList(typeNameList);
    parsePokemonStatsList(pokemonStatsList);
}