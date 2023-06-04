#include "poli_inher(Header).h"

int main() {
	red_book rb(1, 1, 1, 1, 1, 1);

	rb.set();
	rb.print();
	
	cout << "\nBiggest population:\n"; 
	rb.highest();
	cout << "\nSmallest population:\n";
	rb.lowest();




	return 0;
}