#include <iostream>
#include <string>
#include <cstdlib>

#include "hash.h"
using namespace std;

int main()
{
    //int index;
    //hash hashObj;
    //hashObj.Hash("Paul");

    //index = hashObj.Hash("Paul");
   // cout << "index = " << index;
   // return 0;

   hash Hashy;
   //Hashy.PrintTable();
   string name;

   Hashy.AddItem("good", "test");
   Hashy.AddItem("good", "test");
   Hashy.AddItem("loq", "aest");
   Hashy.AddItem("lowl", "best");
   Hashy.AddItem("lorl", "gest");
   Hashy.AddItem("lols", "oest");
   Hashy.AddItem("lolx", "ehst");
   Hashy.AddItem("lolr", "esmt");
   //Hashy.PrintTable();

//   Hashy.PrintItemsInIndex(0);
//   Hashy.PrintItemsInIndex(1);
//   Hashy.PrintItemsInIndex(2);
//   Hashy.PrintItemsInIndex(3);
//   Hashy.PrintItemsInIndex(4);
//   Hashy.PrintItemsInIndex(5);
//   Hashy.PrintItemsInIndex(6);
//   Hashy.PrintItemsInIndex(7);
//   Hashy.PrintItemsInIndex(8);
//   Hashy.PrintItemsInIndex(9);

   while(name != "exit")
   {
       cout << "Search for ";
       cin >> name;
       if(name != "exit")
       {
           Hashy.FindDrink(name);
       }
   }

   return 0;
}
