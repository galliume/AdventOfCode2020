#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int day2()
{
	ifstream data;
	string line;
	int min = 0, max = 0, count = 0, oldTotal = 0, newTotal = 0;
	char letter, password[50];

	data.open("day2/input.txt");

	if (data.is_open()) 
	{
		while (getline(data, line))
		{	
			sscanf_s(line.c_str(), "%d-%d %c:%49s", &min, &max, &letter, sizeof(letter), &password, sizeof(password));
			
			for (char c : password)
			{
				if (c == letter) count++;
			}

			if (count >= min && count <= max) oldTotal++;
			if ((letter == password[min - 1] && letter != password[max - 1]) || (letter != password[min - 1] && letter == password[max - 1])) newTotal++;
			
			count = 0;
		}		
		data.close();
	};

	cout << "old : " << oldTotal << " new : " << newTotal << endl;

	return 0;
}

int main()
{	
	return day2();
}