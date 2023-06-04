#include <iostream>
#include <iomanip>
#include <time.h>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <functional>
#include <numeric>
#include <fstream>

using namespace std;

class carStat_network;
class truckStat_network;

class fuel_type {
	string fuel_name;
public:
	fuel_type();
	fuel_type(string);
	void set();
	string get_fuel_type() const;
	void print() const;
	void operator=(const string&);
};

class event_date {
	fuel_type fType;
	string date;
	float fuel_am;
public:
	event_date();
	event_date(string, string, float);
	void set();
	string get_date() const;
	string get_fType() const;
	float get_amount() const;
	void print() const;
};

class gas_stat {
protected:
	float total_fuel_remain;
	vector<event_date> delievery;
	vector<event_date> suppliement;
public:
	void download_data(string, string, string);
	void set();
	void virtual print() const = 0;
	float get_fuel_remain() const;
	vector<event_date> get_delVector() const;
	vector<event_date> get_supVector() const;
	void supply_fuel(event_date&);
	void deliever_fuel(event_date);
	void upload_data(string, string, string);
};

class car_gasStat : public gas_stat {
public:
	car_gasStat(float);
	car_gasStat(float, vector<event_date>, vector<event_date>);
	void download_data(string, string, string);
	void set();
	void print() const override;
	float get_fuel_remain() const;
	vector<event_date> get_delVector() const;
	vector<event_date> get_supVector() const;
	void supply_fuel(event_date);
	void deliever_fuel(event_date);
	void upload_data(string, string, string);

	friend class carStat_network;
};

class truck_gasStat : public gas_stat {
public:
	truck_gasStat(float);
	truck_gasStat(float, vector<event_date>, vector<event_date>);
	void download_data(string, string, string);
	void print() const override;
	void set();
	float get_fuel_remain() const;
	vector<event_date> get_delVector() const;
	vector<event_date> get_supVector() const;
	void supply_fuel(event_date);
	void deliever_fuel(event_date);
	void upload_data(string, string, string);

	friend class truckStat_network;
};

class carStat_network {
	vector<car_gasStat> carStations;
public:
	void download_data(string, string, string);
	void add();
	vector<car_gasStat> get_vector() const;
	void print() const;
	void upload_data(string, string, string);
	car_gasStat& operator[](const int&);
};

class truckStat_network {
	vector<truck_gasStat> truckStations;
public:
	void download_data(string, string, string);
	void add();
	vector<truck_gasStat> get_vector() const;
	void print() const;
	void upload_data(string, string, string);
	truck_gasStat& operator[](const int&);
};