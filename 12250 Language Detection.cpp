#include <iostream>
#include <string>

using namespace std;

int main() {

	int kace = 0;
	string S, s;

	while (cin >> S && S != "#") {

		if (S == "HELLO") { s = "ENGLISH"; }
		else if (S == "HOLA") { s = "SPANISH"; }
		else if (S == "HALLO") { s = "GERMAN"; }
		else if (S == "BONJOUR") { s = "FRENCH"; }
		else if (S == "CIAO") { s = "ITALIAN"; }
		else if (S == "ZDRAVSTVUJTE") { s = "RUSSIAN"; }
		else { s = "UNKNOWN"; }

		printf("Case %d: %s\n", ++kace, s.c_str());
	}

	return 0;
}