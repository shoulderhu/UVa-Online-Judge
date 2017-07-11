#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int pos;
	bool isHyphen = false;	
	string line, text;
	vector<int> Cut;
	
	while (getline(cin, line) && line != "#") {
		
		bool isHandle = (line.back() == '-');

		for (auto iter = line.begin(); iter != line.end(); ) {
						
			if (isalpha(*iter) == 0 && *iter != ' ') {

				iter = line.erase(iter);
			}
			else { ++iter; }
		}
		
		if (isHyphen == true) {

			pos = 0, isHyphen = false;

			for (;;++pos) {
			
				if (line[pos] == ' ') {

					Cut.push_back(text.size() + pos - 1);
					break;
				}
				if (pos + 1 >= line.size()) {

					Cut.push_back(text.size() + pos);
					break;
				}
			}			
		}

		if (isHandle == true) {

			pos = line.size() - 1, isHyphen = true;

			for (;;--pos) {
						
				if(line[pos] == ' '){ 
					
					Cut.push_back(text.size() + pos); 
					break;
				}
				if (pos - 1 < 0) {
				
					Cut.push_back(text.size() + pos - 1);
					break;
				}
			}			
		}
		
		text += line;
		if (isHandle == false) { Cut.push_back(text.size() - 1); }
	}

	cout << text.substr(0, Cut[0] + 1) << endl;

	for (int i = 1; i < Cut.size(); ++i) {

		cout << text.substr(Cut[i - 1] + 1, Cut[i] - Cut[i - 1]) << endl;
	}

	return 0;
}