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

//1

void print(vector<int> v) {
	cout << string(100, '-') << endl;
	cout << "Size: " << v.size() << endl;

	for (auto it : v)
		cout << it << " ";
	cout << endl;
	cout << string(100, '-') << endl;
}

int find_min(vector<int> v) {
	int min = 0;
	for (auto it : v)
		if (it < min)
			min = it;

	return min;
}

int find_max(vector<int> v) {
	int max = 0;
	for (auto it : v)
		if (it > max)
			max = it;

	return max;

}

class functor {
	int val;
public:
	functor(int val) : val(val) {}
	int operator()(int& el) { return el += val; }
};

void menu() {
	cout << "\n 1 - find max value\n";
	cout << " 2 - find min value\n";
	cout << " 3 - sort descendinly\n";
	cout << " 4 - sort ascendinly\n";
	cout << " 5 - add value to all elements\n";
	cout << " 6 - take away value from all elements\n";
	cout << " 7 - delete element\n";
	cout << "Press 0 to exit\n";
}

class dealership;
class car {
	string name;
	int year; 
	double volume, price;
public:
	car() : name(""), year(0), volume(0), price(0) {}
	car(string name, int year, double volume, double price) :
		name(name), year(year), volume(volume), price(price) {}

	void set() {
		cout << "Enter car name: ";
		getline(cin, name);

		cout << "Enter car release year: ";
		cin >> year;

		cout << "Enter car engine volume: ";
		cin >> volume;

		cout << "Enter car price: ";
		(cin >> price).get();
	}

	int get_price() const { return price; }

	void print() const {
		cout << string(100, '-');
		cout << "\n Car name: " << name;
		cout << "\n Car release year: " << year;
		cout << "\n Engine volume: " << volume;
		cout << "\n Car price: " << price << endl;
		cout << string(100, '-') << endl;
	}

	friend class dealership;
};

class dealership {
	vector<car> cars;
public:
	void download_data(string path) {
		ifstream fin; string name; int year; double volume, price;
		fin.open(path);

		while (fin >> name >> year >> volume >> price)
			cars.push_back(car(name, year, volume, price));

		fin.close();
	}
	void add() {
		car add_car;
		add_car.set();
		cars.push_back(add_car);
	}

	void remove_car(string del_name) {
		auto it = remove_if(cars.begin(), cars.end(), [del_name](const car& c) {
			return del_name == c.name; 
		});

		cars.erase(it, cars.end());
	}

	void sort_price() { sort(cars.begin(), cars.end()); }

	void search_carName(string find_name) const {
		for (auto it : cars)
			if (it.name == find_name)
				it.print();
	}

	void print() const {
		for (auto it : cars)
			it.print();
	}

	void upload_data(string path) {
		ofstream fout;
		fout.open(path);

		for (auto it : cars)
			fout << it.name << " " << it.year << " " << it.volume << " " << it.price << endl;

		fout.close();
	}
};

bool operator <(const car& c1, const car& c2) {
	return c1.get_price() < c2.get_price();
}

bool operator >(const car& c1, const car& c2) {
	return c1.get_price() > c2.get_price();
}


int main() {
	srand(time(0));

	//2
	int choice, i, j = 0; string car_name, path = "dealership.txt";
	dealership dl;

	dl.download_data(path);

	cout << "Enter amount of cars: ";
	(cin >> i).get();

	while ((j++) < i)
		dl.add();

	while (true) {
		cout << "\n 1 - print info";
		cout << "\n 2 - add new car";
		cout << "\n 3 - remove car by name";
		cout << "\n 4 - sort by price\n 5 - search car by name\n Press 0 to exit\nYour choice: ";
		(cin >> choice).get();

		if (!choice)
			break;

		switch (choice) {
		case 1:
			dl.print();
			break;
		case 2:
			dl.add();
			break;
		case 3:
			cout << "Enter car name to delete: ";
			getline(cin, car_name);

			dl.remove_car(car_name);
			break;
		case 4:
			dl.sort_price();
			break;
		case 5:
			cout << "Enter car name to delete: ";
			getline(cin, car_name);

			dl.search_carName(car_name);
			break;
		default:
			cout << "Wrong option\n\n";
			break;
		}
	}

	dl.upload_data(path);






	//1
	/*int choice, value = 0; 
	vector<int> v;

	for (int i = 0; i < 8; i++)
		v.push_back(rand() % 101 - 50);

	auto it = v.begin();

	while (true) {
		print(v);
		menu();
		cout << "Enter your choice: ";
		cin >> choice;

		if (!choice)
			break;

		switch (choice)
		{
		case 1:
			cout << "Max element: " << find_max(v) << endl;
			system("Pause");
			break;
		case 2:
			cout << "Min element: " << find_min(v) << endl;
			system("Pause");
			break;
		case 3:
			sort(v.begin(), v.end(), greater<int>());
			break; 
		case 4:
			sort(v.begin(), v.end());
			break;
		case 5:
			cout << "Enter a value: ";
			cin >> value;

			for_each(v.begin(), v.end(), functor(value));
			break;
		case 6:
			cout << "Enter a value: ";
			cin >> value;

			for_each(v.begin(), v.end(), [value](int& el) { el -= value; });
			break;
		case 7:
			cout << "Enter a value: ";
			cin >> value;

			it = remove_if(v.begin(), v.end(), [value](int el) { return el == value; });
			v.erase(it, v.end());
			
			break;
		default:
			cout << "Wrong option\n";
			system("Pause");
			break;
		}

		system("cls");
	}

*/






	return 0;
}