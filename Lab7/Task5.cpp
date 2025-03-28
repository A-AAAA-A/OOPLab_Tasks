#include<iostream>
#include<string>
using namespace std;

class Character
{
protected:
    int charID;
    string charName;
    int charLevel;
    int charHealth;
    string charWeapon;
public: 
    Character(int id, string name, int level, int health, string weapon)
    {
        charID = id;
        charName = name;
        charLevel = level;
        charHealth = health;
        charWeapon = weapon;
    }

    virtual void attack()
    {
        cout << charName << " attacks with " << charWeapon << endl;
    }

    virtual void defend()
    {
        cout << charName << " defends with " << charWeapon << endl;
    }

    virtual void displayStats()
    {
        cout << "Character ID: " << charID << endl;
        cout << "Name: " << charName << endl;
        cout << "Level: " << charLevel << endl;
        cout << "Health Points: " << charHealth << endl;
        cout << "Weapon Type: " << charWeapon << endl;
    }
};

class Warrior : public Character
{
    int armor;
    int meleeDmg;
public: 
    Warrior(int id, string name, int level, int health, string weapon, int arm, int dmg) 
    : Character(id, name, level, health, weapon)
    {
        armor = arm;
        meleeDmg = dmg;
    }

    void attack() override
    {
        cout << charName << " swings " << charWeapon << " with " << meleeDmg << " melee damage!" << endl;
    }

    void displayStats() override
    {
        Character::displayStats();
        cout << "Armor: " << armor << endl;
        cout << "Melee Damage: " << meleeDmg << endl;
    }
};

class Mage : public Character
{
    int spellPower;
    int mana;
public:
    Mage(int id, string name, int level, int health, string weapon, int spPower, int mp) 
    : Character(id, name, level, health, weapon)
    {
        spellPower = spPower;
        mana = mp;
    }

    void defend() override
    {
        cout << charName << " shields with a magical barrier!" << endl;
    }

    void displayStats() override
    {
        Character::displayStats();
        cout << "Spell Power: " << spellPower << endl;
        cout << "Mana: " << mana << endl;
    }
};

class Archer : public Character
{
    int numOfArrows;
    string accuracyLevel;
public:
    Archer(int id, string name, int level, int health, string weapon, int arrows, string accuracy) 
    : Character(id, name, level, health, weapon)
    {
        numOfArrows = arrows;
        accuracyLevel = accuracy;
    }

    void attack() override
    {
        cout << charName << " shoots an arrow with " << accuracyLevel << " accuracy!" << endl;
    }

    void displayStats() override
    {
        Character::displayStats();
        cout << "Arrows Available: " << numOfArrows << endl;
        cout << "Accuracy Level: " << accuracyLevel << endl;
    }
};

class Rogue : public Character
{
    int stealth;
    int dexterity;
public:
    Rogue(int id, string name, int level, int health, string weapon, int stealthLevel, int dex) 
    : Character(id, name, level, health, weapon)
    {
        stealth = stealthLevel;
        dexterity = dex;
    }

    void displayStats() override
    {
        Character::displayStats();
        cout << "Stealth: " << stealth << endl;
        cout << "Dexterity: " << dexterity << endl;
    }
};

int main()
{
    Warrior warrior1(1, "Thor", 12, 150, "Hammer", 80, 40);
    Mage mage1(2, "Merlin", 15, 120, "Staff", 70, 100);
    Archer archer1(3, "Legolas", 14, 110, "Bow", 50, "Excellent");
    Rogue rogue1(4, "Loki", 13, 130, "Dagger", 60, 75);

    warrior1.displayStats();
    cout << endl;
    mage1.displayStats();
    cout << endl;
    archer1.displayStats();
    cout << endl;
    rogue1.displayStats();
    cout << endl;

    warrior1.attack();
    mage1.defend();
    archer1.attack();

    return 0;
}
