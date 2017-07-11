#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>
#include <stack>

using namespace std;

int tmp;
size_t pos;
string Str;
stack<char> Stack;

struct Arr {

	int size = 0;
	unordered_map<int, int> m;
};

int getValue(int begin, int end) {

	for (int i = begin; i < end; ++i) {

		if (isalpha(Str[i]) != 0) { Stack.push(Str[i]); }
		else if (isdigit(Str[i]) != 0) {

			tmp = 1;
			while (isdigit(Str[i + tmp]) != 0) { ++tmp; }
			return  stoi(Str.substr(i, tmp), nullptr, 10);			
		}
	}
}

int main() {

	while (cin >> Str && Str != ".") {

		int line = 0;
		bool isBug = false;
		unordered_map<char, struct Arr> Map;
		
		do {
			
			if (isBug) { continue; }
			else { ++line; }

			if ((pos = Str.find('=')) == string::npos) { 
				
				tmp = 1;
				while (isdigit(Str[2 + tmp]) != 0) { ++tmp; }
				Map[Str[0]].size = stoi(Str.substr(2, tmp), nullptr, 10);
			}
			else {
				
				int right = getValue(pos + 1, Str.size());				

				while (!Stack.empty()) {

					tmp = Stack.top(), Stack.pop();

					if (Map.find(tmp) == Map.end() || right >= Map[tmp].size ||
						Map[tmp].m.find(right) == Map[tmp].m.end()) {

						isBug = true; break;
					}
					else { right = Map[tmp].m[right]; }
				}

				if (isBug) { cout << line << endl; continue; }
				else { --pos; }
				
				int left = getValue(0, (int)pos);
				
				while (!Stack.empty()) {

					tmp = Stack.top(), Stack.pop();

					if (Map.find(tmp) == Map.end() || left >= Map[tmp].size ) {

						isBug = true; break;
					}
					else if (Stack.size() != 0) { left = Map[tmp].m[left]; }
				}

				if (isBug) { cout << line << endl; continue; }
				else { Map[tmp].m[left] = right; }
			}
		} while (cin >> Str && Str != ".");

		if (!isBug) { cout << 0 << endl; }
	}

	return 0;
}