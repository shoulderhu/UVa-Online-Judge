#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N, S, kace = 0;
	vector<int> sequence;

	while (cin >> N) {

		sequence.clear();

		for (int i = 1; i <= N; i++){
			
			cin >> S;
			sequence.push_back(S);		
		}

		int length = sequence.size();
		long long int product = 0;
		
		for (int i = 0; i < length; ++i) {

			long long int result = 1;

			for (int j = i; j < length; ++j) {
				
				result *= sequence[j];
				if (result > product) { product = result; }
			}
		}

		cout << "Case #" << ++kace << ": The maximum product is " << product << ".\n\n";
	}
	
	return 0;
}