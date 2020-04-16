///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            484
// Title:            484
// Course:           CMPS-3013-201
// Semester:         Spring 2020
//
// Description:
//       A program that is used to find the total amount of mice can escape
//		maze that has obsticles that take a certain amount of time to get over.
//		TL;DR: Finds the shortest path using dijkstras and outputs the amount 
//		of passes.
//      
// Usage:
//         None
//
// Files:            
//      main.cpp
//		in.txt
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

/**
* Public : Dijkstras
* 
* Description:
*      uses dijkstras to find how many mice exit the maze
* 
* Params:
*      int   						:  number of cells in graph
*      int   						:  the exit cell for the mice
*	   int		 					:  the time limit
* 	   vector<pair <int, int>>[]	:  the graph used to store nodes
* Returns:
*      int   						: the amount of mice that escaped in time
*/
int Dijkstras(int numCells, int ExitCell, int Time, 
	vector<pair <int, int>> Graph[])
{
	priority_queue <pair <int, int>> PrioQue;			//priority que used to 
														//make dijkstras easier

	int Distances[101];

	for (int i = 1; i <= numCells; i++)
	{
		Distances[i] = INT_MAX;							//loads infinity to each
														//vertex
	}

	PrioQue.push(pair<int, int>(ExitCell, 0));			//puts start onto queue

	Distances[ExitCell] = 0;

	int P1, P2, temp, weight;

	while (!PrioQue.empty())
	{
		P1 = PrioQue.top().first;
		weight = PrioQue.top().second;

		PrioQue.pop();

		for (int i = 0; i < Graph[P1].size(); i++)
		{
			P2 = Graph[P1][i].first;
			temp = Graph[P1][i].second;

			if (Distances[P1] + temp < Distances[P2])	//Dijkstras algorithm
			{
				Distances[P2] = Distances[P1] + temp;
				PrioQue.push(pair<int, int>(P2, 
					Distances[P2]));
			}

		}

	}

	int count = 0;

	for (int i = 1; i <= numCells; i++)
	{
		if (Distances[i] <= Time)
		{
			count += 1;									//counts mice that made 
														//it through maze in time
		}
	}

	return count;
}

int main()
{
	int numSet, numCells, ExitCell, Time, numConnections
		, P1, P2, Weight;

	cin >> numSet;

	while (numSet != 0)
	{
		cin >> numCells >> ExitCell >> Time >> 
			numConnections;

		vector<pair <int, int>> Graph[101];				//array of vectors of 
														//pairs of ints used 
														//to hold the graph 
														//and weights for 
														//dijkstras

		for (int i = 0; i < numConnections; i++)
		{
			cin >> P1 >> P2 >> Weight;
			Graph[P2].push_back(pair<int, int>(P1, 		//loads Graph
				Weight));
		}

		cout << Dijkstras(numCells, ExitCell, Time, 	//outputs answer
			Graph);

		numSet--;
		
		cout << '\n';
		
		if (numSet != 0)
		{
			cout << '\n';
		}

		for (int i = 1; i <= numCells; i++)
		{
			Graph[i].clear();							//clears graph
		}

	}

	return 0;
}