#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void day6()
{
	ifstream data;
	string line, answers, tmp;
	uint32_t totalYes = 0, totalYes2 = 0, nbPersons = 0;	

	data.open("day6/input.txt");

	if (data.is_open())
	{
		while (!data.eof())
		{			
			getline(data, line);

			if (line.size())
			{
				answers += line;
				nbPersons++;
			}
			if (0 == line.size())
			{
				sort(answers.begin(), answers.end());
				unique_copy(answers.begin(), answers.end(), back_inserter(tmp));

				for (auto c : tmp)
				{
					if (nbPersons == count(answers.begin(), answers.end(), c))
					{
						totalYes2++;
					}
				}
				totalYes += tmp.size();
				tmp = answers = "";
				nbPersons = 0;
			}
		}
	}
	data.close();

	cout << "6.1 Total yes : " << totalYes << endl;
	cout << "6.2 Total yes : " << totalYes2 << endl;
}

int main()
{
	day6();
	return 0;
}