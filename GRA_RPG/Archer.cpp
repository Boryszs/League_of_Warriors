#include "Archer.h"
#include <random>

using namespace std;

int Archer::attack()
{
    int min_attack = dexterity;
    int max_attack = dexterity + strength * 0.50;

    random_device dev;
    mt19937_64 rng(dev());
    uniform_int_distribution<> dist(min_attack, max_attack);
    int stroke = dist(rng);

    int critical_attack = 0;
    uniform_int_distribution<> dice(0, 6);
    int roll = dice(rng);

    if (roll == 5)
        critical_attack = stroke;
    if (roll == 6)
        critical_attack = 2 * stroke;

    return stroke + critical_attack;
}

int Archer::block()
{
    random_device dev;
    mt19937_64 rng(dev());
    uniform_int_distribution<> dice(1, 6);
    int roll = dice(rng);

    if (roll == 6)
        return INT_MAX;
    else
        return 0;
}
