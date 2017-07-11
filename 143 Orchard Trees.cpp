#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

double countArea(double xCp0, double yCp0, double xCp1, double yCp1, double xCp2, double yCp2) {

	return fabs(xCp0*yCp1 + xCp2*yCp0 + xCp1*yCp2 - xCp2*yCp1 - xCp0*yCp2 - xCp1*yCp0);
}

int main() {

	double x[3], y[3];

	while (scanf("%lf %lf %lf %lf %lf %lf", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2]) != EOF) {

		if (x[0] == 0 && y[0] == 0 && x[1] == 0 && y[1] == 0 && x[2] == 0 && y[2] == 0) { break; }

		int tree = 0;
		int xLower = ceil(*min_element(x, x + 3)), xHigher = floor(*max_element(x, x + 3));
		int yLower = ceil(*min_element(y, y + 3)), yHigher = floor(*max_element(y, y + 3));
		double triangle = countArea(x[0], y[0], x[1], y[1], x[2], y[2]);

		xLower = max(xLower, 1), xHigher = min(xHigher, 99);
		yLower = max(yLower, 1), yHigher = min(yHigher, 99);

		for (int i = xLower; i <= xHigher ; i++) {

			for (int j = yLower; j <= yHigher; j++) {

				double temp = countArea(x[0], y[0], x[1], y[1], i, j) + countArea(i, j, x[1], y[1], x[2], y[2]) + countArea(x[0], y[0], i, j, x[2], y[2]);

				if (fabs(triangle - temp) < 1e-9) { tree++; }
			}
		}

		printf("%4d\n", tree);
	}

	return 0;
}
