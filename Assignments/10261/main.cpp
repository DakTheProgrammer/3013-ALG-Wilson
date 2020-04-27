///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            10261
// Title:            10261
// Course:           CMPS-3013-201
// Semester:         Spring 2020
//
// Description:
//       Takes in a set of ferry and car lengths and figures out the maximum
//		amount of cars that can fit on the ferry.
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
	int Cases, FerrySize, CarSize, PortHolding, 
		StarHolding, AmtCars, Check;

	bool stoploading, Here;

	queue <int> Cars;

	cin >> Cases;									//ins the amount of cases

	while (Cases != 0)
	{
		stoploading = false;

		vector <string> Ans;

		StarHolding = 0;							//sets defaults

		PortHolding = 0;

		AmtCars = 0;

		cin >> FerrySize >> CarSize;

		FerrySize = FerrySize * 100;				//makes the ferry size in cms

		while (CarSize != 0)
		{
			Cars.push(CarSize);						//loads queue with sizes cars
			cin >> CarSize;
		}

		while (!Cars.empty() && !stoploading)
		{
			if (PortHolding + Cars.front() 
				<= FerrySize)
			{
				Check = Cars.front();				//used for consecutive input 
													//for balancing purposes
				PortHolding += Cars.front();
				Cars.pop();
				Ans.push_back("port");
				AmtCars++;							//incs cars on ferry
				Here = true;
			}
			else if (StarHolding + Cars.front() 
				<= FerrySize)
			{
				Check = Cars.front();
				StarHolding += Cars.front();
				Cars.pop();
				Ans.push_back("starboard");
				AmtCars++;
				Here = false;
			}
			else
			{
				stoploading = true;					//breaks when case full
			}

			if (!stoploading && !Cars.empty() 		
				&& Check == Cars.front())			//used for when there are 2 
													//of the same inputs in a 
													//row balancing on both sides 
													//to reach net 0
			{
				if (!Here)
				{
					PortHolding += Cars.front();
					Cars.pop();
					Ans.push_back("port");
					AmtCars++;
				}
				else if(Here)
				{
					StarHolding += Cars.front();
					Cars.pop();
					Ans.push_back("starboard");
					AmtCars++;
				}

			}
		}

		while (!Cars.empty())
		{
			Cars.pop();								//empties queue
		}

		cout << AmtCars << '\n';

		for (int i = 0; i < Ans.size(); i++)		//answers
		{
			cout << Ans[i] << '\n';
		}

		Cases--;
		
		if (Cases != 0)
		{
			cout << '\n';							//removes extra line
		}
	}

	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//                   				NOTE:
//		solution is not the same as the debug site however it is still correct
//		the only diffrence is that the sides are loaded in a diffrent order but
//		both algorithims produce the same result amount of cars on the ferry 
//		every time.
/////////////////////////////////////////////////////////////////////////////////