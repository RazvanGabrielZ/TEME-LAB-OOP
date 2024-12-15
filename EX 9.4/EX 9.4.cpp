#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Base Character Class
class Character {
protected:
    string name;
    int health;
    int attackPower;

public:
    Character(string n, int h, int ap) : name(n), health(h), attackPower(ap) {}

    // Public accessor methods for health
    int getHealth() const {
        return health;
    }

    void setHealth(int newHealth) {
        health = (newHealth < 0) ? 0 : newHealth; // Prevent health from dropping below zero
    }

    // Base methods
    virtual void attack(Character& target) {
        target.setHealth(target.getHealth() - attackPower);
    }

    virtual void heal(Character& target) {}

    bool isAlive() const {
        return health > 0;
    }

    void display() const {
        cout << name << " (Health: " << health << ")";
    }

    string getName() const { return name; }
};

// Warrior Class
class Warrior : public Character {
private:
    int attackRange; // Maximum attack range

public:
    Warrior(string n, int h, int ap, int range)
        : Character(n, h, ap), attackRange(range) {}

    // Check if a target is within range
    bool canAttack(Character& target, int distance) const {
        return distance <= attackRange;
    }

    // Override attack method
    void attack(Character& target) override {
        target.setHealth(target.getHealth() - attackPower);
        cout << name << " attacked " << target.getName() << " causing "
            << attackPower << " damage." << endl;
        if (target.getHealth() <= 0)
            cout << target.getName() << " has been killed!" << endl;
    }
};

// Mage Class
class Mage : public Character {
private:
    int healingPower;

public:
    Mage(string n, int h, int ap, int heal)
        : Character(n, h, ap), healingPower(heal) {}

    // Heal a friendly target
    void heal(Character& target) override {
        target.setHealth(target.getHealth() + healingPower);
        cout << name << " healed " << target.getName()
            << " for " << healingPower << " health." << endl;
    }
};

// Simulate the Fight Session
void simulateFight(vector<Character*>& team1, vector<Character*>& team2) {
    cout << "Fight session begins!" << endl;
    int round = 1;

    while (!team1.empty() && !team2.empty()) {
        cout << "\n--- Round " << round << " ---" << endl;

        // Team 1 attacks Team 2
        for (size_t i = 0; i < team1.size(); ++i) {
            Warrior* warrior = dynamic_cast<Warrior*>(team1[i]);
            if (warrior) {
                for (size_t j = 0; j < team2.size(); ++j) {
                    int distance = abs((int)i - (int)j);
                    if (warrior->canAttack(*team2[j], distance)) {
                        warrior->attack(*team2[j]);
                        if (!team2[j]->isAlive()) {
                            delete team2[j];
                            team2.erase(team2.begin() + j);
                            break;
                        }
                    }
                }
            }

            Mage* mage = dynamic_cast<Mage*>(team1[i]);
            if (mage && i > 0) {
                mage->heal(*team1[i - 1]);
            }
        }

        // Team 2 attacks Team 1
        for (size_t i = 0; i < team2.size(); ++i) {
            Warrior* warrior = dynamic_cast<Warrior*>(team2[i]);
            if (warrior) {
                for (size_t j = 0; j < team1.size(); ++j) {
                    int distance = abs((int)i - (int)j);
                    if (warrior->canAttack(*team1[j], distance)) {
                        warrior->attack(*team1[j]);
                        if (!team1[j]->isAlive()) {
                            delete team1[j];
                            team1.erase(team1.begin() + j);
                            break;
                        }
                    }
                }
            }

            Mage* mage = dynamic_cast<Mage*>(team2[i]);
            if (mage && i > 0) {
                mage->heal(*team2[i - 1]);
            }
        }

        round++;
    }

    cout << "\nFight session over!" << endl;
    if (team1.empty())
        cout << "Team 2 wins!" << endl;
    else
        cout << "Team 1 wins!" << endl;
}

int main() {
    srand(time(0));

    // Create two teams
    vector<Character*> team1;
    vector<Character*> team2;

    // Populate Team 1
    team1.push_back(new Warrior("Warrior1", 100, 20, 1));
    team1.push_back(new Mage("Mage1", 70, 10, 15));
    team1.push_back(new Warrior("Warrior2", 90, 25, 2));

    // Populate Team 2
    team2.push_back(new Warrior("Warrior3", 110, 18, 1));
    team2.push_back(new Mage("Mage2", 75, 12, 20));
    team2.push_back(new Warrior("Warrior4", 85, 22, 2));

    // Display Teams
    cout << "Team 1:" << endl;
    for (auto c : team1)
        c->display(), cout << endl;

    cout << "\nTeam 2:" << endl;
    for (auto c : team2)
        c->display(), cout << endl;

    // Start the fight session
    simulateFight(team1, team2);

    // Clean up memory
    for (auto c : team1)
        delete c;

    for (auto c : team2)
        delete c;

    return 0;
}
