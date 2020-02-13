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
	

public:
	
	ListDictionary()
	{
		Head = nullptr;
		Tail = nullptr;
		length = 0;
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
			outfile << temp->Word << " - " << temp->definition << '\n';
			temp = temp->next;
		}
		delete temp;
	}

};