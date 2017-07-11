#include <stdio.h>
#include <vector>

using namespace std;

int main() {

	int point = 0;
	char r;
	double x, y;
	struct rectangle { double xUpperLeft, yUpperLeft, xLowerRight, yLowerRight; }rec;
	vector<struct rectangle> figure;
	
	while (scanf("%c", &r) != EOF && r != '*') {
		
		scanf("%lf %lf %lf %lf", &rec.xUpperLeft, &rec.yUpperLeft, &rec.xLowerRight, &rec.yLowerRight),	getchar();
		figure.push_back(rec);			 
	}

	while (scanf("%lf %lf", &x, &y) != EOF && !(x == 9999.9 && y == 9999.9)) {

		bool isContained = false;
		point++;

		for (int i = 0; i < figure.size(); i++) {

			if (figure[i].xUpperLeft<x && x<figure[i].xLowerRight && figure[i].yLowerRight<y && y<figure[i].yUpperLeft) {

				isContained = true;
				printf("Point %d is contained in figure %d\n", point, i + 1);
			}			
		}

		if (isContained == false) { printf("Point %d is not contained in any figure\n", point); }
	}

	return 0;
}