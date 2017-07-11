#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
		
	double x, y;
	struct side { double x[2], y[2]; }Side[2];

	while (cin >> Side[0].x[0] >> Side[0].y[0] >> Side[0].x[1] >> Side[0].y[1] >> Side[1].x[0] >> Side[1].y[0] >> Side[1].x[1] >> Side[1].y[1]) {

		if (Side[0].x[0] == Side[1].x[0] && Side[0].y[0] == Side[1].y[0]) {
		
			x = Side[0].x[1] + Side[1].x[1] - Side[0].x[0];
			y = Side[0].y[1] + Side[1].y[1] - Side[0].y[0];			
		}
		else if (Side[0].x[0] == Side[1].x[1] && Side[0].y[0] == Side[1].y[1]) {

			x = Side[0].x[1] + Side[1].x[0] - Side[0].x[0];
			y = Side[0].y[1] + Side[1].y[0] - Side[0].y[0];			
		}
		else if (Side[0].x[1] == Side[1].x[0] && Side[0].y[1] == Side[1].y[0]) {

			x = Side[0].x[0] + Side[1].x[1] - Side[0].x[1];
			y = Side[0].y[0] + Side[1].y[1] - Side[0].y[1];
		}
		else {

			x = Side[0].x[0] + Side[1].x[0] - Side[0].x[1];
			y = Side[0].y[0] + Side[1].y[0] - Side[0].y[1];
		}

		cout << fixed << setprecision(3) << x << " " << y << endl;
	}

	return 0;
}