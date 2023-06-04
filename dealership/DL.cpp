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

	return 0;
}

