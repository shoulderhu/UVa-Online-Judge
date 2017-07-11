#include <stdio.h>

int main() {

	int T, DNow, MNow, YNow, DBirth, MBirth, YBirth;

	scanf("%d", &T), getchar();

	for (int i = 1; i <= T; i++) {

		scanf("%d/%d/%d", &DNow, &MNow, &YNow), getchar();
		scanf("%d/%d/%d", &DBirth, &MBirth, &YBirth), getchar();

		printf("Case #%d: ", i);
		
		if (YBirth>YNow || (YBirth==YNow && MBirth>MNow) || (YBirth==YNow && MBirth==MNow && DBirth>DNow)) { printf("Invalid birth date\n"); }
		else {

			int age;

			if ((MNow==MBirth && DNow>=DBirth) || MNow>MBirth) { age = YNow - YBirth; }
			else { age = YNow - YBirth - 1; }
						
			if (age > 130) { printf("Check birth date\n"); }
			else { printf("%d\n", age); }
		}		
	}

	return 0;
}