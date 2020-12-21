#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <vector>

using namespace std;

class character
{
private:
    string name;
    string type1;
    string type2;
    int total;
    int hp;
    int attack;
    int defense;
    int specialAttack;
    int specialDefense;
    int speed;
    int generation;
    bool legendary;

public:
    character(string n, string t1, string t2, int total, int hp, int attack, int defense, int specialAttack, int specialDefense,
              int speed, int gen, bool legend);

    string getName();
    string getType1();
    string getType2();
    int getTotal();
    int getHP();
    int getAttack();
    int getDefense();
    int getSpecialAttack();
    int getSpecialDefense();
    int getSpeed();
    int getGeneration();
    bool geteLegendary();

    static void sortName(vector<character> &vec);
    static void sortHP(vector<character> &vec);
    static void sortAttack(vector<character> &vec);
    static void sortDefense(vector<character> &vec);
};

bool compareName(character charA, character charB);
bool compareHP(character charA, character charB);
bool compareAttack(character charA, character charB);
bool compareDefense(character charA, character charB);

#endif // CHARACTER_H
