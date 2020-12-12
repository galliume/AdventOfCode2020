#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <string>

using namespace std;

void checkSeats(map<int, string>& originalSeats)
{
	map<int, string>seats = originalSeats;
	for (auto& line : seats)
	{
		int position = 0;
		for (auto& seat : line.second)
		{
			if ('L' == seat)
			{
				if (0 == line.first)
				{
					if (0 == position)
					{
						if (
							(originalSeats[line.first][position + 1] == 'L' || originalSeats[line.first][position + 1] == '.') &&
							(originalSeats[line.first + 1][position] == 'L' || originalSeats[line.first + 1][position] == '.') &&
							(originalSeats[line.first + 1][position + 1] == 'L' || originalSeats[line.first + 1][position + 1] == '.')
							)
						{
							seats[line.first][position] = '#';
						}
					}
					else if (line.second.size() - 1 == position)
					{
						if (
							(originalSeats[line.first][position - 1] == 'L' || originalSeats[line.first][position - 1] == '.') &&
							(originalSeats[line.first + 1][position] == 'L' || originalSeats[line.first + 1][position] == '.') &&
							(originalSeats[line.first + 1][position - 1] == 'L' || originalSeats[line.first + 1][position - 1] == '.')
							)
						{
							seats[line.first][position] = '#';
						}
					}
					else
					{
						if (
							(originalSeats[line.first][position - 1] == 'L' || originalSeats[line.first][position - 1] == '.') &&
							(originalSeats[line.first][position + 1] == 'L' || originalSeats[line.first][position + 1] == '.') &&
							(originalSeats[line.first + 1][position] == 'L' || originalSeats[line.first + 1][position] == '.') &&
							(originalSeats[line.first + 1][position - 1] == 'L' || originalSeats[line.first + 1][position - 1] == '.') &&
							(originalSeats[line.first + 1][position + 1] == 'L' || originalSeats[line.first + 1][position + 1] == '.')
							)
						{
							seats[line.first][position] = '#';
						}
					}
				}
				else if (line.first == seats.size() - 1)
				{
					if (0 == position)
					{
						if (
							(originalSeats[line.first][position + 1] == 'L' || originalSeats[line.first][position + 1] == '.') &&
							(originalSeats[line.first - 1][position] == 'L' || originalSeats[line.first - 1][position] == '.') &&
							(originalSeats[line.first - 1][position + 1] == 'L' || originalSeats[line.first - 1][position + 1] == '.')
							)
						{
							seats[line.first][position] = '#';
						}
					}
					else if (line.second.size() - 1 == position)
					{
						if (
							(originalSeats[line.first][position - 1] == 'L' || originalSeats[line.first][position - 1] == '.') &&
							(originalSeats[line.first - 1][position] == 'L' || originalSeats[line.first - 1][position] == '.') &&
							(originalSeats[line.first - 1][position - 1] == 'L' || originalSeats[line.first - 1][position - 1] == '.')
							)
						{
							seats[line.first][position] = '#';
						}
					}
					else
					{
						if (
							(originalSeats[line.first][position - 1] == 'L' || originalSeats[line.first][position - 1] == '.') &&
							(originalSeats[line.first][position + 1] == 'L' || originalSeats[line.first][position + 1] == '.') &&
							(originalSeats[line.first - 1][position] == 'L' || originalSeats[line.first - 1][position] == '.') &&
							(originalSeats[line.first - 1][position - 1] == 'L' || originalSeats[line.first - 1][position - 1] == '.') &&
							(originalSeats[line.first - 1][position + 1] == 'L' || originalSeats[line.first - 1][position + 1] == '.')
							)
						{
							seats[line.first][position] = '#';
						}
					}
				}
				else
				{
					if (0 == position)
					{
						if (
							(originalSeats[line.first][position + 1] == 'L' || originalSeats[line.first][position + 1] == '.') &&
							(originalSeats[line.first - 1][position] == 'L' || originalSeats[line.first - 1][position] == '.') &&
							(originalSeats[line.first - 1][position + 1] == 'L' || originalSeats[line.first - 1][position + 1] == '.') &&
							(originalSeats[line.first + 1][position] == 'L' || originalSeats[line.first + 1][position] == '.') &&
							(originalSeats[line.first + 1][position + 1] == 'L' || originalSeats[line.first + 1][position + 1] == '.')
							)
						{
							seats[line.first][position] = '#';
						}
					}
					else if (line.second.size() - 1 == position)
					{
						if (
							(originalSeats[line.first][position - 1] == 'L' || originalSeats[line.first][position - 1] == '.') &&
							(originalSeats[line.first - 1][position] == 'L' || originalSeats[line.first - 1][position] == '.') &&
							(originalSeats[line.first - 1][position - 1] == 'L' || originalSeats[line.first - 1][position - 1] == '.') &&
							(originalSeats[line.first + 1][position] == 'L' || originalSeats[line.first + 1][position] == '.') &&
							(originalSeats[line.first + 1][position - 1] == 'L' || originalSeats[line.first + 1][position - 1] == '.')
							)
						{
							seats[line.first][position] = '#';
						}
					}
					else
					{
						if (
							(originalSeats[line.first - 1][position] == 'L' || originalSeats[line.first - 1][position] == '.') &&
							(originalSeats[line.first - 1][position - 1] == 'L' || originalSeats[line.first - 1][position - 1] == '.') &&
							(originalSeats[line.first - 1][position + 1] == 'L' || originalSeats[line.first - 1][position + 1] == '.') &&
							(originalSeats[line.first][position - 1] == 'L' || originalSeats[line.first][position - 1] == '.') &&
							(originalSeats[line.first][position + 1] == 'L' || originalSeats[line.first][position + 1] == '.') &&
							(originalSeats[line.first + 1][position] == 'L' || originalSeats[line.first + 1][position] == '.') &&
							(originalSeats[line.first + 1][position - 1] == 'L' || originalSeats[line.first + 1][position - 1] == '.') &&
							(originalSeats[line.first + 1][position + 1] == 'L' || originalSeats[line.first + 1][position + 1] == '.')
							)
						{
							seats[line.first][position] = '#';
						}
					}
				}
			}
			position++;
		}
	}
	for (auto& line : seats)
	{
		int position = 0;
		for (auto& seat : line.second)
		{
			if ('#' == seat)
			{
				int count = 0;
				if (0 == line.first)
				{
					if (0 != position && line.second.size() - 1 != position)
					{
						if (originalSeats[line.first][position + 1] == '#')
						{
							count++;
						}
						if (originalSeats[line.first][position - 1] == '#')
						{
							count++;
						}
						if (originalSeats[line.first + 1][position] == '#')
						{
							count++;
						}
						if (originalSeats[line.first + 1][position + 1] == '#')
						{
							count++;
						}
						if (originalSeats[line.first + 1][position - 1] == '#')
						{
							count++;
						}
					}
				}
				else if (line.first == seats.size() - 1)
				{
					if (0 != position && line.second.size() - 1 != position)
					{
						if (originalSeats[line.first][position + 1] == '#')
						{
							count++;
						}
						if (originalSeats[line.first][position - 1] == '#')
						{
							count++;
						}
						if (originalSeats[line.first - 1][position] == '#')
						{
							count++;
						}
						if (originalSeats[line.first - 1][position + 1] == '#')
						{
							count++;
						}
						if (originalSeats[line.first - 1][position - 1] == '#')
						{
							count++;
						}
					}
				}
				else
				{
					if (0 == position)
					{
						if (originalSeats[line.first][position + 1] == '#')
						{
							count++;
						}
						if (originalSeats[line.first - 1][position] == '#')
						{
							count++;
						}
						if (originalSeats[line.first - 1][position + 1] == '#')
						{
							count++;
						}
						if (originalSeats[line.first + 1][position] == '#')
						{
							count++;
						}
						if (originalSeats[line.first + 1][position + 1] == '#')
						{
							count++;
						}
					}
					else if (line.second.size() - 1 == position)
					{
						if (originalSeats[line.first][position - 1] == '#')
						{
							count++;
						}
						if (originalSeats[line.first - 1][position] == '#')
						{
							count++;
						}
						if (originalSeats[line.first - 1][position - 1] == '#')
						{
							count++;
						}
						if (originalSeats[line.first + 1][position] == '#')
						{
							count++;
						}
						if (originalSeats[line.first + 1][position - 1] == '#')
						{
							count++;
						}
					}
					else
					{
						if (originalSeats[line.first][position + 1] == '#')
						{
							count++;
						}
						if (originalSeats[line.first][position - 1] == '#')
						{
							count++;
						}
						if (originalSeats[line.first - 1][position] == '#')
						{
							count++;
						}
						if (originalSeats[line.first - 1][position + 1] == '#')
						{
							count++;
						}
						if (originalSeats[line.first - 1][position - 1] == '#')
						{
							count++;
						}
						if (originalSeats[line.first + 1][position] == '#')
						{
							count++;
						}
						if (originalSeats[line.first + 1][position + 1] == '#')
						{
							count++;
						}
						if (originalSeats[line.first + 1][position - 1] == '#')
						{
							count++;
						}
					}
				}
				if (4 <= count)
				{
					seats[line.first][position] = 'L';
				}
			}
			position++;
		}
	}

	originalSeats = seats;
}

void checkSeats2(map<int, string>& originalSeats)
{
	map<int, string>seats = originalSeats;

	for (auto& line : seats)
	{
		int position = line.first;
		int x = 0;
		for (auto& seat : line.second)
		{
			int status = 0;
			if ('L' == seat)
			{
				int l = 0;

				for (l = x + 1; l <= line.second.size(); l++)
				{
					if (l == line.second.size() || originalSeats[position][l] == 'L')
					{
						status++;
						break;
					}
					if ('#' == originalSeats[position][l])
					{
						break;
					}
				}
				for (l = x - 1; l >= -1; l--)
				{
					if (l == -1 || originalSeats[position][l] == 'L')
					{
						status++;
						break;
					}
					if ('#' == originalSeats[position][l])
					{
						break;
					}
				}
				for (l = position + 1; l <= originalSeats.size(); l++)
				{
					if (l == originalSeats.size() || originalSeats[l][x] == 'L')
					{
						status++;
						break;
					}
					if ('#' == originalSeats[l][x])
					{
						break;
					}
				}
				for (l = position - 1; l >= -1; l--)
				{
					if (l == -1 || originalSeats[l][x] == 'L')
					{
						status++;
						break;
					}
					if ('#' == originalSeats[l][x])
					{
						break;
					}
				}
				int c = x + 1;
				for (l = position + 1; l <= originalSeats.size(); l++)
				{
					if (l == originalSeats.size() || c == line.second.size() || originalSeats[l][c] == 'L')
					{
						status++;
						break;
					}
					if ('#' == originalSeats[l][c])
					{
						break;
					}
					c++;
				}
				c = x - 1;
				for (l = position + 1; l <= originalSeats.size(); l++)
				{
					if (c == -1 || l == originalSeats.size() || originalSeats[l][c] == 'L')
					{
						status++;
						break;
					}
					if ('#' == originalSeats[l][c])
					{
						break;
					}
					c--;
				}

				c = x - 1;
				for (l = position - 1; l >= -1; l--)
				{
					if (l == -1 || c <= -1 || originalSeats[l][c] == 'L')
					{
						status++;
						break;
					}
					if ('#' == originalSeats[l][c])
					{
						break;
					}
					c--;
				}

				c = x + 1;
				for (l = position - 1; l >= -1; l--)
				{
					if (l == -1 || c == line.second.size() || originalSeats[l][c] == 'L')
					{
						status++;
						break;
					}
					if ('#' == originalSeats[l][c])
					{
						break;
					}
					c++;
				}

				if (8 == status)
				{
					seats[position][x] = '#';
				}
			}
			x++;
		}
	}

	for (auto& line : seats)
	{
		int x = 0;
		for (auto& seat : line.second)
		{
			int count = 0;
			if ('#' == seat)
			{
				int l = 0;

				for (l = x + 1; l < line.second.size(); l++)
				{
					if (originalSeats[line.first][l] == 'L')
					{
						break;
					}

					if (originalSeats[line.first][l] == '#')
					{
						count++;
						break;
					}
				}
				for (l = x - 1; l >= 0; l--)
				{
					if (originalSeats[line.first][l] == 'L')
					{
						break;
					}
					if (originalSeats[line.first][l] == '#')
					{
						count++;
						break;
					}
				}
				for (l = line.first + 1; l < originalSeats.size(); l++)
				{
					if (originalSeats[l][x] == 'L')
					{
						break;
					}

					if (originalSeats[l][x] == '#')
					{
						count++;
						break;
					}
				}
				for (l = line.first - 1; l >= 0; l--)
				{
					if (originalSeats[l][x] == 'L')
					{
						break;
					}
					if (originalSeats[l][x] == '#')
					{
						count++;
						break;
					}
				}
				int c = x + 1;
				for (l = line.first + 1; l < originalSeats.size(); l++)
				{
					if (c < line.second.size() && originalSeats[l][c] == 'L')
					{
						break;
					}
					if (c < line.second.size() && originalSeats[l][c] == '#')
					{
						count++;
						break;
					}
					c++;
				}

				c = x - 1;
				for (l = line.first + 1; l < originalSeats.size(); l++)
				{
					if (c >= 0 && originalSeats[l][c] == 'L')
					{
						break;
					}
					if (c >= 0 && originalSeats[l][c] == '#')
					{
						count++;
						break;
					}
					c--;
				}
				c = x - 1;
				for (l = line.first - 1; l >= 0; l--)
				{
					if (c >= 0 && originalSeats[l][c] == 'L')
					{
						break;
					}
					if (c >= 0 && originalSeats[l][c] == '#')
					{
						count++;
						break;
					}
					c--;
				}
				c = x + 1;
				for (l = line.first - 1; l >= 0; l--)
				{
					if (c < line.second.size() && originalSeats[l][c] == 'L')
					{
						break;
					}
					if (c < line.second.size() && originalSeats[l][c] == '#')
					{
						count++;
						break;
					}
					c++;
				}
			}
			if (5 <= count)
			{
				seats[line.first][x] = 'L';
			}
			x++;
		}
	}

	originalSeats = seats;
}

void day11()
{
	ifstream inputFile("day11/input.txt");
	string seats;
	int line = 0;
	map<int, string>seatsMap;
	map<int, string>seatsMap2;

	auto start = chrono::high_resolution_clock::now();

	while (inputFile >> seats)
	{
		seatsMap[line] = seats;
		seatsMap2[line] = seats;
		line++;
	}

	int count = 0, lastCount = 1;
	bool done = false;

	while (!done)
	{
		count = 0;

		checkSeats(seatsMap);

		for (auto seats : seatsMap)
		{
			for (auto seat : seats.second)
			{
				if (seat == '#') count++;
			}
		}
		if (count == lastCount)
		{
			done = true;
		}
		else
		{
			lastCount = count;
		}
	}

	auto finish = chrono::high_resolution_clock::now();
	cout << "Part 1 : " << count << " " << chrono::duration_cast<chrono::milliseconds>(finish - start).count() << "milliseconds" << endl;

	count = 0, lastCount = 1;
	done = false;

	start = chrono::high_resolution_clock::now();

	while (!done)
	{
		count = 0;

		checkSeats2(seatsMap2);

		for (auto seats : seatsMap2)
		{
			for (auto seat : seats.second)
			{
				if (seat == '#') count++;
			}
		}
		if (count == lastCount)
		{
			done = true;
		}
		else
		{
			lastCount = count;
		}
	}

	finish = chrono::high_resolution_clock::now();
	cout << "Part 2 : " << count << " " << chrono::duration_cast<chrono::milliseconds>(finish - start).count() << "milliseconds" << endl;

}