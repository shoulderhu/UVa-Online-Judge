#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <functional>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string str1, str2;
	long long int num1, num2, num3;

	while (cin >> str1 && str1 != "0") {

		int length = 0;		
		unordered_set<long long int> Set;
		
		cout << "Original number was " << str1 << endl;
		
		str2 = str1;
		sort(str1.begin(), str1.end(), greater<char>());
		sort(str2.begin(), str2.end());
		num1 = stoll(str1, nullptr, 10), num2 = stoll(str2, nullptr, 10);
		num3 = num1 - num2;

		while (Set.find(num3) == Set.end()) {

			Set.insert(num3), ++length;
			cout << num1 << " - " << num2 << " = " << num3 << endl;

			str1 = to_string(num3), str2 = str1;
			sort(str1.begin(), str1.end(), greater<char>());
			sort(str2.begin(), str2.end());
			num1 = stoll(str1, nullptr, 10), num2 = stoll(str2, nullptr, 10);
			num3 = num1 - num2;
		}
		
		cout << num1 << " - " << num2 << " = " << num3 << endl;
		cout << "Chain length " << length + 1 << endl << endl;
	}

	return 0;
}