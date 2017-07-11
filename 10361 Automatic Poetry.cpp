#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {

	int n;
	string line1, line2;

	scanf("%d", &n), getchar();

	for (int i = 1; i <= n; i++) {

		getline(cin, line1);
		getline(cin, line2);
		
		size_t left1 = line1.find('<'), right1 = line1.find('>');
		size_t left2 = line1.rfind('<'), right2 = line1.rfind('>');
		string s2 = line1.substr(left1 + 1, right1 - left1 - 1);
		string s3 = line1.substr(right1 + 1, left2 - right1 - 1);
		string s4 = line1.substr(left2 + 1, right2 - left2 - 1);
		string s5 = line1.substr(right2 + 1, line1.size() - right2 - 1);

		for (int j = 0; j < line1.size(); j++) {

			if (line1[j] != '<' && line1[j] != '>') {

				printf("%c", line1[j]);
			}
		}
		printf("\n");

		for (int j = 0; j < line2.size(); j++) {

			if (line2[j] != '.') { printf("%c", line2[j]); }
			else { 
				
				printf("%s%s%s%s\n", s4.c_str(), s3.c_str(), s2.c_str(), s5.c_str());
				break;
			}
		}		
	}

	return 0;
}