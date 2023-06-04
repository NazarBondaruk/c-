#include<iostream> 
#include<iomanip> 
#include<time.h> 
#include<string> 

using namespace std;

class cap {
	string color;
public: cap(string color) {
	this->color = color;
}
	  string getCap() const { return color; }
};

class brain {
public:
	void think() {
		cout << "I think\n";
	}
};

class human {
	brain b;
	cap* c;
public:
	human(cap* c) {
		this->c = c;
	}

	void think() {
		b.think();
	}
};

class citizen {
	string name;
public:
	citizen() : name("No name") {}

	citizen(string name) {
		this->name = name;
	}

	void print() const {
		cout << "Name: " << name << endl;
	}

	string get_name() const { return name; }

	void set() {
		cout << "Enter name:\n";
		cin >> name;
	}
};

class state {
	citizen* people;
public:
	state() : people(nullptr) {}

	state(citizen* arr) {
		people = arr;
	}



	void print(int size) const {
		for (int i = 0; i < size; i++)
			people[i].print();

		cout << endl;
	}

};

class processor {
	string name;
	int core_amount;
	int price;
public:
	processor() : name("No instance for this name"), core_amount(0), price(0) {}

	processor(string name, int core_amount, int price) {
		this->name = name;
		this->core_amount = core_amount;
		this->price = price;
	}

	void set() {
		cout << "Enter name of processor:\n";
		getline(cin, name);

		cout << "Enter core amount:\n";
		cin >> core_amount;

		cout << "Entre price:\n";
		(cin >> price).get();
	}

	string get_name() const { return name; }
	int get_coreAmount() const { return core_amount; }
	int get_price() const { return price; }

	void print() const {
		cout << "Name of processor: " << name;
		cout << "\nCore amount: " << core_amount;
		cout << "\nPrice: " << price << "\n\n";
	}
};

class ram {
	string name;
	int mem_volume;
	int price;
public:
	ram() : name("No instance for this name"), mem_volume(0), price(0) {}

	ram(string name, int mem_volume, int price) {
		this->name = name;
		this->mem_volume = mem_volume;
		this->price = price;
	}

	void set() {
		cout << "Enter name of ram:\n";
		getline(cin, name);

		cout << "Enter volume of memory:\n";
		cin >> mem_volume;

		cout << "Enter price:\n";
		(cin >> price).get();
	}

	string get_name() const { return name; }
	int get_memVolume() const { return mem_volume; }
	int get_price() const { return price; }

	void print() const {
		cout << "Name of ram: " << name;
		cout << "\nVolume of memory: " << mem_volume;
		cout << "\nPrice: " << price << "\n\n";
	}
};

class videocard {
	string name;
	string GPU_name;
	int price;
public:
	videocard() : name("No instance for this name"), GPU_name("No instance for this name"), price(0) {}

	videocard(string name, int GPU_name, int price) {
		this->name = name;
		this->GPU_name = GPU_name;
		this->price = price;
	}

	void set() {
		cout << "Enter name of company:\n";
		getline(cin, name);

		cout << "Enter GPU name:\n";
		getline(cin, GPU_name);

		cout << "Enter price:\n";
		(cin >> price).get();
	}

	string get_name() const { return name; }
	string get_GPU_name() const { return GPU_name; }
	int get_price() const { return price; }

	void print() const {
		cout << "Name of company: " << name;
		cout << "\nGPU name: " << GPU_name;
		cout << "\nPrice: " << price << "\n\n";
	}
};

class sys_unit {
	string name;
	processor* proc;
	videocard* videoCard;
	ram* RAM;
	int price;
public:
	sys_unit(string name, processor* proc, videocard* videoCard, ram* RAM) {
		this->name = name;
		this->proc = proc;
		this->videoCard = videoCard;
		this->RAM = RAM;
		this->price = proc->get_price() + videoCard->get_price() + RAM->get_price();
	}

	void set() {
		cout << "Enter name of system unit:\n";
		getline(cin, name);

		proc->set();
		videoCard->set();
		RAM->set();

		this->price = proc->get_price() + videoCard->get_price() + RAM->get_price();
	}
		
	void print() const {
		cout << string(100, '-') << "\n";
		proc->print();
		videoCard->print();
		RAM->print();
		cout << "Price: " << price << "\n";
		cout << string(100, '-') << "\n\n";
	}
};

int main() {
	srand(time(0));
	processor proc; videocard vc; ram RAM; string name;

	proc.set();
	vc.set();
	RAM.set();
	
	videocard* ptr_vc = new videocard;
	*ptr_vc = vc;

	processor* ptr_proc = new processor;
	*ptr_proc = proc;

	ram* ram_ptr = new ram;
	*ram_ptr = RAM;

	cout << "Enter S.U. name:\n";
	getline(cin, name);

	sys_unit* ptr_su = new sys_unit(name, ptr_proc, ptr_vc, ram_ptr);

	ptr_su->print();

	delete ptr_proc;

	ptr_su->print();






	/*citizen* citizens = new citizen[3]{
		citizen("Max"),
		citizen("Lewis"),
		citizen("Fred")
	};

	state country(citizens);
	country.print(3);

	delete[] citizens;*/

	/*cap* c = new cap("red");
	human h(c);

	h.think();

	delete c;*/

	return 0;
}