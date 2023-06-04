#include <iostream>
using namespace std;

class train {
	char* num;
	char* name;
	int* carr;
	int carr_count;
public:
	train();
	train(char*, char*, int*, int);
	train(const train&);
	void set();
	char* get_num();
	char* get_name();
	int* get_carr();
	int get_carrCount();
	void print();
	int get_max();
	int get_min();
	int sum();
	train& operator=(const train&);
	~train();
};

void biggest_carr(train*&, int);