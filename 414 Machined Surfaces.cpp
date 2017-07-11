#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N;
	string image;
	vector<int> surface;
	vector<int>::iterator iter;

	while (scanf("%d", &N) != EOF && N != 0) {
				
		getchar();

		surface.clear();

		for (int i = 1; i <= N; i++) {

			getline(cin, image);
			surface.push_back(count(image.begin(), image.end(), 'X'));			
		}

		sort(surface.begin(), surface.end());

		int  roughness = 0;

		for (iter = surface.begin(); iter != surface.end() - 1; iter++) {

			roughness += surface[N - 1] - *iter;
		}

		printf("%d\n", roughness);
	}

	return 0;
}