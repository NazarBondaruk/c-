#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

class file_helper {
public:
	static string read_text(string path)  {
		string text; char s;
		ifstream fin;
		fin.open(path);

		if (!fin.is_open())
			return "File error!\n";

		else {
			while (fin.get(s)) {
				text += s;
			}
		}

		fin.close();
		return text;
	}

	static void write_text(string path, string text) {
		ofstream fout;
		fout.open(path);

		if (!fout.is_open())
			cout << "File error!\n";

		else {
			fout << text;
		}

		fout.close();
	}
};

class point {
	int x, y;
public:
	point(): x(0), y(0) {}
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void print() const { cout << "X: " << x << " | Y: " << y << endl; }

	friend ostream& operator<<(ostream&, const point&);
	friend istream& operator>>(istream&, point&);

	friend ofstream& operator<<(ofstream&, const point&);
	friend ifstream& operator>>(ifstream&, point&);
};

ostream& operator<<(ostream& os, const point& p) {
	os << "X: " << p.x << " | Y: " << p.y << endl;
	return os;
}

istream& operator>>(istream& is, point& p) {
	is >> p.x >> p.y;
	return is;
}

ofstream& operator<<(ofstream& fout, const point& p) {
	fout <<  p.x << " " << p.y << endl;
	return fout;
}

ifstream& operator>>(ifstream& fin, point& p) {
	fin >> p.x >> p.y;
	return fin;
}

class person {
	string name, surname; int age;
public:
	person(): name("No instance for this name"), surname("No instance for this surname"), age(0) {}
	person(string name, string surname, int age) {
		this->name = name;
		this->surname = surname;
		this->age = age;
	}

	void print() const {
		cout << "Name: " << name;
		cout << "\nSurname: " << surname;
		cout << "\nAge: " << age << endl;
	}

	friend ofstream& operator<<(ofstream&, const person&);
	friend ifstream& operator>>(ifstream&, person&);
};

ofstream& operator << (ofstream& fout, const person& p) {
	fout << p.name << " " << p.surname << " " << p.age << endl;
	return fout;
}

ifstream& operator >> (ifstream& fin, person& p) {
	(fin >> p.name >> p.surname >> p.age).get();
	return fin;
}

int  main() {
	srand(time(0));




	////read
	//vector<point> points;
	//point tmp;
	//
	//string path = "doc.txt";
	//ifstream fin;
	//fin.open(path);
	//
	//if (!fin.is_open())
	//	cout << "Path error!\n";
	//else {
	//	while (fin >> tmp)
	//		points.push_back(tmp);
	//}

	//for (point p : points)
	//	cout << p;

	//fin.close();
	
	//write
	/*vector<point> points;
	points.push_back(point(10, 20));
	points.push_back(point(7, -22));
	points.push_back(point(0, 31));
	points.push_back(point(8, 2));
	points.push_back(point(-11, 2));

	string path = "doc.txt";

	ofstream fout;
	fout.open(path);

	if (!fout.is_open())
		cout << "Path error!\n";
	else {
		for (int i = 0; i < points.size(); i++)
		{
			fout << points[i];
		}
	}

	fout.close();*/





	/*person p("Max", "Tierney", 17);

	string path = "person.txt";

	ofstream fout;
	fout.open(path);

	if (!fout.is_open())
		cout << "Path error!\n";

	else fout << p;

	fout.close();*/

	/*person p1;
	string path = "person.txt";

	ifstream fin;
	fin.open(path);

	if (!fin.is_open())
		cout << "Path error!\n";
	else
		fin >> p1;

	p1.print();
	fin.close();*/



	//----------------read
	/*point p;
	string path = "point.txt";

	ifstream fin;
	fin.open(path);

	if (!fin.is_open())
		cout << "Path error!\n";
	else
		fin >> p;

	p.print();
	fin.close();*/


	//write
	/*point p(10, 20);
	string path = "point.txt";

	ofstream fout;
	fout.open(path);

	if (!fout.is_open())
		cout << "Path error!\n";

	else fout << p;

	fout.close();*/




	/*string path = "doc.txt";
	fstream fs;
	
	fs.open(path, fstream::in | fstream::out);

	if (!fs.is_open())
		cout << "Path error!\n";
	else {
		string message;
		int choice;

		cout << "1 - write\n2 - read\nYour choice: ";
		(cin >> choice).get();

		switch (choice)
		{
		case 1:
			getline(cin, message);
			fs << message;
			break;
		case 2:
			fs >> message;
			cout << message;
			break;
		default:
			break;
		}
	}

	fs.close();*/



	/*cout << file_helper::read_text("doc.txt");
	file_helper::write_text("doc.txt", "Hello world!");*/


	/*char s;
	string path = "doc.txt";
	ifstream fin;
	fin.open(path);

	string str = "";

	if (!fin.is_open())
		cout << "File error!\n";

	else {
		while (fin.get(s)) {
			str += s;
		}
	}

	cout << str;

	fin.close();*/





	//------------------ifstream
	//string path = "doc.txt";
	//ifstream fin;
	//string name, surname; int age = 0;

	//fin.open(path);

	//if (!fin.is_open())
	//	cout << "File error!\n";
	//else {
	//	fin >> name;
	//	fin >> surname;
	//	fin >> age;
	//}

	//fin.close();
	//cout << name << " ";
	//cout << surname << " ";
	//cout << age << "\n";


	//----------------ofstream
	/*string name, surname; int age;

	cout << "Enter name: ";
	getline(cin, name);

	cout << "Enter surname: ";
	getline(cin, surname);

	cout << "Enter age: ";
	cin >> age;

	string path = "doc.txt";
	ofstream fout;
	fout.open(path);

	if (!fout.is_open())
		cout << "Path error!\n\n";
	else {
		fout << name << " ";
		fout  << surname << " ";
		fout << age << "\n";
	}*/

	//fout.close();





	return 0;
}