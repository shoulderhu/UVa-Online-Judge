#include <iostream>
#include <string>

using namespace std;

int main() {

	int i, n;
	string result;

	scanf("%d", &n), getchar();

	for (i = 1; i <= n; i++) {

		cin >> result;

		if (result == "1" || result == "4" || result == "78") { printf("+\n"); }
		else if (result[result.size() - 2] == '3' && result[result.size() - 1] == '5') { printf("-\n"); }
		else if (result[0] == '9' && result[result.size() - 1] == '4') { printf("*\n"); }
		else if (result[0] == '1' && result[1] == '9' && result[2] == '0') { printf("?\n"); }		
	}

	return 0;
}