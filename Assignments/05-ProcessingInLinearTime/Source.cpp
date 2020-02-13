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

    cout << "To exit program press capital Z\n\n\n";

    while ((Typed = getch()) != 'Z') 
    {
        Timer T;
        T.Start();
        word += Typed;

        

        if((int)Typed != 10)
        {   // if Typed is not a space print it
            cout << word << "\n\n";
        }
        LList.search(word);

        T.End();
        double s = T.Seconds();

        cout << LList.getTermsFound() << " words found in: " << s << " Seconds\n\n";

        LList.printTenWords();

        cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    }

    return 0;
}