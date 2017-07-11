#include <stdio.h>
#include <iostream>
#include <ctype.h>
#include <string>
#include <algorithm>

using namespace std;

int m, n, o, p;
char grid[50][50];
string word;

bool isOut(int oCp, int pCp) {

	if (oCp < 0 || pCp < 0 || oCp >= m || pCp >= n) { return true; }
	else { return false; }
}

bool isMatch(int posCp) {

	if (posCp == word.size() - 1) { 

		printf("%d %d\n", o + 1, p + 1);
		return true; 
	}

	return false;
}

bool upperLeft(int pos) {

	while (isOut(o - pos, p - pos) == false && grid[o - pos][p - pos] == word[pos]) {

		if (isMatch(pos) == true) { return true; }
		else { pos++; }
	}

	return false;
}

bool upperMid(int pos) {

	while (isOut(o - pos, p) == false && grid[o - pos][p] == word[pos]) {

		if (isMatch(pos) == true) { return true; }
		else { pos++; }
	}

	return false;
}

bool upperRight(int pos) {

	while (isOut(o - pos, p + pos) == false && grid[o - pos][p + pos] == word[pos]) {

		if (isMatch(pos) == true) { return true; }
		else { pos++; }
	}

	return false;
}

bool Left(int pos) {

	while (isOut(o , p - pos) == false && grid[o][p - pos] == word[pos]) {

		if (isMatch(pos) == true) { return true; }
		else { pos++; }
	}

	return false;	
}

bool Right(int pos) {

	while (isOut(o, p + pos) == false && grid[o][p + pos] == word[pos]) {

		if (isMatch(pos) == true) { return true; }
		else { pos++; }
	}

	return false;
}

bool lowerLeft(int pos) {

	while (isOut(o + pos, p - pos) == false && grid[o + pos][p - pos] == word[pos]) {

		if (isMatch(pos) == true) { return true; }
		else { pos++; }
	}

	return false;
}

bool lowerMid(int pos) {

	while (isOut(o + pos, p) == false && grid[o + pos][p] == word[pos]) {

		if (isMatch(pos) == true) { return true; }
		else { pos++; }
	}

	return false;
}


bool lowerRight(int pos) {

	while (isOut(o + pos, p + pos) == false && grid[o + pos][p + pos] == word[pos]) {

		if (isMatch(pos) == true) { return true; }
		else { pos++; }
	}

	return false;
}

int main() {

	int kace, k;	

	scanf("%d", &kace), getchar();

	for (int i = 1; i <= kace; i++) {

		if (i > 1) { printf("\n"); }

		scanf("%d %d", &m, &n), getchar();

		for (int j = 0; j < m; j++) {

			for (int l = 0; l < n; l++) {

				scanf("%c", &grid[j][l]);
				grid[j][l] = tolower(grid[j][l]);
			}

			getchar();
		}

		scanf("%d", &k), getchar();

		for (int j = 1; j <= k; j++) {

			cin >> word;
			transform(word.begin(), word.end(), word.begin(), ::tolower);
							
			bool isFound = false;

			for (o = 0; o < m; o++) {

				for (p = 0; p < n; p++) {

					if (grid[o][p] == word[0]) { 
						
						if (upperLeft(0) == true) { isFound = true; break; }
						else if (upperMid(0) == true) { isFound = true; break; }
						else if (upperRight(0) == true) { isFound = true; break; }
						else if (Left(0) == true) { isFound = true; break; }
						else if (Right(0) == true) { isFound = true; break; }
						else if (lowerLeft(0) == true) { isFound = true; break; }
						else if (lowerMid(0) == true) { isFound = true; break; }
						else if (lowerRight(0) == true) { isFound = true; break; }
					}					
				}

				if (isFound == true) { break; }
			}			
		}
	}

	return 0;
}