#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int tribonacci(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	else if (n == 3)
	{
		return 4;
	}
	else
	{
		return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
	}
}

void day10()
{
	ifstream inputFile("day10/input.txt");
	int jolt = 0, adapter = 0;
	vector<int>jolts;
	while (inputFile >> jolt)
	{
		jolts.push_back(jolt);
	}

	sort(jolts.begin(), jolts.end());
	int adaptersToUse = jolts.size();
	int joltDifference1 = 0, joltDifference2 = 0, joltDifference3 = 0;
	vector<int>tribonacciJolts;

	while(adaptersToUse >= 0)
	{
		for (int jolt : jolts)
		{
			if ((adapter + 1) == jolt)
			{
				joltDifference1++;
				adapter = jolt;
				tribonacciJolts.emplace_back(1);
			}
			else if ((adapter + 2) == jolt)
			{
				joltDifference2++;
				adapter = jolt;
				tribonacciJolts.emplace_back(2);
			}
			else if ((adapter + 3) == jolt)
			{
				joltDifference3++;
				adapter = jolt;
				tribonacciJolts.emplace_back(3);
			}
		}

		adaptersToUse--;
	}
	//Finally, your device's built-in adapter is always 3 higher than the highest adapter
	joltDifference3++;

	cout << "10.1 : " << joltDifference1 * joltDifference3 << endl;

	//count how many consecutives one we have until the next none one,
	//then calculate how many permutations are possible with tribonnacci
	//example :  1 1 1 3 can be permutted with 4 possibilities => 1 1 1 3, 2 1 3, 1 2 3, 3 3
	//then power the current number of permutations with those 4 possibilites wich became the new number of permutations.
	int counsecutivesOne = 0;
	long long nbPermutations = 1;

	for (int jolt : tribonacciJolts)
	{
		if (jolt == 1)
		{
			counsecutivesOne += 1;
		}
		else
		{
			nbPermutations *= tribonacci(counsecutivesOne);
			counsecutivesOne = 0;
		}
	}	
	cout << "10.2 : " << nbPermutations * tribonacci(counsecutivesOne) << endl;
}

int main()
{
	day10();
	return 0;
}