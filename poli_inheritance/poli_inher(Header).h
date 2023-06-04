#include <iostream>
#include <string>

using namespace std;

class red_book;
class animal {
	string an_name;
	int an_count;
	friend class red_book;
public:
	void print() const;
};

class bird : public animal{
	string an_name;
	int an_count;
	friend class red_book;
public:
	void print() const;
};
class reptile : public animal{
	string an_name;
	int an_count;
	friend class red_book;
public:
	void print() const;
};
class mammal : public animal{
	string an_name;
	int an_count;
	friend class red_book;
public:
	void print() const;
};

class hawk : public bird{
	string an_name;
	int an_count;
public:
	hawk();
	hawk(int, string);
	void print() const;
	void set();
	friend class red_book;
};

class falcon : public bird {
protected:
	string an_name;
	int an_count;
public:
	falcon();
	falcon(int, string);
	void print() const;
	void set();
	friend class red_book;
};

class snake : public reptile {
	string an_name;
	int an_count;
public:
	snake();
	snake(int, string);
	void print() const;
	void set();
	friend class red_book;
};

class viper : public reptile {
	string an_name;
	int an_count;
public:
	viper();
	viper(int, string);
	void print() const;
	void set();
	friend class red_book;
};

class marten : public mammal {
	string an_name;
	int an_count;
public:
	marten();
	marten(int, string);
	void print() const;
	void set();
	friend class red_book;
};

class cat : public mammal {
	string an_name;
	int an_count;
public:
	cat();
	cat(int, string);
	void print() const;
	void set();
	friend class red_book;
};

class red_book {
	hawk* hawks;
	falcon* falcons;
	snake* snakes;
	viper* vipers;
	marten* martens;
	cat* cats;

	bird* birds;
	reptile* reptiles;
	mammal* mammals;

	animal* animals;

	int size_h, size_f, size_s, size_v, size_m, size_c;
	int size_B, size_R, size_M;
	int size_A;
public:
	red_book();
	red_book(int, int, int, int, int, int);
	void set();
	void print() const;
	void lowest();
	void highest();
	~red_book();
};
