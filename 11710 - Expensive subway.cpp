#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int s, c;
string name;

struct station { 
	
	int cost;
	string from, to;

	bool operator<(struct station &s) { 

		return cost < s.cost;
	}
}S[79800];
unordered_map<string, string> Map;

inline string getRoot(string s) {

	if (Map[s] == s) { return s; }
	else { return Map[s] = getRoot(Map[s]); }
}

int main() {

	ios::sync_with_stdio(false);	

	while (cin >> s >> c && !(s == 0 && c == 0)) {

		int ss = 0, price = 0;
		Map.clear();

		for (int i = 0; i < s; ++i) { 
			
			cin >> name; 
			Map[name] = name;
		}

		for (int i = 0; i < c; ++i) { 
		
			cin >> S[i].from >> S[i].to >> S[i].cost;
		}

		cin >> name;
		sort(S, S + c);		

		for (int i = 0; i < c && ss < s; ++i) {

			S[i].from = getRoot(S[i].from);
			S[i].to = getRoot(S[i].to);

			if (S[i].from != S[i].to) {

				price += S[i].cost, ++ss;
				Map[S[i].to] = S[i].from;
			}
		}

		if (ss == s - 1) { cout << price << endl; }
		else { cout << "Impossible" << endl; }
	}

	return 0;
}
