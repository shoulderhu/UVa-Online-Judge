#include <stdio.h>
#include <stack>
#include <queue>

using namespace std;

int main() {

	stack<int> station;
	queue<int> A;
	
	int N, coach;

	while (scanf("%d", &N) != EOF && N != 0) {
							
		while (true) {
		    
			while (A.empty() == false) { A.pop(); }
			while (station.empty() == false) { station.pop(); }
			
			for (int i = 1; i <= N; i++) { A.push(i); }
		    
			bool isPossible = true;

			for (int i = 1; i <= N; i++) {

				scanf("%d", &coach);
				
				if (coach == 0) { break; }
				else if (isPossible == true) {

					if (station.empty() == false && coach == station.top()) { station.pop(); }
					else {

						while (A.empty() == false && coach != A.front()) {

							station.push(A.front());
							A.pop();
						}

						if (A.empty() == false) { A.pop(); }
						else { isPossible = false; }
					}
				}									
			}

			if (coach == 0) { break; }
			else { printf(isPossible == true ? "Yes\n" : "No\n"); }											
		}	

		printf("\n");
	}

	return 0;
}