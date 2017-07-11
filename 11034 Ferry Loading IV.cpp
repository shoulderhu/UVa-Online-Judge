#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	int c, m;
	double l, length;
	string bank;
		
	cin >> c;

	for (int i = 1; i <= c; ++i){
	
		cin >> l >> m;

		int time = 0;
		queue<double> left, right;

		for (int j = 1; j <= m; ++j){
		
			cin >> length >> bank;
			length /= 100;
			bank == "left" ? left.push(length) : right.push(length);
		}	

		while (true){

			double L = l;
			
			while (left.empty() == false && L >= left.front()){
				
				L -= left.front(), left.pop(); 
			}

			++time;
			if (left.empty() == true && right.empty() == true){ break; }
			else{ L = l; }
			
			while (right.empty() == false && L >= right.front()){
				
				L -= right.front(), right.pop();				
			}

			++time;
			if (left.empty() == true && right.empty() == true){ break; }
		}

		cout << time << endl;
	}

	return 0;
}