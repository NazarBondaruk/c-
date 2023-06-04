#include "vector(header).h"



int main() {
    srand(time(0));
    cout << "----------------------------------------------\n";
    vector v1(6);

    v1.print();

    vector v2 = v1;
    v2.print();


    v2.addEnd(13);
    v2.print();

    v2.addBeg(11);
    v2.print();

    v2.addPos(44, 2);
    v2.print();

    v2.delBeg();
    v2.print();

    v2.delEnd();
    v2.print();

    v2.delPos(2);
    v2.print();

    cout << "max: " << v2.retMax();

    cout << "\nmin: " << v2.retMin() << endl;

    cout << "amount of elements: " << v2.retSize() << endl;

    if (v2.retEL(3) == -1)
        cout << "not found\n";
    else
        cout << "element: " << v2.retEL(3) << endl;

    v2.sortAsc();
    v2.print();

    v2.sortDesc();
    v2.print();

    v2.reverse();
    v2.print();

    if (v2 == v1)
        cout << "Arrays are equal\n";
    else
        cout << "Arrays are not equal\n";

    cout << "String: " << (char*)v2 << endl;

    v2.moveLeft(1);
    v2.print();

    v2.moveRight(1);
    v2.print();


    return 0;
}
