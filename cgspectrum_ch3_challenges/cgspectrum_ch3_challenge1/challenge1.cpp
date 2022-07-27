#include <iostream>
#include <chrono>
#include <ctime>
#include <string>

using namespace std;

int main()
{
	int year;
	char t_buff[10];
	struct tm local_tm;

	// get current year from system clock
	chrono::system_clock::time_point tp = chrono::system_clock::now();
	time_t tt = chrono::system_clock::to_time_t(tp);
	localtime_s(&local_tm, &tt);
	strftime(t_buff, 10, "%Y", &local_tm);
	year = stoi(t_buff);

	if (year % 4 == 0)
	{
		// leap year...
		//UNLESS
		if (year % 100 == 0)
		{
			// not leap year...
			//UNLESS
			if (year % 400 == 0)
			{
				// leap year...
				cout << year << " is a Leap year...\n";
			}
			else
			{
				cout << year << " is not a Leap year...\n";
			}
		}
		else
		{
			cout << year << " is a Leap year...\n";
		}
	}
	else
	{
		cout << year << " is not a Leap year...\n";
	}
}