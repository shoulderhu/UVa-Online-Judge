#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

struct job {

	bool myJob;
	int priority;
}N;

int main() {

	int i, j, kace, n, m;
	deque<struct job> J;
	deque<struct job>::iterator loop;
	
	cin >> kace;

	for (i = 1; i <= kace; i++) {

		cin >> n >> m;
		
		J.clear();

		for (j = 0; j < n; j++) { 
			
			cin >> N.priority;
			N.myJob = (j == m ? true : false);
			J.push_back(N);
		}

		int minutes = 0;
		
		for (;;) {

			bool isHigher = false;
			deque<struct job>::iterator loopB = J.begin();

			for (loop = J.begin(); loop != J.end(); loop++) {

				if ((*loopB).priority < (*loop).priority) {

					isHigher = true;
					break;
				}
			}

			if (isHigher == true) {

				N.myJob = (*loopB).myJob;
				N.priority = (*loopB).priority;
				J.push_back(N);
				J.pop_front();
			}
			else {

				minutes++;

				if ((*loopB).myJob == true) { 
					
					printf("%d\n", minutes); 
					break;
				}

				J.pop_front();
			}
		}		
	}

	return 0;
}