#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int main() {

	int i, command, x, n;
	string output;
	stack<int> Stack;
	queue<int> Queue;
	priority_queue<int> PriorityQueue;

	while (cin >> n) {

		int guess = 3;
		bool isStack = true, isQueue = true, isPriorityQueue = true;
		
		while (Stack.empty() == false) { Stack.pop(); }
		while (Queue.empty() == false) { Queue.pop(); }
		while (PriorityQueue.empty() == false) { PriorityQueue.pop(); }

		for (i = 1; i <= n; i++) {

			cin >> command >> x;

			if (command == 1) {

				Stack.push(x), Queue.push(x), PriorityQueue.push(x);
			}
			else if (command == 2) {

				if (isStack == true) {
					
					if (Stack.empty() != true && Stack.top() == x) { Stack.pop(); }
					else { isStack = false, guess--; }
				}

				if (isQueue == true) {
					
					if (Queue.empty() != true && (Queue.front() == x)) { Queue.pop(); }
					else { isQueue = false, guess--; }
				}

				if (isPriorityQueue == true) {
					
					if (PriorityQueue.empty() != true && PriorityQueue.top() == x) { PriorityQueue.pop(); }
					else { isPriorityQueue = false, guess--; }
				}
			}
		}

		switch (guess) {

		case 0:
			output = "impossible";
			break;
		case 1:
			if (isStack == true) { output = "stack"; }
			else if (isQueue == true) { output = "queue"; }
			else if (isPriorityQueue == true) { output = "priority queue"; }
			break;
		case 2: case 3:
			output = "not sure";
			break;
		}

		cout << output << endl;
	}	

	return 0;
}