#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>

using namespace std;

class logistics {
protected:
	string set_off;
	string drop_off;
	int route_length;
	int price;
public:
	logistics();
	logistics(string, string, int, double);
	virtual void print() const;
	virtual double eval_price() = 0;
};

class train_logist : public logistics {
protected:
	int longRoute_discount;
public:
	train_logist();
	train_logist(string, string, int, double);
	void print() const override;
	double eval_price() override;
};

class air_logist : public logistics {
protected:
	int cargo_insurance;
public:
	air_logist();
	air_logist(string, string, int, double, int);
	void print() const override;
	double eval_price() override;
};

class sea_logist : public logistics {
protected:
	int accomod_price;
public:
	sea_logist();
	sea_logist(string, string, int, double);
	void print() const override;
	double eval_price() override;
};

class auto_logist : public logistics {
protected:
	int safetyMeasures_price;
public:
	auto_logist();
	auto_logist(string, string, int, double);
	void print() const override;
	double eval_price() override;
};

