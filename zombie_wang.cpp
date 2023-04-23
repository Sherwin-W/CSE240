#include "zombie_wang.h"
#include <iostream>
#include <string>

Zombie::Zombie()
{
    int randNum = rand() % 6;
    switch (randNum)
    {
    case 1:
        letter = 'R';
        break;
    case 2:
        letter = 'Y';
        break;
    case 3:
        letter = 'G';
        break;
    case 4:
        letter = 'B';
        break;
    case 5:
        letter = 'C';
        break;
    case 6:
        letter = 'M';
        break;
        m_type = randNum;
    }

    Zombie::Zombie(char type)
    {
        m_type = type;
    }

    char Zombie::getType()
    {
        return m_type;
    }

    bool Zombie::operator==(Zombie &other)
    {
        return m_type == other.m_type;
    }

    bool Zombie::operator!=(Zombie &other)
    {
        return m_type != other.m_type;
    }

    std::ostream &operator<<(std::ostream &os, Zombie &zombie)
    {
        os << zombie.m_type;
        return os;
    }
}