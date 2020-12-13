#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

void day13()
{
	ifstream inputFile;
	string line;
	int count = 1;
	uint32_t departureTimestamp = 0, waitingTime = 0, minWaitingTime = numeric_limits<size_t>::max(), nearestBus = 0;
	vector<string>busList;

	inputFile.open("day13/input.txt");

	if (inputFile.is_open())
	{		
		while (!inputFile.eof())
		{
			if (1 == count)
			{
				getline(inputFile, line);
				departureTimestamp = stoi(line);
				count++;
			}
			else
			{
				getline(inputFile, line, ',');
				busList.push_back(line);
				
			}
		}
	}
	inputFile.close();

	for (auto bus : busList)
	{
		if ("x" != bus)
		{
			waitingTime = ceil(departureTimestamp / stof(bus)) * stoi(bus) - departureTimestamp;

			if (waitingTime < minWaitingTime)
			{
				minWaitingTime = waitingTime;
				nearestBus = stoi(bus);
			}
		}
	}
	
	cout << "Part 1 : " << nearestBus * minWaitingTime << endl;

	long long time = 0;
	long long stride = 1;

	int i = 0;
	for (auto bus : busList)
	{
		if ("x" != bus)
		{
			while ((time + i) % stoi(bus) != 0)
			{
				time += stride;
			}

			stride *= stoi(bus);
		}
		i++;
	}

	cout << "Part 2 : " << time << endl;
}

int main()
{
	day13();
	return 0;
}