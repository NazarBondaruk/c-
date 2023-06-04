#include "fraction(header).h"

fraction::fraction() : numerator(0), denominator(1) {}

fraction::fraction(int numerator, int denominator) {
	this->numerator = numerator;
	this->denominator = denominator;
}

void fraction::set() {
	cout << "Enter numerator: ";
	cin >> numerator;
	cout << "Enter denominator: ";
	cin >> denominator;
}

void fraction::set_numerator(int n) { numerator = n; }

void fraction::set_denominator(int d) { denominator = d; }

int fraction::get_numerator() const { return numerator; }

int fraction::get_denominator() const { return denominator; }

int fraction::getInteger() const { return numerator / denominator; }

double fraction::getDouble() const { return (double)numerator / denominator; }

void fraction::print() const { cout << "\nFraction: " << numerator << "/" << denominator << "\n"; }

fraction& fraction::operator+=(const fraction& other) {
	this->numerator = this->numerator * other.denominator + other.numerator * this->denominator;
	this->denominator = this->denominator * other.denominator;
	return *this;
}

fraction& fraction::operator-=(const fraction& other) {
	this->numerator = this->numerator * other.denominator - other.numerator * this->denominator;
	this->denominator = this->denominator * other.denominator;
	return *this;
}

fraction& fraction::operator*=(const fraction& other) {
	this->numerator = this->numerator * other.numerator;
	this->denominator = this->denominator * other.denominator;
	return *this;
}

fraction& fraction::operator/=(const fraction& other) {
	this->numerator = this->numerator * other.denominator;
	this->denominator = this->denominator * other.numerator;
	return *this;
}

fraction::operator int() {
	return numerator / denominator;
}

fraction::operator double() {
	return (double)numerator / denominator;
}

//-----------------------------------------------------------------------

fraction operator+(const fraction& f1, int num) {
	return fraction(f1.numerator * 1 + num * f1.denominator,
		1 * f1.denominator
	);
}

fraction operator-(const fraction& f1, int num) {
	return fraction(f1.numerator * 1 - num * f1.denominator,
		1 * f1.denominator
	);
}

fraction operator*(const fraction& f1, int num) {
	return fraction(f1.numerator * num ,
		f1.denominator
	);
}

fraction operator/(const fraction& f1, int num) {
	return fraction(f1.numerator,
		f1.denominator * num
	);
}

//--------------------------------------------------------------
fraction operator+(int num, const fraction& f1) {
	return fraction(f1.numerator * 1 + num * f1.denominator,
		1 * f1.denominator
	);
}

fraction operator-(int num, const fraction& f1) {
	return fraction(num * f1.denominator + f1.numerator,
		f1.denominator
	);
}

fraction operator*(int num, const fraction& f1) {
	return fraction(f1.numerator * num,
		f1.denominator
	);
}

fraction operator/(int num, const fraction& f1) {
	return fraction(f1.denominator * num,
		f1.numerator
	);
}

//---------------------------------------------------------------

fraction operator+(const fraction& f1, const fraction& f2) {
	return fraction(f1.numerator * f2.denominator + f2.numerator * f1.denominator,
		f2.denominator * f1.denominator
	);
}

fraction operator-(const fraction& f1, const fraction& f2) {
	return fraction(f1.numerator * f2.denominator - f2.numerator * f1.denominator,
		f2.denominator * f1.denominator
	);
}

fraction operator*(const fraction& f1, const fraction& f2) {
	return fraction(f1.numerator * f2.numerator,
		f2.denominator * f1.denominator
	);
}

fraction operator/(const fraction& f1, const fraction& f2) {
	return fraction(f1.numerator * f2.denominator,
		f1.denominator * f1.numerator
	);
}

//----------------------------------------------------------------------------

fraction operator++(const fraction& f) {
	return fraction(f.numerator * f.denominator + f.denominator * f.denominator,
		f.denominator * f.denominator
	);
}

fraction operator--(const fraction& f) {
	return fraction(f.numerator * f.denominator - f.denominator * f.denominator,
		f.denominator * f.denominator
	);
}

bool operator==(const fraction& f1, const fraction& f2) {
	return f1.getDouble() == f2.getDouble();
}

bool operator!=(const fraction& f1, const fraction& f2) {
	return f1.getDouble() != f2.getDouble();
}

bool operator>(const fraction& f1, const fraction& f2) {
	return f1.getDouble() > f2.getDouble();
}

bool operator<(const fraction& f1, const fraction& f2) {
	return f1.getDouble() < f2.getDouble();
}

bool operator>=(const fraction& f1, const fraction& f2) {
	return f1.getDouble() >= f2.getDouble();
}

bool operator<=(const fraction& f1, const fraction& f2) {
	return f1.getDouble() <= f2.getDouble();
}

ostream& operator <<(ostream& os, const fraction& f) {
	f.print();
	return os;
}

istream& operator>>(istream& is, fraction& f) {
	f.set();
	return is;
}
