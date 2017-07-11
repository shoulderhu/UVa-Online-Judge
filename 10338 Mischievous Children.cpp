#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

long long int factorial(int sizeCp) {

	long long int sum = 1;
	
	for (int i = 2; i <= sizeCp; i++) { sum *= i; }
	
	return sum;
}

int main() {

	int dataSet;
	string word;
	map<char, int> Map;
	map<char, int>::iterator iter;

	scanf("%d", &dataSet), getchar();

	for (int i = 1; i <= dataSet; i++) {

		Map.clear();

		cin >> word;

		long long int result = factorial(word.size());

		for (int j = 0; j < word.size(); j++) { Map[word[j]]++; }

		for (iter = Map.begin(); iter != Map.end(); iter++) {

			if (iter->second > 1) { result /= factorial(iter->second); }
		}

		printf("Data set %d: %lld\n", i, result);		
	}

	return 0;
}