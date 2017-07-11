#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int x, y;
char island[50][50];
bool isVisit[50][50];
struct hole {

	int size;
	char letter;	
}Hole;

bool mySort(struct hole a, struct hole b) {

	if (a.size != b.size) { return a.size > b.size; }
	else { return a.letter < b.letter; }
}

void DFS(int i, int j, char& c) {

	if (i < 0 || j < 0 || i >= x || j >= y || isVisit[i][j] == true) { return; }
	else if (island[i][j] == '.' || island[i][j] != c) { return; }
	else {

		++Hole.size, isVisit[i][j] = true;
		DFS(i - 1, j, c);
		DFS(i, j + 1, c);
		DFS(i + 1, j, c);
		DFS(i, j - 1, c);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int problem = 0;
	string line;

	while (cin >> x >> y && !(x == 0 && y == 0)) {

		vector<struct hole> Vector;
		cin.ignore();

		for (int i = 0; i < x; ++i) {

			for (int j = 0; j < y; ++j) {

				isVisit[i][j] = false;
			}
		}

		for (int i = 0; i < x; ++i) { 
			
			getline(cin, line);

			for (int j = 0; j < y; ++j) { island[i][j] = line[j]; }
		}
		
		for (int i = 0; i < x; ++i) {

			for (int j = 0; j < y; ++j) {

				if (island[i][j] != '.' && isVisit[i][j] == false) {
					
					Hole.size = 0, DFS(i, j, island[i][j]);
					Hole.letter = island[i][j];
					Vector.push_back(Hole);
				}
			}
		}

		sort(Vector.begin(), Vector.end(), mySort);

		cout << "Problem " << ++problem << ":" << endl;

		for (auto iter = Vector.begin(); iter != Vector.end(); ++iter) {

			cout << iter->letter << " " << iter->size << endl;
		}
	}

	return 0;
}