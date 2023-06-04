#include <iostream>
#include <iomanip>
#include <time.h>
#include <vector>
#include <string>

using namespace std;

class students;
class student {
	string name;
	vector<int> marks;
public:
	student(): name("No instance for this name"), marks(0) {}
	student(string name, int amount) {
		this->name = name;
		for (int i = 0; i < amount; i++)
			marks.push_back(rand() % 13);
	}

	void set() {
		int amount;
		cout << "Enter student`s name: ";
		getline(cin, name);
		
		cout << "Enter amount of marks: ";
		(cin >> amount).get();

		for (int i = 0; i < amount; i++)
			marks.push_back(rand() % 13);

		cout << endl;
	}

	void print() const {
		cout << "\nStudent`s name: " << name;
		cout << "\nMarks: ";

		for (auto mark : marks)
			cout << mark << " ";

		cout << endl;
	}

	friend class students;
};

class students {
	vector<student> studs;
public:
	//students(): studs(0) {}

	void set() {
		int amount;
		cout << "Enter amount of students: ";
		(cin >> amount).get();

		for (int i = 0; i < amount; i++) {
			student create_stud;
			create_stud.set();
			studs.push_back(create_stud);
		}
	}

	void print() const {
		for (auto it : studs)
			it.print();
	}

	void add_new() {
		student new_stud;
		new_stud.set();

		studs.push_back(new_stud);
	}

	void find_stud(string find_name) {
		for (auto it : studs) {
			if (it.name == find_name)
				it.print();
		}
	}

	void stud_aver() {
		for (auto it : studs) {
			int sum = 0;
			for (auto it_1 : it.marks) {
				sum += it_1;
			}
			cout << "Student's average grade(" << it.name << "): " << double(sum / it.marks.size()) << endl;
		}
	}

	void class_aver() {
		int grade_count = 0, sum = 0;
		for (auto it : studs) {
			for (auto it_1 : it.marks) {
				sum += it_1;
				grade_count++;
			}
		}

		cout << "Class's average grade: " << double(sum / grade_count) << endl;
	}
};

void menu() {
	cout << string(100, '-');
	cout << "\n1 - print info\n";
	cout << "2 - add new student\n";
	cout << "3 - find student by name\n";
	cout << "4 - print each student`s average grade\n";
	cout << "5 - print class average grade\n";
	cout << string(100, '-') << endl;
}

int main() {
	srand(time(0));
	string find_name;
	students studs;
	studs.set();

	int choice;
	while (true) {
		menu();
		cout << "Enter your choice: ";
		(cin >> choice).get();

		switch (choice)
		{
		case 1:
			studs.print();
			break;
		case 2:
			studs.add_new();
			break;
		case 3:
			cout << "Enter a name to find: ";
			getline(cin, find_name);

			studs.find_stud(find_name);
			break;
		case 4:
			studs.stud_aver();
			break;
		case 5:
			studs.class_aver();
			break;
		default:
			cout << "Wrong option\n\n";
			break;
		}
	}
	





	return 0;
}