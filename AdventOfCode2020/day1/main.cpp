#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ifstream data1, data2, data3;
	string line1, line2, line3;

	data1.open("day1/data.txt");

	if (data1.is_open()) {
		while (getline(data1, line1))
		{
			int current1 = atoi(line1.c_str());
			data2.open("day1/data.txt");

			if (data2.is_open()) {
				while (getline(data2, line2)) {
					int current2 = atoi(line2.c_str());

					data3.open("day1/data.txt");
	
					while (getline(data3, line3)) {
						int current3 = atoi(line3.c_str());

						if (2020 == current1 + current2 + current3) {
							cout << current1 << " - " << current2 << " - " << current3 << " : " << current1 * current2 * current3 << endl;
							data1.close();
							data2.close();
							data3.close();
							return 0;
						}
					}
					data3.close();
				}
				data2.close();
			}
		}
		data1.close();
	}

	return 0;
}