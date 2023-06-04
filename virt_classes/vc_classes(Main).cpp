#include "vc_class(header).h"

int main() {
	srand(time(0));

	/*logistics* transport = nullptr;
	auto_logist al("Melbourne", "Sidney", 1500, 2300.5);

	auto_logist* al_ptr = &al;
	transport = al_ptr;

	transport->print();
	cout << "Total price: " << transport->eval_price();*/

	double train_log = 0, air_log = 0, sea_log = 0, auto_log = 0, total = 0;

	train_logist* tArr[4] = {
		new train_logist("Kyoto", "Tokyo", 1000, 2300),
		new train_logist("Melbourne", "Sidney", 1500, 2000),
		new train_logist("Roma", "Berlin", 2250, 2100),
		new train_logist("London", "Manchester", 1750, 2050)
	};

	air_logist* aArr[4] = {
		new air_logist("Kyiv", "Ankara", 1000, 2300, 1300),
		new air_logist("Washington", "Toronto", 750, 2000, 900),
		new air_logist("Oslo", "Stockholm", 300, 2100, 1000),
		new air_logist("Rio-de-Janeyro", "Madrid", 4000, 2050, 100)
	};

	sea_logist* sArr[4] = {
		new sea_logist("Odesa", "Istanbul", 550, 2300),
		new sea_logist("New York", "Hamburg", 4000, 2000),
		new sea_logist("Singapore", "Kuala-Lumpur", 800, 2100),
		new sea_logist("Sao-Paulo", "Reykyavik", 5000, 2050)
	};

	auto_logist* a_Arr[4] = {
		new auto_logist("Lviv", "Prague", 450, 2300),
		new auto_logist("Cairo", "Algeria", 900, 2000),
		new auto_logist("Seul", "Pekin", 1100, 2100),
		new auto_logist("Montevideo", "Bogota", 2000, 2050)
	};

	logistics* highest = tArr[0], * lowest = tArr[0];


	for (int i = 0; i < 4; i++)
	{
		tArr[i]->print();
		train_log += tArr[i]->eval_price();

		cout << "Total price: " << tArr[i]->eval_price();
		cout << "\n\n---------------------------------------------\n\n";

		if (tArr[i]->eval_price() > highest->eval_price()) highest = tArr[i];
		if (tArr[i]->eval_price() < lowest->eval_price()) lowest = tArr[i];
	}

	for (int i = 0; i < 4; i++)
	{
		aArr[i]->print();
		air_log += aArr[i]->eval_price();

		cout << "Total price: " << aArr[i]->eval_price();
		cout << "\n\n---------------------------------------------\n\n";

		if (aArr[i]->eval_price() > highest->eval_price()) highest = aArr[i];
		if (aArr[i]->eval_price() < lowest->eval_price()) lowest = aArr[i];
	}

	for (int i = 0; i < 4; i++)
	{
		sArr[i]->print();
		sea_log += sArr[i]->eval_price();

		cout << "Total price: " << sArr[i]->eval_price();
		cout << "\n\n---------------------------------------------\n\n";

		if (sArr[i]->eval_price() > highest->eval_price()) highest = sArr[i];
		if (sArr[i]->eval_price() < lowest->eval_price()) lowest = sArr[i];
	}

	for (int i = 0; i < 4; i++)
	{
		a_Arr[i]->print();
		auto_log += a_Arr[i]->eval_price();

		cout << "Total price: " << a_Arr[i]->eval_price();
		cout << "\n\n---------------------------------------------\n\n";

		if (a_Arr[i]->eval_price() > highest->eval_price()) highest = a_Arr[i];
		if (a_Arr[i]->eval_price() < lowest->eval_price()) lowest = a_Arr[i];
	}

	total = train_log + auto_log + air_log + sea_log;

	cout << "\n\nRevenue from train logistics: " << train_log;
	cout << "\nRevenue from air logistics: " << air_log;
	cout << "\nRevenue from ship logistics: " << sea_log;
	cout << "\nRevenue from auto logistics: " << auto_log;
	cout << "\nTotal: " << total;

	cout << "\n\n\nMost expensive transportation: \n";
	highest->print();
	cout << "\nPrice: " << highest->eval_price();

	cout << "\n\n\nCheapest transportation:\n";
	lowest->print();
	cout << "\nPrice: " << lowest->eval_price();






	return 0;
}