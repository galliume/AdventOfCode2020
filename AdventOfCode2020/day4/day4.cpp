#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void explode(const string& string, vector<std::string>& tokens, char delimiter)
{
	stringstream ss(string);
	std::string token;

	while (getline(ss, token, delimiter))
	{
		tokens.push_back(token);
	}
}

bool isValid(vector<std::string>& tokens)
{
	string field, fieldData;

	for (auto& data : tokens)
	{
		vector<string>dataTokens;
		explode(data, dataTokens, ':');
		
		field = dataTokens[0];
		fieldData = dataTokens[1];

		if ("byr" == field && !(stoi(fieldData) >= 1920 && stoi(fieldData) <= 2002))
		{
			return false;
		}
		if ("iyr" == field && !(stoi(fieldData) >= 2010 && stoi(fieldData) <= 2020))
		{
			return false;
		}
		if ("eyr" == field && !(stoi(fieldData) >= 2020 && stoi(fieldData) <= 2030))
		{
			return false;
		}
		if ("hgt" == field)
		{
			if (fieldData.find("cm") != string::npos)
			{
				if (!(stoi(fieldData) >= 150 && stoi(fieldData) <= 193)) return false;
			}			
			else if (fieldData.find("in") != string::npos)
			{
				if (!(stoi(fieldData) >= 59 && stoi(fieldData) <= 76)) return false;
			}
			else
			{
				return false;
			}
		}
		if ("hcl" == field)
		{
			char color[7];
			int count = sscanf_s(fieldData.c_str(), "#%6[a-f0-9]", &color, sizeof(color));
			if (0 == count) return false;
		}
		if ("ecl" == field)
		{
			vector<string>colors = { "amb", "blu", "brn", "gry", "grn", "hzl", "oth" };
			if (colors.end() == find(colors.begin(), colors.end(), fieldData)) return false;
		}
		if ("pid" == field && 0 != fieldData[0] && 9 != fieldData.size())
		{
			return false;
		}
	}
	return true;
}

void compute(string& tmp, vector<string>& tokens, int& totalValid, int& totalValid2)
{
	explode(tmp, tokens, ' ');

	if ((8 == tokens.size()) || (7 == tokens.size() && tmp.find("cid") == string::npos))
	{
		totalValid++;
		if (isValid(tokens)) totalValid2++;
	}

	tokens.clear();
	tmp = "";
}

void day4()
{
	ifstream data;
	string line;
	data.open("day4/input.txt");
	vector<string>tokens;
	string tmp;
	int totalValid = 0, totalValid2 = 0;

	if (data.is_open())
	{
		while (getline(data, line))
		{			
			if (line.size()) tmp += line + " ";
			if (0 == line.size() || data.eof())
			{
				compute(tmp, tokens, totalValid, totalValid2);
			}
		}
	}
	data.close();

	cout << "4.1 Total valid passports : " << totalValid << endl;
	cout << "4.2 Total valid passports : " << totalValid2 << endl;
}