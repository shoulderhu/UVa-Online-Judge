#include <stdio.h>

int dimension;
char Tigerville[25][26];
bool isVisited[25][26];

void DFS(int i, int j) {

	if (i < 0 || j < 0 || i >= dimension || j >= dimension || isVisited[i][j] == true || Tigerville[i][j] == '0') { return; }
	else {

		isVisited[i][j] = true;
		DFS(i - 1, j - 1), DFS(i - 1, j), DFS(i - 1, j + 1);
		DFS(i, j - 1), DFS(i, j + 1);
		DFS(i + 1, j - 1), DFS(i + 1, j), DFS(i + 1, j + 1);
	}
}

int main() {

	int image = 0;
	
	while (scanf("%d", &dimension) != EOF) {

		for (int i = 0; i < dimension; i++) {

			scanf("%s", &Tigerville[i]), getchar();

			for (int j = 0; j < dimension; j++) {

				isVisited[i][j] = false;
			}
		}

		int eagle = 0;

		for (int i = 0; i < dimension; i++) {

			for (int j = 0; j < dimension; j++) {

				if (Tigerville[i][j] == '1' && isVisited[i][j] == false) {

					eagle++, DFS(i, j);
				}
			}
		}

		printf("Image number %d contains %d war eagles.\n", ++image, eagle);
	}

	return 0;
}