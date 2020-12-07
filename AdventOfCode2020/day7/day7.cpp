#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <map>
#include <functional>
#include <algorithm>
#include <set>

using namespace std;
set<string> checked = {};

string findMainColor(string line)
{
	smatch match_str;
	regex word_regex("(.+?(?= bags))");
	regex_search(line, match_str, word_regex);
	return match_str.str();
}

map<string, int> findContain(string line)
{
	int count;
	char bag[40];
	map<string, int>contain;

	regex word_regex("([0-9].+?[a-zA-Z]*)(?= bags| bag)");
	sregex_iterator iter(line.begin(), line.end(), word_regex);
	sregex_iterator end;

	while (iter != end)
	{
		for (unsigned i = 1; i < iter->size(); ++i)
		{
			string bags = (*iter)[i];
			sscanf_s(bags.c_str(), "%d %39[a-zA-Z ]s", &count, &bag, sizeof(bag));;
			contain[bag] = count;
		}
		++iter;
	}

	return contain;
}

int count(map<string, map<string, int>> bags, string name)
{	
	int total = 0;

	for (auto bag : bags)
	{
		bool found = false;
		for (auto& b : bag.second)
		{
			if (name == b.first)
			{
				found = true;
			}
		}
		if (found)
		{
			bool isChecked = find(checked.begin(), checked.end(), bag.first) == checked.end();
			checked.insert(bag.first);

			if (isChecked)
			{
				total++;
				total += count(bags, bag.first);
			}
		}
	}
	return total;
}

int countBag(map<string, map<string, int>>bags, string name, int count)
{
	int total = count;

	for (auto bag : bags[name])
	{
		total += count * countBag(bags, bag.first, bag.second);
	}
	return total;
}

void day7()
{
	ifstream data;
	string line;
	string shinyBag = "shiny gold";
	map<string, map<string, int>>contain;
	data.open("day7/input.txt");

	if (data.is_open())
	{
		while (!data.eof())
		{
			getline(data, line);
			string bag = findMainColor(line);
			contain[bag] = findContain(line);
		}
	}
	data.close();

	int total = count(contain, shinyBag);
	int total2 = countBag(contain, shinyBag, 1);

	cout << "7.1 Total : " << total << endl;
	cout << "7.2 Total : " << total2 - 1 << endl;
}

int main()
{
	day7();
	return 0;
}