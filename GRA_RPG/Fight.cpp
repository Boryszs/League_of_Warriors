#include "Fight.h"
#include <Windows.h>
using namespace std;

std::ostream& operator<<(std::ostream& out, const Fight& p)
{
    out << p.champ1->getHealth() << "\t";
    out << p.champ2->getHealth() << endl;
    return out;
}

void Fight::heal(const Champion* const champ)
{
    if (flag_use_skil == false)
    {
        int oldhealth = champ1->getHealth();
        int newhealth = champ1->getHealth() / 3;

        if (oldhealth + newhealth > champ->getHealth())
            champ1->setHealth(champ->getHealth());
        else
            champ1->setHealth(oldhealth + newhealth);
        flag_use_skil = true;
    }
}

void Fight::startFigft()
{
    while (champ1->getHealth() > 0 && champ2->getHealth() > 0)
    {
        int champ1_hit = champ1->attack();
        int champ1_def = champ1->block();
        int champ2_hit = champ2->attack();
        int champ2_def = champ2->block();

        int champ1_final_hit = (champ1_hit - champ2_def);
        int champ2_final_hit = (champ2_hit - champ1_def);

        if (champ1_final_hit < 0)
            champ1_final_hit = 0;
        if (champ2_final_hit < 0)
            champ2_final_hit = 0;

        champ1->setHealth(champ1->getHealth() - champ2_final_hit);
        champ2->setHealth(champ2->getHealth() - champ1_final_hit);

        if (champ2->getHealth() <= 0)
            cout << "Wygrywa p1" << endl;
        else if (champ1->getHealth() <= 0)
            cout << "Wygrywa p2" << endl;
        else
        {
            cout << champ1->getHealth() << "\t" << champ2->getHealth() << endl;
            Sleep(100);
        }
    }
}
