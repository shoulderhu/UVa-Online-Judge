#include <iostream>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	int NC, pair[2], kace = 0;
	
	while (cin >> NC && NC != 0){
		
		map<int, set<int>> Map;
		
		for (int i = 1; i <= NC; ++i){

			cin >> pair[0] >> pair[1];
			Map[pair[0]].insert(pair[1]), Map[pair[1]].insert(pair[0]);
		}

		while (cin >> pair[0] >> pair[1] && !(pair[0] == 0 && pair[1] == 0)){
			
			set<int> isVisit;

			if(Map.find(pair[0])!=Map.end()){
				
				queue<int> Queue;				
				Queue.push(pair[0]);

				for (int i = 0; i <= pair[1]; ++i){
				
					int length = Queue.size();

					for (int j = 0; j < length; ++j){

						int temp = Queue.front();
						Queue.pop(), isVisit.insert(temp);

						for (auto iter = Map[temp].begin(); iter != Map[temp].end(); ++iter){

							if(isVisit.find(*iter)==isVisit.end()){Queue.push(*iter);}
						}
					}
				}
			}
						
			cout << "Case " << ++kace << ": " << Map.size() - isVisit.size() << " nodes not reachable from node " << pair[0] << " with TTL = " << pair[1] << "." << endl;
		}
	}

	return 0;
}