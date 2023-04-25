//defines the methods mentioned in zombie_wang.h
#include "zombie_wang.h"
#include <iostream>
//generates random char when create Zombie
Zombie::Zombie()
{
    int randNum = rand() % 6;
    switch (randNum){
    
    case 1:
        m_type = 'R';
        break;
    case 2:
        m_type = 'Y';
        break;
    case 3:
        m_type = 'G';
        break;
    case 4:
        m_type = 'B';
        break;
    case 5:
        m_type = 'C';
        break;
    default:
        m_type = 'M';
        break;
    }
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