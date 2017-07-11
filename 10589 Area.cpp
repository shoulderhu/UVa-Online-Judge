#include <iostream>
#include <iomanip>

using namespace std;

int a;
double x, y;

inline bool upperLeft() { return x*x + (y - a)*(y - a) <= a*a; }

inline bool upperRight() { return (x - a)*(x - a) + (y - a)*(y - a) <= a*a; }

inline bool lowerLeft() { return x*x + y*y <= a*a; }

inline bool lowerRight() { return (x - a)*(x - a) + y*y <= a*a; }

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	
	while (cin >> N >> a && N != 0) {
		
		int M = 0;

		for (int i = 1; i <= N; ++i) {

			cin >> x >> y;

			if (upperLeft() == true && upperRight() == true && 
				lowerLeft() == true && lowerRight() == true) { ++M; }
		}

		cout << fixed << setprecision(5) << (double)M * a * a / N << endl;
	}

	return 0;
}