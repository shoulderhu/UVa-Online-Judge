#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	bool isVisit[9][9];
	string from, to;
	
	while (cin >> from >> to){
				
		for (int i = 1; i < 9; ++i){
		
			for (int j = 1; j < 9; ++j){
			
				isVisit[i][j] = false;
			}
		}

		int toX = (int)to[0] - 96, toY = to[1] - '0';
		bool isFound = false;
		struct xy{ int x, y; }XY;
		queue<struct xy> Move;

		XY.x = (int)from[0] - 96, XY.y = from[1] - '0';
		Move.push(XY);
		
		for (int i = 0; ; ++i){

			int length = Move.size();

			for (int j = 1; j <= length; ++j){

				struct xy temp = Move.front();
				Move.pop();

				if (temp.x > 0 && temp.y > 0 && temp.x < 9 && temp.y < 9 && isVisit[temp.x][temp.y] == false){

					if (temp.x == toX && temp.y == toY){

						cout << "To get from " << from << " to " << to << " takes " << i << " knight moves.\n";
						isFound = true; break;
					}
					else{

						isVisit[temp.x][temp.y] = true;
						XY.x = temp.x - 2, XY.y = temp.y - 1, Move.push(XY);
						XY.x = temp.x - 1, XY.y = temp.y - 2, Move.push(XY);
						XY.x = temp.x + 1, XY.y = temp.y - 2, Move.push(XY);
						XY.x = temp.x + 2, XY.y = temp.y - 1, Move.push(XY);
						XY.x = temp.x + 2, XY.y = temp.y + 1, Move.push(XY);
						XY.x = temp.x + 1, XY.y = temp.y + 2, Move.push(XY);
						XY.x = temp.x - 1, XY.y = temp.y + 2, Move.push(XY);
						XY.x = temp.x - 2, XY.y = temp.y + 1, Move.push(XY);
					}
				}
			}

			if (isFound == true){ break; }
		}
	}

	return 0;
}