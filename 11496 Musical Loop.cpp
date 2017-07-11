#include <iostream>
#include <vector>

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N, H;

	while (cin >> N && N != 0){

		int peak = 0;
		vector<int> PCM;

		for (int i = 0; i < N; ++i){

			cin >> H;
			PCM.push_back(H);
		}

		PCM.push_back(PCM[0]), PCM.push_back(PCM[1]);

		for (int i = 1; i <= N; ++i){

			if (PCM[i] > PCM[i - 1] && PCM[i] > PCM[i + 1] ||
				PCM[i] < PCM[i - 1] && PCM[i] < PCM[i + 1]){

				++peak;
			}			
		}

		cout << peak << endl;
	}
	
	return 0;
}
