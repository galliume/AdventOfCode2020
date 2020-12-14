#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <bitset>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

void day14()
{
	ifstream inputFile;
	string line;
	char lineMask[50];
	bitset<36>maskZero, maskOne, value;
	int memIndex = 0, memValue = 0;
	uint64_t count = 0;
	vector<tuple<string, map<int, int>>>memList;
	map<int, int>mem;
	map<int, uint64_t> tmpMem;
	string m;

	inputFile.open("day14/input.txt");

	if (inputFile.is_open())
	{
		while (!inputFile.eof())
		{
			getline(inputFile, line);

			if (line.find("mask") != string::npos)
			{
				if (mem.size())
				{
					memList.push_back({ m, mem });
					mem.clear();
				}
				sscanf_s(line.c_str(), "mask = %49s", &lineMask, sizeof(lineMask));
				m = lineMask;
			}
			else
			{
				sscanf_s(line.c_str(), "mem[%d] = %d", &memIndex, &memValue);
				mem[memIndex] = memValue;
			}
		}
		memList.push_back({ m, mem });
	}
	inputFile.close();

	for (auto memData : memList)
	{		
		string tmp = get<0>(memData);
		replace(tmp.begin(), tmp.end(), 'X', '0');
		maskOne = bitset<36>(tmp);

		tmp = get<0>(memData);
		replace(tmp.begin(), tmp.end(), 'X', '1');
		maskZero = bitset<36>(tmp);

		map<int, int>mems = get<1>(memData);

		for (auto& mem : mems)
		{
			value = bitset<36>(get<1>(mem));
			value = value | maskOne;
			value = value & maskZero;
			tmpMem[get<0>(mem)] = value.to_ullong();
		}
	}

	for (auto tmp : tmpMem)
	{
		count += tmp.second;
	}

	cout << "Part 1 : " << count << endl;
}

int main()
{
	day14();
	return 0;
}