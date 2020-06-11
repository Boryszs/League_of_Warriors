#include "Warrior.h"
#include <random>

using namespace std;

int Warrior::attack()
{
    int min_attack = (0.75 / 100) * strength;
    int max_attack = strength + dexterity * 0.33;

    random_device dev;
    mt19937_64 rng(dev());
    uniform_int_distribution<> dist(min_attack, max_attack);
    int stroke = dist(rng);

    int critical_attack = 0;
    uniform_int_distribution<> dice(0, 6);
    int roll = dice(rng);

    if (roll == 5)
        critical_attack = 0.5 * stroke;
    if (roll == 6)
        critical_attack = stroke;

    return stroke + critical_attack;
}

int Warrior::block()
{
    return defence * 0.66;
}
