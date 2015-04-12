#include <iostream>
#include <string>
#include <cstdlib>

#include "hash.h"
using namespace std;

hash::hash() // **Constructor  ::hash()
{
    //tableSize = 100;
    for(int i = 0; i < tableSize; i++)
    {
        HashTable[i] = new item;
        HashTable[i]->name = "empty"; // Default value
        HashTable[i]->drink = "empty";
        HashTable[i]->next = NULL;

    }
    item* HashTable[tableSize];

}

void hash::AddItem(string name, string drink)
{
    int index = Hash(name);

    if(HashTable[index]->name == "empty")
    {
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;

    }
    else // add item to the end of
    {
        item* Ptr = HashTable[index];
        item* n = new item;
        n->name = name;
        n->drink = drink;
        n->next = NULL;

        while(Ptr->next != NULL) // Pointer traverse the list till the last item
        {
            Ptr = Ptr->next;
        }
        Ptr->next = n;
    }

}

int hash::NumberOfItemsInIndex(int index)
{
    int count = 0;

    if(HashTable[index]->name == "empty")
    {
        return count;
    }
    else
    {
        count++;
        item* Ptr = HashTable[index];
        while(Ptr->next != NULL)
        {
            count++;
            Ptr = Ptr->next;
        }
    }
    return count;
}

void hash::PrintTable()
{
    int number;
    for(int i = 0; i < tableSize; i++)
    {
        number = NumberOfItemsInIndex(i);
        cout << "---------------\n";
        cout << "index = " << i << endl;
        cout << HashTable[i]->name << endl;
        cout << HashTable[i]->drink <<endl;
        cout << "# of items = " << number << endl;
        cout << "---------------\n";
    }
}

void hash::PrintItemsInIndex(int index)
{
    item* Ptr = HashTable[index];
    if(Ptr->name == "empty")
    {
        cout << "index = " << index << " is empty\n";
    }
    else
    {
        cout << "index " << index << " contains the following item\n";

        while(Ptr != NULL)
        {
            cout << "-------------\n";
            cout << Ptr->name << endl;
            cout << Ptr->drink << endl;
            cout << "-------------\n";
            Ptr = Ptr->next;
        }

    }
}

int hash::Hash(string key)
{
    int hash = 0;
    int index;

   // index = key.length();

    for(int i=0; i<key.length(); i++)
    {
        hash = hash + (int)key[i]; // Can modify to get different hash key
       // cout << "hash = " << hash <<endl; // Print Hash number
    }


   // cout<<"key[0] = "<< (int)key[0] <<endl;
   // cout<<"key[1] = "<< (int)key[1] <<endl;
  // cout<<"key[2] = "<< (char)key[2] <<endl;

    index = hash % tableSize; // For exaple: 402 / 100(sizeoftable) = 4 r 2
    return index; // now it should return remainder 2
   // return index;

}

void hash::FindDrink(string name)
{
    int index = Hash(name);
    bool foundName = false;
    string drink;

    item* Ptr = HashTable[index];
    while(Ptr != NULL)
    {
        if(Ptr->name == name)
        {
            foundName = true;
            drink = Ptr->drink;
        }
        Ptr = Ptr->next;
    }
    if(foundName == true)
    {
        cout << "Favorite drink = "<< drink <<endl;
    }
    else
    {
        cout << name << "'s info was not found in the Hash Table\n";
    }
}
