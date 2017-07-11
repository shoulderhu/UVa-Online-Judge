#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {

	bool grid[51][51];
	char orientation;
	int xUpRight, yUpRight, x, y;
	string instruction;

	for (int i = 0; i < 51; i++) {

		for (int j = 0; j < 51; j++) {

			grid[i][j] = false;
		}
	}

	scanf("%d %d", &xUpRight, &yUpRight), getchar();

	while (scanf("%d %d %c", &x, &y, &orientation) != EOF) {
				
		cin >> instruction;

		bool isLost = false;

		for (int i = 0; i < instruction.size(); i++) {

			if (instruction[i] == 'L') {
			
				switch (orientation) {

				case 'N': orientation = 'W'; break;
				case 'E': orientation = 'N'; break;
				case 'S': orientation = 'E'; break;
				case 'W': orientation = 'S'; break;
				}
			}
			else if(instruction[i] == 'R'){
			
				switch (orientation) {

				case 'N': orientation = 'E'; break;
				case 'E': orientation = 'S'; break;
				case 'S': orientation = 'W'; break;
				case 'W': orientation = 'N'; break;
				}
			}
			else {

				int xTemp = x, yTemp = y;

				switch (orientation) {

				case 'N': yTemp++; break;
				case 'E': xTemp++; break;
				case 'S': yTemp--; break;
				case 'W': xTemp--; break;
				}

				if (xTemp >= 0 && yTemp >= 0 && xTemp <= xUpRight && yTemp <= yUpRight) { 

					x = xTemp, y = yTemp; 
				}
				else {

					if (grid[x][y] == false) {

						grid[x][y] = true, isLost = true;
						printf("%d %d %c LOST\n", x, y, orientation);
						break;
					}
				}
			}			
		}

		if (isLost == false) { printf("%d %d %c\n", x, y, orientation); }
	}

	return 0;
}