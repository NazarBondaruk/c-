#include "poli_inher(Header).h"

void animal::print() const {
	cout << "Animal name: " << an_name;
	cout << "\nAnimal count: " << an_count << endl;
}

void bird::print() const {
	cout << "Animal name: " << an_name;
	cout << "\nAnimal count: " << an_count << endl;
}

void reptile::print() const {
	cout << "Animal name: " << an_name;
	cout << "\nAnimal count: " << an_count << endl;
}

void mammal::print() const {
	cout << "Animal name: " << an_name;
	cout << "\nAnimal count: " << an_count << endl;
}

hawk::hawk(): an_name("No instance for this name"), an_count(0) {}
hawk::hawk(int an_count, string an_name) { this->an_count = an_count; this->an_name = an_name; }
void hawk::print() const { 
	cout << "Animal name: " << an_name;
	cout << "\nAnimal count: " << an_count << endl;
}
void hawk::set() {
	cout << "Enter animal name(HAWK): ";
	getline(cin, an_name);
	cout << "Enter animal count: ";
	(cin >> an_count).get();
	cout << endl;
}

falcon::falcon() : an_name("No instance for this name"), an_count(0) {}
falcon::falcon(int an_count, string an_name) { this->an_count = an_count; this->an_name = an_name; }
void falcon::print() const {
	cout << "Animal name: " << an_name;
	cout << "\nAnimal count: " << an_count << endl;
}
void falcon::set() {
	cout << "Enter animal name(FALCON): ";
	getline(cin, an_name);
	cout << "Enter animal count: ";
	(cin >> an_count).get();
	cout << endl;
}

snake::snake() : an_name("No instance for this name"), an_count(0) {}
snake::snake(int an_count, string an_name) { this->an_count = an_count; this->an_name = an_name; }
void snake::print() const {
	cout << "Animal name: " << an_name;
	cout << "\Animal count: " << an_count << endl;
}
void snake::set() {
	cout << "Enter animal name(SNAKE): ";
	getline(cin, an_name);
	cout << "Enter animal count: ";
	(cin >> an_count).get();
	cout << endl;
}

viper::viper() : an_name("No instance for this name"), an_count(0) {}
viper::viper(int an_count, string an_name) { this->an_count = an_count; this->an_name = an_name; }
void viper::print() const {
	cout << "Animal name: " << an_name;
	cout << "\nAnimal count: " << an_count << endl;
}
void viper::set() {
	cout << "Enter animal name(VIPER): ";
	getline(cin, an_name);
	cout << "Enter animal count: ";
	(cin >> an_count).get();
	cout << endl;
}

marten::marten() : an_name("No instance for this name"), an_count(0) {}
marten::marten(int an_count, string an_name) { this->an_count = an_count; this->an_name = an_name; }
void marten::print() const {
	cout << "Animal name: " << an_name;
	cout << "\nAnimal count: " << an_count << endl;
}
void marten::set() {
	cout << "Enter animal name(MARTEN): ";
	getline(cin, an_name);
	cout << "Enter animal count: ";
	(cin >> an_count).get();
	cout << endl;
}

cat::cat() : an_name("No instance for this name"), an_count(0) {}
cat::cat(int an_count, string an_name) { this->an_count = an_count; this->an_name = an_name; }
void cat::print() const {
	cout << "Animal name: " << an_name;
	cout << "\nAnimal count: " << an_count << endl;
}
void cat::set() {
	cout << "Enter animal name(CAT): ";
	getline(cin, an_name);
	cout << "Enter animal count: ";
	(cin >> an_count).get();
	cout << endl;
}

red_book::red_book() : hawks(nullptr), falcons(nullptr), snakes(nullptr),
vipers(nullptr), martens(nullptr), cats(nullptr), animals(nullptr), size_h(0), size_f(0),
size_s(0), size_v(0), size_m(0), size_c(0), size_B(0), size_R(0), size_M(0), size_A(0) {}

red_book::red_book(int size_h, int size_f, int size_s, int size_v, int size_m, int size_c) {
	hawks = new hawk[size_h]; falcons = new falcon[size_f];
	snakes = new snake[size_s]; vipers = new viper[size_v];
	martens = new marten[size_m]; cats = new cat[size_c];

	this->size_h = size_h; this->size_f = size_f;
	this->size_s = size_s; this->size_v = size_v;
	this->size_m = size_m; this->size_c = size_c;

	size_B = size_h + size_f; size_R = size_s + size_v; size_M = size_m + size_c;
	size_A = size_B + size_R + size_M;

	birds = new bird[size_B]; reptiles = new reptile[size_R]; mammals = new mammal[size_M];
	animals = new animal[size_A];
}

void red_book::set() {
	int b = 0, r = 0, m = 0, j = 0;

	for (int i = 0; i < size_h; i++)
	{
		hawks[i].set();

		birds[b].an_name = hawks[i].an_name;
		birds[b].an_count = hawks[i].an_count;

		animals[j].an_name = hawks[i].an_name;
		animals[j++].an_count = hawks[i].an_count;

		b++;
	}
	for (int i = 0; i < size_h; i++)
	{
		falcons[i].set();

		birds[b].an_name = falcons[i].an_name;
		birds[b].an_count = falcons[i].an_count;

		animals[j].an_name = falcons[i].an_name;
		animals[j++].an_count = falcons[i].an_count;

		b++;
	}


	for (int i = 0; i < size_h; i++)
	{
		snakes[i].set();

		reptiles[r].an_name = snakes[i].an_name;
		reptiles[r].an_count = snakes[i].an_count;

		animals[j].an_name = snakes[i].an_name;
		animals[j++].an_count = snakes[i].an_count;

		r++;
	}
	for (int i = 0; i < size_h; i++)
	{
		vipers[i].set();

		reptiles[r].an_name = vipers[i].an_name;
		reptiles[r].an_count = vipers[i].an_count;

		animals[j].an_name = vipers[i].an_name;
		animals[j++].an_count = vipers[i].an_count;

		r++;
	}

	for (int i = 0; i < size_h; i++)
	{
		martens[i].set();

		mammals[m].an_name = martens[i].an_name;
		mammals[m].an_count = martens[i].an_count;

		animals[j].an_name = martens[i].an_name;
		animals[j++].an_count = martens[i].an_count;

		m++;
	}
	for (int i = 0; i < size_h; i++)
	{
		cats[i].set();

		mammals[m].an_name = cats[i].an_name;
		mammals[m].an_count = cats[i].an_count;

		animals[j].an_name = cats[i].an_name;
		animals[j++].an_count = cats[i].an_count;

		m++;
	}
}

void red_book::print() const {
	for (int i = 0; i < size_h; i++)
		hawks[i].print();
	cout << string(100, '-') << endl;

	for (int i = 0; i < size_f; i++)
		falcons[i].print();
	cout << string(100, '-') << endl;

	for (int i = 0; i < size_s; i++)
		snakes[i].print();
	cout << string(100, '-') << endl;

	for (int i = 0; i < size_v; i++)
		vipers[i].print();
	cout << string(100, '-') << endl;

	for (int i = 0; i < size_m; i++)
		martens[i].print();
	cout << string(100, '-') << endl;

	for (int i = 0; i < size_c; i++)
		cats[i].print();
	cout << string(100, '-') << endl;
}

void red_book::highest() {
	animal max = animals[0];

	for (int i = 1; i < size_A; i++)
	{
		if (animals[i].an_count > max.an_count) {
			max.an_name = animals[i].an_name;
			max.an_count = animals[i].an_count;
		}
	}

	max.print();
}

void red_book::lowest() {
	animal min = animals[0];

	for (int i = 1; i < size_A; i++)
	{
		if (animals[i].an_count < min.an_count) {
			min.an_name = animals[i].an_name;
			min.an_count = animals[i].an_count;
		}
	}

	min.print();
}

red_book::~red_book() {
	delete[] hawks; delete[] falcons;
	delete[] snakes; delete[] vipers;
	delete[] martens; delete[] cats;

	delete[] birds; delete[] reptiles; delete[] mammals;

	delete[] animals;
}