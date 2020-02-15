///////////////////////////////////////////////////////////////////////////////
//
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            P-2
// Title:            Assignment 5 - Heapify
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//      A linked list search program that stores a json file with a dictionary
//  in it seperating the words and definition. With that information the program
//  then allowes the user to type in a series of charecters. Everytime a user 
//  enters a char the program will search through the list to find all the words
//  with a substring of the chars entered and returns the top ten results plus 
//  the time it took to search the list.
//
/////////////////////////////////////////////////////////////////////////////////
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
    ListDictionary LList;                       //Linked list to hold dictionary

    char Typed;             
    string word = "";

    vector<string> keys = J.getKeys();           //list of words in alpha order

    for(int i = 0; i < keys.size(); i++)
    {
        string DicWord = J.getKey(i);            //gets terms in alpha order 0-X
        string DicDef = J.getValue(DicWord);     //gets def of term
        LList.insert(DicWord, DicDef);           //loads deg and term
    }

    cout << "To exit program press capital Z\n\n\n";

    while ((Typed = getch()) != 'Z') 
    {
        Timer T;                                  //makes timer
        T.Start();
        word += Typed;                            //string for the chars typed

        

        if((int)Typed != 10)
        {                                         //if Typed is not a space print
            cout << word << "\n\n";
        }
        LList.search(word);                       //searches list for substrings

        T.End();
        double s = T.Seconds();                   //stores time of search

        cout << LList.getTermsFound() << " words found in: " << s 
            << " Seconds\n\n";

        LList.printTenWords();                    //prints top 10 results

        cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    }

    return 0;
}