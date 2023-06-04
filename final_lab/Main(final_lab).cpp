#include "Header(final_lab).h"

void menu() {
	cout << "\n 1 - print info";
	cout << "\n 2 - supply fuel";
	cout << "\n 3 - deliever fuel";
	cout << "\n 4 - add gas station";
	cout << "\n Press 0 to exit\n";
}


void print_car(vector<car_gasStat> v) {
	int i = 1;
	for (auto it : v) {
		cout << i++ << ")\n";
		it.print();
	}
}

void print_truck(vector<truck_gasStat> v) {
	for (auto it : v)
		it.print();
}

int main() {
	srand(time(0));
	carStat_network carNet;
	truckStat_network truckNet;

	car_gasStat add_carStat(0);

	event_date day;

	string pathCar_fuel = "carfuel.txt", pathCar_del = "cardel.txt", pathCar_sup = "carsup.txt";
	string pathTruck_fuel = "truckfuel.txt", pathTruck_del = "truckdel.txt", pathTruck_sup = "trucksup.txt";

	int choice, id;

	carNet.download_data(pathCar_fuel, pathCar_del, pathCar_sup);
	truckNet.download_data(pathTruck_fuel, pathTruck_del, pathTruck_sup);

	while (true) {
		menu();
		cout << "\nEnter your choice: ";
		(cin >> choice).get();

		if (!choice)
			break;

		switch (choice)
		{
		case 1:
			cout << "Car gas stations:\n";
			carNet.print();
			cout << "Truck gas stations:\n";
			truckNet.print();
			break;
		case 2:
			cout << " 1 - car\n 2 - truck\nYour choice: ";
			(cin >> choice).get();

			day.set();

			if (choice == 1) {
				carNet.print();
				cout << "Enter station ID(1 - " << carNet.get_vector().size() << "): ";

				cin >> id;

				for (int i = 1; i <= carNet.get_vector().size(); i++) {
					if (i == id)
						carNet[i - 1].supply_fuel(day);
				}
			}

			else if (choice == 2) {
				truckNet.print();
				cout << "Enter station ID(1 - " << truckNet.get_vector().size() << "): ";

				cin >> id;
				for (int i = 1; i <= truckNet.get_vector().size(); i++) {
					if (i == id)
						truckNet[i - 1].supply_fuel(day);
				}
			}
			break;
		case 3:
			cout << " 1 - car\n 2 - truck\nYour choice: ";
			(cin >> choice).get();

			day.set();

			if (choice == 1) {
				carNet.print();
				cout << "Enter station ID(1 - " << carNet.get_vector().size() << "): ";

				cin >> id;
				for (int i = 0; i <= carNet.get_vector().size(); i++) {
					if (i == id)
						carNet[i - 1].deliever_fuel(day);
				}
			}

			else if (choice == 2) {
				truckNet.print();
				cout << "Enter station ID(1 - " << truckNet.get_vector().size() << "): ";

				cin >> id;
				for (int i = 1; i <= truckNet.get_vector().size(); i++) {
					if (i == id)
						truckNet[i - 1].deliever_fuel(day);
				}
			}
			break;
		case 4:
			cout << " 1 - car\n 2 - truck\nYour choice: ";
			(cin >> choice).get();

			if (choice == 1)
				carNet.add();

			else if (choice == 2)
				truckNet.add();
		default:
			break;
		}
	}

	carNet.upload_data(pathCar_fuel, pathCar_del, pathCar_sup);
	truckNet.upload_data(pathTruck_fuel, pathTruck_del, pathTruck_sup);



	return 0;
}