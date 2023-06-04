#include "vc_class(header).h"

logistics::logistics() : set_off("No instance for this location"), drop_off("No instance for this location"),
route_length(0), price(0) {}

logistics::logistics(string set_off, string drop_off, int route_length, double price) {
	this->set_off = set_off;
	this->drop_off = drop_off;
	this->route_length = route_length;

	if (price > 2000)
		this->price = price;
	else
		this->price = 2000;
}

void logistics::print() const {
	cout << "Sending place: " << set_off;
	cout << "\nDelivery place: " << drop_off;
	cout << "\nRoute length: " << route_length << " km";
	cout << "\nPrice per 250 km: " << price << endl;
}

train_logist::train_logist(): logistics(), longRoute_discount(0) {}
train_logist::train_logist(string set_off, string drop_off, int route_length, double price):
	logistics(set_off, drop_off, route_length, price), longRoute_discount(rand() % 7) {}

void train_logist::print() const {
	logistics::print();
	cout << "Discount: " << longRoute_discount << "%\n";
}

double train_logist::eval_price() {
	return (((double)route_length / 250.0) * price) * ((100.0 - (double)longRoute_discount) / 100.0);
}

air_logist::air_logist(): logistics(), cargo_insurance(0) {}

air_logist::air_logist(string set_off, string drop_off, int route_length, double price, int cargo_insurance) :
	logistics(set_off, drop_off, route_length, price) {
	this->cargo_insurance = cargo_insurance;
} 

void air_logist::print() const {
	logistics::print();
	cout << "Insurance: " << cargo_insurance << "$" << endl;
}

double air_logist::eval_price() {
	return (((double)route_length / 250.0) * price) + (double)cargo_insurance;
}

sea_logist::sea_logist() : logistics(), accomod_price(0) {}

sea_logist::sea_logist(string set_off, string drop_off, int route_length, double price) :
	logistics(set_off, drop_off, route_length, price) {
	this->accomod_price = 1450;
}

void sea_logist::print() const {
	logistics::print();
	cout << "Accomodation price: " << accomod_price << "$" << endl;
}

double sea_logist::eval_price() {
	return (((double)route_length / 250.0) * price) + (double)accomod_price;
}

auto_logist::auto_logist() : logistics(), safetyMeasures_price(0) {}

auto_logist::auto_logist(string set_off, string drop_off, int route_length, double price) :
	logistics(set_off, drop_off, route_length, price) {
	this->safetyMeasures_price = 1500;
}

void auto_logist::print() const {
	logistics::print();
	cout << "Price for safety measures: " << safetyMeasures_price << "$" << endl;
}

double auto_logist::eval_price() {
	return (((double)route_length / 250.0) * price) + (double)safetyMeasures_price;
}