#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

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
			int seatIndex = 0;

			for (int i = 0; i < line.size(); i++)
			{
				line.at(i) = (line.at(i) == 'B' || line.at(i) == 'R') ? '1' : '0';
			}
			seatIndex = std::stoi(line, nullptr, 2);

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