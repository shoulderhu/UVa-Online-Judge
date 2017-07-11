#include <stdio.h>
#include <math.h>

int main() {

	int category, kace = 0;
	double u, a, t, v, s;

	while (scanf("%d", &category) != EOF && category != 0) {

		if (category == 1) {

			scanf("%lf %lf %lf", &u, &v, &t), getchar();

			a = (v - u) / t, s = (v + u)*t / 2;

			printf("Case %d: %.3lf %.3lf\n", ++kace, s, a);
		}
		else if (category == 2) {

			scanf("%lf %lf %lf", &u, &v, &a), getchar();

			t = (v - u) / a, s = (v + u)*t / 2;

			printf("Case %d: %.3lf %.3lf\n", ++kace, s, t);
		}
		else if (category == 3) {

			scanf("%lf %lf %lf", &u, &a, &s), getchar();

			v = sqrt(u*u + 2 * a*s), t = (v - u) / a;

			printf("Case %d: %.3lf %.3lf\n", ++kace, v, t);
		}
		else if (category == 4) {

			scanf("%lf %lf %lf", &v, &a, &s), getchar();

			u = sqrt(v*v - 2 * a*s), t = (v - u) / a;

			printf("Case %d: %.3lf %.3f\n", ++kace, u, t);
		}
	}

	return 0;
}