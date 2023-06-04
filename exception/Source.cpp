#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

class account {
	string id;
public:
	void set() {
		cout << "Enter ID:\n";
		getline(cin, id);
	}

	string get_id() const { return id; }

	void print() const {
		cout << "ID: " << id << endl;
	}
};

class bank {
	account* accounts;
	int size;
public:
	bank(): accounts(nullptr), size(0) {}

	void set() {
		cout << "Enter size: ";
		(cin >> size).get();

		accounts = new account[size];
		for (int i = 0; i < size; i++)
			accounts[i].set();
	}

	void print() const {
		for (int i = 0; i < size; i++)
			accounts[i].print();
	}

	void operation(account find_acc) {
		for (int i = 0; i < size; i++)
		{
			if (find_acc.get_id() == accounts[i].get_id()) {
				cout << "ID found!\n"; 
				return;
			}
		}

		throw exception ("ID not found!");
	}

	~bank() {
		delete[] accounts;
	}
};

int main() {
	bank accs;
	accs.set();

	cout << "\nID to find:\n";
	account acc;
	acc.set();

	//accs.print();

	try {
		accs.operation(acc);
	}

	catch (exception ex) {
		cout << ex.what();
	}




	return 0;
}