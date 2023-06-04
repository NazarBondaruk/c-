#include <iostream>
#include <iomanip>
#include <time.h>
#include <string>

using namespace std;

struct element {
	int data;
	element* next, * prev;
};

class list {
	int size;
	element* head, * tail;
public:
	list() {
		head = tail = nullptr;
		size = 0;
	}

	list(int size) {
		for (int i = 0; i < size; i++)
			add_head(rand() % 101 - 50);
	}

	bool is_empty() const { return !size; }

	void print() const {
		cout << "\nSize: " << size << endl;
		element* tmp = head;

		while (tmp) {
			cout << tmp->data << "  ";
			tmp = tmp->next;
		}

		cout << endl;
	}

	void add_head(int value) {
		element* newElem = new element;
		newElem->data = value;
		newElem->next = newElem->prev = nullptr;

		if (!size)
			head = tail = newElem;

		else {
			newElem->next = head;
			head->prev = newElem;
			head = newElem;
			newElem = nullptr;
		}

		size++;
	}

	void add_tail(int value) {
		element* newElem = new element;
		newElem->data = value;
		newElem->next = newElem->prev = nullptr;

		if (!size)
			head = tail = newElem;

		else {
			newElem->prev = tail;
			tail->next = newElem;
			tail = newElem;
		}
	}

	void add_pos(int value, int pos) {
		if (pos > size) {
			cout << "Invalid position!\n\n";
			return;
		}

		if (pos == size) {
			add_tail(value);
			return;
		}


		if (pos == 0) {
			add_head(value);
			return;
		}


		element* newElem = new element;
		newElem->data = value;
		newElem->next = newElem->prev = nullptr;

		element* tmp = head;
		element* tmp_side = head;
		int i = 0;

		while (i++ < pos - 1) {
			tmp_side = tmp;
			tmp = tmp->next;
		}

		newElem->next = tmp->next;
		tmp->next = newElem;

		newElem->prev = tmp->prev;
		tmp->prev = newElem;

		if (pos == size)
			tail = newElem;

		size++;
	}

	int find(int value) {
		int i = 0;
		element* tmp = head;

		while (tmp) {
			if (tmp->data == value)
				return i;

			tmp = tmp->next;
			i++;
		}

		return -1;
	}

	void reverse() {
		element* ptr_head = head;
		element* ptr_tail = tail;
		int tmp = 0;

		for (int i = 0; i < size / 2; i++)
		{
			tmp = ptr_head->data;
			ptr_head->data = ptr_tail->data;
			ptr_tail->data = tmp;

			ptr_head = ptr_head->next;
			ptr_tail = ptr_tail->prev;
		}
	}

	void replace_value(int value_find, int value_confirm) {
		if (find(value_find) != -1) {
			int ind = find(value_find);
			delete_pos(ind);
			add_pos(value_confirm, ind);

			return;
		}

		cout << "Value not found!\n\n";
	}

	void delete_value(int value_find) {
		if (find(value_find) != -1) {
			delete_pos(find(value_find));
			return;
		}

		cout << "Value not found!\n\n";
	}

	void delete_head() {
		if (!size)
			return;

		element* tmp = head;
		tmp = tmp->next;

		delete head;
		head = tmp;

		if(size > 1)
			tmp->prev = nullptr;

		size--;
	}

	void delete_tail() {
		if (!size)
			return;

		element* tmp = tail;
		tmp = tmp->prev;

		delete tail;
		tail = tmp;

		tmp->next = nullptr;
		size--;
	}

	void delete_pos(int pos) {
		int i = 0;

		if (pos >= size || pos < 0) {
			cout << "Invalid position!\n";
			return;
		}

		if (!size)
			return;

		if (tail == head) {
			delete_head();
			return;
		}

		if (pos == size - 1) {
			delete_tail();
			return;
		}

		if (pos == 0) {
			delete_head();
			return;
		}

		element* tmp = head;
		element* tmp_side = head;
		element* tmp_side2 = head;

		while (i++ < pos) {
			tmp_side = tmp;
			tmp = tmp->next;
		}

		tmp_side2 = tmp->next;

		tmp_side->next = tmp->next;
		tmp_side2 = tmp->prev;

		size--;
		delete tmp;
	}

	void clear() {
		if (!size)
			return;

		while (head)
			delete_head();
	}
};

void menu() {
	cout << "\n1 - add head\n";
	cout << "2 - add tail\n";
	cout << "3 - delete head\n";
	cout << "4 - delete tail\n";
	cout << "5 - add position\n";
	cout << "6 - delete position\n";
	cout << "7 - search\n";
	cout << "8 - search and replace\n";
	cout << "9 - search and delete\n";
	cout << "10 - clear list\n";
	cout << "11 - reverse list\n";
	cout << "Press 0 to exit\n\n";
}

int main() {
	srand(time(0));

	int size, num, choice, pos, res, num2;

	cout << "Enter size of list: ";
	cin >> size;

	list list(size);
	list.print();

	while (true) {
		menu();
		cout << "Enter your choice: ";
		cin >> choice;

		if (!choice)
			break;

		switch (choice)
		{
		case 1:
			cout << "Enter a number: ";
			cin >> num;

			list.add_head(num);
			list.print();

			break;
		case 2:
			cout << "Enter a number: ";
			cin >> num;

			list.add_tail(num);
			list.print();
			break;
		case 3:
			if (!list.is_empty()) {
				list.delete_head();
				list.print();
			}

			else
				cout << "List is empty\n";

			break;
		case 4:
			if (!list.is_empty()) {
				list.delete_tail();
				list.print();
			}

			else
				cout << "List is empty\n";

			break;
		case 5:
			cout << "Enter value: ";
			cin >> num;

			cout << "Enter position: ";
			cin >> pos;

			list.add_pos(num, pos);
			list.print();

			break;
		case 6:
			cout << "Enter position: ";
			cin >> pos;

			list.delete_pos(pos);
			list.print();

			break;
		case 7:
			cout << "Enter a number: ";
			cin >> num;

			res = list.find(num);
			if (res != -1)
				cout << "Found!\nPosition: " << res << endl;

			else
				cout << "Not found!\n\n";


			break;
		case 8:
			cout << "Enter a number: ";
			cin >> num;

			cout << "Enter a new number: ";
			cin >> num2;

			list.replace_value(num, num2);
			list.print();

			break;
		case 9:
			cout << "Enter a number: ";
			cin >> num;

			list.delete_value(num);
			list.print();

			break;
		case 10:
			if (!list.is_empty()) {
				list.clear();
				list.print();
			}

			else
				cout << "List is empty\n";
			break;
		case 11:
			list.reverse();
			list.print();

			break;
		default:
			cout << "Wrong option\n\n";
			break;
		}
	}













	return 0;
}