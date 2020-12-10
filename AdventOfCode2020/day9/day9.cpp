#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void day9()
{
	ifstream inputFile("day9/input.txt");
	vector<int>numbers, part2;
	bool found = true;
	int preambleSize = 25, number = 0, part1 = 0, index = 0, num = 0;

	while (inputFile >> number) numbers.emplace_back(number);

	vector<int>numbersToCalculate = vector<int>(numbers.begin() + preambleSize, numbers.end());
	vector<int>numbersSum;

	while(found)
	{
		found = false;
		num = numbersToCalculate.at(index);
		numbersSum = vector<int>(numbers.begin() + index , numbers.begin() + index + preambleSize);

		for (int sum1 : numbersSum)
		{
			for (int sum2 : numbersSum)
			{
				found = (sum1 != sum2 && !found && num == sum1 + sum2) ? true : found;
			}
		}

		++index;
		part1 = (!found) ? num : part1;
	}

	int sum = index = 0;
	found = false;

	while (!found)
	{
		num = sum = numbers.at(index);
		numbersSum = vector<int>(numbers.begin(), numbers.end());
		part2.emplace_back(num);

		for_each(numbersSum.begin() + index, numbersSum.end(), [&](int n) {
			if (num != n && !found && (sum += n) <= part1)
			{
				part2.emplace_back(n);
				found = (sum == part1) ? true : found;
			}
		});
		if (!found) part2.clear();
		index++;
	}

	sort(part2.begin(), part2.end());

	cout << "9.1 : Num with no sum " << part1 << endl;
	cout << "9.2 Weakness : " << part2.at(0) + part2.at(part2.size() - 1) << endl;
}