#include <iostream>
#include <string>
#include <cctype>
#include <set>
#include <algorithm>

using namespace std;

char key[5][5];
struct p { int row, column; }P[2];

void Found(char text1, char text2) {

	bool isFound[2] = { false, false };

	for (int i = 0; i < 5; ++i) {

		for (int j = 0; j < 5; ++j) {

			if (text1 == key[i][j]) {

				P[0].row = i, P[0].column = j, isFound[0] = true;
				if (isFound[1] == true) { break; }
			}
			else if (text2 == key[i][j]) {

				P[1].row = i, P[1].column = j, isFound[1] = true;
				if (isFound[0] == true) { break; }
			}			
		}

		if (isFound[0] == true && isFound[1] == true) { break; }
	}
}

void handle() {

	if (P[0].row == P[1].row) {
 
		if (P[0].column + 1 < 5) { cout << key[P[0].row][P[0].column + 1]; }
		else { cout << key[P[0].row][0]; }
		
		if (P[1].column + 1 < 5) { cout << key[P[1].row][P[1].column + 1]; }
		else { cout << key[P[1].row][0]; }
	}
	else if (P[0].column == P[1].column) {

		if (P[0].row + 1 < 5) { cout << key[P[0].row + 1][P[0].column]; }
		else { cout << key[0][P[0].column]; }

		if (P[1].row + 1 < 5) { cout << key[P[1].row + 1][P[1].column]; }
		else { cout << key[0][P[1].column]; }
	}
	else { cout << key[P[0].row][P[1].column] << key[P[1].row][P[0].column]; }
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N;	
	char letter[] = { 'A', 'B', 'C', 'D', 'E',
		              'F', 'G', 'H', 'I', 'J', 
		              'K', 'L', 'M', 'N', 'O', 
		              'P', 'R', 'S', 'T', 'U', 
		              'V', 'W', 'X', 'Y', 'Z' };
	size_t pos;
	string phrase, text;
	
	cin >> N, cin.ignore();

	for (int i = 0; i < N; ++i) {

		int x = 0, y = 0;
		set<char> Set(letter, letter + 25);

		getline(cin, phrase), getline(cin, text);

		while ((pos = phrase.find(' ')) != string::npos) { phrase.erase(pos, 1); }
		while ((pos = text.find(' ')) != string::npos) { text.erase(pos, 1); }

		transform(phrase.begin(), phrase.end(), phrase.begin(), ::toupper);
		transform(text.begin(), text.end(), text.begin(), ::toupper);

		for (int j = 0; j < phrase.size(); ++j) {

			if (Set.find(phrase[j]) != Set.end()) {

				key[x][y++] = phrase[j], Set.erase(phrase[j]);
				if (y == 5) { ++x, y = 0; }
			}
		}

		for (auto iter = Set.begin(); iter != Set.end(); ++iter) {

			key[x][y++] = *iter;
			if (y == 5) { ++x, y = 0; }
		}
		
		for (int j = 0; j < text.size(); ++j) {
			
			if (j + 1 < text.size()) {

				if (text[j] != text[j + 1]) {

					Found(text[j], text[j + 1]);
					++j, handle();
				}
				else { 
				
					Found(text[j], 'X');
					handle();
				}
			}
			else {

				Found(text[j], 'X');
				handle();
			}
		}

		cout << endl;
	}
	
	return 0;
}