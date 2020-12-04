#include <fstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int countTrees(int slopeX, int slopeY, map<int, string>treesMap)
{
	int total = 0, x = 0, y = 0;

	while (treesMap.size() - 1 > y)
	{
		y += slopeY;
		string nextLine = treesMap[y];
		x = (x + slopeX) % nextLine.length();

		if ('#' == nextLine[x])
		{
			total++;
		}
	}
	return total;
}

void day3()
{
	ifstream data;
	string line;
	map<int, string>treesMap;
	signed long long int totalTrees = 0;

	data.open("day3/input.txt");

	if (data.is_open())
	{		
		int count = 0;
		while (getline(data, line))
		{
			treesMap[count] = line;
			count++;
		}
	}
	data.close();

	totalTrees = countTrees(3, 1, treesMap);
	cout << "day 3.1 Total trees : " << totalTrees << endl;

	totalTrees *= countTrees(1, 1, treesMap);
	totalTrees *= countTrees(5, 1, treesMap);
	totalTrees *= countTrees(7, 1, treesMap);
	totalTrees *= countTrees(1, 2, treesMap);
	cout << "day 3.2 Total trees : " << totalTrees << endl;
}