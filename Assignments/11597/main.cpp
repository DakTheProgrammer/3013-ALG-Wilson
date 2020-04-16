///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            11597
// Title:            11597
// Course:           CMPS-3013-201
// Semester:         Spring 2020
//
// Description:
//       Takes in the number of vertices of a fully complete graph and finds
//		all spanning subtress.
//      
// Usage:
//         None
//
// Files:            
//      main.cpp
//		in.txt
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

int main()
{
	int i = 0, n, ans;

	cin >> n;

	while (n != 0)
	{
		i++;

		ans = n / 2; 									// n/2 of complete graphs
														// gives total subtree

		cout << "Case " << i << ": " << ans << '\n';

		cin >> n;
	}

	return 0;
}