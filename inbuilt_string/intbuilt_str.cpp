#include <iostream>
#include <iomanip>
#include <time.h>
#include <string>

using namespace std;

class person {
	string name;
	int age;
public:
	person() {
		name = "No instance for this name\n";
		age = 0;
	}

	person(string name, int age) {
		this->name = name;
		this->age = age;
	}

	string get_name() const { return name; }
	int get_age() const { return age; }

	void print() const {
		cout << "Name: " << name << endl << "Age: " << age << endl << endl;
	}
};

void menu() {
	cout << "\n1 - print text\n";
	cout << "2 - print size\n";
	cout << "3 - amount of words in text and positions\n";
	cout << "4 - swap word\n";
	cout << "5 - delete word\n";
	cout << "6 - reverse\n\n";
}

int main() {
	srand(time(0));
	//1.--------------------------------------------------------------
	string input_str;

	cout << "Enter string: ";
	getline(cin, input_str);

	input_str.append("ABC");

	for (int i = 0; i < input_str.length(); i++) {
		if (input_str[i] == 'z') {
			input_str.erase(i, 1);
			i--;
		}
	}

	cout << "New string: " << input_str << endl << endl;
	cout << string(100, '-') << "\n\n";

	//2.-------------------------------------------------------
	string text, str, str_new;
	int choice, pos = 0, i = 0, ind = 0;
	char tmp;

	cout << "Enter text:\n";
	getline(cin, text);

	while (true) {
		menu();
		cout << "Enter choice:\n";
		(cin >> choice).get();
		cout << endl;

		switch (choice)
		{
		case 1:
			cout << text << endl;
			break;
		case 2:
			cout << text.length() << endl;
			break;
		case 3:
			cout << "Enter a word: ";
			getline(cin, str);

			cout << "Positions: ";
			pos = text.find(str);

			if (pos == -1) cout << "Not found!!!\n";

			else {
				while (pos != -1) {
					cout << pos << " ";
					pos = text.find(str, pos + 1);
					ind++;
				}
			}

			cout << "\nAmount: " << ind << endl;

			break;
		case 4:
			i = 0;
			cout << "Enter a word to change: ";
			getline(cin, str);

			cout << "Enter a new word: ";
			getline(cin, str_new);

			pos = text.find(str, i);
			text.erase(pos, pos + str.size());

			text.insert(pos, str_new);

			cout << text << endl;

			break;
		case 5:
			cout << "Enter a word to delete: ";
			getline(cin, str);

			pos = text.find(str, i);
			text.erase(pos, pos + str.size());
			cout << text << endl;

			break;
		case 6:
			for (int i = 0; i < text.size()/2; i++)
			{
				tmp = text[i];
				text[i] = text[text.size() - 1 - i];
				text[text.size() - 1 - i] = tmp;
			}

			cout << text << endl;

			break;
		default:
			cout << "Wrong option\n\n";
			break;
		}
	}



	//-----------------------------

	/*person p1("John", 23);
	p1.print();

	person p2;
	p2.print();*/

	//--------------------------------
	//practise
	/*string str1 = "Hello";
	string str2 = " World";


	if (str1 != str2)
		cout << "Different\n";
	else cout << "Same\n";

	if (str1 >= str2)
		cout << "str1 >= str2\n";
	else cout << "str1 <= str2\n";

	cout << str1[2] << endl;

	str1.append(str2);
	cout << str1 << endl << "Size: " << str1.length() << endl;

	str1.insert(str1.size(), 1, '!');
	cout << str1 << endl;

	str2.erase(0, 3);
	cout << str2 << endl;

	str2.replace(0, str2.size(), "World!");
	cout << str2 << endl;

	if (str1.empty())
		cout << "Str1 is empty\n";
	else
		cout << "Str1 contains symbols\n";

	if (str1.find("Hello") >= 0)
		cout << "Str1 contains this substring\n";*/

		//------------




	return 0;
}