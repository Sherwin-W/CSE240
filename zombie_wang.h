#ifndef ZOMBIE_WANG_H
#define ZOMBIE_WANG_H

#include <iostream>
class Zombie
{
public:
    Zombie();
    Zombie(char type);
    char getType();
    bool operator==(Zombie &other);
    bool operator!=(Zombie &other);
    friend std::ostream &operator<<(std::ostream &os, Zombie &zombie);

private:
    char m_type;
};

#endif
