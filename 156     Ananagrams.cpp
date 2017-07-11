#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	int i;
	string word;
	map<string, int> identity;
	map<string, string> dictionary;	
	map<string, string>::iterator loop;

	while (cin >> word && word != "#") {

		string wordCp = word;

		for (i = 0; i < wordCp.size(); i++) { wordCp[i] = tolower(wordCp[i]); }
		sort(wordCp.begin(), wordCp.end());

		dictionary[word] = wordCp, identity[wordCp]++;		
	}

	for (loop = dictionary.begin(); loop != dictionary.end(); loop++) {
		
		if (identity[loop->second] == 1) { printf("%s\n", loop->first.c_str()); }
	}

	return 0;
}