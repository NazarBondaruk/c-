#include "train(header).h"

train::train() {
	num = new char[50];
	name = new char[50];
	carr = nullptr;
	carr_count = 0;
}

train::train(char* num, char* name, int* carr, int carr_count) {
	this->num = new char[strlen(num) + 1];
	strcpy_s(this->num, strlen(num) + 1, num);

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->carr_count = carr_count;

	this->carr = new int[carr_count];
	for (int i = 0; i < carr_count; i++)
		this->carr[i] = carr[i];
}

train::train(const train& other) {
	this->num = new char[strlen(other.num) + 1];
	strcpy_s(this->num, strlen(other.num) + 1, other.num);

	this->name = new char[strlen(other.name) + 1];
	strcpy_s(this->name, strlen(other.name) + 1, other.name);

	this->carr_count = other.carr_count;

	this->carr = new int[other.carr_count];
	for (int i = 0; i < other.carr_count; i++)
		this->carr[i] = other.carr[i];
}

void train::set() {
	cout << "Enter train's id:\n";
	gets_s(num, 50);

	cout << "Enter train's name:\n";
	gets_s(name, 100);

	cout << "Enter amount of carriages:\n";
	cin >> carr_count;

	carr = new int[carr_count];

	for (int i = 0; i < carr_count; i++)
	{
		cout << "Enter number of people in carriage " << i + 1 << ": ";
		(cin >> carr[i]).get();
	}
}

char* train::get_num() { return num; }
char* train::get_name() { return name; }
int* train::get_carr() { return carr; }
int train::get_carrCount() { return carr_count; }

void train::print() {
	cout << "\nTrain's number: " << num << endl;
	cout << "Train's name: " << name << endl;
	cout << "Train's amount of carriages: " << carr_count << endl;

	for (int i = 0; i < carr_count; i++)
	{
		cout << "Number of people in carriage " << i + 1 << ": " << carr[i] << endl;
	}

	cout << endl;
}

int train::get_max() {
	int max = carr[0];

	for (int i = 0; i < carr_count; i++)
	{
		if (max < carr[i])
			max = carr[i];
	}

	return max;
}

int train::get_min() {
	int min = carr[0];

	for (int i = 0; i < carr_count; i++)
	{
		if (min > carr[i])
			min = carr[i];
	}

	return min;
}

int train::sum() {
	int sum = 0;

	for (int i = 0; i < carr_count; i++)
		sum += carr[i];

	return sum;
}

train& train::operator=(const train& t) {
	delete[] this->num;
	delete[] this->name;
	delete[] this->carr;

	this->num = new char[strlen(t.num) + 1];
	strcpy_s(this->num, strlen(t.num) + 1, t.num);
	this->num[strlen(t.num)] = '\0';

	this->name = new char[strlen(t.name) + 1];
	strcpy_s(this->name, strlen(t.name) + 1, t.name);
	this->name[strlen(t.name)] = '\0';

	this->carr = new int[t.carr_count];
	for (int i = 0; i < t.carr_count; i++)
		this->carr[i] = t.carr[i];

	this->carr_count = t.carr_count;

	return *this;
}

train::~train() {
	delete[] num;	
	delete[] name;
	delete[] carr;
}

void biggest_carr(train*& tArr, int size) {
	train t = tArr[0];

	for (int i = 0; i < size; i++)
	{
		if (tArr[i].sum() > t.sum())
			t = tArr[i];
	}

	t.print();
}