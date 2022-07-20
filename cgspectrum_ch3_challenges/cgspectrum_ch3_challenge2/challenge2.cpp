#include <iostream>
#include <vector>
#include <set>
#include <numeric>

int main() {
	int response;
	int max_factor;

	std::vector<int> p_factors;
	std::set<int> results;
	std::cout << "Provide a number value: ";
	std::cin >> response;

	max_factor = response;

	results.insert(1);
	results.insert(response);
	// [2, 3, 5, 7] prime factorizations
	while (true) {
		if (response % 2 == 0 && response != 2) {
			response = response / 2;
			p_factors.push_back(2);
			continue;
		}
		else if (response % 3 == 0 && response != 3) {
			response = response / 3;
			p_factors.push_back(3);
			continue;
		}
		else if (response % 5 == 0 && response != 5) {
			response = response / 5;
			p_factors.push_back(5);
			continue;
		}
		else if (response % 7 == 0 && response != 7) {
			response = response / 7;
			p_factors.push_back(7);
			continue;
		}
		else {
			// no more prime values to factor out
			p_factors.push_back(response);
			break;
		}
	}

	for (int offset = 0; offset < p_factors.size(); offset++) {
		for (int i = 0; i+offset < p_factors.size(); i++) {
			int factor = std::accumulate(p_factors.begin()+i, p_factors.begin()+i+offset+1, 1, std::multiplies<>());
			results.insert(factor);
		}
	}

	for ( int fact : results) {
		std::cout << fact << std::endl;
	}
}