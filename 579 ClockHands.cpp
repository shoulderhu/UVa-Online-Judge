#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	int H, M;
	double degree;
	string time;
	
	while (cin >> time && time != "0:00") {

		if (time.size() == 4) {

			H = stoi(time.substr(0, 1), nullptr, 10);
			M = stoi(time.substr(2, 2), nullptr, 10);
		}
		else{
		
			H = stoi(time.substr(0, 2), nullptr, 10);
			M = stoi(time.substr(3, 2), nullptr, 10);
		}
		
		if (H > 6) { degree = (12 - H) * 30 + M * 5.5; }
		else { degree = H * 30 - M * 5.5; }

		if (degree >= 360) { degree -= 360; }
		else if (degree < 0) { degree += 360; }
		
		cout << fixed << setprecision(3) << min(degree, 360 - degree) << endl;
	}
	
	return 0;
}