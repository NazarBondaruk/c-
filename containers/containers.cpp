#include <iostream>
#include <iomanip>
#include <time.h>
#include <vector>
#include <string>
#include <list>
#include <forward_list>
#include <map>	
#include <array>	
#include <deque>	
#include <set>	
#include <stack>	
#include <queue>	

using namespace std;

class point {
	int x, y;
public:
	point() : x(0), y(0) {}
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void print() const { cout << "X: " << x << " | Y:" << y << endl; }
};


class client {
	int prior;
	string name;
public:
	client() : prior(0) {}
	client(string name, int prior) {
		this->name = name;
		this->prior = prior;
	}

	void print() const {
		cout << "Name: " << name;
		cout << "\nPriority: " << prior << endl;
	}

	int get_prior() const { return prior; }
};

bool operator<(const client& c1, const client& c2) {
	return c1.get_prior() > c2.get_prior();
}

class database;
class desc_break {
	string descript, date, time;
public:
	desc_break() : descript(""), date(""), time("") {}
	desc_break(string descript, string date, string time) {
		this->descript = descript;
		this->date = date;
		this->time = time;
	}

	void set() {
		cout << "Enter law break info:\n";
		getline(cin, descript);

		cout << "Enter date: ";
		getline(cin, date);

		cout << "Enter time: ";
		getline(cin, time);
	}

	void print() const {
		cout << string(100, '-');
		cout << "\nLaw break description: " << descript;
		cout << "\nDate: " << date;
		cout << "\nTime: " << time << endl;
		cout << string(100, '-') << endl;
	}

	friend class database;
};

class database {
	map<string, list<desc_break>> veh_info;
public:
	pair<string, list<desc_break>> operator[](int i) {
		int j = 0;
		for (auto it = veh_info.begin(); it != veh_info.end(); it++) {
			if ((j++) == i)
				return *it;
		}
	}

	void add(string plate, desc_break add_break) {

		for (auto it : veh_info) {
			if (plate == it.first) {
				it.second.push_back(add_break);
				return;
			}
		}

		list<desc_break> new_list;
		new_list.push_back(add_break);
		veh_info.insert({ plate, new_list });
	}

	void print() const {
		for (auto it : veh_info) {
			cout << "\n\nCar plate: " << it.first;
			cout << "\nLaw breaks:\n";

			for (auto viol : it.second)
					viol.print();
		}
	}
};



int main() {
	srand(time(0));

	database viol_data;
	int amount, i = 0;

	cout << "Enter amount of breaks: ";
	(cin >> amount).get();

	while (i < amount) {
		desc_break viol;
		string plate;

		cout << "Enter car plate: ";
		getline(cin, plate);

		cout << "Enter violation info\n ";
		viol.set();

		viol_data.add(plate, viol);
		i++;
	}

	viol_data.print();





	/*priority_queue<client> clPq;
	clPq.push(client("John", 3));
	clPq.push(client("Jack", 1));
	clPq.push(client("Max", 5));
	clPq.push(client("Lewis", 2));

	while (!clPq.empty()) {
		clPq.top().print();
		clPq.pop();
	}*/


	//адаптери контейнерів(steck, queue, prioirity_queue) - не асоціативними контейнери, є адаптерами для інших контейнерів
	//pririty queue - черга з пріорітетом

	/*priority_queue<int> pq;
	pq.push(12);
	pq.push(-4);
	pq.push(41);
	pq.push(0);
	pq.push(16);

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}*/


	//queue - перший зайшов перший вийшов

	//queue<point> points_queue;
	//points_queue.push(point(23, -11));
	//points_queue.push(point(0, 2));
	//points_queue.push(point(9, 7));
	//points_queue.push(point(-8, 14));

	//while (!points_queue.empty()) {
	//	/*point p = points_queue.front();	
	//	p.print();*/
	//	points_queue.front().print();
	//	points_queue.pop();
	//}





	// stack - останній зайшов перший вийшов
	//stack<int> s;
	//s.push(4);
	//s.push(-13);
	//s.push(25);
	//s.push(0);
	//s.push(9);

	//cout << s.top() << endl;
	//s.pop();
	//cout << s.top() << "\n\n";

	//while (!s.empty()) {
	//	cout << s.top() << " ";
	//	s.pop();
	//}

	////stack<int, vector<int>> s;



	//---------------------------------------------------------------------------------------------------------




	//-------------Multiset
	//multiset - асоціативний контейнер, побудований на основі дерева, містить набір не унікальних ключів
	/*multiset<int> ms = { 12, 9, -7, 0, 16, 12 };
	for (auto it : ms)
		cout << it << " ";*/


		//-------------------------Set
		//set - асоціативний контейнер, побудований на основі дерева, містить набір унікальних ключів
		///*set<int> s;
		//s.insert(5);
		//s.insert(32);
		//s.insert(-6);
		//s.insert(0);
		//s.insert(13);

		//for (auto nod : s)
		//	cout << nod << " ";*/

		//set <int> s = { 12, 9, -7, 0, 16 };
		//for (auto nod : s)
		//	cout << nod << " ";

		////find
		//auto it = s.find(9);
		//if (it != s.end())
		//	cout << "\nFound\n";

		//s.erase(it);
		//for (auto nod : s)
		//	cout << nod << " ";



		//--------------Deque
		/*deque<int> dq = { 12, 9, -7, 0, 16 };
		dq.push_back(-3);
		dq.pop_front();

		for (auto it : dq)
			cout << it << " ";*/



			//--------------Multimap
			//// Multimap - асоціaтивний контейнер, який містить пари ключ-значення
			//multimap<string, int> mm;
			//mm.insert({ "John", 23 });
			//mm.insert({ "Jack", 21 });
			//mm.insert({ "Doe", 29 });
			//mm.insert({ "John", 27 });

			//for (auto it : mm)
			//	cout << it.first << " | " << it.second << endl;

			////earse
			//mm.erase("John");

			//cout << endl;
			//for (auto it : mm)
			//	cout << it.first << " | " << it.second << endl;

			////find
			//auto it = mm.find("John");
			//cout << it->second << endl;





			////array - аналог статичного масиву
			//array<int, 5> arr = { 12, 9, -7, 0, 16 };

			///*for (auto it = arr.begin(); it != arr.end(); it++)
			//	cout << *it << " ";*/

			//for (auto it : arr)
			//	cout << it << " ";
			//cout << endl;
			//cout << "Size: " << arr.size() << endl;

			//array<int, 5> arr2 = { 12, 9, -7, 0, 16 };
			//if (arr == arr2)
			//	cout << "Arrays are equal\n\n";





			//forward_list<int> fl = { 12, 9, -7, 0, 16 };
			//fl.push_front(45);

			//for (auto it : fl)
			//	cout << it << " ";
			//cout << endl;

			////forward_list<int>::iterator it = fl.begin();
			//auto it = fl.begin();
			//
			//advance(it, 3);
			//fl.erase_after(it);

			//for (auto it_1 : fl)
			//	cout << it_1 << " ";
			//cout << endl;






	return 0;
}