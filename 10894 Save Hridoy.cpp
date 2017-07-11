#include <iostream>

using namespace std;

void Y(int N, char orientation, int row) {

	if (row == 0) {

		for (int k = 0; k < N; ++k) { cout << "*"; }
		for (int k = 0; k < N; ++k) { cout << "..."; }
		for (int k = 0; k < N; ++k) { cout << "*"; }
	}
	else if (row == 1) {

		for (int k = 0; k < N; ++k) { cout << "."; }
		for (int k = 0; k < N; ++k) { cout << "*"; }
		for (int k = 0; k < N; ++k) { cout << "."; }
		for (int k = 0; k < N; ++k) { cout << "*"; }
		for (int k = 0; k < N; ++k) { cout << "."; }
	}
	else {

		for (int k = 0; k < N; ++k) { cout << ".."; }
		for (int k = 0; k < N; ++k) { cout << "*"; }
		for (int k = 0; k < N; ++k) { cout << ".."; }
	}

	cout << endl;
}

void O(int N, char orientation, int row) {

	if (row == 0 || row == 4) {

		for (int k = 0; k < N; ++k) { cout << "*****"; }
	}
	else {

		for (int k = 0; k < N; ++k) { cout << "*"; }
		for (int k = 0; k < N; ++k) { cout << "..."; }
		for (int k = 0; k < N; ++k) { cout << "*"; }
	}

	if (orientation == 'h') {

		for (int i = 0; i < N; ++i) { cout << "."; }
		Y(N, orientation, row);
	}
	else { cout << endl; }
}

void D(int N, char orientation, int row) {

	if (row == 0 || row == 4) {

		for (int k = 0; k < N; ++k) { cout << "***"; }
		for (int k = 0; k < N; ++k) { cout << ".."; }
	}
	else if (row == 1 || row == 3) {

		for (int k = 0; k < N; ++k) { cout << "*"; }
		for (int k = 0; k < N; ++k) { cout << ".."; }
		for (int k = 0; k < N; ++k) { cout << "*"; }
		for (int k = 0; k < N; ++k) { cout << "."; }
	}
	else {

		for (int k = 0; k < N; ++k) { cout << "*"; }
		for (int k = 0; k < N; ++k) { cout << "..."; }
		for (int k = 0; k < N; ++k) { cout << "*"; }
	}

	if (orientation == 'h') {

		for (int i = 0; i < N; ++i) { cout << "."; }
		O(N, orientation, row);
	}
	else { cout << endl; }
}

void I(int N, char orientation, int row) {

	if (row == 0 || row == 4) {

		for (int k = 0; k < N; ++k) { cout << "*****"; }
	}
	else {

		for (int k = 0; k < N; ++k) { cout << ".."; }
		for (int k = 0; k < N; ++k) { cout << "*"; }
		for (int k = 0; k < N; ++k) { cout << ".."; }
	}

	if (orientation == 'h') {

		for (int i = 0; i < N; ++i) { cout << "."; }
		D(N, orientation, row);
	}
	else { cout << endl; }
}

void R(int N, char orientation, int row) {

	if (row == 0 || row == 2) {

		for (int k = 0; k < N; ++k) { cout << "*****"; }
	}
	else if (row == 1) {

		for (int k = 0; k < N; ++k) { cout << "*"; }
		for (int k = 0; k < N; ++k) { cout << "..."; }
		for (int k = 0; k < N; ++k) { cout << "*"; }
	}
	else if (row == 3) {

		for (int k = 0; k < N; ++k) { cout << "*"; }
		for (int k = 0; k < N; ++k) { cout << "."; }
		for (int k = 0; k < N; ++k) { cout << "*"; }
		for (int k = 0; k < N; ++k) { cout << ".."; }
	}
	else {

		for (int k = 0; k < N; ++k) { cout << "*"; }
		for (int k = 0; k < N; ++k) { cout << ".."; }
		for (int k = 0; k < N; ++k) { cout << "**"; }
	}

	if (orientation == 'h') {

		for (int i = 0; i < N; ++i) { cout << "."; }
		I(N, orientation, row);
	}
	else { cout << endl; }
}

void H(int N, char orientation, int row) {

	if (row == 0 || row == 1 || row == 3 || row == 4) {

		for (int k = 0; k < N; ++k) { cout << "*"; }
		for (int k = 0; k < N; ++k) { cout << "..."; }
		for (int k = 0; k < N; ++k) { cout << "*"; }
	}
	else {

		for (int k = 0; k < N; ++k) { cout << "*****"; }
	}

	if (orientation == 'h') {

		for (int i = 0; i < N; ++i) { cout << "."; }
		R(N, orientation, row);
	}
	else { cout << endl; }
}

void E(int N, char orientation, int row) {

	if (row == 0 || row == 4) {

		for (int k = 0; k < N; ++k) { cout << "*****"; }

	}
	else if (row == 1 || row == 3) {

		for (int k = 0; k < N; ++k) { cout << "*"; }
		for (int k = 0; k < N; ++k) { cout << "...."; }
	}
	else {

		for (int k = 0; k < N; ++k) { cout << "***"; }
		for (int k = 0; k < N; ++k) { cout << ".."; }
	}

	if (orientation == 'h') {

		for (int i = 0; i < N; ++i) { cout << "..."; }
		H(N, orientation, row);
	}
	else { cout << endl; }
}

void V(int N, char orientation, int row) {

	if (row == 0 || row == 1 || row == 2) {

		for (int k = 0; k < N; ++k) { cout << "*"; }
		for (int k = 0; k < N; ++k) { cout << "..."; }
		for (int k = 0; k < N; ++k) { cout << "*"; }
	}
	else if (row == 3) {

		for (int k = 0; k < N; ++k) { cout << "."; }
		for (int k = 0; k < N; ++k) { cout << "*"; }
		for (int k = 0; k < N; ++k) { cout << "."; }
		for (int k = 0; k < N; ++k) { cout << "*"; }
		for (int k = 0; k < N; ++k) { cout << "."; }
	}
	else {

		for (int k = 0; k < N; ++k) { cout << ".."; }
		for (int k = 0; k < N; ++k) { cout << "*"; }
		for (int k = 0; k < N; ++k) { cout << ".."; }
	}

	if (orientation == 'h') {

		for (int i = 0; i < N; ++i) { cout << "."; }
		E(N, orientation, row);
	}
	else { cout << endl; }
}

void A(int N, char orientation, int row) {

	if (row == 0) {

		for (int k = 0; k < N; ++k) { cout << "."; }
		for (int k = 0; k < N; ++k) { cout << "***"; }
		for (int k = 0; k < N; ++k) { cout << "."; }
	}
	else if (row == 1 || row == 3 || row == 4) {

		for (int k = 0; k < N; ++k) { cout << "*"; }
		for (int k = 0; k < N; ++k) { cout << "..."; }
		for (int k = 0; k < N; ++k) { cout << "*"; }
	}
	else {

		for (int k = 0; k < N; ++k) { cout << "*****"; }
	}

	if (orientation == 'h') {

		for (int i = 0; i < N; ++i) { cout << "."; }
		V(N, orientation, row);
	}
	else { cout << endl; }
}

void S(int N, char orientation) {

	for (int i = 0; i < 5; ++i) {

		for (int j = 0; j < N; ++j) {

			if (i == 0 || i == 2 || i == 4) {

				for (int k = 0; k < N; ++k) { cout << "*****"; }
			}
			else if (i == 1) {

				for (int k = 0; k < N; ++k) { cout << "*"; }
				for (int k = 0; k < N; ++k) { cout << "...."; }
			}
			else {

				for (int k = 0; k < N; ++k) { cout << "...."; }
				for (int k = 0; k < N; ++k) { cout << "*"; }
			}

			if (orientation == 'h') {

				for (int i = 0; i < N; ++i) { cout << "."; }
				A(N, orientation, i);
			}
			else { cout << endl; }
		}
	}

	if (orientation == 'v') {

		for (int j = 0; j < N; ++j) {

			for (int i = 0; i < N; ++i) { cout << "....."; }
			cout << endl;
		}
		
		for (int i = 0; i < 5; ++i) {

			for (int j = 0; j < N; ++j) {

				A(N, orientation, i);
			}
		}

		for (int j = 0; j < N; ++j) {

			for (int i = 0; i < N; ++i) { cout << "....."; }
			cout << endl;
		}

		for (int i = 0; i < 5; ++i) {

			for (int j = 0; j < N; ++j) {

				V(N, orientation, i);
			}
		}

		for (int j = 0; j < N; ++j) {

			for (int i = 0; i < N; ++i) { cout << "....."; }
			cout << endl;
		}

		for (int i = 0; i < 5; ++i) {

			for (int j = 0; j < N; ++j) {

				E(N, orientation, i);
			}
		}
		
		for (int k = 0; k < N; ++k) {

			for (int j = 0; j < 3; ++j) {

				for (int i = 0; i < N; ++i) { cout << "....."; }
				cout << endl;
			}
		}		

		for (int i = 0; i < 5; ++i) {

			for (int j = 0; j < N; ++j) {

				H(N, orientation, i);
			}
		}

		for (int j = 0; j < N; ++j) {

			for (int i = 0; i < N; ++i) { cout << "....."; }
			cout << endl;
		}

		for (int i = 0; i < 5; ++i) {

			for (int j = 0; j < N; ++j) {

				R(N, orientation, i);
			}
		}

		for (int j = 0; j < N; ++j) {

			for (int i = 0; i < N; ++i) { cout << "....."; }
			cout << endl;
		}

		for (int i = 0; i < 5; ++i) {

			for (int j = 0; j < N; ++j) {

				I(N, orientation, i);
			}
		}

		for (int j = 0; j < N; ++j) {

			for (int i = 0; i < N; ++i) { cout << "....."; }
			cout << endl;
		}

		for (int i = 0; i < 5; ++i) {

			for (int j = 0; j < N; ++j) {

				D(N, orientation, i);
			}
		}

		for (int j = 0; j < N; ++j) {

			for (int i = 0; i < N; ++i) { cout << "....."; }
			cout << endl;
		}

		for (int i = 0; i < 5; ++i) {

			for (int j = 0; j < N; ++j) {

				O(N, orientation, i);
			}
		}

		for (int j = 0; j < N; ++j) {

			for (int i = 0; i < N; ++i) { cout << "....."; }
			cout << endl;
		}

		for (int i = 0; i < 5; ++i) {

			for (int j = 0; j < N; ++j) {

				Y(N, orientation, i);
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;

	while (cin >> N && N != 0) {

		N > 0 ? S(N, 'h') : S(N*-1, 'v');
		cout << endl << endl;
	}

	return 0;
}
