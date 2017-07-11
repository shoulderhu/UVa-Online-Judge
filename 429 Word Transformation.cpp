#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <queue>

using namespace std;

string word, Begin, End;
set<string> dictionary;

bool canBuild(string w) {

	if (word.size() != w.size()) { return false; }

	int c = 0;
	
	for (int i = 0; i < word.size(); ++i) {

		if (word[i] != w[i]) {
		
			if (++c > 1) { return false; }
		}		
	}
	
	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	string line;

	cin >> N;

	for (int k = 0; k < N; ++k) {

		if (k > 0) { cout << endl; }

		dictionary.clear();
		while (cin >> word && word != "*") { dictionary.insert(word); }

		cin.ignore(1024, '\n');

		while (getline(cin, line) && line != "") {

			bool isEnd = false;
			stringstream ss(line);
			queue<string> Queue;
			set<string> Set(dictionary);
			ss >> Begin >> End, Queue.push(Begin), Set.erase(Begin);

			if (Begin == End) { cout << Begin << " " << End << " 0" << endl; continue; }

			for (int i = 1; ; ++i) {

				int Size = Queue.size();

				for (int j = 0; j < Size; ++j) {

					word = Queue.front(), Queue.pop();

					for (auto iter = Set.begin(); iter != Set.end(); ) {

						if (canBuild(*iter)) {

							if (End == *iter) { isEnd = true; break; }
							else { Queue.push(*iter), Set.erase(iter++); }
						}
						else { ++iter; }
					}

					if (isEnd) { break; }
				}

				if (isEnd) { cout << Begin << " " << End << " " << i << endl; break; }
			}
		}
	}

	return 0;
}
