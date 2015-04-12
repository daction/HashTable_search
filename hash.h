#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#ifndef HASH_H
#define HASH_H


class hash
{
private:
   // int tableSize;
   static const int tableSize = 10;
   struct item
   {
       // two string, one pointer
       string name;
       string drink;
       item* next;
   };
   // define item

    item* HashTable[tableSize];

public:
    hash(); // Constructure
       int Hash(string key);
       void AddItem(string name, string drink);
       int NumberOfItemsInIndex(int index);
       void PrintTable();
       void PrintItemsInIndex(int index);
       void FindDrink(string name);

};

#endif // HASH_H
