#include "character.h"

character::character(string n, string t1, string t2, int total, int hp, int attack, int defense, int specialAttack, int specialDefense,
          int speed, int gen, bool legend)
{
    this->name = n;
    this->type1 = t1;
    this->type2 = t2;
    this->total = total;
    this->hp = hp;
    this->attack = attack;
    this->defense = defense;
    this->specialAttack = specialAttack;
    this->specialDefense = specialDefense;
    this->speed = speed;
    this->generation = gen;
    this->legendary = legend;
}

string character::getName()
{
    return name;
}
string character::getType1()
{
    return type1;
}
string character::getType2()
{
    return type2;
}
int character::getTotal()
{
    return total;
}
int character::getHP()
{
    return hp;
}
int character::getAttack()
{
    return attack;
}
int character::getDefense()
{
    return defense;
}
int character::getSpecialAttack()
{
    return specialAttack;
}
int character::getSpecialDefense()
{
    return specialDefense;
}
int character::getSpeed()
{
    return speed;
}
int character::getGeneration()
{
    return generation;
}
bool character::geteLegendary()
{
    return legendary;
}


void character::sortName(vector<character> &vec) {
  sort(vec.begin(), vec.end(), compareName);
}

void character::sortHP(vector<character> &vec) {
    sort(vec.begin(), vec.end(), compareHP);
}

void character::sortAttack(vector<character> &vec) {
    sort(vec.begin(), vec.end(), compareAttack);
}

void character::sortDefense(vector<character> &vec) {
    sort(vec.begin(), vec.end(), compareDefense);
}


bool compareName(character charA, character charB)
{
    if(charA.getName() == charB.getName())
        return compareHP(charA, charB);
    return charA.getName() < charB.getName();
}

bool compareHP(character charA, character charB)
{
    if(charA.getHP() == charB.getHP())
        return compareAttack(charA, charB);
    return charA.getHP() < charB.getHP();
}

bool compareAttack(character charA, character charB)
{
    if(charA.getAttack() == charB.getAttack())
        return compareDefense(charA, charB);
    return charA.getAttack() < charB.getAttack();
}

bool compareDefense(character charA, character charB)
{
    return charA.getDefense() < charB.getDefense();
}
