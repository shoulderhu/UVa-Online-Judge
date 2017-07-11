#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

struct graph {

	char type;
	double xUpper, yUpper, xLower, yLower, xCenter, yCenter, r, x[3], y[3];
}g;

double countArea(double x1, double y1, double x2, double y2, double x3, double y3) {

	return fabs(x1*y2 + x2*y3 + x3*y1 - x1*y3 - x2*y1 - x3*y2);
}

bool isRactangle(vector<struct graph>::iterator iter, double x, double y) {

	if (iter->xUpper < x && x < iter->xLower && iter->yLower < y && y < iter->yUpper) { return true; }
	else{ return false; }	
}

bool isCircle(vector<struct graph>::iterator iter, double x, double y) {

	if (pow((iter->xCenter - x), 2.0) + pow((iter->yCenter - y), 2.0) < pow(iter->r, 2.0)) { return true; }
	else { return false; }
}

bool isTriangle(vector<struct graph>::iterator iter, double x, double y) {

	double area[3];
	
	if ((area[0] = countArea(x, y, iter->x[0], iter->y[0], iter->x[1], iter->y[1])) == 0.0 ||
		(area[1] = countArea(x, y, iter->x[0], iter->y[0], iter->x[2], iter->y[2])) == 0.0 ||
		(area[2] = countArea(x, y, iter->x[1], iter->y[1], iter->x[2], iter->y[2])) == 0.0 ||
		fabs(countArea(iter->x[0], iter->y[0], iter->x[1], iter->y[1], iter->x[2], iter->y[2]) - area[0] - area[1] - area[2]) >= 1e-9) {

		return false;
	}		
	else { return true; }
}

int main() {

	char t;
	int point = 0;
	double x, y;	
	vector<struct graph> plane;
	vector<struct graph>::iterator iter;
	
	while (scanf("%c", &t) != EOF && t != '*') {

		if (t == 'r') {

			g.type = 'r';
			scanf("%lf %lf %lf %lf", &g.xUpper, &g.yUpper, &g.xLower, &g.yLower), getchar();
			plane.push_back(g);
		}
		else if (t == 'c') {
			
			g.type = 'c';
			scanf("%lf %lf %lf", &g.xCenter, &g.yCenter, &g.r), getchar();
			plane.push_back(g);
		}
		else if (t == 't') {
						
			g.type = 't';
			scanf("%lf %lf %lf %lf %lf %lf", &g.x[0], &g.y[0], &g.x[1], &g.y[1], &g.x[2], &g.y[2]), getchar();
			plane.push_back(g);
		}
	}

	while (scanf("%lf %lf", &x, &y) != EOF && !(x == 9999.9  && y == 9999.9)) {

		int figure = 1;
		bool isPrint = false;
		point++;

		for (iter = plane.begin(); iter != plane.end(); iter++, figure++) {

			if (iter->type == 'r') {

				if (isRactangle(iter, x, y) == true) {

					isPrint = true;
					printf("Point %d is contained in figure %d\n", point, figure);
				}				
			}
			else if (iter->type == 'c') {

				if (isCircle(iter, x, y) == true) {

					isPrint = true;
					printf("Point %d is contained in figure %d\n", point, figure);
				}
			}
			else if (iter->type == 't') {

				if (isTriangle(iter, x, y) == true) {

					isPrint = true;
					printf("Point %d is contained in figure %d\n", point, figure);
				}
			}			
		}

		if (isPrint == false) { printf("Point %d is not contained in any figure\n", point); }
	}

	return 0;
}