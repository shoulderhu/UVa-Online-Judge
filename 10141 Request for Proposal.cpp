#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
struct proposal {

	double d, r;
	string name;
}Proposal;

bool mySort(struct proposal a, struct proposal b) {

	double complianceA = a.r / n, complianceB = b.r / n;

	if (complianceA != complianceB) { return complianceA > complianceB; }
	else if (a.d != b.d) { return a.d < b.d; }
	else { return false; }
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int p, RFP = 0;
	bool isBlank = false;	
	string requirement;
	
	while (cin >> n >> p && !(n == 0 && p == 0)) {

		vector<struct proposal> Vector;
		cin.ignore();

		if (isBlank == false) { isBlank = true; }
		else { cout << endl; }

		for (int i = 1; i <= n; ++i) { getline(cin, requirement); }

		for (int i = 1; i <= p; ++i) {

			getline(cin, Proposal.name);
			cin >> Proposal.d >> Proposal.r, cin.ignore();
			Vector.push_back(Proposal);

			for (int j = 1; j <= Proposal.r; ++j) { getline(cin, requirement); }
		}

		sort(Vector.begin(), Vector.end(), mySort);

		cout << "RFP #" << ++RFP << endl << Vector[0].name << endl;
	}

	return 0;
}