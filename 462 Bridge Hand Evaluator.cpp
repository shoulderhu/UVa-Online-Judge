#include <iostream>
#include <string>
#include <set>

using namespace std;

void rule2(set<char> &suit, int &point) {

	if (suit.find('K') != suit.end() && suit.size() == 1) { --point; }
}

void rule3(set<char> &suit, int &point) {

	if (suit.find('Q') != suit.end() && suit.size() <= 2) { --point; }
}

void rule4(set<char> &suit, int &point) {

	if (suit.find('J') != suit.end() && suit.size() <= 3) { --point; }
}

void rule567(set<char> &suit, int & noTrump) {

	switch (suit.size()) {

	case 0:
	case 1: noTrump += 2; break;
	case 2: ++noTrump; break;
	}
}

bool isStopped(set<char> &suit) {

	if (suit.find('A') != suit.end()) { return true; }
	if (suit.find('K') != suit.end() && suit.size() >= 2) { return true; }
	if (suit.find('Q') != suit.end() && suit.size() >= 3) { return true; }

	return false;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
		
	string card;
	
	while (cin >> card) {

		int point = 0;
		set<char> S, H, D, C;

		switch (card[0]) {

		case 'A': point += 4; break;
		case 'K': point += 3; break;
		case 'Q': point += 2; break;
		case 'J': point += 1; break;
		}

		switch (card[1]) {

		case 'S': S.insert(card[0]); break;
		case 'H': H.insert(card[0]); break;
		case 'D': D.insert(card[0]); break;
		case 'C': C.insert(card[0]); break;
		}

		for (int i = 1; i < 13; ++i) {

			cin >> card;

			switch (card[0]) {

			case 'A': point += 4; break;
			case 'K': point += 3; break;
			case 'Q': point += 2; break;
			case 'J': point += 1; break;
			}

			switch (card[1]) {

			case 'S': S.insert(card[0]); break;
			case 'H': H.insert(card[0]); break;
			case 'D': D.insert(card[0]); break;
			case 'C': C.insert(card[0]); break;
			}		
		}

		rule2(S, point), rule2(H, point), rule2(D, point), rule2(C, point);
		rule3(S, point), rule3(H, point), rule3(D, point), rule3(C, point);
		rule4(S, point), rule4(H, point), rule4(D, point), rule4(C, point);
		
		if (point >= 16 && isStopped(S) == true && isStopped(H) == true
		             	&& isStopped(D) == true && isStopped(C) == true) {

			cout << "BID NO-TRUMP" << endl;
			continue;
		}

		int noTrump = point;
		rule567(S, noTrump), rule567(H, noTrump);
		rule567(D, noTrump), rule567(C, noTrump);
		
		if (noTrump < 14) { cout << "PASS" << endl; }		
		else { 
			
			int max = 0;

			if (S.size() > max) { max = S.size(); }
			if (H.size() > max) { max = H.size(); }
			if (D.size() > max) { max = D.size(); }
			if (C.size() > max) { max = C.size(); }
			
			cout << "BID ";
			if (max == S.size()) { cout << "S" << endl; continue; }
			if (max == H.size()) { cout << "H" << endl; continue; }
			if (max == D.size()) { cout << "D" << endl; continue; }
			if (max == C.size()) { cout << "C" << endl; continue; }
		}
	}

	return 0;
}
