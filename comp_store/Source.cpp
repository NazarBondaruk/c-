#include <iostream>
using namespace std;

class sys_unit {
	char* processor;
	char* moth_board;
	char* ram;
	int sum;
public:
	sys_unit() {
		processor = new char[100];
		moth_board = new char[100];
		ram = new char[100];
		sum = 0;
	}

	sys_unit(char* processor, char* moth_board, char* ram, int sum) {
		this->processor = new char[strlen(processor) + 1];
		strcpy_s(this->processor, strlen(processor) + 1, processor);

		this->moth_board = new char[strlen(moth_board) + 1];
		strcpy_s(this->moth_board, strlen(moth_board) + 1, moth_board);

		this->ram = new char[strlen(ram) + 1];
		strcpy_s(this->ram, strlen(ram) + 1, ram);

		this->sum = sum;
	}

	char* get_proc() const { return processor; }
	char* get_moth_board() const { return moth_board; }
	char* get_ram() const { return ram; }
	int get_sum() const { return sum; }

	void set() {
		int price;
		cout << "Type in type of processor:\n";
		gets_s(processor, 100);
		processor[strlen(processor)] = '\0';

		cout << "Enter price of processor:\n";
		(cin >> price).get();
		sum += price;


		cout << "Type in type of mother board:\n";
		gets_s(moth_board, 100);
		moth_board[strlen(moth_board)] = '\0';

		cout << "Enter price of mother board:\n";
		(cin >> price).get();
		sum += price;


		cout << "Type in type of ram:\n";
		gets_s(ram, 100);
		ram[strlen(ram)] = '\0';

		cout << "Enter price of ram:\n";
		(cin >> price).get();
		sum += price;

		cout << endl;
	}

	void print() const{
		cout << "Processor: " << processor << endl;
		cout << "Mother board: " << moth_board << endl;
		cout << "RAM: " << ram << endl;
		cout << "Price: " << sum << endl << endl;
	}

	~sys_unit() {
		delete[] processor;
		delete[] moth_board;
		delete[] ram;
	}
};

void search_processor(sys_unit* arr, int size, char* proc_str) {
	bool found = false;

	for (int i = 0; i < size; i++)
	{
		if (!strcmp(arr[i].get_proc(), proc_str)) {
			arr[i].print();
			found = true;
		}

	}

	if (found == false)
		cout << "No system units found\n\n";
}

void search_mother_board(sys_unit* arr, int size, char* moth_board_str) {
	bool found = false;

	for (int i = 0; i < size; i++)
	{
		if (!strcmp(arr[i].get_moth_board(), moth_board_str)) {
			arr[i].print();
			found = true;
		}

	}

	if (found == false)
		cout << "No system units found\n\n";
}

void search_RAM(sys_unit* arr, int size, char* ram_str) {
	bool found = false;

	for (int i = 0; i < size; i++)
	{
		if (!strcmp(arr[i].get_ram(), ram_str)) {
			arr[i].print();
			found = true;
		}

	}

	if (found == false)
		cout << "No system units found\n\n";
}

void menu_sys_unit() {
	cout << "1 - processor\n";
	cout << "2 - mother board\n";
	cout << "3 - ram\n\n";
}

class monitor {
	char* resolution;
	char* screen_type;
	int size;
	int price;
public:
	monitor() {
		resolution = new char[100];
		screen_type = new char[100];
		size = 0;
		price = 0;
	}

	monitor(char* resolution, char* screen_type, int size, int price) {
		this->resolution = new char[strlen(resolution) + 1];
		strcpy_s(this->resolution, strlen(resolution) + 1, resolution);

		this->screen_type = new char[strlen(screen_type) + 1];
		strcpy_s(this->screen_type, strlen(screen_type) + 1, screen_type);

		this->size = size;
		this->price = price;
	}

	void set() {
		cout << "Type in resolution:\n";
		gets_s(resolution, 100);
		resolution[strlen(resolution)] = '\0';

		cout << "Type in type of screen type:\n";
		gets_s(screen_type, 100);
		screen_type[strlen(screen_type)] = '\0';

		cout << "Type in size:\n";
		cin >> size;

		cout << "Enter price of monitor:\n";
		(cin >> price).get();

		cout << endl;
	}
	
	char* get_resolution() const { return resolution; }
	char* get_screen_type() const { return screen_type; }
	int get_size() const { return size; }
	int get_price() const { return price; }

	void print() {
		cout << "Resolution: " << resolution << endl;
		cout << "Screen type: " << screen_type << endl;
		cout << "Size: " << size << endl;
		cout << "Price: " << price << endl << endl;
	}

	~monitor() {
		delete[] resolution;
		delete[] screen_type;
	}
};

void search_res(monitor* arr, int size, char* res_str) {
	bool found = false;

	for (int i = 0; i < size; i++)
	{
		if (!strcmp(arr[i].get_resolution(), res_str)) {
			arr[i].print();
			found = true;
		}

	}

	if (found == false)
		cout << "No monitors found\n\n";
}

void search_screen(monitor* arr, int size, char* screen_str) {
	bool found = false;

	for (int i = 0; i < size; i++)
	{
		if (!strcmp(arr[i].get_screen_type(), screen_str)) {
			arr[i].print();
			found = true;
		}

	}

	if (found == false)
		cout << "No monitors found\n\n";
}

void search_size(monitor* arr, int size, int find_size) {
	bool found = false;

	for (int i = 0; i < size; i++)
	{
		if (arr[i].get_size() == find_size) {
			arr[i].print();
			found = true;
		}

	}

	if (found == false)
		cout << "No monitors found\n\n";
}

void menu_monitor() {
	cout << "1 - resolution\n";
	cout << "2 - screen type\n";
	cout << "3 - size\n";
}

int main() {
	int choice, size, size_monitor, find_size;

	char* search_proc = new char[100];
	char* search_moth_board = new char[100];
	char* search_ram = new char[100];

	char* search_resolution = new char[100];
	char* search_screen_type = new char[100];

	cout << "Enter size of system unit's array: ";
	(cin >> size).get();

	sys_unit* uArr = new sys_unit[size];

	for (int i = 0; i < size; i++)
		uArr[i].set();

	for (int i = 0; i < size; i++)
		uArr[i].print();

	cout << "Enter size of monitor's array: ";
	(cin >> size_monitor).get();

	monitor* mArr = new monitor[size_monitor];

	for (int i = 0; i < size_monitor; i++)
		mArr[i].set();

	for (int i = 0; i < size_monitor; i++)
		mArr[i].print();


	while (true) {
		cout << "1 - browse system units, 2 - browse monitors\nPress 0 to exit\nYour choice: ";
		(cin >> choice).get();
		cout << endl;

		if (!choice)
			break;

		else if (choice == 1) {
			menu_sys_unit();
			cout << "Enter choice:\n";
			(cin >> choice).get();

			switch (choice) {
			case 1:
				cout << "Enter a processor you are looking for:\n";
				gets_s(search_proc, 100);
				search_proc[strlen(search_proc)] = '\0';
				cout << "Results:\n";
				search_processor(uArr, size, search_proc);
				break;
			case 2:
				cout << "Enter a mother board you are looking for:\n";
				gets_s(search_moth_board, 100);
				search_moth_board[strlen(search_moth_board)] = '\0';
				cout << "Results:\n";
				search_mother_board(uArr, size, search_moth_board);
				break;
			case 3:
				cout << "Enter a ram you are looking for:\n";
				gets_s(search_ram, 100);
				search_ram[strlen(search_ram)] = '\0';
				cout << "Results:\n";
				search_RAM(uArr, size, search_ram);
				break;
			default:
				cout << "Wrong option\n\n";
				break;
			}
		}

		else if (choice == 2) {
			menu_monitor();
			cout << "Enter choice:\n";
			(cin >> choice).get();

			switch (choice)
			{
				case 1:
					cout << "Enter a resolution you are looking for:\n";
					gets_s(search_resolution, 100);
					search_resolution[strlen(search_resolution)] = '\0';
					cout << "Results:\n";
					search_res(mArr, size_monitor, search_resolution);
					break;
				case 2:
					cout << "Enter a screen type you are looking for:\n";
					gets_s(search_screen_type, 100);
					search_screen_type[strlen(search_screen_type)] = '\0';
					cout << "Results:\n";
					search_screen(mArr, size_monitor, search_screen_type);
					break;
				case 3:
					cout << "Enter a size you are looking for:\n";
					(cin >> find_size).get();
					cout << "Results:\n";
					search_size(mArr, size_monitor, find_size);
					break;
				default:
					cout << "Wrong option\n\n";
					break;
			}
		}

		else cout << "Wrong option\n";
	}



	return 0;
}