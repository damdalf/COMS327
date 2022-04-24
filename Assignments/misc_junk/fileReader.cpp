//
// Created by Devin Amdahl on 3/29/22.
//

#include "file_reader.h"

Pokemon ::Pokemon(int id, string identifier, int species_id, int height, int weight, int base_experience, int order, int is_default)
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

Pokemon ::getID() const { return id; }
Pokemon ::getIdentifier() const { return identifier; }
Pokemon ::getSpeciesID() const { return species_id; }
Pokemon ::getHeight() const { return height; }
Pokemon ::getWeight() const { return weight; }
Pokemon ::getBaseExperience() const { return base_experience; }
Pokemon ::getOrder() const { return order; }
Pokemon ::getIsDefault() const { return is_default; }
Pokemon ::print()
{
    cout << "ID: " << this.id << endl;
    cout << "IDENTIFIER: " << this.identifier << endl;
    cout << "HEIGHT: " << this.height << endl;
    cout << "WEIGHT: " << this.weight << endl;
    cout << "BASE EXPERIENCE: " << this.base_experience << endl;
    cout << "ORDER: " << this.order << endl;
    cout << "IS DEFAULT: " << this.is_default << endl;
    cout << endl;
}

Move ::Move(int id, string identifier, int generation_id, int type_id, int power, int pp, int accuracy, int priority, int target_id, int damage_class_id, int effect_id, int effect_chance, int contest_type_id, int contest_effect_id, int super_contest_effect_id)
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

Move ::getID() const { return id; }
Move ::getIdentifier() const { return identifier; }
Move ::getGenerationID() const { return generation_id; }
Move ::getTypeID() const { return type_id; }
Move ::getPower() const { return power; }
Move ::getPP() const { return pp; }
Move ::getAccuracy() const { return accuracy; }
Move ::getPriority() const return {priority} Move ::getTargetID() const { return target_id; }
Move ::getDamageClassID() const { damage_class_id; }
Move ::getEffectID() const { effect_id; }
Move ::getEffectChance() const { effect_chance; }
Move ::getContestTypeID() const { contest_type_id; }
Move ::getContestEffectID() const { contest_effect_id; }
Move ::getSuperContestEffectID() const { super_contest_effect_id; }
Move ::print()
{
    cout << "ID: " << this.id << endl;
    cout << "IDENTIFIER: " << this.identifier << endl;
    cout << "GENERATION ID: " << this.generation_id << endl;
    cout << "TYPE ID: " << this.type_id << endl;
    cout << "POWER: " << this.power << endl;
    cout << "PP: " << this.pp << endl;
    cout << "ACCURACY: " << this.accuracy << endl;
    cout << "PRIORITY: " << this.priority << endl;
    cout << "TARGET ID: " << this.target_id << endl;
    cout << "DAMAGE CLASS ID: " << this.damage_class_id << endl;
    cout << "EFFECT ID: " << this.effect_id << endl;
    cout << "EFFECT CHANCE: " << this.effect_chance << endl;
    cout << "CONTEST TYPE ID: " << this.contest_type_id << endl;
    cout << "CONTEST EFFECT ID: " << this.contest_effect_id << endl;
    cout << "SUPER CONTEST EFFECT ID: " << this.super_contest_effect_id << endl;
    cout << endl;
}

Pokemon_Move ::Pokemon_Move(int pokemon_id, int version_group_id, int move_id, int pokemon_move_method_id, int level, int order)
{
    this->pokemon_id = pokemon_id;
    this->version_group_id = version_group_id;
    this->move_id = move_id;
    this->pokemon_move_method_id = pokemon_move_method_id;
    this->level = level;
    this->order = order;
};

Pokemon_Move ::getPokemonID() const { return pokemon_id; }
Pokemon_Move ::getVersionGroupID() const { return version_group_id; }
Pokemon_Move ::getMoveID() const { return move_id; }
Pokemon_Move ::getPokemonMoveMethodID() const { return pokemon_move_method_id; }
Pokemon_Move ::getLevel() const { return level; }
Pokemon_Move ::getOrder() const { return order; }
Pokemon_Move ::print()
{
    cout << "POKEMON ID: " << this.pokemon_id << endl;
    cout << "VERSION GROUP ID: " << this.version_group_id << endl;
    cout << "MOVE ID: " << this.move_id << endl;
    cout << "POKEMON MOVE METHOD ID: " << this.pokemon_move_method_id << endl;
    cout << "LEVEL: " << this.level << endl;
    cout << "ORDER: " << this.order << endl;
    cout << endl;
}

Pokemon_Species ::Pokemon_Species(int id, string identifier, int generation_id, int evolves_from_species_id, int evolution_chain_id, int color_id,
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

Pokemon_Species ::getID() const { return id; }
Pokemon_Species ::getIdentifier() const { return identifier; }
Pokemon_Species ::getGenerationID() const { return generation_id; }
Pokemon_Species ::getEvolvesFromSpeciesID() const { return evolves_from_species_id; }
Pokemon_Species ::getEvolutionCHainID() const { return evolution_chain_id; }
Pokemon_Species ::colorID() const { return color_id; }
Pokemon_Species ::getShapeID() const { return getShapeID; }
Pokemon_Species ::getHabitatID() const { return habitat_id; }
Pokemon_Species ::getGenderRate() const { return gender_rate; }
Pokemon_Species ::getCaptureRate() const { return capture_rate; }
Pokemon_Species ::getBaseHappiness() const { return base_happiness; }
Pokemon_Species ::getIsBaby() const { return is_baby; }
Pokemon_Species ::getHatchCounter() const { return hatch_counter; }
Pokemon_Species ::getHasGenderDifferences() const { return has_gender_differences; }
Pokemon_Species ::getGrowthRateID() const { return growth_rate_id; }
Pokemon_Species ::getFormsSwitchable() const { return forms_switchable; }
Pokemon_Species ::getIsLegendary() const { return is_legendary; }
Pokemon_Species ::getIsMythical() const { return is_mythical; }
Pokemon_Species ::getOrder() const { return order; }
Pokemon_Species ::getConquestOrder() const { return conquest_order; }
Pokemon_Species ::print()
{
    cout << "ID: " << this.id << endl;
    cout << "IDENTIFIER: " << this.identifier << endl;
    cout << "GENERATION ID: " << this.generation_id << endl;
    cout << "EVOLVES FROM SPECIES ID: " << this.evolves_from_species_id << endl;
    cout << "EVOLUTION CHAIN ID: " << this.evolution_chain_id << endl;
    cout << "COLOR ID: " << this.color_id << endl;
    cout << "SHAPE ID: " << this.shape_id << endl;
    cout << "HABITAT ID: " << this.habitat_id << endl;
    cout << "GENDER RATE: " << this.gender_rate << endl;
    cout << "CAPTURE RATE: " << this.capture_rate << endl;
    cout << "BASE HAPPINESS: " << this.base_happiness << endl;
    cout << "IS BABY: " << this.is_baby << endl;
    cout << "HATCH COUNTER: " << this.hatch_counter << endl;
    cout << "HAS GENDER DIFFERENCES: " << this.has_gender_differences << endl;
    cout << "GROWTH RATE ID: " << this.growth_rate_id << endl;
    cout << "FORMS SWITCHABLE: " << this.forms_switchable << endl;
    cout << "IS LEGENDARY: " << this.is_legendary << endl;
    cout << "IS MYTHICAL: " << this.is_mythical << endl;
    cout << "ORDER: " << this.order << endl;
    cout << "CONQUEST ORDER: " << this.conquest_order << endl;
    cout << endl;
}

Experience ::Experience(int growth_rate_id, int level, int experience)
{
    this->growth_rate_id = growth_rate_id;
    this->level = level;
    this->experience = experience;
};

Experience ::getGrowthRateID() const { return growth_rate_id; }
Experience ::getLevel() const { return level; }
Experience ::getExperience() const { return experience; }
Experience ::print()
{
    cout << "GROWTH RATE ID: " << this.growth_rate_id << endl;
    cout << "LEVEL: " << this.level << endl;
    cout << "EXPERIENCE: " << this.experience << endl;
    cout << endl;
}

Type_Name ::Type_Name(int type_id, int local_language_id, string name)
{
    this->type_id = type_id;
    this->local_language_id = local_language_id;
    this->name = name;
};

Type_Name ::getTypeID() const { return type_id; }
Type_Name ::getLocalLanguageID() const { return local_language_id; }
Type_Name ::getName() const { return name; }
Type_Name ::print()
{
    cout << "TYPE ID: " << this.type_id << endl;
    cout << "LOCAL LANGUAGE ID: " << this.local_language_id << endl;
    cout << "NAME: " << this.name << endl;
    cout << endl;
}

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

        pokemonList.push_back(Pokemon(id, identifier, species_id, height, weight, base_experience, order, is_default));
    }

    // close the file
    in_file.close();
}

void printPokemonList(vector<Pokemon> &pokemonList)
{
    cout << "PRINTING POKEMON LIST:" << endl;

    for (pok : pokemonList)
    {
        pok.print();
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

        movesList.push_back(Move(id, identifier, generation_id, type_id, power, pp, accuracy, priority, target_id, damage_class_id, effect_id, effect_chance, contest_type_id, contest_effect_id, super_contest_effect_id));
    }

    // close the file
    in_file.close();
}

void printMovesList(vector<Move> &movesList)
{
    cout << "PRINTING MOVE LIST:" << endl;

    for (mov : movesList)
    {
        mov.print();
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

        pokemonMovesList.push_back(Pokemon_Move(pokemon_id, version_group_id, move_id, pokemon_move_method_id, level, order));
    }

    // close the file
    in_file.close();
}

void printPokemonMovesList(vector<Pokemon_Move> &pokemonMovesList)
{
    cout << "PRINTING POKEMON MOVE LIST:" << endl;

    for (pok_mov : pokemonMovesList)
    {
        pok_mov.print();
    }
}

void parsePokemonSpeciesList(vector<Pokemon_Species> &pokemonSpeciesList)
{
    ifstream in_file;
    vector<string> row;
    string line, token;

    int id, generation_id, evolves_from_species_id, evolution_chain_id, color_id, shape_id, habitat_id, gender_rate, capture_rate, base_happiness, is_baby,
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
        if (row[19] == "" || row[19] == "\n")
            conquest_order = -1;
        else
            conquest_order = stoi(row[19]);

        pokemonSpeciesList.push_back(Pokemon_Species(id, identifier, generation_id, evolves_from_species_id, evolution_chain_id, color_id, shape_id, habitat_id, gender_rate, capture_rate, base_happiness, is_baby,
                                                     hatch_counter, has_gender_differences, growth_rate_id, forms_switchable, is_legendary, is_mythical, order, conquest_order));
    }

    // close the file
    in_file.close();
}

void printPokemonSpeciesList(vector<Pokemon_Species> &pokemonSpeciesList)
{
    cout << "PRINTING POKEMON SPECIES LIST:" << endl;

    for (spec : pokmonSpeciesList)
    {
        spec.print();
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

        experienceList.push_back(Experience(growth_rate_id, level, experience));
    }

    // close the file
    in_file.close();
}

void printExperienceList(vector<Experience> &experienceList)
{
    cout << "PRINTING EXPERIENCE LIST:" << endl;
    for (exp : experienceList)
    {
        exp.print();
    }
}

void parseTypeNamesList(vector<Type_Name> &typeNameList)
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

        typeNameList.push_back(Type_Name(type_id, local_language_id, name));
    }

    // close the file
    in_file.close();
}

void printTypeNamesList(vector<Type_Name> &typeNameList)
{
    cout << "PRINTING TYPE NAME LIST:" << endl;

    for (typ : typeNameList)
    {
        typ.print();
    }
}

void askUserForFile()
{
    vector<Pokemon> pokemonList;
    vector<Move> movesList;
    vector<Pokemon_Move> pokemonMovesList;
    vector<Pokemon_Species> pokemonSpeciesList;
    vector<Experience> experienceList;
    vector<Type_Name> typeNameList;

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
    else
        cout << "ERROR: FILE COULD NOT BE FOUND!" << endl;
}