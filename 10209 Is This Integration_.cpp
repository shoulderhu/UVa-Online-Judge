#include <iostream>
#include <iomanip>
#include <cmath>
#define PI acos(-1.0)

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	double a;

	while (cin >> a) {
		
		double square = a*a, sector = square*PI / 4; 
		double bullet = square*(PI / 3 - sqrt(3.0) / 4); 
		double rest = square + bullet - 2 * sector;
		double dot = sector - bullet - rest;
		double stripe = bullet - rest - 2 * dot;
		
		cout << fixed << setprecision(3) << stripe << " " << 4 * dot 
			                                       << " " << 4 * rest << endl;
	}

	return 0;
}