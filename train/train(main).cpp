#include <iomanip>
#include <time.h>
#include "train(header).h"


int main() {
	srand(time(0));

	int size;
	cout << "Enter amount of trains:\n";
	(cin >> size).get();
	train* tArr = new train[size];

	for (int i = 0; i < size; i++)
		tArr[i].set();

	for (int i = 0; i < size; i++)
		tArr[i].print();

	for (int i = 0; i < size; i++)
		cout << "Passengers in train " << i + 1 << ": " << tArr[i].sum() << endl;

	cout << "\nTrain with biggest number of passengers: \n";
	biggest_carr(tArr, size);




	return 0;
}