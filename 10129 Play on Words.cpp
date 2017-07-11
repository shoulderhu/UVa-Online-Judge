#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<char, bool> isVisit;
unordered_map<char, unordered_set<char>> Map;

void DFS(char s, int &plate) {

	isVisit[s] = true, ++plate;

	for (auto iter = Map[s].begin(); iter != Map[s].end(); ++iter) {

		if (isVisit[*iter] == false) { DFS(*iter, plate); }
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, N;
	struct road { int in = 0, out = 0; };
	string word;

	cin >> T;

	for (int i = 0; i < T; ++i) {

		cin >> N;

		int begin = 0, end = 0;
		char start;
		bool isOpened = true;		
		unordered_map<char, struct road> path;
		isVisit.clear(), Map.clear();

		for (int j = 0; j < N; ++j) {

			cin >> word;
			Map[word[0]].insert(word[word.size() - 1]);
			++path[word[0]].out, ++path[word[word.size() - 1]].in;
			isVisit[word[0]] = false, isVisit[word[word.size() - 1]] = false;
		}

		for (auto iter = path.begin(); iter != path.end(); ++iter) {

			if (iter->second.out != iter->second.in) {

				if (iter->second.out - iter->second.in == 1) { ++begin, start = iter->first; }
				else if (iter->second.in - iter->second.out == 1) { ++end; }
				else { isOpened = false; }
			}			
		}
		  
		if (isOpened == true && begin == end && begin <= 1) {

			int plate = 0;

			if (begin == 0) { start = Map.begin()->first; }
			DFS(start, plate);
			if (plate != Map.size()) { isOpened = false; }	
		}
		else { isOpened = false; }

		isOpened == true ? cout << "Ordering is possible.\n" : cout << "The door cannot be opened.\n";
	}

	return 0;
}