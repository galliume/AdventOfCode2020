#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <chrono>
using namespace std;

void part1(vector<tuple<char, int>> instructions)
{
	auto start = chrono::high_resolution_clock::now();

	char curDir = 'E', nextDir;
	int distance = 0, manhattanDistance = 0, x = 0, y = 0;

	for (auto instruction : instructions)
	{
		nextDir = get<0>(instruction);
		distance = get<1>(instruction);

		if ('R' != nextDir && 'L' != nextDir)
		{
			nextDir = ('F' == nextDir) ? curDir : nextDir;

			if ('N' == nextDir)
			{
				x += distance;
			}
			else if ('S' == nextDir)
			{
				x -= distance;
			}
			else if ('E' == nextDir)
			{
				y += distance;
			}
			else if ('W' == nextDir)
			{
				y -= distance;
			}
		}
		else
		{
			if ('L' == nextDir)
			{
				if ('N' == curDir)
				{
					if (90 == distance)
					{
						curDir = 'W';
					}
					else if (180 == distance)
					{
						curDir = 'S';
					}
					else if (270 == distance)
					{
						curDir = 'E';
					}
				}
				else if ('S' == curDir)
				{
					if (90 == distance)
					{
						curDir = 'E';
					}
					else if (180 == distance)
					{
						curDir = 'N';
					}
					else if (270 == distance)
					{
						curDir = 'W';
					}
				}
				else if ('E' == curDir)
				{
					if (90 == distance)
					{
						curDir = 'N';
					}
					else if (180 == distance)
					{
						curDir = 'W';
					}
					else if (270 == distance)
					{
						curDir = 'S';
					}
				}
				else if ('W' == curDir)
				{
					if (90 == distance)
					{
						curDir = 'S';
					}
					else if (180 == distance)
					{
						curDir = 'E';
					}
					else if (270 == distance)
					{
						curDir = 'N';
					}
				}
			}
			else if ('R' == nextDir)
			{
				if ('N' == curDir)
				{
					if (90 == distance)
					{
						curDir = 'E';
					}
					else if (180 == distance)
					{
						curDir = 'S';
					}
					else if (270 == distance)
					{
						curDir = 'W';
					}
				}
				else if ('S' == curDir)
				{
					if (90 == distance)
					{
						curDir = 'W';
					}
					else if (180 == distance)
					{
						curDir = 'N';
					}
					else if (270 == distance)
					{
						curDir = 'E';
					}
				}
				else if ('E' == curDir)
				{
					if (90 == distance)
					{
						curDir = 'S';
					}
					else if (180 == distance)
					{
						curDir = 'W';
					}
					else if (270 == distance)
					{
						curDir = 'N';
					}
				}
				else if ('W' == curDir)
				{
					if (90 == distance)
					{
						curDir = 'N';
					}
					else if (180 == distance)
					{
						curDir = 'E';
					}
					else if (270 == distance)
					{
						curDir = 'S';
					}
				}
			}
		}
	}

	manhattanDistance = abs(x) + abs(y);
	auto finish = chrono::high_resolution_clock::now();

	cout << "Part 1 : " << manhattanDistance << " took : " << chrono::duration_cast<chrono::milliseconds>(finish - start).count() << " milliseconds" << endl;
}

void part2(vector<tuple<char, int>> instructions)
{
	auto start = chrono::high_resolution_clock::now();

	char nextDir;
	int distance = 0, manhattanDistance = 0, x = 0, y = 0, wX = 10, wY = 1, tmp = 0;

	for (auto instruction : instructions)
	{
		nextDir = get<0>(instruction);
		distance = get<1>(instruction);

		if ('F' == nextDir)
		{
			x += distance * wX;
			y += distance * wY;
		}
		else if ('N' == nextDir)
		{
			wY += distance;
		}
		else if ('S' == nextDir)
		{
			wY -= distance;
		}
		else if ('E' == nextDir)
		{
			wX += distance;
		}
		else if ('W' == nextDir)
		{
			wX -= distance;
		}
		else if ('L' == nextDir)
		{
			for (int j = 0; j < distance / 90; j++) {
				tmp = -wY;
				wY = wX;
				wX = tmp;
			}
		}
		else if ('R' == nextDir)
		{				
			for (int j = 0; j < distance / 90; j++) {
				tmp = wY;
				wY = -wX;
				wX = tmp;
			}
		}
	}

	manhattanDistance = abs(x) + abs(y);
	auto finish = chrono::high_resolution_clock::now();

	cout << "Part 2 : " << manhattanDistance << " took : " << chrono::duration_cast<chrono::milliseconds>(finish - start).count() << " milliseconds" << endl;
}

void day12()
{
	ifstream inputFile("day12/input.txt");
	string instruction;
	char direction;
	int distance = 0;
	vector<tuple<char, int>>instructions;
	
	while (inputFile >> instruction)
	{
		sscanf_s(instruction.c_str(), "%c%d", &direction, sizeof(direction), &distance);
		instructions.push_back({ direction, distance });
	}

	part1(instructions);
	part2(instructions);
}

int main()
{
	day12();
	return 0;
}