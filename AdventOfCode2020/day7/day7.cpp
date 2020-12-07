#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <map>
#include <functional>
#include <algorithm>
#include <set>

using namespace std;

static inline void ltrim(std::string& s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
		return !std::isspace(ch);
	}));
}

static inline void rtrim(std::string& s) {
	s.erase(
		std::find_if(s.rbegin(), s.rend(), 
			[](unsigned char ch) {
			return !std::isspace(ch);
		})
	.base(), s.end());
}

static inline void trim(std::string& s) {
	ltrim(s);
	rtrim(s);
}

void eraseAllSubStr(std::string& mainStr, const std::string& toErase)
{
	size_t pos = std::string::npos;
	while ((pos = mainStr.find(toErase)) != std::string::npos)
	{
		mainStr.erase(pos, toErase.length());
	}
}

string findMainColor(string line)
{
	smatch match_str;
	regex word_regex("(.+?(?=contain))");
	regex_search(line, match_str, word_regex);

	string find = match_str.str();
	trim(find);

	return find;
}

map<string, int> findContain(string line)
{
	int count;
	char bag[40];
	map<string, int>contain;

	regex word_regex("([0-9].+?[a-zA-Z ]*)");
	sregex_iterator iter(line.begin(), line.end(), word_regex);
	sregex_iterator end;

	while (iter != end)
	{
		for (unsigned i = 1; i < iter->size(); ++i)
		{
			string bags = (*iter)[i];
			sscanf_s(bags.c_str(), "%d %[a-zA-Z ]s", &count, &bag, sizeof(bag));
			string find = bag;
			trim(find);
			contain[find] = count;
		}
		++iter;
	}

	return contain;
}

set<string> checked = {};

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

set<string> checked2 = {};


int countBag(map<string, map<string, int>> bags, string name, int count)
{
	int total = count;

	for (auto bag : bags[name])
	{
		auto& bagStr = bag;
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
	static bool found = false;

	int nbLines = 0;

	if (data.is_open())
	{

		while (!data.eof())
		{
			getline(data, line);

			const std::vector<std::string>strList = { "bags", "bag" };
			std::for_each(strList.begin(), strList.end(), std::bind(eraseAllSubStr, ref(line), placeholders::_1));
			string bag = findMainColor(line);

			contain[bag] = findContain(line);
			nbLines++;
		}
	}
	data.close();

	int cur = 1;

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