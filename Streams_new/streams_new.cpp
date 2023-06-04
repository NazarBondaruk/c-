#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
class phone_book;

class person {
	string name, surname; int num;
public:
	person() : name("No instance for this name"), surname("No instance for this surname"), num(0) {}
	person(string name, string surname, int num) {
		this->name = name;
		this->surname = surname;
		this->num = num;
	}

	void set() {
		cout << "Enter name: ";
		getline(cin, name);

		cout << "Enter surname: ";
		getline(cin, surname);

		cout << "Enter phone number: ";
		(cin >> num).get();
	}

	void print() const {
		cout << "\nName: " << name;
		cout << "\nSurname: " << surname;
		cout << "\nPhone number: " << num << endl;
	}

	string get_name() const { return name; }
	string get_surname() const { return surname; }
	int get_num() const { return num; }

	friend ofstream& operator<<(ofstream&, const person&);
	friend ifstream& operator>>(ifstream&, person&);
	friend fstream& operator<<(fstream&, const person&);
	friend fstream& operator>>(fstream&, person&);

	friend class phone_book;
};

ofstream& operator << (ofstream& fout, const person& p) {
	fout << p.name << " " << p.surname << " " << p.num << endl;
	return fout;
}

ifstream& operator >> (ifstream& fin, person& p) {
	(fin >> p.name >> p.surname >> p.num).get();
	return fin;
}

fstream& operator << (fstream& fout, const person& p) {
	fout << p.name << " " << p.surname << " " << p.num << endl;
	return fout;
}

fstream& operator >> (fstream& fin, person& p) {
	(fin >> p.name >> p.surname >> p.num).get();
	return fin;
}

class phone_book {
	vector<person> contacts;
	fstream fs_base;
	string path;
	static string find_end;
public:
	void upload_phone_book(string path) {
		person tmp;
		fs_base.open(path, fstream::in | fstream::out);

		while (fs_base >> tmp) 
			contacts.push_back(tmp);

		fs_base.close();
	}

	void print() const {
		for (person item : contacts)
			item.print();
	}

	void add_contact(person& new_contact) {
		contacts.push_back(new_contact);
	}

	void delete_surname(string& find_surname) {
		int i = 0;
		for (person item : contacts) {
			if (item.get_surname() == find_surname) {
				contacts.erase(contacts.begin() + i);
				return;
			}
			i++;
		}

		cout << "Contact not found!\n";
	}

	void sort_book() {
		person tmp;
		for (int i = 0; i < contacts.size(); i++)
		{
			for (int j = contacts.size() - 1; j > i; j--)
			{
				if (contacts[j - 1].name > contacts[j].name) {
					tmp = contacts[j];
					contacts[j] = contacts[j - 1];
					contacts[j - 1] = tmp;
				}
			}
		}
	}

	void edit_surname(string& find_surname, string& new_surname) {
		int i = 0;
		person new_p;

		for (person item : contacts) {
			if (item.surname == find_surname) {
				item.surname = new_surname;
				new_p = item;

				contacts.erase(contacts.begin() + i);
				contacts.push_back(new_p);
				sort_book();

				return;
			}
		}

		throw exception("Contact not found!\n");
	}

	void clear_book() { contacts.clear(); }

	person search_number(int find_num) {
		for (person item : contacts) {
			if (item.num == find_num)
				return item;
		}

		throw exception("Contact not found!\n");
	}

	person search_surname(string find_surname) {
		for (person item : contacts) {
			if (item.get_surname() == find_surname)
				return item;
		}

		throw exception("Contact not found!");
	}

	void save_phone_book(string path) {
		fs_base.open(path, fstream::in | fstream::out);

		for (person item : contacts)
			fs_base << item;
	
		fs_base.close();
	}
};

void menu() {
	cout << string(100, '-');
	cout << "\n1 - print contacts\n";
	cout << "2 - add contacts\n";
	cout << "3 - delete contact by surname\n";
	cout << "4 - edit contact by surname\n";
	cout << "5 - clear contacts\n";
	cout << "6 - search contact by phone number\n";
	cout << "7 - search contact by surname\n";
	cout << "8 - sort contact book by surname\n";
	cout << "Press 0 to exit\n";
	cout << string(100, '-') << endl;
}

int main() {
	srand(time(0));
	int choice, find_num = 0;
	string find_surname, new_surname;
	person new_contact, ret_contact;
	string path = "phone_book.txt";

	phone_book pb;
	pb.upload_phone_book(path);

	while (true) {
		menu();
		cout << "Enter your choice: ";
		(cin >> choice).get();

		if(!choice)
			break;

		switch (choice)
		{
		case 1:
			pb.print();
			break;
		case 2:
			new_contact.set();
			pb.add_contact(new_contact);
			break;
		case 3:
			cout << "Enter contact's surname to delete: ";
			getline(cin, find_surname);
			pb.delete_surname(find_surname);
			break;
		case 4:
			cout << "Enter contact's surname to edit: ";
			getline(cin, find_surname);

			cout << "Enter new contact's surname: ";
			getline(cin, new_surname);

			try {
				pb.edit_surname(find_surname, new_surname);
			}

			catch (exception ex) {
				cout << ex.what() << endl;
			}			
			break;
		case 5:
			pb.clear_book();
			break;
		case 6:
			cout << "Enter contact's number to search: ";
			(cin >> find_num).get();

			try {
				ret_contact = pb.search_number(find_num);
				ret_contact.print();
			}

			catch (exception ex) {
				cout << ex.what() << endl;
			}
			break;
		case 7:
			cout << "Enter contact's surname to search: ";
			getline(cin, find_surname);

			try {
				ret_contact = pb.search_surname(find_surname);
				ret_contact.print();
			}

			catch (exception ex) {
				cout << ex.what() << endl;
			}
			break;
		case 8:
			pb.sort_book();
			break;
		default:
			cout << "Wrong option, please try again\n\n";
			break;
		}
	}

	pb.save_phone_book(path);




	/*person p("Luke", "Kole", 678002);

	string path = "person.txt";

	ofstream fout;
	fout.open(path);

	if (!fout.is_open())
		cout << "Path error!\n";

	else fout << p;

	fout.close();

	person p1;
	string path1 = "person.txt";

	ifstream fin;
	fin.open(path1);

	if (!fin.is_open())
		cout << "Path error!\n";
	else
		fin >> p1;

	p1.print();
	fin.close();*/







	return 0;
}