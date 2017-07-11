#include <stdio.h>
#include <vector>

using namespace std;

double distance(double xAnimal , double yAnimal, double xHole, double yHole) {

	return (xAnimal - xHole) * (xAnimal - xHole) + (yAnimal - yHole) * (yAnimal - yHole);
}

int main() {

	int n;
	struct coordinate { double x, y; }gopher, dog, hole;
	vector<struct coordinate> holes;
	vector<struct coordinate>::iterator iter;

	while (scanf("%d %lf %lf %lf %lf", &n, &gopher.x, &gopher.y, &dog.x, &dog.y) != EOF) {

		getchar(), holes.clear();

		for (int i = 1; i <= n; i++) { 
			
			scanf("%lf %lf", &hole.x, &hole.y); 
			holes.push_back(hole);
		}

		bool isEscaped = false;

		for (iter = holes.begin(); iter != holes.end(); iter++) {

			if (distance(dog.x, dog.y, iter->x, iter->y) >= 4 * distance(gopher.x, gopher.y, iter->x, iter->y)) {

				printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", iter->x, iter->y);
				isEscaped = true;
				break;
			}
		}

		if (isEscaped == false) { printf("The gopher cannot escape.\n"); }		
	}

	return 0;
}