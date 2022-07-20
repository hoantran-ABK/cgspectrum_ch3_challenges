#include <iostream>
#include <chrono>
#include <ctime>
#include <string>

int main() {
	int year;
	char t_buff[10];
	struct tm local_tm;

	// get current year from system clock
	std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();
	time_t tt = std::chrono::system_clock::to_time_t(tp);
	localtime_s(&local_tm, &tt);
	strftime(t_buff, 10, "%Y", &local_tm);
	year = std::stoi(t_buff);

	if (year % 4 == 0) {
		// leap year...
		//UNLESS
		if (year % 100 == 0) {
			// not leap year...
			//UNLESS
			if (year % 400 == 0) {
				// leap year...
				std::cout << year << " is a Leap year...\n";
			}
			else {
				std::cout << year << " is not a Leap year...\n";
			}
		}
		else {
			std::cout << year << " is a Leap year...\n";
		}
	}
	else {
		std::cout << year << " is not a Leap year...\n";
	}
}