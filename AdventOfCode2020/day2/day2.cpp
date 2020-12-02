#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int day21()
{
	ifstream data;
	string line;

	data.open("day2/input.txt");

	if (data.is_open()) {

		int min = 0, max = 0, count = 0, total = 0;
		char letter;
		char password[50];

		while (getline(data, line))
		{	
			sscanf_s(line.c_str(), "%d-%d %c:%49s", &min, &max, &letter, sizeof(letter), &password, sizeof(password));
			
			for (char c : password)
			{
				if (c == letter)
				{
					count++;
				}
			}

			if (count >= min && count <= max)
			{
				total++;
			}
			
			cout << min << " - " << max << " - " << letter << " - " << password << endl;	
			count = 0;
		}

		cout << "Total " << total;
		data.close();
	}

	return 0;
}

int day22()
{
	ifstream data;
	string line;

	data.open("day2/input.txt");

	if (data.is_open()) {

		int min = 0, max = 0, count = 0, total = 0;
		char letter;
		char password[50];

		while (getline(data, line))
		{
			sscanf_s(line.c_str(), "%d-%d %c:%49s", &min, &max, &letter, sizeof(letter), &password, sizeof(password));
			
			if ((letter == password[min - 1] && letter != password[max - 1]) || (letter != password[min - 1] && letter == password[max - 1]))
			{
				total++;
			}
		}

		cout << "Total " << total;
		data.close();
	}

	return 0;
}

int main()
{	
	return day22();
}