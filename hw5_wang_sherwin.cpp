#include <iostream>
#include "zombie_wang.h"
#include "linkedlist_wang.hpp"
#include <list>

using namespace std;

void engine_action(DoublyLinkedList<Zombie> list, Zombie randomZomb)
{
    list.AddToFront(randomZomb);
}
void caboose_action(DoublyLinkedList<Zombie> list, Zombie randomZomb)
{
    list.AddToEnd(randomZomb);
}
void jump_in_action(DoublyLinkedList<Zombie> list, Zombie randomZomb)
{
    int len = list.Length();
    list.AddAtIndex(randomZomb, len);
}
void everyone_out_action(DoublyLinkedList<Zombie> list, Zombie randomZomb)
{
    list.RemoveAllOf(randomZomb);
}
void you_out_action(DoublyLinkedList<Zombie> list, Zombie randomZomb)
{
    list.RemoveTheFirst(randomZomb);
}
void brains_action(DoublyLinkedList<Zombie> list, Zombie randomZomb)
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
        caboose_action(list, randomZomb);
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
    int currRound = 0;
    int randRound;
    int action;
    char randZomb;
    string phrase;
    int yeno;
    

    DoublyLinkedList<Zombie> zombList;
    std::cout << "How many rounds do you want to run?";
    std::cin >> numRounds;

    while (numRounds != 0)
    {
        Zombie *temp = new Zombie();
        randZomb = temp.getType();
        action = rand() % 8;
        switch (action)
        {

        case 1:
            caboose_action(zombList, randZomb);
            phrase = "Caboose!";
            break;
        case 2:
            jump_in_action(zombList, randZomb);
            phrase = "Jump In!";
            break;
        case 3:
            everyone_out_action(zombList, randZomb);
            phrase = "Everyone Out!";
            break;
        case 4:
            you_out_action(zombList, randZomb);
            phrase = "You Out!";
            break;
        case 5:
            brains_action(zombList, randZomb);
            phrase = "Brains!";
            break;
        case 6:
            rainbow_action(zombList, randZomb);
            phrase = "Rainbow!";
            break;
        case 7:
            friends_action(zombList, randZomb);
            phrase = "New Friends!";
            break;
        default:
            engine_action(zombList, randZomb);
            phrase = "Engine!";
            break;
        }
        std::cout << "Round: " << currRound << std::endl;
        std::cout << "Size: " << zombList.Length() << " :: ";
        zombList.PrintList();
        std::cout << std::endl
                  << "New Zombie: [<" << temp.getType() << ">] -- ";
        std::cout << "Action: [<" << phrase << ">]" << std::endl;
        std::cout << "The conga line is now:" << std::endl;
        std::cout << "Size: " << zombList.Length() << " :: ";
        zombList.PrintList();
        std::cout << "**************************************************";
        currRound++;
        numRounds--;
        if (zombList.Length() == 0)
        {
            std::cout << "Party is Over";
            break;
        }
        else
        {
            if (numRounds == 0)
            {
                std::cout << "Would you like to continue? (1 yes) (2 no)";
                std::cin >> yeno;
                if (yeno == 1)
                {
                    std::cout << "How many rounds do you want to run?";
                    std::cin >> numRounds;
                }
                else
                {
                    break;
                }
            }
        }
    }
}
