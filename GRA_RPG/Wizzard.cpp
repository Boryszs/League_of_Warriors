#include "Wizzard.h"
#include <random>

using namespace std;

int Wizzard::attack()
{
    int min_attack = magic;
    int max_attack = magic + dexterity;

    random_device dev;
    mt19937_64 rng(dev());
    uniform_int_distribution<> dist(min_attack, max_attack);
    int stroke = dist(rng);

    int critical_attack = 0;
    uniform_int_distribution<> dice(1, 6);
    int roll = dice(rng);

    if (roll == 5)
        critical_attack = 2 * stroke;
    if (roll == 6)
        critical_attack = 3 * stroke;

    return stroke + critical_attack;
}
