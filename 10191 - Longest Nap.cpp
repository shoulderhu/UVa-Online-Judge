#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
ofstream ofs("out.txt", ios::out);


int main() {

	ios::sync_with_stdio(false);

	int day = 0, s, start, last, end;
	struct time { int time1, time2; }T[100];
	string line, time1, time2;
	stringstream ss;

	while (cin >> s) {

		cin.ignore();

		for (int i = 0; i < s; ++i) {

			getline(cin, line);
			ss.str(""), ss << line, ss >> time1 >> time2;
			T[i].time1 = ((time1[0] - '0') * 10 + (time1[1] - '0')) * 60 +
				(time1[3] - '0') * 10 + (time1[4] - '0');
			T[i].time2 = ((time2[0] - '0') * 10 + (time2[1] - '0')) * 60 +
				(time2[3] - '0') * 10 + (time2[4] - '0');
		}


		T[s].time1 = 1080, T[s].time2 = 1080;

		sort(T, T + s + 1, [](struct time &a, struct time &b) {

			return a.time1 < b.time1;
		});

		start = 600, end = 600, last = 0;

		for (int i = 0; i <= s; i++) {

			while (T[i].time1 < end) {

				end = max(end, T[i].time2), ++i;
			}

			if (T[i].time1 - end > last) {

				start = end;
				last = T[i].time1 - end;
			}

			end = T[i].time2;
		}

		ofs << "Day #" << ++day << ": the longest nap starts at "			<< setw(2) << setfill('0') << start / 60 << ":"			<< setw(2) << setfill('0') << start % 60			<< " and will last for ";		if (last >= 60) { ofs << last / 60 << " hours and "; }		ofs << last % 60 << " minutes." << endl;
	}

	return 0;
}