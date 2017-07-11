#include <iostream>
#include <set>
#include <vector>
#include <deque>

using namespace std;

int total;

inline bool Combo1(deque<int> &Queue){

	total = Queue.front() + Queue[1] + Queue.back();
	return total == 10 || total == 20 || total == 30;
}

inline bool Combo2(deque<int> &Queue) {

	total = Queue.front() + Queue[Queue.size() - 2] + Queue.back();
	return total == 10 || total == 20 || total == 30;
}

inline bool Combo3(deque<int> &Queue){

	total = Queue[Queue.size() - 3] + Queue[Queue.size() - 2] + Queue.back();
	return total == 10 || total == 20 || total == 30;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
		
	int d;
	set<vector<int>> Set;
	
	while (cin >> d && d) {

		int delt = 14;		
		deque<int> Deck(52), Queue[7];
				
		Deck[0] = d, Set.clear();
		for (int i = 1; i < 52; ++i) { cin >> Deck[i]; }

		for (int i = 0; i < 2; ++i) {

			for (int j = 0; j < 7; ++j) {

				Queue[j].push_back(Deck.front());
				Deck.pop_front();
			}
		}

		for (int i = 0; ; ++i) {

			if (i == 7) { i = 0; }
			if (Queue[i].empty()) { continue; }
			
			Queue[i].push_back(Deck.front()), Deck.pop_front(), ++delt;
			
			bool isCombo = true;

			while (Queue[i].size() > 2 && isCombo) {

				isCombo = false;

				if (Combo1(Queue[i])) {

					Deck.push_back(Queue[i].front()), Queue[i].pop_front();
					Deck.push_back(Queue[i].front()), Queue[i].pop_front();
					Deck.push_back(Queue[i].back()), Queue[i].pop_back();
					isCombo = true;
				}
				else if (Combo2(Queue[i])) {

					Deck.push_back(Queue[i].front()), Queue[i].pop_front();
					Deck.push_back(Queue[i][Queue[i].size() - 2]);
					Deck.push_back(Queue[i].back());
					Queue[i].pop_back(), Queue[i].pop_back();
					isCombo = true;
				}
				else if (Combo3(Queue[i])) {

					Deck.push_back(Queue[i][Queue[i].size() - 3]);
					Deck.push_back(Queue[i][Queue[i].size() - 2]);
					Deck.push_back(Queue[i].back());
					Queue[i].pop_back(), Queue[i].pop_back(), Queue[i].pop_back();
					isCombo = true;
				}
			}
									
			if (Deck.size() == 52) { cout << "Win : " << delt << endl; break; }
			else if (Deck.empty()) { cout << "Loss: " << delt << endl; break; }
			else { 
				
				vector<int> Vec(Deck.begin(), Deck.end());

				for (int i = 0; i < 7; ++i) {

					Vec.push_back(0);
					Vec.insert(Vec.end(), Queue[i].begin(), Queue[i].end());
				}

				if (Set.find(Vec) == Set.end()) { Set.insert(Vec); }
				else { cout << "Draw: " << delt << endl; break; }
			}
		}			
	}

	return 0;
}