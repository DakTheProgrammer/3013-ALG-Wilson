#include <iostream> 
#include <list> 
#include <string>
using namespace std;

class Graph
{
	int Vertice, numTimes;

	list<int>* GraphList;

	void DepFirSear(int Ver, bool marked[])
	{
		marked[Ver] = true;

		list<int>::iterator i;//used to make an iterator so searhing list is easier

		for (i = GraphList[Ver].begin(); i != GraphList[Ver].end(); i++)
		{
			if (!marked[*i])
			{
				DepFirSear(*i, marked);
			}
		}
	}
public:
	Graph(int Ver)
	{
		numTimes = 0;

		Vertice = Ver;

		GraphList = new list<int>[Ver];
	}

	void NewConnection(int Ver, int Con)
	{
		GraphList[Con].push_back(Ver);

		GraphList[Ver].push_back(Con);
	}

	void TotalGraphs()
	{
		bool* marked = new bool[Vertice];

		for (int i = 0; i < Vertice; i++)
		{
			marked[i] = false;
		}

		for (int i = 0; i < Vertice; i++)
		{
			if (marked[i] == false)
			{
				DepFirSear(i, marked);

				numTimes++;
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
	NumSet = stoi(Temps);

	getline(cin, Temps);

	while (i != NumSet)
	{
		checking = true;

		getline(cin, Temps);

		GSize = int(Temps.at(0)) - 'A' + 1;

		Graph Gra(GSize);

		i++;

		while (checking)
		{
			getline(cin, Connections);

			if (Connections == "")
			{
				checking = false;
			}
			else
			{
				Gra.NewConnection(int(Connections.at(0)) - 'A', int(Connections.at(1)) - 'A');
			}
		}
		if (i != NumSet + 1 && i != 1)
		{
			cout << '\n';
		}
		Gra.TotalGraphs();
	}

	return 0;
}