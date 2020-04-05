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
//       takes in a set of numbers and shows them in order and how many of the
//		same number are in the set.
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

using namespace std;

int main()
{
	int num, temp;
	vector<pair<int,int> > Storage;
	bool found;

	while (cin >> num)
	{
		found = false;

		for (int i = 0; i < Storage.size(); i++)
		{
			if (num == Storage[i].first)						//if found break
			{
				temp = i;
				found = true;
				i = 10000000;
			}
		}
		
		if (Storage.empty() || !found)
		{
			Storage.push_back(make_pair(num, 1));				//make a pair if empty or not there
		}
		else if(found)
		{
			Storage[temp].second = Storage[temp].second + 1; 	//if found increment
		}
		
	}

	for (int i = 0; i < Storage.size(); i++)					//print results
	{
		cout << Storage[i].first << " " << Storage[i].second << '\n';
	}

}