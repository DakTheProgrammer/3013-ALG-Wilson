#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
	string definition;
	string Word;
	Node* next;
};

class ListDictionary
{
private:
	Node* Head;
	Node* Tail;
	int length;
	string TenWords[10];
	int TermsFound;

public:
	
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

	int getTermsFound()
	{
		return TermsFound;
	}
	

};