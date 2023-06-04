#include "string(header).h"

int main() {

    String s1;
    s1.set();
    s1.print();
    cout << "Size s1: " << s1.get_size() << endl;
    cout << "Length s1: " << (int)s1 << endl;

    String s2;
    s2 = s1;    
    cout << "Size s2: " << s2.get_size() << "\nCopied ";
    s2.print();

    












    return 0;
}