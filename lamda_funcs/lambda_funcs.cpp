#include <iostream>
#include <iomanip>
#include <time.h>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <fstream>

using namespace std;

class student {
	string name, course;
	int av_grade;
public:
	student() : name(""), course(""), av_grade(0) {}
	void set() {
		cout << "Enter name: ";
		getline(cin, name);

		cout << "Enter course name: ";
		getline(cin, course);

		cout << "Enter average grade: ";
		(cin >> av_grade).get();
	}

	string get_course() const { return course; }
	int get_grade() const { return av_grade; }

	void print() const {
		cout << string(100, '-');
		cout << "\nName: " << name;
		cout << "\nCourse name: " << course;
		cout << "\nAverage grade: " << av_grade << endl;
		cout << string(100, '-') << endl;
	}
};

class functor {
public:
	bool operator()(const student& s){ return s.get_course() == "Programming" && s.get_grade() > 9; }
};

void print(vector<student> v) {
	for (auto it : v)
		it.print();
}

int main() {

	vector<student> studs; int count;

	cout << "Enter amount of students: ";
	(cin >> count).get();

	for (int i = 0; i < count; i++) {
		student add_stud;
		add_stud.set();
		studs.push_back(add_stud);
	}

	print(studs);

	count = 0;
	auto it = studs.begin(), check_it = studs.begin();

	while (it != studs.end()) {
		it = find_if(it, studs.end(), [](const student& s) {
			return s.get_course() == "Programming" && s.get_grade() > 9;
		});

		check_it = it;
		if (check_it == studs.end())
			break;

		count++; it++;
	}

	/*while (it != studs.end()) {
		it = find_if(it, studs.end(), functor());

		check_it = it;
		if (check_it == studs.end())
			break;

		count++; it++;
	}*/

	cout << "\nAmount of students with programing course and average grade above 9: " << count;







	return 0;
}