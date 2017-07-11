#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char board[8][8];

bool UP(int &x, int &y, int &isLower, int end) {

	if (x - 1 < 0) { return false; }

	for (int i = x - 1; i >= end; --i) {

		if (board[i][y] != '.') {

			if ((board[i][y] == 'k' || board[i][y] == 'K') && 
				(isLower && isupper(board[i][y]) || !isLower && islower(board[i][y]))) {

				 return true;				
			}
			else { return false; }
		}		
	}

	return false;
}

bool DOWN(int &x, int &y, int &isLower, int end) {

	if (x + 1 > 7) { return false; }

	for (int i = x + 1; i < end; ++i) {

		if (board[i][y] != '.') {

			if ((board[i][y] == 'k' || board[i][y] == 'K') && 
				(isLower && isupper(board[i][y]) || !isLower && islower(board[i][y]))) {

				return true; 				
			}
			else { return false; }
		}
	}

	return false;
}

bool LEFT(int &x, int &y, int &isLower, int end) {

	if (y - 1 < 0) { return false; }

	for (int i = y - 1; i >= end; --i) {

		if (board[x][i] != '.') {

			if ((board[x][i] == 'k' || board[x][i] == 'K') &&
				(isLower && isupper(board[x][i]) || !isLower && islower(board[x][i]))) {

				 return true;				
			}
			else { return false; }
		}
	}

	return false;
}

bool RIGHT(int &x, int &y, int &isLower, int end) {

	if (y + 1 > 7) { return false; }

	for (int i = y + 1; i < end; ++i) {

		if (board[x][i] != '.') {

			if ((board[x][i] == 'k' || board[x][i] == 'K') &&
				(isLower && isupper(board[x][i]) || !isLower && islower(board[x][i]))) {

				return true; 				
			}
			else { return false; }
		}
	}

	return false;
}

bool UPLEFT(int &x, int &y, int &isLower, int endX, int endY) {

	if (x - 1 < 0 || y - 1 < 0) { return false; }

	for (int i = x - 1, j = y - 1; i >= endX && j >= endY; --i, --j) {

		if (board[i][j] != '.') {

			if ((board[i][j] == 'k' || board[i][j] == 'K') && 
				(isLower && isupper(board[i][j]) || !isLower && islower(board[i][j]))) {

				return true; 				
			}
			else { return false; }
		}
	}

	return false;
}

bool UPRIGHT(int &x, int &y, int &isLower, int endX, int endY) {

	if (x - 1 < 0 || y + 1 > 7) { return false; }

	for (int i = x - 1, j = y + 1; i >= endX && j < endY; --i, ++j) {

		if (board[i][j] != '.') {

			if ((board[i][j] == 'k' || board[i][j] == 'K') &&
				(isLower && isupper(board[i][j]) || !isLower && islower(board[i][j]))) {

				return true;
			}
			else { return false; }
		}
	}

	return false;
}

bool DOWNLEFT(int &x, int &y, int &isLower, int endX, int endY) {

	if (x + 1 > 7 || y - 1 < 0) { return false; }

	for (int i = x + 1, j = y - 1; i < endX && j >= endY; ++i, --j) {

		if (board[i][j] != '.') {

			if ((board[i][j] == 'k' || board[i][j] == 'K') &&
				(isLower && isupper(board[i][j]) || !isLower && islower(board[i][j]))) {

				return true;
			}
			else { return false; }
		}
	}

	return false;
}

bool DOWNRIGHT(int &x, int &y, int &isLower, int endX, int endY) {

	if (x + 1 > 7 || y + 1 > 7) { return false; }

	for (int i = x + 1, j = y + 1; i < endX && j < endY; ++i, ++j) {

		if (board[i][j] != '.') {

			if ((board[i][j] == 'k' || board[i][j] == 'K') &&
				(isLower && isupper(board[i][j]) || !isLower && islower(board[i][j]))) {

				return true;
			}
			else { return false; }
		}
	}

	return false;
}

bool isPawn(int &x, int &y, int &isLower) {

	if (isLower) {

		if (DOWNLEFT(x, y, isLower, x + 2, y - 1) || 
			DOWNRIGHT(x, y, isLower, x + 2, y + 2)) {

			return true;
		}		
	}
	else {

		if (UPLEFT(x, y, isLower, x - 1, y - 1) ||
			UPRIGHT(x, y, isLower, x - 1, y + 2)) {

			return true;
		}
	}

	return false;
}

bool isKnight(int &x, int &y, int &isLower) {

	if (x - 2 >= 0) {

		if (y - 1 >= 0) {

			if ((board[x - 2][y - 1] == 'k' || board[x - 2][y - 1] == 'K') &&
				(isLower && isupper(board[x - 2][y - 1]) || !isLower && islower(board[x - 2][y - 1]))) {

				return true;
			}
		}
		if (y + 1 < 8) {

			if ((board[x - 2][y + 1] == 'k' || board[x - 2][y + 1] == 'K') &&
				(isLower && isupper(board[x - 2][y + 1]) || !isLower && islower(board[x - 2][y + 1]))) {

				return true;
			}
		}	
	}

	if (x + 2 < 8) {

		if (y - 1 >= 0) {

			if ((board[x + 2][y - 1] == 'k' || board[x + 2][y - 1] == 'K') &&
				(isLower && isupper(board[x + 2][y - 1]) || !isLower && islower(board[x + 2][y - 1]))) {

				return true;
			}
		}
		if (y + 1 < 8) {

			if ((board[x + 2][y + 1] == 'k' || board[x + 2][y + 1] == 'K') &&
				(isLower && isupper(board[x + 2][y + 1]) || !isLower && islower(board[x + 2][y + 1]))) {

				return true;
			}
		}
	}

	if (y - 2 >= 0) {

		if (x - 1 >= 0) {

			if ((board[x - 1][y - 2] == 'k' || board[x - 1][y - 2] == 'K') &&
				(isLower && isupper(board[x - 1][y - 2]) || !isLower && islower(board[x - 1][y - 2]))) {

				return true;
			}
		}
		if (x + 1 < 8) {

			if ((board[x + 1][y - 2] == 'k' || board[x + 1][y - 2] == 'K') &&
				(isLower && isupper(board[x + 1][y - 2]) || !isLower && islower(board[x + 1][y - 2]))) {

				return true;
			}
		}
	}

	if (y + 2 < 8) {

		if (x - 1 >= 0) {

			if ((board[x - 1][y + 2] == 'k' || board[x - 1][y + 2] == 'K') &&
				(isLower && isupper(board[x - 1][y + 2]) || !isLower && islower(board[x - 1][y + 2]))) {

				return true;
			}
		}
		if (x + 1 < 8) {

			if ((board[x + 1][y + 2] == 'k' || board[x + 1][y + 2] == 'K') &&
				(isLower && isupper(board[x + 1][y + 2]) || !isLower && islower(board[x + 1][y + 2]))) {

				return true;
			}
		}
	}

	return false;
}

bool isBishop(int &x, int &y, int &isLower) {

	if (UPLEFT(x, y, isLower, 0, 0) || 
		UPRIGHT(x, y, isLower, 0, 8) || 
		DOWNLEFT(x, y, isLower, 8, 0) ||
		DOWNRIGHT(x, y, isLower, 8, 8)) {

		return true;
	}
	else { return false; }
}

bool isRook(int &x, int &y, int &isLower) {
	
	if (UP(x, y, isLower, 0) || 
		DOWN(x, y, isLower, 8) || 
		LEFT(x, y, isLower, 0) ||
		RIGHT(x, y, isLower, 8)) {

		return true;
	}
	else { return false; }
}

bool isQueen(int &x, int &y, int &isLower) {

	if (UP(x, y, isLower, 0) ||
		DOWN(x, y, isLower, 8) ||
		LEFT(x, y, isLower, 0) ||
		RIGHT(x, y, isLower, 8) ||
		UPLEFT(x, y, isLower, 0, 0) ||
		UPRIGHT(x, y, isLower, 0, 8) ||
		DOWNLEFT(x, y, isLower, 8, 0) ||
		DOWNRIGHT(x, y, isLower, 8, 8)) {

		return true;
	}
	else { return false; }
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int game = 0, isLower;	
	string line;

	while (true) {

		bool isWhite = false, isBlack = false;
		string empty;

		for (int i = 0; i < 8; ++i) {

			cin >> line;

			empty += line;
			for (int j = 0; j < 8; ++j) { board[i][j] = line[j]; }
		}

		if (empty == "................................................................") { break; }

		cout << "Game #" << ++game << ": ";

		for (int i = 0; i < 8 && isBlack == false && isWhite == false; ++i) {

			for (int j = 0; j < 8; ++j) {
								
				if (board[i][j] == 'p' || board[i][j] == 'P') {
					
					isLower = islower(board[i][j]);

					if (isPawn(i, j, isLower)) {
					
						isLower ? isWhite = true : isBlack = true;
						break;
					}
				}				
				else if (board[i][j] == 'n' || board[i][j] == 'N') {
					
					isLower = islower(board[i][j]);

					if (isKnight(i, j, isLower)) {

						isLower ? isWhite = true : isBlack = true;
						break;
					}
				}				
				else if (board[i][j] == 'b' || board[i][j] == 'B') {

					isLower = islower(board[i][j]);

					if (isBishop(i, j, isLower)) {

						isLower ? isWhite = true : isBlack = true;
						break;
					}
				}				
				else if (board[i][j] == 'r' || board[i][j] == 'R') {
					
					isLower = islower(board[i][j]);

					if (isRook(i, j, isLower)) {

						isLower ? isWhite = true : isBlack = true;
						break;
					}
				}				
				else if (board[i][j] == 'q' || board[i][j] == 'Q') {

					isLower = islower(board[i][j]);

					if (isQueen(i, j, isLower)) {

						isLower ? isWhite = true : isBlack = true;
						break;
					}
				}								
			}
		}

		if (isBlack) { cout << "black king is in check." << endl; }
		else if (isWhite) { cout << "white king is in check." << endl; }
		else { cout << "no king is in check." << endl; }		
	}

	return 0;
}