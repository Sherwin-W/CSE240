#include <iostream>
#include "zombie_wang.h"
#include "linkedlist_wang.hpp"
#include <list>

using namespace std;

void engine_action(DoublyLinkedList<Zombie> &list, Zombie randomZomb)
{
    list.AddToFront(randomZomb);
}
void caboose_action(DoublyLinkedList<Zombie> &list, Zombie randomZomb)
{
    list.AddToEnd(randomZomb);
}
void jump_in_action(DoublyLinkedList<Zombie> &list, Zombie randomZomb)
{
    int len = list.Length();
    list.AddAtIndex(randomZomb, len);
}
void everyone_out_action(DoublyLinkedList<Zombie> &list, Zombie randomZomb)
{
    list.RemoveAllOf(randomZomb);
}
void you_out_action(DoublyLinkedList<Zombie> &list, Zombie randomZomb)
{
    list.RemoveTheFirst(randomZomb);
}
void brains_action(DoublyLinkedList<Zombie> &list, Zombie randomZomb)
{
    int len = list.Length();
    int rounded = len / 2;
    engine_action(list, randomZomb);
    caboose_action(list, randomZomb);
    list.AddAtIndex(randomZomb, rounded);
}
void rainbow_action(DoublyLinkedList<Zombie> &list, Zombie randomZomb)
{
    engine_action(list, randomZomb);
    caboose_action(list, 'R');
    caboose_action(list, 'Y');
    caboose_action(list, 'G');
    caboose_action(list, 'B');
    caboose_action(list, 'C');
    caboose_action(list, 'M');
}
void friends_action(DoublyLinkedList<Zombie> &list, Zombie randomZomb)
{
    int coinFlip = rand() % 2;
    if (list.Find(randomZomb) != nullptr)
    {
        if (coinFlip == 0)
        {
            list.AddBefore(list.Find(randomZomb), randomZomb);
        }
        else
        {
            list.AddAfter(list.Find(randomZomb), randomZomb);
        }
    }
    else
    {
        caboose_action(randomZomb);
    }
}
void everyFive(DoublyLinkedList<Zombie> &list)
{
    list.RemoveFromFront();
    list.RemoveFromEnd();
}
int main(int argc, char *argv[])
{
    int numRounds;
    int randRound;
    char randZomb;

    DoublyLinkedList<Zombie> zombList;
    char char1 = 'R';
    Zombie *temp = new Zombie(char1);
    brains_action(zombList, *temp);
    zombList.PrintList();
}
