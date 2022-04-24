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

class Pokemon_DB
{
    private:
        int id;
        string identifier;
        int species_id;
        int height;
        int weight;
        int base_experience;
        int order;
        int is_default;

    public:
        Pokemon_DB(int, string, int, int, int, int, int, int);
        int getID() const;
        string getIdentifier() const;
        int getSpeciesID() const;
        int getHeight() const;
        int getWeight() const;
        int getBaseExperience() const;
        int getOrder() const;
        int getIsDefault() const;
        void print();
};

class Move_DB
{
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

    public:
        Move_DB(int, string, int, int, int, int, int, int, int, int, int, int, int, int, int);
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
        void print();
};

class Pokemon_Move_DB
{
    private:
        int pokemon_id;
        int version_group_id;
        int move_id;
        int pokemon_move_method_id;
        int level;
        int order;

    public:
        Pokemon_Move_DB(int, int, int, int, int, int);
        int getPokemonID() const;
        int getVersionGroupID() const;
        int getMoveID() const;
        int getPokemonMoveMethodID() const;
        int getLevel() const;
        int getOrder() const;
        void print();
};

class Pokemon_Species_DB
{
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

    public:
        Pokemon_Species_DB(int, string, int, int, int, int, int, int, int,
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
        void print();
};

class Experience_DB
{
    private:
        int growth_rate_id;
        int level;
        int experience;

    public:
        Experience_DB(int, int, int);
        int getGrowthRateID() const;
        int getLevel() const;
        int getExperience() const;
        void print();
};

class Type_Name_DB
{
    private:
        int type_id;
        int local_language_id;
        string name;

    public:
        Type_Name_DB(int, int, string);
        int getTypeID() const;
        int getLocalLanguageID() const;
        string getName() const;
        void print();
};

class Pokemon_Stat_DB
{
    private:
        int pokemon_id;
        int stat_id;
        int base_stat;
        int effort;
    public:
        Pokemon_Stat_DB(int, int, int, int);
        int getPokemonID() const;
        int getStatID() const;
        int getBaseStat() const;
        int getEffort() const;
        void print();
};

void parsePokemonList(vector<Pokemon_DB> *);
void printPokemonList(vector<Pokemon_DB> *);

void parseMovesList(vector<Move_DB> *);
void printMovesList(vector<Move_DB> *);

void parsePokemonMovesList(vector<Pokemon_Move_DB> *);
void printPokemonMovesList(vector<Pokemon_Move_DB> *);

void parsePokemonSpeciesList(vector<Pokemon_Species_DB> *);
void printPokemonSpeciesList(vector<Pokemon_Species_DB> *);

void parseExperienceList(vector<Experience_DB> *);
void printExperienceList(vector<Experience_DB> *);

void parseTypeNamesList(vector<Type_Name_DB> *);
void printTypeNamesList(vector<Type_Name_DB> *);

void parsePokemonStatsList(vector<Pokemon_Stat_DB> *);
void printPokemonStatsList(vector<Pokemon_Stat_DB> *);

void askUserForFile();

void parseAll(vector<Pokemon_DB> *, vector<Move_DB> *, vector<Pokemon_Move_DB> *, vector<Pokemon_Species_DB> *,
              vector<Experience_DB> *, vector<Type_Name_DB> *, vector<Pokemon_Stat_DB> *);

#endif