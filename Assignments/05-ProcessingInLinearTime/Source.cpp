#include <iostream>
#include "JsonFacade.hpp"       
#include <time.h>
#include <chrono> 
#include "Timer.hpp"            
#include "ListDictionary.h"
#include "mygetch.hpp"
#include <fstream>

using namespace std;

int main()
{
    JsonFacade J("dict_w_defs.json");
    ListDictionary LList;

    char Typed;             
    string word = "";

    vector<string> keys = J.getKeys();       //list of words in alpha order

    for(int i = 0; i < keys.size(); i++)
    {
        string DicWord = J.getKey(i);            //gets terms in alpha order 0-X
        string DicDef = J.getValue(DicWord);     //gets def of term
        LList.insert(DicWord, DicDef);
    }

    LList.print();

    /*while ((Typed = getch()) != 'Z') 
    {
        word += Typed;          

        if((int)Typed != 10)
        {   // if k is not a space print it
            cout << Typed;
        }
    }
    */

    return 0;
}