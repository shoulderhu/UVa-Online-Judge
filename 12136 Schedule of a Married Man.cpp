#include <iostream>
#include <string>

using namespace std;

struct time { int hh[2], mm[2]; } wife, meeting;

bool isHit(struct time &w, struct time &m) {

	for (int i = 0; i < 2; ++i) {
		
		if (((m.hh[i] == w.hh[0] && m.mm[i] >= w.mm[0]) || m.hh[i] > w.hh[0]) &&
			((m.hh[i] == w.hh[1] && m.mm[i] <= w.mm[1]) || m.hh[i] < w.hh[1])) {

			return false;
		}
	}
	
	if (((m.hh[0] == w.hh[0] && m.mm[0] <= w.mm[0]) || m.hh[0] < w.hh[0]) &&
		((m.hh[1] == w.hh[1] && m.mm[1] >= w.mm[1]) || m.hh[1] > w.hh[1])) {

		return false;
	}

	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;	
	string begin, end;

	cin >> N;

	for (int i = 1; i <= N; ++i) {

		cin >> begin >> end;
		wife.hh[0] = stoi(begin.substr(0, 2), nullptr, 10);
		wife.mm[0] = stoi(begin.substr(3, 2), nullptr, 10);
		wife.hh[1] = stoi(end.substr(0, 2), nullptr, 10);
		wife.mm[1] = stoi(end.substr(3, 2), nullptr, 10);
		
		cin >> begin >> end;
		meeting.hh[0] = stoi(begin.substr(0, 2), nullptr, 10);
		meeting.mm[0] = stoi(begin.substr(3, 2), nullptr, 10);
		meeting.hh[1] = stoi(end.substr(0, 2), nullptr, 10);
		meeting.mm[1] = stoi(end.substr(3, 2), nullptr, 10);

		cout << "Case " << i << ": ";
		isHit(wife, meeting) == true ? cout << "Hits" : cout << "Mrs";
		cout << " Meeting" << endl; 
	}
	
	return 0;
}