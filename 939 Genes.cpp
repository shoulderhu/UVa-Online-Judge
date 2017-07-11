#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	string first, second;
	map <string, string> gene;
	unordered_map <string, vector<string>> parent;

	cin >> N;

	for (int i = 0; i < N; ++i) {

		cin >> first >> second;

		if (second == "non-existent" || second == "recessive" || second == "dominant") {

			gene[first] = second;
		}
		else { parent[second].push_back(first); }
	}

	while (parent.empty() == false) {

		for (auto iter = parent.begin(); iter != parent.end(); ) {

			if (gene.find(iter->second[0]) != gene.end() && gene.find(iter->second[1]) != gene.end()) {

				if (gene[iter->second[0]] == "dominant" && gene[iter->second[1]] == "dominant" ||
					gene[iter->second[0]] == "dominant" && gene[iter->second[1]] == "recessive" ||
					gene[iter->second[0]] == "recessive" && gene[iter->second[1]] == "dominant") {

					gene[iter->first] = "dominant";
				}
				else if (gene[iter->second[0]] == "dominant" || gene[iter->second[1]] == "dominant" ||
				     	(gene[iter->second[0]] == "recessive" && gene[iter->second[1]] == "recessive")) {

					gene[iter->first] = "recessive";
				}
				else { gene[iter->first] = "non-existent"; }

				parent.erase(iter++);
			}
			else { ++iter; }
		}
	}	

	for (auto iter = gene.begin(); iter != gene.end(); ++iter) {

		cout << iter->first << " " << iter->second << endl;
	}

	return 0;
}