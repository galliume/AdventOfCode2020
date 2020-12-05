#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int getIndex(string rows, int max)
{
	int index = 0;

	for (auto& pos : rows)
	{
		if ('L' == pos || 'F' == pos)
		{
			max = (max - index) / 2 + index;
		}
		else
		{
			index = (max - index) / 2 + index;
		}
	}
	return ('L' == rows[rows.size()] || 'F' == rows[rows.size()]) ? index : max;
}

void day5()
{
	ifstream data;
	string line;
	data.open("day5/input.txt");

	int maxSeatIndex = 0;
	vector<int>listIndex;

	if (data.is_open())
	{
		while (getline(data, line))
		{			
			char rows[8], cols[4];
			int rowIndex = 0, colIndex = 0, seatIndex = 0;
			sscanf_s(line.c_str(), "%7s%3s", &rows, sizeof(rows), &cols, sizeof(cols));

			rowIndex = getIndex(rows, 127);
			colIndex = getIndex(cols, 7);
			seatIndex = rowIndex * 8 + colIndex;

			if (seatIndex > maxSeatIndex)
			{
				maxSeatIndex = seatIndex;
			}
			listIndex.push_back(seatIndex);
		}
	}
	data.close();
	
	cout << "5.1 Max Seat ID : " << maxSeatIndex << endl;

	sort(listIndex.begin(), listIndex.end());
	
	for (auto& index : listIndex)
	{
		if (find(listIndex.begin(), listIndex.end(), index + 1) == listIndex.end() && find(listIndex.begin(), listIndex.end(), index + 2) != listIndex.end())
		{
			cout << "5.2 Seat index : " << index + 1 << endl;
			break;
		}
	}
}

int main()
{
	day5();
	return 0;
}