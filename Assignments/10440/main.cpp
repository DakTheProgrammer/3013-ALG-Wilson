///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            10440
// Title:            10440
// Course:           CMPS-3013-201
// Semester:         Spring 2020
//
// Description:
//       Takes in a set of car times with a ferry capacity to find how few trips
//		a ferry can take to get all cars to the other side.
//      
// Usage:
//         None
//
// Files:            
//      main.cpp
//		in.txt
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int Cases, CanTake, CrossTime, AmtCars, 
		ArvTime, Answer, CurOn;

	bool first, incd;

	cin >> Cases;										//inputs amount of cases

	while (Cases != 0)
	{
		first = true;

		incd = false;									//defaults

		CurOn = 0;

		Answer = 0;

		cin >> CanTake >> CrossTime >> AmtCars;

		queue <int> Line;								//cars in line

		for (int i = 0; i < AmtCars; i++)
		{
			cin >> ArvTime;
			Line.push(ArvTime);
		}

		while (!Line.empty())
		{
			if (first && AmtCars % CanTake != 0)		//first case for odds
			{
				Answer = Line.front() + (CrossTime * 2);

				Line.pop();
				
				first = false;
			}
			else if (first)								//first case for evens
			{
				for (int i = 1; i < CanTake; i++)
				{
					Line.pop();
				}
				
				Answer = Line.front() + (CrossTime * 2);

				Line.pop();

				first = false;
			}
			else										//all other cases
			{
				while (CurOn != CanTake && 
					!Line.empty())
				{
					if (Line.front() <= Answer)
					{
						CurOn++;
						Line.pop();
					}
					else
					{
						Answer = Line.front();
						incd = true;
					}
				}

				if (incd)							//checks for if ferry 
													//needs to "return"
				{
					Answer += CrossTime;
				}
				else
				{
					Answer += (CrossTime * 2);
					incd = true;
				}
				

				CurOn = 0;
			}
		}

		cout << Answer << ' ' << 
			(AmtCars + CanTake - 1) / CanTake;		//prints answers

		Cases--;
		
		if (Cases != 0)
		{
			cout << '\n';							//removes lines
		}
		
	}

	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//                   				NOTE:
//		solution is not accepted to UVA and I still can not figure out why.
//		matches all debugs given for the problem and still getting the broad 
//		response of "wrong answer". If anyone notices whats wrong I would love to
//		know why!
/////////////////////////////////////////////////////////////////////////////////