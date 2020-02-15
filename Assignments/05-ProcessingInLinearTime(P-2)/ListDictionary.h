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
#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

/**
 * Node
 * 
 * Description:
 *      A node that holds 2 strings for a dictionary 
 * 		and a next pointer
 * 
 * Public Methods:
 *      string 					definition
 *		string 					Word
 *		Node* 					next	
 * 
 * Private Methods:
 *      None
 * 
 * Usage: 
 * 		Node Temp;				//Creates node
 *      
 */
struct Node
{
	string definition;			//holds def of word
	string Word;				//holds the word
	Node* next;					//pointer to a next node in the list
};

/**
 * ListDictionary
 * 
 * Description:
 *      A linked list that holds a dictionary and 
 * 		can search for substrings of chars
 * 
 * Public Methods:
 *      						ListDictionary() 
 *      void 					insert(string W, string D)
 *      void 					print()
 *		void 					search(string input) 
 * 		void 					printTenWords()
 * 		int 					getTermsFound()
 * 
 * Private Methods:
 *      Node* 					Head;
 *		Node* 					Tail;	
 *		int 					length;
 *		string 					TenWords[10];
 *		int 					TermsFound;
 * 
 * Usage: 
 * 
 *      ListDictionary LL; 		//creates list
 * 		LL.insert("A", "B");	//adds a word A and a definition b to list
 * 		LL.print();				//prints the list to a Checking.txt file
 * 		LL.search("ste");		//searches list for words with substring ste
 * 		ll.printTenWords();		//prints top ten results from searching
 * 		ll.getTermsFound();		//returns the terms found from searching
 *      
 */
class ListDictionary
{
private:
	Node* Head;				//pointer to the head of the list
	Node* Tail;				//pointer to the tail of the list
	int length;				//length of the list
	string TenWords[10];	//top ten words found when searching the list
	int TermsFound;			//how many items found after searching list

public:
	
	/**
     * Public/Private/Protected : function_name
     * 
     * Description:
     *      Describe the functions purpose
     * 
     * Params:
     *      - list params
     *      - one per line
     *      - with return type
     *      - and one line description
     * 
     * Returns:
     *      - what does this function return (including the type)?
     */
	ListDictionary()
	{
		Head = nullptr;
		Tail = nullptr;
		length = 0;
		TermsFound = 0;
		for(int i = 0; i < 10; i++)
		{
			TenWords[i] = "ZZZ";
		}
	}

	/**
     * Public/Private/Protected : function_name
     * 
     * Description:
     *      Describe the functions purpose
     * 
     * Params:
     *      - list params
     *      - one per line
     *      - with return type
     *      - and one line description
     * 
     * Returns:
     *      - what does this function return (including the type)?
     */
	void insert(string W, string D)
	{
		Node* temp = new Node;
		temp->Word = W;
		temp->definition = D;
		temp->next = nullptr;
		if (Head == nullptr)
		{
			Head = temp;
			length++;
		}
		else if (Head->next == nullptr)
		{
			Tail = temp;
			Head->next = Tail;
			length++;
		}
		else
		{
			Tail->next = temp;
			Tail = temp;
			length++;
		}
		temp = nullptr;
	}

	/**
     * Public/Private/Protected : function_name
     * 
     * Description:
     *      Describe the functions purpose
     * 
     * Params:
     *      - list params
     *      - one per line
     *      - with return type
     *      - and one line description
     * 
     * Returns:
     *      - what does this function return (including the type)?
     */
	void print()
	{
		ofstream outfile;
    	outfile.open("Checking.txt");
		Node* temp = new Node;	
		temp = Head;
		while (temp != nullptr)
		{
			outfile << '|' << temp->Word << "| -> (" << temp->definition << ")\n";
			temp = temp->next;
		}
		temp = nullptr;
	}

	/**
     * Public/Private/Protected : function_name
     * 
     * Description:
     *      Describe the functions purpose
     * 
     * Params:
     *      - list params
     *      - one per line
     *      - with return type
     *      - and one line description
     * 
     * Returns:
     *      - what does this function return (including the type)?
     */
	void search(string input)
	{
		int timeSeen = 0;
		Node* temp = new Node;	
		temp = Head;
		int i = 0;
		while (temp != nullptr)
		{
			string check = temp->Word;

			size_t found = check.find(input);

			if (found != string::npos)
			{
				if(i < 10)
				{
					TenWords[i] = temp->Word;
					i++;
				}
				timeSeen++;
			}

			temp = temp->next;
		}
		TermsFound = timeSeen; 
		temp = nullptr;
	}

	/**
     * Public/Private/Protected : function_name
     * 
     * Description:
     *      Describe the functions purpose
     * 
     * Params:
     *      - list params
     *      - one per line
     *      - with return type
     *      - and one line description
     * 
     * Returns:
     *      - what does this function return (including the type)?
     */
	void printTenWords()
	{
		bool printed = false;
		for(int i = 0; i < 10; i++)
		{
			if(TenWords[i] != "ZZZ")
			{
				printed = true;
				cout << TenWords[i] << " -> ";
			}
			else if(!printed)
			{
				cout << "No matches";
				printed = true;
			}
		}
		cout << '\n';
		for(int i = 0; i < 10; i++)
		{
			TenWords[i] = "ZZZ";
		}
	}

	/**
     * Public/Private/Protected : function_name
     * 
     * Description:
     *      Describe the functions purpose
     * 
     * Params:
     *      - list params
     *      - one per line
     *      - with return type
     *      - and one line description
     * 
     * Returns:
     *      - what does this function return (including the type)?
     */
	int getTermsFound()
	{
		return TermsFound;
	}
	

};