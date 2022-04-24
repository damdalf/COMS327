//
// Created by Devin Amdahl on 3/29/22.
//

#ifndef FILE_READER_H
#define FILE_READER_H

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
        Pokemon(int, string, int, int, int, int, int, int);
        int getID() const;
        string getIdentifier() const;
        int getSpeciesID() const;
        int getHeight() const;
        int getWeight() const;
        int getBaseExperience() const;
        int getOrder() const;
        int getIsDefault() const;
    private:
        int id;
        string identifier;
        int species_id;
        int height;
        int weight;
        int base_experience;
        int order;
        int is_default;
}

class Move
{
    public:
        Move(int, string, int, int, int, int, int, int, int, int, int, int, int, int, int);
        int getID() const;
        string getIdentifier() const;
        int getGenerationID() const;
        int getTypeID() const;
        int getPower() const;
        int getPP() const;
        int getAccuracy() const;
        int getPriority() const;
        int getTargetID() const;
        int getDamageClassID() const;
        int getEffectID() const;
        int getEffectChance() const;
        int getContestTypeID() const;
        int getContestEffectID() const;
        int getSuperContestEffectID() const;
    private:
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
}

class Pokemon_Move
{
    public:
        Pokemon_Move(int, int, int, int, int, int);
        int getPokemonID() const;
        int getVersionGroupID() const;
        int getMoveID() const;
        int getPokemonMoveMethodID() const;
        int getLevel() const;
        int getOrder() const;
    private:
        int pokemon_id;
        int version_group_id;
        int move_id;
        int pokemon_move_method_id;
        int level;
        int order;
}

class Pokemon_Species
{
    public:
        Pokemon_Species(int, string, int, int, int, int, int, int, int,
                        int, int, int, int, int, int, int, int, int, int, int);
        int getID() const;
        string getIdentifier() const;
        int getGenerationID() const;
        int getEvolvesFromSpeciesID() const;
        int getEvolutionCHainID() const;
        int colorID() const;
        int getShapeID() const;
        int getHabitatID() const;
        int getGenderRate() const;
        int getCaptureRate() const;
        int getBaseHappiness() const;
        int getIsBaby() const;
        int getHatchCounter() const;
        int getHasGenderDifferences() const;
        int getGrowthRateID() const;
        int getFormsSwitchable() const;
        int getIsLegendary() const;
        int getIsMythical() const;
        int getOrder() const;
        int getConquestOrder() const;
    private:
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

}

class Experience
{
    public:
        Experience(int, int, int);
        int getGrowthRateID() const;
        int getLevel() const;
        int getExperience() const;
    private:
        int growth_rate_id;
        int level;
        int experience;
}

class Type_Name
{
    public:
        Type_Name(int, int, string);
        int getTypeID() const;
        int getLocalLanguageID() const;
        string getName() const;
    private:
        int type_id;
        int local_language_id;
        string name;
}

void parsePokemonList(vector<Pokemon>);
void printPokemonList(vector<Pokemon>);

void parseMovesList(vector<Move>);
void printMovesList(vector<Move>);

void parsePokemonMovesList(vector<Pokemon_Move>);
void printPokemonMovesList(vector<Pokemon_Move>);

void parsePokemonSpeciesList(vector<Pokemon_Species>);
void printPokemonSpeciesList(vector<Pokemon_Species>);

void parseExperienceList(vector<Experience>);
void printExperienceList(vector<Experience>);

void parseTypeNamesList(vector<Type_Name>);
void printTypeNamesList(vector<Type_Name>);

void askUserForFile();

#endif
