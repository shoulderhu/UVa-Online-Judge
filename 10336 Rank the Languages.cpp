#include <stdio.h>
#include <map>

using namespace std;

int H, W;
char Map[100][100];
bool isCheck[100][100];

void DFS(int jCp, int kCp, char MapCp) {

	if (jCp < 0 || kCp < 0 || jCp >= H || kCp >= W || isCheck[jCp][kCp] == true || Map[jCp][kCp] != MapCp) { return; }
	else {

		isCheck[jCp][kCp] = true;
		DFS(jCp+1, kCp, MapCp);
		DFS(jCp, kCp-1, MapCp);
		DFS(jCp-1, kCp, MapCp);
		DFS(jCp, kCp+1, MapCp);
	}
}

int main() {

	int N;	
	map<char, int> world;
	map<char, int>::iterator iter;

	scanf("%d", &N), getchar();

	for (int i = 1; i <= N; i++) {

		scanf("%d %d", &H, &W), getchar();

		for (int j = 0; j < H; j++) {

			for (int k = 0; k < W; k++) {

				scanf("%c", &Map[j][k]);
				isCheck[j][k] = false;
			}

			getchar();
		}

		int max = 0;
		world.clear();

		printf("World #%d\n", i);

		for (int j = 0; j < H; j++) {

			for (int k = 0; k < W; k++) {

				if (isCheck[j][k] == false) {

					DFS(j, k, Map[j][k]);
					world[Map[j][k]]++;
					if (max < world[Map[j][k]]) { max = world[Map[j][k]]; }
				}
			}
		}

		for (int j = max; j >= 1; j--) {

			for (iter = world.begin(); iter != world.end(); iter++) {

				if (iter->second == j) { printf("%c: %d\n", iter->first, iter->second); }
			}
		}
	}

	return 0;
}