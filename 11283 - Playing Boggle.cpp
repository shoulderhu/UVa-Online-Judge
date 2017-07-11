#include <iostream>
#include <cstring>
#include <string>
#include <unordered_set>

using namespace std;

int N, M, score;
char Boggle[4][4];
bool isVisit[4][4], isFind;
string word; 
unordered_set<string> Set;

void DFS(int x, int y, int z, bool V[][4]) {
	
	if (isFind) { return; }
	if (++z == word.size()) { isFind = true; return; }

	V[x][y] = true;
			
	if (x - 1 >= 0 && y - 1 >= 0 && !V[x - 1][y - 1] && Boggle[x - 1][y - 1] == word[z]) {

		bool isVisit[4][4];
		
		for (int i = 0; i < 4; ++i) {

			for (int j = 0; j < 4; ++j) {

				isVisit[i][j] = V[i][j];
			}
		}
		
		DFS(x - 1, y - 1, z, isVisit);
	}
	if (x - 1 >= 0 && !V[x - 1][y] && Boggle[x - 1][y] == word[z]) {

		bool isVisit[4][4];
		
		for (int i = 0; i < 4; ++i) {

			for (int j = 0; j < 4; ++j) {

				isVisit[i][j] = V[i][j];
			}
		}

		DFS(x - 1, y, z, isVisit);
	}
	if (x - 1 >= 0 && y + 1 < 4 && !V[x - 1][y + 1] && Boggle[x - 1][y + 1] == word[z]) {

		bool isVisit[4][4];
		memcpy(isVisit, V, sizeof(V));
		for (int i = 0; i < 4; ++i) {

			for (int j = 0; j < 4; ++j) {

				isVisit[i][j] = V[i][j];
			}
		}

		DFS(x - 1, y + 1, z, isVisit);
	}
	if (y - 1 >= 0 && !V[x][y - 1] && Boggle[x][y - 1] == word[z]) {

		bool isVisit[4][4];
		
		for (int i = 0; i < 4; ++i) {

			for (int j = 0; j < 4; ++j) {

				isVisit[i][j] = V[i][j];
			}
		}

		DFS(x, y - 1, z, isVisit);
	}
	if (y + 1 < 4 && !V[x][y + 1] && Boggle[x][y + 1] == word[z]) {

		bool isVisit[4][4];
		
		for (int i = 0; i < 4; ++i) {

			for (int j = 0; j < 4; ++j) {

				isVisit[i][j] = V[i][j];
			}
		}

		DFS(x, y + 1, z, isVisit);
	}
	if (x + 1 < 4 && y - 1 >= 0 && !V[x + 1][y - 1] && Boggle[x + 1][y - 1] == word[z]) {

		bool isVisit[4][4];
		
		for (int i = 0; i < 4; ++i) {

			for (int j = 0; j < 4; ++j) {

				isVisit[i][j] = V[i][j];
			}
		}

		DFS(x + 1, y - 1, z, isVisit);
	}
	if (x + 1 < 4 && !V[x + 1][y] && Boggle[x + 1][y] == word[z]) {

		bool isVisit[4][4];
		memcpy(isVisit, V, sizeof(V));
	    for (int i = 0; i < 4; ++i) {

			for (int j = 0; j < 4; ++j) {

				isVisit[i][j] = V[i][j];
			}
		}

		DFS(x + 1, y, z, isVisit);
	}
	if (x + 1 < 4 && y + 1 < 4 && !V[x + 1][y + 1] && Boggle[x + 1][y + 1] == word[z]) {

		bool isVisit[4][4];
		
		for (int i = 0; i < 4; ++i) {

			for (int j = 0; j < 4; ++j) {

				isVisit[i][j] = V[i][j];
			}
		}

		DFS(x + 1, y + 1, z, isVisit);
	}
}

int main() {

	ios::sync_with_stdio(false);
		
	cin >> N;

	for (int i = 1; i <= N; ++i) {

		score = 0, Set.clear();		

		for (int j = 0; j < 4; ++j) {

			for (int k = 0; k < 4; ++k) {

				cin >> Boggle[j][k];
			}
		}

		cin >> M;

		for (int j = 0; j < M; ++j) {

			cin >> word;
			if (Set.find(word) != Set.end()) { continue; }
			isFind = false, Set.insert(word);
			
			for (int k = 0; k < 4; ++k) {

				for (int l = 0; l < 4; ++l) {

					if (Boggle[k][l] == word[0]) {
						
						memset(isVisit, false, sizeof(isVisit));
						DFS(k, l, 0, isVisit);

						if(isFind) {

							switch (word.size()) {

							case 3: 
							case 4: score += 1; break;
							case 5: score += 2; break;
							case 6: score += 3; break;
							case 7: score += 5; break;
							default: score += 11; break;
							}
							
							break;
						}
					}
				}

				if (isFind) { break; }
			}
		}

		cout << "Score for Boggle game #" << i << ": " << score << endl;
	}

	return 0;
}