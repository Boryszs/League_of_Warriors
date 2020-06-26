#include "Monster.h"
#include <random>

using namespace std;

int Monster::attack()
{
    int min_attack =  (0.33 * strength) + (0.33 * dexterity) + (0.33 * magic);
    int max_attack = (0.50 * strength) + (0.50 * dexterity) + (0.50 * magic);

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

int Monster::block()
{
    return 0.5 * defence;
}
