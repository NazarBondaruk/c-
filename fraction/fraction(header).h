#include<iostream>

using namespace std;

class fraction {
	int numerator;
	int denominator;
public:
	fraction();

	fraction(int, int);

	void set();

	void set_numerator(int);
	void set_denominator(int);

	int get_numerator() const;
	int get_denominator() const;

	int getInteger() const;
	double getDouble() const;

	void print() const;

	//+= -= *= /=

	operator int();

	operator double();

	fraction& operator+=(const fraction&);
	fraction& operator-=(const fraction&);
	fraction& operator*=(const fraction&);
	fraction& operator/=(const fraction&);


	friend fraction operator+(const fraction&, const fraction&);
	friend fraction operator-(const fraction&, const fraction&);
	friend fraction operator*(const fraction&, const fraction&);
	friend fraction operator/(const fraction&, const fraction&);

	friend fraction operator+(const fraction&, int);
	friend fraction operator-(const fraction&, int);
	friend fraction operator*(const fraction&, int);
	friend fraction operator/(const fraction&, int);

	friend fraction operator+(int, const fraction&);
	friend fraction operator-(int, const fraction&);
	friend fraction operator*(int, const fraction&);
	friend fraction operator/(int, const fraction&);

	friend fraction operator++(const fraction&);
	friend fraction operator--(const fraction&);
};

// + - * /
//fraction operator+(const fraction& f1, const fraction& f2) {
//	fraction f;
//	f.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
//	f.denominator = f2.denominator * f1.denominator;
//	return f;
//}

//fraction operator+(fraction& f1, fraction& f2) {
//	return f1.add(f2);
//}

// == != > < <= >=
bool operator==(const fraction&, const fraction&);

bool operator!=(const fraction&, const fraction&);

bool operator>(const fraction&, const fraction&);

bool operator<(const fraction&, const fraction&);

bool operator>=(const fraction&, const fraction&);

bool operator<=(const fraction&, const fraction&);

ostream& operator <<(ostream&, const fraction&);

istream& operator>>(istream&, fraction&);

