#include <iostream>
#include <iomanip>
#include <time.h>
#include <string>

using namespace std;

struct elem {
	int data;
	elem* next;
};

class list {
	elem* head, * tail;
	int size;
public:
	list() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	list(int size) {
		for (int i = 0; i < size; i++)
			add_tail(rand() % 101 - 50);
	}

	list(const elem& obj) {
		head = tail = 0;
		size = 0;
		*this = obj;
	}

	int get_size() const { return size; }
	bool is_empty() const { return !size; }

	void add_head(int value) {
		elem* newElem = new elem;
		newElem->data = value;
		newElem->next = nullptr;

		if (!size)
			head = tail = newElem;

		else {
			newElem->next = head;
			head = newElem;
		}

		size++;
	}

	void add_tail(int value) {
		elem* newElem = new elem;
		newElem->data = value;
		newElem->next = nullptr;

		elem* tmp = tail;

		if (!size)
			head = tail = newElem;

		else {
			tail = newElem;
			tmp->next = tail;
		}

		size++;
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

		if (!pos) {
			add_head(value);
			return;
		}

		elem* newElem = new elem;
		newElem->data = value;
		newElem->next = nullptr;

		elem* tmp = head;
		int i = 0;

		while (i++ < pos - 1)
			tmp = tmp->next;

		newElem->next = tmp->next;
		tmp->next = newElem;

		if (pos == size)
			tail = newElem;

		size++;
	}

	int find(int value) {
		int i = 0;
		elem* tmp = head;

		while (tmp) {
			if (tmp->data == value)
				return i;

			tmp = tmp->next;
			i++;
		}

		return -1;
	}

	void print() const {
		cout << "Size: " << size << endl;
		cout << string(100, '-') << endl;

		elem* tmp = head;

		while (tmp) {
			cout << tmp->data << " ";
			tmp = tmp->next;
		}

		cout << endl << endl;
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

	elem* side_func(int ind) {
		int i = 0;
		elem* ptr = head;

		while (ptr) {
			if (i == size - 1 - ind) {
				return ptr;
			}

			ptr = ptr->next;
			i++;
		}
	}

	void reverse() {
		elem* ptr_head = head;
		elem* ptr_tail = tail;
		int tmp = 0;

		for (int i = 0; i < size/2; i++)
		{
			ptr_tail = side_func(i);

			tmp = ptr_head->data;
			ptr_head->data = ptr_tail->data;
			ptr_tail->data = tmp;

			ptr_head = ptr_head->next;
		}
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

		elem* tmp = head;
		head = head->next;

		delete tmp;
		size--;
	}

	void delete_tail() {
		if (!size)
			return;

		if (tail == head)
			delete_head();

		int ind = 0;
		elem* find = head;

		while (find) {
			if (ind == size - 2) {
				break;
			}

			find = find->next;
			ind++;
		}

		find->next = nullptr;
		elem* delete_tail = tail;
		tail = find;
		delete delete_tail;

		size--;
	}

	void delete_pos(int pos) {
		int i = 0;

		if (pos >= size) {
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

		elem* tmp = head;
		elem* tmp_side = head;

		while (i++ < pos) {
			tmp_side = tmp;
			tmp = tmp->next;
		}

		tmp_side->next = tmp->next;
		delete tmp;

		size--;
	}

	void clear() {
		while (head)
			delete_head();
	}
};

void menu() {
	cout << "1 - add head\n";
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

	cout << "Enter list size: ";

	int size, num, num2, choice, pos, res;
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