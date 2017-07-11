#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {

	int T, Term1, Term2, Final, Attendance, Class_Test[3], kace = 0;

	scanf("%d", &T), getchar();

	for (int i = 1; i <= T; i++) {

		scanf("%d %d %d %d %d %d %d", &Term1, &Term2, &Final, &Attendance, &Class_Test[0], 
			                          &Class_Test[1], &Class_Test[2]);
				
		double total = Term1 + Term2 + Final + Attendance; 

		sort(Class_Test, Class_Test + 3);
		total += ((double)Class_Test[1] + Class_Test[2]) / 2;

		printf("Case %d: ", ++kace);
		if (90 <= total) { printf("A\n"); }
		else if (80 <= total) { printf("B\n"); }
		else if (70 <= total) { printf("C\n"); }
		else if (60 <= total) { printf("D\n"); }
		else { printf("F\n"); }
	}

	return 0;
}