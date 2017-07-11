#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

struct shape { double x1, y1, x2, y2, r; };

int main() {

	char T;
	int point = 0;
	double x, y;
	vector<char> type;
	vector<struct shape> figure;	
	vector<struct shape>::iterator loop;
	
	while (scanf("%c", &T) != EOF && T != '*') {

		getchar();

		if(T == 'r'){
			
			struct shape ractangle;
			scanf("%lf %lf %lf %lf", &ractangle.x1, &ractangle.y1, &ractangle.x2, &ractangle.y2), getchar();
			figure.push_back(ractangle);
		}
		else if (T == 'c') {

			struct shape circle;
			scanf("%lf %lf %lf", &circle.x1, &circle.y1, &circle.r), getchar();
			figure.push_back(circle);
		}

		type.push_back(T);
	}

	while (scanf("%lf %lf", &x, &y) != EOF && !(x == 9999.9 && y == 9999.9)) {

		int i = -1;
		bool isPrint = true;

		point++;

		for (loop = figure.begin(); loop != figure.end(); loop++) {

			bool isContained = false;

			if (type[++i] == 'r') {

				if ((*loop).x1 < x && x < (*loop).x2 && (*loop).y2 < y && y<(*loop).y1) { isContained = true; }
			}
			else {

				if (pow(x - (*loop).x1, 2) + pow(y - (*loop).y1, 2) < pow((*loop).r, 2)) { isContained = true; }
			}

			if (isContained == true) {
				
				printf("Point %d is contained in figure %d\n", point, i + 1); 
				isPrint = false;
			}
		}
				
		if (isPrint == true) { printf("Point %d is not contained in any figure\n", point); }
	}

	return 0;
}
