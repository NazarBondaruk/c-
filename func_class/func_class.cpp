#include <iostream>
#include <iomanip>
#include <time.h>
#include <vector>
#include <string>
//#include <list>
#include <forward_list>
#include <map>	
#include <array>	
#include <deque>	
#include <set>	
#include <stack>	
#include <queue>	
#include <functional>
#include <algorithm>

using namespace std;

void func(int a) {
	cout << a << endl;
}

void func2(int a) {
	cout << "A: " << a << endl;
}

int sum(int a, int b) {
	return a + b;
}

int dif(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

int calc(int a, int b, function<int(int, int)> callback) {
	return callback(a, b);
}

void printEl(int el) {
	cout << el << " ";
}

void print_evenEl(int el) {
	if (el % 2 == 0)
		cout << el << " ";
}

void print_oddEl(int el) {
	if (el % 2 != 0)
		cout << el << " ";
}

void print_positiveEl(int el) {
	if (el > 0)
		cout << el << " ";
}

void print_negativeEl(int el) {
	if (el < 0)
		cout << el << " ";
}

void print_vector(vector<int> v, function<void(int)> callback) {
	for (auto el : v)
		callback(el);
}

/*
 anonymous funcs:
		[захоплення даних](параметри){
			ТІЛО ФУНКЦІЇ;
		}
*/

bool is_pos(int el) {
	return el > 0;
}

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

class list {
	struct element {
		int data;
		element* next;
	};
	element* head, * tail;
	int size;
public:
	list() {
		head = tail = nullptr;
		size = 0;
	}
	list(int size) {
		for (int i = 0; i < size; i++)
			addTail(rand() % 101 - 50);
	}
	list(const list& obj) {
		head = tail = 0;
		size = 0;
		*this = obj;
	}
	int getSize() const { return size; }
	bool isEmpty() { return !size; }

	//Додавання елемента в голову(на початок) 
	void addHead(int value) {
		element* newElement = new element;
		newElement->data = value;
		newElement->next = nullptr;
		if (size == 0) head = tail = newElement;
		else {
			newElement->next = head;
			head = newElement;
		}
		size++;
	}
	//Додавання елемента у хвіст(вкінець) 
	void addTail(int value) {
		element* newElement = new element;
		newElement->data = value;
		newElement->next = nullptr;

		if (!size) head = tail = newElement;
		else {
			tail->next = newElement;
			tail = newElement;
		}
		size++;
	}

	//Видалення елемента з голови 
	void deleteHead() {
		if (!size) return;
		element* tmp = head;
		head = head->next;
		delete tmp;
		size--;
	}

	//Видалення елемента з хвоста 
	void deleteTail() {
		if (!size) return;
		if (tail == head) deleteHead();
		else {
			element* tmp = head;
			while (tmp) {
				if (tmp->next == tail) {
					delete tail;
					tail = tmp;

					tail->next = nullptr;
					break;
				}
				tmp = tmp->next;
			}
			size--;
		}
	}

	void remove_if(function<bool(int a)> callback) {
		if (!size) return;
		else {
			element* bef_tmp = head;
			element* tmp = head->next;

			while (tmp) {
				if (callback(tmp->data)) {
					bef_tmp->next = tmp->next;
					tmp = tmp->next;
					size--;
				}
				else {
					tmp = tmp->next;
					bef_tmp = bef_tmp->next;
				}
			}
		}
	}

	int count_if(function<bool(int a)> callback) {
		element* tmp = head; int count = 0;
		while (tmp) {
			if (callback(tmp->data))
				count++;
			tmp = tmp->next;
		}

		return count;
	}

	list copy_if(function<bool(int a)> callback) {
		list l(this->size);
		element* tmp = head;
		element* tmp_newlist = l.head;

		while (tmp) {
			if (callback(tmp->data))
				tmp_newlist->data = tmp->data;

			tmp = tmp->next;
			tmp_newlist = tmp_newlist->next;
		}

		return l;
	}
	int find_if(function<bool(int a)> callback) {
		element* tmp = head;
		while (tmp) {
			if (callback(tmp->data))
				return tmp->data;
			tmp = tmp->next;
		}
	}

	int sum_if(function<bool(int a)> callback) {
		element* tmp = head;
		int sum = 0;
		while (tmp) {
			if (callback(tmp->data))
				sum += tmp->data;
			tmp = tmp->next;
		}

		return sum;
	}

	//Очищення списку 
	void clear() {
		while (head) deleteHead();
	}

	//Додавання елемента в позицію 
	void addPosition(int value, int pos) {
		if (pos > size) return;
		element* newElement = new element;
		newElement->data = value;
		if (!pos) addHead(value);
		else {
			element* tmp = head;
			int i = 0;
			while (i++ < pos - 1)
				tmp = tmp->next;

			newElement->next = tmp->next;
			tmp->next = newElement;

			if (pos == size) tail = newElement;
			size++;
		}
	}

	//Вивід списку 
	void print() const {
		cout << string(35, '-') << "\n";
		cout << "Size: " << size << "\n";
		cout << string(35, '-') << "\n";

		element* tmp = head;
		while (tmp) {
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		cout << "\n";
	}
};

int main() {
	//
	list l(12);
	l.print();
	l.remove_if([](int a) {return a % 10 == 0; });
	cout << "\nList with a % 3 == 0 elements deleted:\n ";  l.print();
	cout << "\nPositive element count: " << l.count_if([](int a) {return a > 0; }) << endl;
	cout << "New list with positive numbers from list 1: \n";
	l.copy_if([](int a) { return a > 0; }).print();
	cout << "\nFirst positive element value: " << l.find_if([](int a) { return a > 0; }) << endl;
	cout << "Sum of positive elements value: " << l.sum_if([](int a) { return a > 0; }) << endl;

	//

	//---------------------------------------------------anonymous funcs

	//list<int> l = { 12,-9, 34, 0, -11, 27 };
	////l.remove_if(is_pos);
	//l.remove_if([](int el) {return el > 0; });

	//for_each(l.begin(), l.end(), [](int el) {cout << el << " "; });


	/*function<void(int)> f = [](int a) {
		cout << "Value: " << a << endl;
	};*/

	//f(-43);

	/*vector<int> v = { 12,-9, 34, 0, -11, 27 };
	print_vector(v, [](int a) {
		cout << "Value: " << a << endl;
		});

	cout << endl;

	print_vector(v, [](int a) {
		if (a % 2 == 0)cout << "Value: " << a << endl;
		});

	cout << endl;

	print_vector(v, [](int a) {
		if (a < 0)cout << "Value: " << a << endl;
		});*/

		/*[](int a) {
			cout << "Value: " << a << endl;
		}*/;


		//---------------------------------------------------
		//---------------------------------------------------

		/*vector<int> v = { 12,-9, 34, 0, -11, 27 };
		int choice;

		cout << "1 - print\n";
		cout << "2 - print even\n";
		cout << "3 - print odd\n";
		cout << "4 - print positive\n";
		cout << "5 - print negative\n";
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			print_vector(v, printEl);
			break;
		case 2:
			print_vector(v, print_evenEl);
			break;
		case 3:
			print_vector(v, print_oddEl);
			break;
		case 4:
			print_vector(v, print_positiveEl);
			break;
		case 5:
			print_vector(v, print_negativeEl);
			break;
		default:
			break;
		}*/



		/*function<int(int, int)> f;
		cout << "Result: " << calc(32, 8, mul) << endl;*/

		//f = sum;
		//cout << "Sum: " << f(23, 89);

		//f = dif;
		//cout << "\nDifference: " << f(23, 89);

		//f = mul;
		//cout << "\nMultiplier: " << f(23, 89);




		return 0;
}