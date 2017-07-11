#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int b, w;
bool black, white;
string Black[5], White[5];

int Face(char &c) {

	switch (c) {

	case '2': return 2; break;
	case '3': return 3; break;
	case '4': return 4; break;
	case '5': return 5; break;
	case '6': return 6; break;
	case '7': return 7; break;
	case '8': return 8; break;
	case '9': return 9; break;
	case 'T': return 10; break;
	case 'J': return 11; break;
	case 'Q': return 12; break;
	case 'K': return 13; break;
	case 'A': return 14; break;
	}
}

inline bool mySort(string &a, string &b) { return Face(a[0]) < Face(b[0]); }

char Rank() {

	if (black && white) {

		if (b > w) { return 'B'; }
		if (b < w) { return 'W'; }

		return 'T'; 
	}
	if (black) { return 'B'; }
	if (white) { return 'W'; }

	return 'N'; 
}

void Win(char &win) {

	switch (win) {
	case 'B': cout << "Black wins." << endl; break;
	case 'W': cout << "White wins." << endl; break;
	case 'T': cout << "Tie." << endl; break;
	}
}

char StraightFlush() {

	black = true, white = true;

	for (int i = 1; i < 5; ++i) {

		if (Black[i][1] != Black[i - 1][1] || 
			Face(Black[i][0]) - Face(Black[i - 1][0]) != 1) {
			
			black = false; 
			break; 
		}
	}

	for (int i = 1; i < 5; ++i) {

		if (White[i][1] != White[i - 1][1] || 
			Face(White[i][0]) - Face(White[i - 1][0]) != 1) {

			white = false;
			break;
		}
	}
		
	if (black) { b = Face(Black[4][0]); }
	if (White) { w = Face(White[4][0]); }
	
	return Rank();
}

char FourOfAKind() {
	
	if ((Black[0][0] == Black[1][0] && Black[1][0] == Black[2][0] && Black[2][0] == Black[3][0]) ||
		(Black[1][0] == Black[2][0] && Black[2][0] == Black[3][0] && Black[3][0] == Black[4][0])) {

		black = true, b = Face(Black[1][0]);
	}
	else { black = false; }

	if ((White[0][0] == White[1][0] && White[1][0] == White[2][0] && White[2][0] == White[3][0]) ||
		(White[1][0] == White[2][0] && White[2][0] == White[3][0] && White[3][0] == White[4][0])) {

		white = true, w = Face(White[1][0]);
	}
	else { white = false; }

	return Rank();
}

char FullHouse() {
		
	if ((Black[0][0] == Black[1][0] && Black[1][0] == Black[2][0] && Black[3][0] == Black[4][0]) ||
		(Black[0][0] == Black[1][0] && Black[2][0] == Black[3][0] && Black[3][0] == Black[4][0])) {

		black = true, b = Face(Black[2][0]);
	}
	else { black = false; }

	if ((White[0][0] == White[1][0] && White[1][0] == White[2][0] && White[3][0] == White[4][0]) ||
		(White[0][0] == White[1][0] && White[2][0] == White[3][0] && White[3][0] == White[4][0])) {

		white = true, w = Face(White[2][0]);
	}
	else { white = false; }

	return Rank();
}

char HighCard() {

	for (int i = 4; i >= 0; --i) {

		if (Face(Black[i][0]) > Face(White[i][0])) { return 'B'; }
		if (Face(Black[i][0]) < Face(White[i][0])) { return 'W'; }
	}

	return 'T';
}

char Flush() {
	
	if (Black[0][1] == Black[1][1] && Black[1][1] == Black[2][1] && 
		Black[2][1] == Black[3][1] && Black[3][1] == Black[4][1]) {

		black = true, b = Face(Black[4][0]);
	}
	else { black = false; }

	if (White[0][1] == White[1][1] && White[1][1] == White[2][1] &&
		White[2][1] == White[3][1] && White[3][1] == White[4][1]) {

		white = true, w = Face(White[4][0]);
	}
	else { white = false; }

	
	if (black && white) { return HighCard(); }
	if (black) { return 'B'; }
	if (white) { return 'W'; }

	return 'N';
}

char Straight() {

	black = true, white = true;

	for (int i = 1; i < 5; ++i) {

		if (Face(Black[i][0]) - Face(Black[i - 1][0]) != 1) {

			black = false;
			break;
		}
	}

	for (int i = 1; i < 5; ++i) {

		if (Face(White[i][0]) - Face(White[i - 1][0]) != 1) {

			white = false;
			break;
		}
	}

	if (black) { b = Face(Black[4][0]); }
	if (white) { w = Face(White[4][0]); }

	return Rank();
}

char ThreeOfAKind() {

	if ((Black[0][0] == Black[1][0] && Black[1][0] == Black[2][0]) || 
		(Black[1][0] == Black[2][0] && Black[2][0] == Black[3][0]) ||
		(Black[2][0] == Black[3][0] && Black[3][0] == Black[4][0])) {

		black = true, b = Face(Black[2][0]);
	}
	else { black = false; }

	if ((White[0][0] == White[1][0] && White[1][0] == White[2][0]) ||
		(White[1][0] == White[2][0] && White[2][0] == White[3][0]) ||
		(White[2][0] == White[3][0] && White[3][0] == White[4][0])) {

		white = true, w = Face(White[2][0]);
	}
	else { white = false; }

	return Rank();
}

char Pairs() {

	int pairB = 0, pairW = 0;
	deque<int> b1, b2, w1, w2;

	for (int i = 1; i < 5; ++i) {

		if (Black[i][0] == Black[i - 1][0]) {

			b1.push_front(Face(Black[i][0]));
			++pairB, ++i;			
		}
		else { b2.push_front(Face(Black[i - 1][0])); }
	}

	for (int i = 1; i < 5; ++i) {

		if (White[i][0] == White[i - 1][0]) {

			w1.push_front(Face(White[i][0]));
			++pairW, ++i;
		}
		else{ w2.push_front(Face(White[i - 1][0])); }
	}

	if (pairB == 0 && pairW == 0) { return 'N'; }
	if (pairW == 0 || pairB > pairW) { return 'B'; }
	if (pairB == 0 || pairB < pairW) { return 'W'; }
	if (pairB == 2) {

		for (int i = 0; i < 2; ++i) {

			if (b1[i] > w1[i]) { return 'B'; }
			if (b1[i] < w1[i]) { return 'W'; }
		}

		if (b2.size() == 0) { b2.push_front(Face(Black[4][0])); }
		if (w2.size() == 0) { w2.push_front(Face(White[4][0])); }
		if (b2[0] > w2[0]) { return 'B'; }
		if (b2[0] < w2[0]) { return 'W'; }		
	}
	else {

		if (b1[0] > w1[0]) { return 'B'; }
		if (b1[0] < w1[0]) { return 'W'; }
		if (b2.size() == 2) { b2.push_front(Black[4][0]); }
		if (w2.size() == 2) { w2.push_front(White[4][0]); }

		for (int i = 0; i < 3; ++i) {

			if (b2[i] > w2[i]) { return 'B'; }
			if (b2[i] < w2[i]) { return 'W'; }
		}			
	}

	return 'T';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	char win;

	while (cin >> Black[0] >> Black[1] >> Black[2] >> Black[3] >> Black[4]
		       >> White[0] >> White[1] >> White[2] >> White[3] >> White[4]) {
		
		sort(Black, Black + 5, mySort), sort(White, White + 5, mySort);

		if ((win = StraightFlush()) != 'N') { Win(win); }
		else if ((win = FourOfAKind()) != 'N') { Win(win); }
		else if ((win = FullHouse()) != 'N') { Win(win); }
		else if ((win = Flush()) != 'N') { Win(win); }
		else if ((win = Straight()) != 'N') { Win(win); }
		else if ((win = ThreeOfAKind()) != 'N') { Win(win); }
		else if ((win = Pairs()) != 'N') { Win(win); }
		else { win = HighCard(), Win(win); }
	}

	return 0;
}