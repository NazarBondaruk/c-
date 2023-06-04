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

//2
class dict {
	map<int, string> word_book;
	static int word_key;
public:
	void upload_dict(string path) {
		ifstream fin; pair<int, string> it; int i = 1;
		fin.open(path);

		if (!fin.is_open())
			cout << "Path error!\n";
		else {
			while (fin >> it.first >> it.second) {
				word_book.insert({ it.first, it.second });
				i++;
			}

			word_key = i;
		}

		fin.close();
	}

	void add(string add_word) { word_book.insert({ word_key++, add_word }); }

	void print() const {
		cout << string(100, '-');
		for (auto it : word_book)
			cout << "\nWord number: " << it.first << " | Word: " << it.second << endl;
		cout << string(100, '-') << endl;
	}

	pair<int, string> search_word(string find_word) {
		for (auto it : word_book) 
			if (it.second == find_word)
				return it;

		throw exception("Word not found!\n");
	}

	void edit_word(int word_key, string new_word) {
		for (auto it : word_book) {
			if (it.first == word_key) {
				it.second = new_word; 
				return;
			}
		}

		cout << "Invalid word number\n";
	}

	void delete_word(string del_word) {
		int i = 1;
		for (auto it : word_book) {
			if (it.second == del_word) {
				word_book.erase({ i });
				return;
			}
			i++;
		}

		cout << "Word not found!\n";
	}

	void save_dict(string path) {
		ofstream fout; pair<int, string> it;
		fout.open(path);

		if (!fout.is_open())
			cout << "Path error!\n";

		else {
			for (auto it : word_book) {
				fout << it.first << " " << it.second << endl;
			}
		}

		fout.close();
	}
};

void menu() {
	cout << "\n 1 - print dictionary\n";
	cout << " 2 - edit word by number\n";
	cout << " 3 - delete word\n";
	cout << " 4 - search word\n";
	cout << " 5 - add word\n";
	cout << " Press 0 to exit\n\n";
}

int dict::word_key = 1;

int main() {
	srand(time(0));

	//3
	ifstream fin; string word, path_fin = "doc.txt", path_fout = "doc2.txt";
	map<string, int> freq_dict;

	fin.open(path_fin);
	if (!fin.is_open())
		cout << "Path error!\n";
	else {
		while (fin >> word) {
			bool found = false;
			for (auto it : freq_dict) {
				if (word == it.first) {
					it.second++;
					found = true;
				}
			}
			if(!found)
				freq_dict.insert({ word, 1 });
		}

		cout << "Word statistic\n";
		for (auto it : freq_dict)
			cout << " Word: " << it.first << " | Frequency: " << it.second << endl;

		cout << "\n\nMost frequent word: ";

		string find_word; int freq = 0;
		for (auto it : freq_dict) {
			if (it.second >= freq) {
				find_word = it.first; freq = it.second;
			}
		}

		cout << find_word << " | Frequency: " << freq << endl;

		ofstream fout;
		fout.open(path_fout);

		for (auto it : freq_dict)
			fout << it.first << " " << it.second << endl;

		fout.close();
	}

	fin.close();





	//2
	/*dict word_book; int choice, num; 
	string word, path = "doc.txt";

	word_book.upload_dict(path);

	while (true) {
		menu();
		cout << "Enter your choice: ";
		(cin >> choice).get();

		if (!choice)
			break;

		switch (choice)
		{
		case 1:
			word_book.print();
			break;
		case 2:
			cout << "Enter word number: ";
			(cin >> num).get();

			cout << "Enter new word: ";
			getline(cin, word);

			word_book.edit_word(num, word);
			break;

		case 3:
			cout << "Enter word to delete: ";
			getline(cin, word);

			word_book.delete_word(word);
			break;

		case 4:
			cout << "Enter word to search: ";
			getline(cin, word);

			try {
				cout << "Number: " << word_book.search_word(word).first <<
					" | Word: " << word_book.search_word(word).second << endl;
			}

			catch (exception ex) {
				cout << ex.what();
			}

			break;
		case 5:
			cout << "Enter word to add: ";
			getline(cin, word);

			word_book.add(word);
			break;
		default:
			cout << "Wrong option\n\n";
			break;
		}
	}

	word_book.save_dict(path);
*/




	return 0;
}