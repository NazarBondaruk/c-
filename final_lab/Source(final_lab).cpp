#include"Header(final_lab).h"

fuel_type::fuel_type() : fuel_name("") {}
fuel_type::fuel_type(string fuel_name) : fuel_name(fuel_name) {}

void fuel_type::set() {
	cout << "Enter fuel type: ";
	getline(cin, fuel_name);
}

string fuel_type::get_fuel_type() const { return fuel_name; }

void fuel_type::print() const {
	cout << string(100, '-');
	cout << "\nFuel type: " << fuel_name << endl;
	cout << string(100, '-') << endl;
}

void fuel_type::operator=(const string& str) { fuel_name = str; }

event_date::event_date() : fType(""), date(""), fuel_am(0) {}
event_date::event_date(string fType, string date, float fuel_am) : fType(fType), date(date), fuel_am(fuel_am) {}

void event_date::set() {
	fType.set();

	cout << "Enter date: ";
	getline(cin, date);

	cout << "Enter fuel amount: ";
	(cin >> fuel_am).get();
	cout << endl;
}

string event_date::get_date() const { return date; }
string event_date::get_fType() const { return fType.get_fuel_type(); }
float event_date::get_amount() const { return fuel_am; }

void gas_stat::download_data(string pathCar_fuel, string pathCar_del, string pathCar_sup) {
	ifstream fin;
	fin.open(pathCar_fuel);

	int read_fuelAm;
	string fuel_name, date; float fuel_am;

	fin >> read_fuelAm;
	total_fuel_remain = read_fuelAm;

	fin.close();
	fin.open(pathCar_del);

	fin >> fuel_name >> date >> fuel_am;
	delievery.push_back(event_date(fuel_name, date, fuel_am));

	fin.close();
	fin.open(pathCar_sup);

	fin >> fuel_name >> date >> fuel_am;
	suppliement.push_back(event_date(fuel_name, date, fuel_am));

	fin.close();
}

void event_date::print() const {
	cout << string(100, '-');
	cout << "\nDate: " << date;
	cout << "\nFuel amount: " << fuel_am;
	cout << "\nFuel type: " << fType.get_fuel_type() << endl;
	cout << string(100, '-') << endl;
}

void gas_stat::set() {
	int add_fuel, amount;

	cout << "\nEnter amount of fuel: ";
	(cin >> add_fuel).get();

	total_fuel_remain += add_fuel;
}

float gas_stat::get_fuel_remain() const { return total_fuel_remain; }
vector<event_date> gas_stat::get_delVector() const { return delievery; }
vector<event_date> gas_stat::get_supVector() const { return suppliement; }

void gas_stat::supply_fuel(event_date& day) {
	total_fuel_remain += day.get_amount();
	suppliement.push_back(day);
}

void gas_stat::deliever_fuel(event_date day) {
	if (day.get_amount() > total_fuel_remain) {
		cout << "Insufficient fuel capacity!\n\n";
		return;
	}

	total_fuel_remain -= day.get_amount();
	delievery.push_back(day);
}

void gas_stat::upload_data(string pathCar_fuel, string pathCar_del, string pathCar_sup) {
	ofstream fout;
	fout.open(pathCar_fuel);

	fout << total_fuel_remain;

	fout.close();
	fout.open(pathCar_del);

	for (auto it : delievery)
		fout << it.get_fType() << " " << it.get_date() << " " << it.get_amount() << endl;

	fout.close();
	fout.open(pathCar_sup);

	for (auto it : suppliement)
		fout << it.get_fType() << " " << it.get_date() << " " << it.get_amount() << endl;

	fout.close();
}

car_gasStat::car_gasStat(float amount) {
	total_fuel_remain = amount;
}

car_gasStat::car_gasStat(float amount, vector<event_date> del, vector<event_date> sup) {
	total_fuel_remain = amount;
	delievery = del;
	suppliement = sup;
}

void car_gasStat::download_data(string pathCar_fuel, string pathCar_del, string pathCar_sup) {
	gas_stat::download_data(pathCar_fuel, pathCar_del, pathCar_sup);
}

void car_gasStat::set() { gas_stat::set(); }

void car_gasStat::print() const {
	cout << string(100, '-');
	cout << "\nFuel remaining: " << total_fuel_remain;

	cout << "\nFuel suppliements info\n";
	for (auto it : suppliement)
		it.print();

	cout << "\nFuel delieveries info\n";
	for (auto it : delievery)
		it.print();

	cout << string(100, '-') << endl;
}

float car_gasStat::get_fuel_remain() const { return gas_stat::get_fuel_remain(); }
vector<event_date> car_gasStat::get_delVector() const { return gas_stat::get_delVector(); }
vector<event_date> car_gasStat::get_supVector() const { return gas_stat::get_supVector(); }

void car_gasStat::supply_fuel(event_date day) { gas_stat::supply_fuel(day); }
void car_gasStat::deliever_fuel(event_date day) { gas_stat::deliever_fuel(day); }

void car_gasStat::upload_data(string pathCar_fuel, string pathCar_del, string pathCar_sup) {
	gas_stat::upload_data(pathCar_fuel, pathCar_del, pathCar_sup);
}

truck_gasStat::truck_gasStat(float amount) {
	total_fuel_remain = amount;
}

truck_gasStat::truck_gasStat(float amount, vector<event_date> del, vector<event_date> sup) {
	total_fuel_remain = amount;
	delievery = del;
	suppliement = sup;
}

void truck_gasStat::download_data(string pathTruck_fuel, string pathTruck_del, string pathTruck_sup) {
	gas_stat::download_data(pathTruck_fuel, pathTruck_del, pathTruck_sup);
}

void truck_gasStat::print() const {
	cout << string(100, '-');
	cout << "\nFuel remaining: " << total_fuel_remain;

	cout << "\nFuel suppliements info\n";
	for (auto it : suppliement)
		it.print();

	cout << "\nFuel delieveries info\n";
	for (auto it : delievery)
		it.print();

	cout << string(100, '-') << endl;
}

float truck_gasStat::get_fuel_remain() const { return gas_stat::get_fuel_remain(); }
vector<event_date> truck_gasStat::get_delVector() const { return gas_stat::get_delVector(); }
vector<event_date> truck_gasStat::get_supVector() const { return  gas_stat::get_supVector(); }

void truck_gasStat::supply_fuel(event_date day) { gas_stat::supply_fuel(day); }
void truck_gasStat::deliever_fuel(event_date day) { gas_stat::deliever_fuel(day); }

void truck_gasStat::upload_data(string pathTruck_fuel, string pathTruck_del, string pathTruck_sup) {
	gas_stat::upload_data(pathTruck_fuel, pathTruck_del, pathTruck_sup);
}

void carStat_network::download_data(string pathCar_fuel, string pathCar_del, string pathCar_sup) {
	ifstream fin_fuel, fin_del, fin_sup;
	fin_fuel.open(pathCar_fuel);
	fin_del.open(pathCar_del);
	fin_sup.open(pathCar_sup);

	float read_fuelAm;
	string fuel_name, fuel_name2, date, date2; float fuel_am, fuel_am2; int i = 0;

	while (fin_fuel >> read_fuelAm) {
		vector<event_date> read_delievery, read_suppliement;
		i = 0;

		while (!fin_del.eof()) {
			fin_del >> fuel_name >> date >> fuel_am;
			if (fuel_name == "end")
				break;
			else if (fuel_name != "A00")
				read_delievery.push_back(event_date(fuel_name, date, fuel_am));
			else if (!i)
				i++;
			else
				break;
		}

		i = 0;

		while (!fin_sup.eof()) {
			fin_sup >> fuel_name2 >> date2 >> fuel_am2;
			if (fuel_name2 == "end")
				break;
			else if (fuel_name2 != "A00")
				read_suppliement.push_back(event_date(fuel_name2, date2, fuel_am2));
			else if (i == 0)
				i++;
			else
				break;
		}

		carStations.push_back(car_gasStat(read_fuelAm, read_delievery, 
			read_suppliement));
	}


	fin_fuel.close();
	fin_del.close();
	fin_sup.close();
}

void carStat_network::add() {
	int add_fuel;

	cout << "Enter amount of fuel: ";
	(cin >> add_fuel).get();

	carStations.push_back(car_gasStat(add_fuel));
}

vector<car_gasStat> carStat_network::get_vector() const { return carStations; }

void carStat_network::print() const {
	int i = 1;
	for (auto it : carStations) {
		cout << i++ << ")\n";
		it.print();
	}
}

void carStat_network::upload_data(string pathCar_fuel, string pathCar_del, string pathCar_sup) {
	ofstream fout_fuel, fout_del, fout_sup;

	fout_fuel.open(pathCar_fuel);
	fout_del.open(pathCar_del);
	fout_sup.open(pathCar_sup);

	for (auto it : carStations) {
		fout_fuel << it.total_fuel_remain << endl;

		if (it.delievery.size()) {
			for (auto it_1 : it.delievery)
				fout_del << it_1.get_fType() << " " << it_1.get_date() << " " << it_1.get_amount() << endl;
			fout_sup << "A00 " << 000000 << " " << 0 << endl;
		}

		if (it.suppliement.size()) {
			for (auto it_1 : it.suppliement)
				fout_sup << it_1.get_fType() << " " << it_1.get_date() << " " << it_1.get_amount() << endl;
			fout_sup << "A00 " << 000000 << " " << 0 << endl;
		}

	}

	fout_del << "end";
	fout_sup << "end";

	fout_fuel.close();
	fout_del.close();
	fout_sup.close();
}

car_gasStat& carStat_network::operator[](const int& ind) { return carStations[ind]; }

void truckStat_network::download_data(string pathCar_fuel, string pathCar_del, string pathCar_sup) {
	ifstream fin_fuel, fin_del, fin_sup;
	fin_fuel.open(pathCar_fuel);
	fin_del.open(pathCar_del);
	fin_sup.open(pathCar_sup);

	float read_fuelAm;
	string fuel_name, fuel_name2, date, date2; float fuel_am, fuel_am2;
	int i = 0;

	while (fin_fuel >> read_fuelAm) {
		vector<event_date> read_delievery, read_suppliement;
		i = 0;

		while (!fin_del.eof()) {
			fin_del >> fuel_name >> date >> fuel_am;
			if (fuel_name == "end")
				break;
			else if (fuel_name != "A00")
				read_delievery.push_back(event_date(fuel_name, date, fuel_am));
			else if (!i)
				i++;
			else
				break;
		}

		i = 0;

		while (!fin_sup.eof()) {
			fin_sup >> fuel_name2 >> date2 >> fuel_am2;
			if (fuel_name2 == "end")
				break;
			else if (fuel_name2 != "A00")
				read_suppliement.push_back(event_date(fuel_name2, date2, fuel_am2));
			else if (!i)
				i++;
			else
				break;
		}

		truckStations.push_back(truck_gasStat(read_fuelAm, read_delievery,
			read_suppliement));
	}


	fin_fuel.close();
	fin_del.close();
	fin_sup.close();
}

void truckStat_network::add() {
	int add_fuel;

	cout << "Enter amount of fuel: ";
	(cin >> add_fuel).get();

	truckStations.push_back(truck_gasStat(add_fuel));
}

vector<truck_gasStat> truckStat_network::get_vector() const { return truckStations; }

void truckStat_network::print() const {
	int i = 1;
	for (auto it : truckStations) {
		cout << i++ << ")\n";
		it.print();
	}
}

void truckStat_network::upload_data(string pathCar_fuel, string pathCar_del, string pathCar_sup) {
	ofstream fout_fuel, fout_del, fout_sup;

	fout_fuel.open(pathCar_fuel);
	fout_del.open(pathCar_del);
	fout_sup.open(pathCar_sup);

	for (auto it : truckStations) {
		fout_fuel << it.total_fuel_remain;

		for (auto it_1 : it.delievery)
			fout_del << it_1.get_fType() << " " << it_1.get_date() << " " << it_1.get_amount() << endl;
		fout_del << "A00 " << 000000 << " " << 0 << endl;

		for (auto it_1 : it.suppliement)
			fout_sup << it_1.get_fType() << " " << it_1.get_date() << " " << it_1.get_amount() << endl;
		fout_sup << "A00 " << 000000 << " " << 0 << endl;
	}

	fout_del << "end";
	fout_sup << "end";

	fout_fuel.close();
	fout_del.close();
	fout_sup.close();
}

truck_gasStat& truckStat_network::operator[](const int& ind) { return truckStations[ind]; }