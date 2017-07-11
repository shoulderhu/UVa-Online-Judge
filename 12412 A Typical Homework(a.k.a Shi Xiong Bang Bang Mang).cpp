#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#define EPS 1e-5

using namespace std;

string temp;
struct student {

	int CID, score[4], total = 0;
	string name, SID;
}Student;
vector<struct student> SPMS;

inline bool mySort(int a, int b) { return a > b; }
inline bool myFind1(struct student s) { return s.SID == Student.SID; }
inline bool myFind2(struct student s) { return s.SID == temp; }
inline bool myFind3(struct student s) { return s.name == temp; }

void Add() {
	
	while (true) {

		cout << "Please enter the SID, CID, name and four scores. Enter 0 to finish.\n";
		cin >> Student.SID;
		
		if (Student.SID == "0") { return; }

		cin >> Student.CID >> Student.name >> Student.score[0] >> Student.score[1]
		                                   >> Student.score[2] >> Student.score[3];

		if (find_if(SPMS.begin(), SPMS.end(), myFind1) != SPMS.end()) { 
			
			cout << "Duplicated SID.\n"; 
		}
		else { SPMS.push_back(Student); }
	}
}

void Remove() {
	
	while (true) {
		
		cout << "Please enter SID or name. Enter 0 to finish.\n";
		cin >> temp;

		if (temp == "0") { return; }
		
		int xx = 0;
		vector<struct student>::iterator p;
		
		if (isalpha(temp[0]) == 0) { p = find_if(SPMS.begin(), SPMS.end(), myFind2); }
		else { p = find_if(SPMS.begin(), SPMS.end(), myFind3); }
		
		while (p != SPMS.end()) { 
			
			SPMS.erase(p), xx++; 
		    
			if (isalpha(temp[0]) == 0) { p = find_if(SPMS.begin(), SPMS.end(), myFind2); }
			else { p = find_if(SPMS.begin(), SPMS.end(), myFind3); }
		}

		cout << xx << " student(s) removed.\n";		
	}
}

void Query() {

	vector<int> rankTable;
	
	for (auto iter = SPMS.begin(); iter != SPMS.end(); ++iter) {

		iter->total = iter->score[0] + iter->score[1] + iter->score[2] + iter->score[3];
		rankTable.push_back(iter->total);
	}

	sort(rankTable.begin(), rankTable.end(), mySort);

	while (true) {

		cout << "Please enter SID or name. Enter 0 to finish.\n";
		cin >> temp;

		if (temp == "0") { return; }
		
		vector<struct student>::iterator p;

		if (isalpha(temp[0]) == 0) { p = find_if(SPMS.begin(), SPMS.end(), myFind2); }
		else {	p = find_if(SPMS.begin(), SPMS.end(), myFind3);	}

		while (p != SPMS.end()) {

			auto iter = find(rankTable.begin(), rankTable.end(), p->total);

			cout << iter - rankTable.begin() + 1 << " " << p->SID << " " << p->CID << " " << p->name << " "
			     << p->score[0] << " " << p->score[1] << " " << p->score[2] << " " << p->score[3] << " "
			     << p->total << " " << fixed << setprecision(2) << p->total / 4.0 + EPS << endl;

			if (isalpha(temp[0]) == 0) { p = find_if(++p, SPMS.end(), myFind2); }
			else { p = find_if(++p, SPMS.end(), myFind3); }
		}		
	}	
}

inline void ShowRanking() {

	cout << "Showing the ranklist hurts students' self-esteem. Don't do that.\n";
}

void ShowStatistics() {

	int ID, people = SPMS.size();
	struct course {

		int pass = 0, fail = 0;
		double average = 0;
	}Chinese, Mathematics, English, Programming;
	struct overAll { int pass0 = 0, pass1 = 0, pass2 = 0, pass3 = 0, pass4 = 0; }Overall;

	cout << "Please enter class ID, 0 for the whole statistics.\n";
	cin >> ID;

	for (auto iter = SPMS.begin(); iter != SPMS.end(); ++iter) {

		if (ID != 0 && iter->CID != ID) {
		
			people--;
			continue;
		}

		int pass = 4;
		
		Chinese.average += iter->score[0];
		Mathematics.average += iter->score[1];
		English.average += iter->score[2];
		Programming.average += iter->score[3];
				
		if (iter->score[0] >= 60) { Chinese.pass++; }
		else { Chinese.fail++, pass--; }
		if (iter->score[1] >= 60) { Mathematics.pass++; }
		else{ Mathematics.fail++, pass--; }
		if (iter->score[2] >= 60) { English.pass++; }
		else{ English.fail++, pass--; }
		if (iter->score[3] >= 60) { Programming.pass++; }
		else{ Programming.fail++, pass--; }

		switch (pass) {

		case 4:	Overall.pass4++;
		case 3: Overall.pass3++;
		case 2: Overall.pass2++;
		case 1: Overall.pass1++; break;
		case 0: Overall.pass0++; break;
		}
	}

	Chinese.average /= people, Mathematics.average /= people;
	English.average /= people, Programming.average /= people;

	cout << "Chinese\n";
	cout << "Average Score: " << fixed << setprecision(2) << Chinese.average + EPS << endl;
	cout << "Number of passed students: " << Chinese.pass << endl;
	cout << "Number of failed students: " << Chinese.fail << endl << endl;

	cout << "Mathematics\n";
	cout << "Average Score: " << Mathematics.average + EPS << endl;
	cout << "Number of passed students: " << Mathematics.pass << endl;
	cout << "Number of failed students: " << Mathematics.fail << endl << endl;

	cout << "English\n";
	cout << "Average Score: " << English.average + EPS << endl;
	cout << "Number of passed students: " << English.pass << endl;
	cout << "Number of failed students: " << English.fail << endl << endl;

	cout << "Programming\n";
	cout << "Average Score: " << Programming.average + EPS << endl;
	cout << "Number of passed students: " << Programming.pass << endl;
	cout << "Number of failed students: " << Programming.fail << endl << endl;

	cout << "Overall:\n";
	cout << "Number of students who passed all subjects: " << Overall.pass4 << endl;
	cout << "Number of students who passed 3 or more subjects: " << Overall.pass3 << endl;
	cout << "Number of students who passed 2 or more subjects: " << Overall.pass2 << endl;
	cout << "Number of students who passed 1 or more subjects: " << Overall.pass1 << endl;
	cout << "Number of students who failed all subjects: " << Overall.pass0 << endl << endl;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int option = 1;
		
	while (option != 0) {

		cout << "Welcome to Student Performance Management System (SPMS).\n\n";

		cout << "1 - Add\n";
		cout << "2 - Remove\n";
		cout << "3 - Query\n";
		cout << "4 - Show ranking\n";
		cout << "5 - Show Statistics\n";
		cout << "0 - Exit\n\n";
		cin >> option, cin.ignore();

		switch (option) {

		case 1: Add(); break;
		case 2: Remove(); break;
		case 3: Query(); break;
		case 4: ShowRanking(); break;
		case 5: ShowStatistics(); break;
		}	
	}

	return 0;
}