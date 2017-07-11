#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	string line, X;

	cin >> N;

	for (int i = 0; i < N; ++i) {

		cin >> line;

		int M = 0, E = 0;
		bool isTheorem = true;
		
		for (int i = 0; i < line.size(); ++i) {

			if (line[i] != 'M' && line[i] != 'E' && line[i] != '?') { 
				
				isTheorem = false;
				break; 
			}
			else if (line[i] == 'M') { line[i] = ' ', ++M; }		
			else if (line[i] == 'E') { line[i] = ' ', ++E; }
		}

		if (M != 1 || E != 1) { isTheorem = false; }

		if (isTheorem == true) {

			int j = -1;
			size_t x[3];
			stringstream ss(line);			

			while (ss >> X) { x[++j] = X.size(); }
			if (j != 2 || x[0] + x[1] != x[2]) { isTheorem = false; }
		}

		isTheorem == true ? cout << "theorem" << endl : cout << "no-theorem" << endl;
	}

	return 0;
}