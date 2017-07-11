#include <stdio.h>
#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;

int main() {

	string message;
			
	while (getline(cin, message)) {
				
		if (isdigit(message[0]) != 0) {
			
			bool isThree = false;

			for (int i = message.size() - 1; i >= 0; isThree == true ? i -= 3 : i -= 2) {

				int ASCII = ((message[i] - '0') * 10 + (message[i-1] - '0'));					
				isThree = false;

				if (ASCII < 32) { 
					
					ASCII = ASCII * 10 + (message[i - 2] - '0');
					isThree = true;
				}

				printf("%c", ASCII);
			}			
		}
		else {

			for (int i = message.size() - 1; i >= 0; i--) { 
				
				int ASCII = message[i], result = 0;
				
				while (ASCII % 10 == 0) {

					ASCII /= 10;
					printf("0");
				}
				while (ASCII > 0) { result = result * 10 + ASCII % 10, ASCII /= 10; }
								
				printf("%d", result); 
			}			
		}

		printf("\n");
	}

	return 0;
}