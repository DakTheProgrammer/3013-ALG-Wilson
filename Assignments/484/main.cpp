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
			if (num == Storage[i].first)
			{
				temp = i;
				found = true;
				i = 10000000;
			}
		}
		
		if (Storage.empty() || !found)
		{
			Storage.push_back(make_pair(num, 1));
		}
		else if(found)
		{
			Storage[temp].second = Storage[temp].second + 1;
		}
		
	}

	for (int i = 0; i < Storage.size(); i++)
	{
		cout << Storage[i].first << " " << Storage[i].second << '\n';
	}

}