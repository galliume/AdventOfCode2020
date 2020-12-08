#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <tuple>
#include <regex>

using namespace std;

set<int>swapDone = { };
bool part1Done = false;

int boot(vector<tuple<string, int>>& instructions, vector<tuple<string, int>>& nextInstructions, int lastIndex)
{
	int index = 0, accumulator = 0;
	bool done = false;
	set<int>instructionsDone = { };

	while (!done)
	{
		string instruction = get<0>(nextInstructions.at(index));
		int value = get<1>(nextInstructions.at(index));

		lastIndex = (find(swapDone.begin(), swapDone.end(), index) == swapDone.end() && ("jmp" == instruction || "nop" == instruction)) ? index : lastIndex;

		if (find(instructionsDone.begin(), instructionsDone.end(), index) != instructionsDone.end())
		{
			vector<tuple<string, int>>nextInstructions = instructions;

			nextInstructions[lastIndex] = ("jmp" == get<0>(nextInstructions.at(lastIndex))) 
				? make_tuple("nop", get<1>(nextInstructions.at(lastIndex))) : make_tuple("jmp", get<1>(nextInstructions.at(lastIndex)));

			if (!part1Done)
			{
				part1Done = true;
				cout << "8.1 Total : " << accumulator << endl;
			}

			done = true;
			swapDone.insert(lastIndex);

			return boot(instructions, nextInstructions, lastIndex);
		}

		instructionsDone.insert(index);

		accumulator = ("acc" == instruction) ? accumulator += value : accumulator;
		index = ("jmp" == instruction) ? value + index : ++index;
		done = (instructions.size() == index) ? true : false;
	}
	return accumulator;
}

void day8()
{
	ifstream inputFile("day8/input.txt");
	vector<tuple<string, int>>instructions;
	string instruction, value;
	smatch matchValue;

	while (inputFile >> instruction >> value)
	{
		regex_search(value, matchValue, regex("[-]?[0-9]{1,5}"));
		instructions.emplace_back(instruction, stoi(matchValue.str()));
	}

	cout << "8.2 Total : " << boot(instructions, instructions, 0) << endl;
}

int main()
{
	day8();
	return 0;
}