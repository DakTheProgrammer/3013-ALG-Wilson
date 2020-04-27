///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            10901
// Title:            10901
// Course:           CMPS-3013-201
// Semester:         Spring 2020
//
// Description:
//       Takes in a set of car and what side there on with a ferry size. With
//		this information the program tries to solve all the times each car is
//		droped off most efficently.
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

int main() {
	int Cases, CarsCanHold, TimeCross, Lines, 
		Location, TimeAriv, Time, InLineTime, CarsHolding;

	bool FerrySide;

	string Side;

	cin >> Cases;

	while (Cases != 0) 
	{
		vector <int> Order;									//used for arivals

		cin >> CarsCanHold >> TimeCross >> Lines;

		queue<int> RightOrLeftLine[2]; 						//0 is the left line 
															//of cars 1 is the 
															//right line

		Time = 0;											//default

		FerrySide = false; 									//curently on left 
															//(true = right)

		for (int i = 0; i < Lines; i++) 
		{
			cin >> TimeAriv >> Side;

			if (Side == "left")								//loads left queue
			{
				RightOrLeftLine[0].push(i);
			}
			else if (Side == "right")						//loads right queue
			{
				RightOrLeftLine[1].push(i);
			}
				
			Order.push_back(TimeAriv);						//loads arival times
		}

		vector <int> Answers(Order.size());

		while (!RightOrLeftLine[0].empty() || 
			!RightOrLeftLine[1].empty()) 					//while there are cars
		{
			InLineTime = 0;

			if (RightOrLeftLine[0].empty())					//edge case for empties
			{
				InLineTime = 
					Order[RightOrLeftLine[1].front()];
			}
			else if (RightOrLeftLine[1].empty())
			{
				InLineTime = 
					Order[RightOrLeftLine[0].front()];
			}
			else											//when they arent empty
			{
				if (Order[RightOrLeftLine[0].front()]
					<= Order[RightOrLeftLine[1].front()])
				{
					InLineTime = 
						Order[RightOrLeftLine[0].front()];
				}
				else
				{
					InLineTime = 
						Order[RightOrLeftLine[1].front()];
				}
			}

			if (InLineTime >= Time)							//gets true time for output
			{
				Time = InLineTime;
			}

			CarsHolding = 0;

			while ((!RightOrLeftLine[FerrySide].empty()) 
				&& (Time >= 
					Order[RightOrLeftLine[FerrySide].front()]) 
						&& (CarsHolding < CarsCanHold)) 		//does the storeing 
																//for output
			{
				Answers[RightOrLeftLine[FerrySide].front()] 
					= Time + TimeCross;
				RightOrLeftLine[FerrySide].pop();
				CarsHolding++;
			}
			
			Time += TimeCross;									//incs time
			
			if (FerrySide == true)								//changes side
			{
				FerrySide = false;
			}
			else
			{
				FerrySide = true;
			}
		}

		for (int i = 0; i < Lines; i++) 						//outs answers
		{
			cout << Answers[i] << '\n';
		}

		Cases--;
	}
	return 0;
}