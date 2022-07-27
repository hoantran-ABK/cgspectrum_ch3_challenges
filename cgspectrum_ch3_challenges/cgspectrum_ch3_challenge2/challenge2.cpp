#include <iostream>
#include <vector>
#include <set>
#include <numeric>

using namespace std;

int main() {
	int response;

	vector<int> p_factors;
	set<int> results;
	cout << "Provide a positive number value: ";
	while (true)
	{
		if (cin >> response)
		{
			if (response > 0)
			{
				break;
			}
		}
		cout << "Invalid, not a positive number, try again: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	// check if all ints up to var response if a factor
	for (int i = 1; i <= (int)response; i++)
	{
		if (response % i == 0)
		{
			results.insert(i);
		}
	}

	for ( int fact : results)
	{
		cout << fact << endl;
	}
}