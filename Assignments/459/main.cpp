///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            459
// Title:            459
// Course:           CMPS-3013-201
// Semester:         Spring 2020
//
// Description:
//       A program that finds the total amount of connected graphs in a set
//      
// Usage:
//         None
//
// Files:            
//      main.cpp
//		in.txt
/////////////////////////////////////////////////////////////////////////////////
#include <iostream> 
#include <list> 
#include <string>
using namespace std;

/**
 * Graph
 *
 * Description:
 *      list based graph
 *
 * Public Methods:
 * 		DepFirSear(int Ver, bool marked[])
 * 
 * Public Methods:
 *      Graph(int Ver)
 * 		NewConnection(int Ver, int Con)
 * 		TotalGraphs()
 *
 * Usage:
 *      Graph g(6)									//makes graph of size 6
 * 		
 * 		g.NewConnection(1, 3)						//makes a conection for 
 * 													//node 3 connected to 1
 * 		
 * 		g.TotalGraphs()								//outs the total graphs
 *
 */
class Graph
{
	int Vertice, numTimes;

	list<int>* GraphList;								//list for nodes

	/**
	 * DepFirSear
	 *
	 * Description:
	 *      does depth first search recursivly
	 *
	 * Params:
	 *     - int ver
	 * 	   - bool marked[]
	 *
	 * Returns:
	 *     - NULL
	 */
	void DepFirSear(int Ver, bool marked[])
	{
		marked[Ver] = true;								//marks the node

		list<int>::iterator i;							//used to make an 
														//iterator so searhing
														//list is easier

		for (i = GraphList[Ver].begin(); i != GraphList[Ver].end(); i++)
		{
			if (!marked[*i])
			{
				DepFirSear(*i, marked);					//recursive call for bfs
			}
		}
	}
public:
	/**
	 * Graph
	 *
	 * Description:
	 *      constructor that makes graph with size
	 *
	 * Params:
	 *     - int ver
	 * 	   
	 * Returns:
	 *     - NULL
	 */
	Graph(int Ver)
	{
		numTimes = 0;

		Vertice = Ver;

		GraphList = new list<int>[Ver];
	}

	/**
	 * Graph
	 *
	 * Description:
	 *      makes a graph connection
	 *
	 * Params:
	 *     - int Ver
	 * 	   - int Con
	 * 	   
	 * Returns:
	 *     - NULL
	 */
	void NewConnection(int Ver, int Con)
	{
		GraphList[Con].push_back(Ver);

		GraphList[Ver].push_back(Con);
	}

	/**
	 * TotalGraphs
	 *
	 * Description:
	 *      outs the total graphs
	 *
	 * Params:
	 *     - none
	 * 	   
	 * Returns:
	 *     - NULL
	 */
	void TotalGraphs()
	{
		bool* marked = new bool[Vertice];

		for (int i = 0; i < Vertice; i++)
		{
			marked[i] = false;						//loads markers
		}

		for (int i = 0; i < Vertice; i++)
		{
			if (marked[i] == false)
			{
				DepFirSear(i, marked);

				numTimes++;							//inrements num of graphs
			}

		}

		cout << numTimes << '\n';
	}

};

int main()
{
	string Temps, Connections;
	int NumSet, i = 0, GSize;
	bool checking;

	getline(cin, Temps);
	NumSet = stoi(Temps);							//string toint of numgraphs

	getline(cin, Temps);

	while (i != NumSet)
	{
		checking = true;

		getline(cin, Temps);

		GSize = int(Temps.at(0)) - 'A' + 1;			//gets the max distance

		Graph Gra(GSize);							//sets size of graph

		i++;

		while (checking)
		{
			getline(cin, Connections);

			if (Connections == "")
			{
				checking = false;					//breaks when there is a 
													//blank
			}
			else
			{
				Gra.NewConnection(
					int(Connections.at(0)) - 'A',
					int(Connections.at(1)) - 'A');
													//makes connection
			}
		}
		if (i != NumSet + 1 && i != 1)
		{
			cout << '\n';							//spacing for output
		}
		Gra.TotalGraphs();							//prints total num of 
													//graphs
	}

	return 0;
}