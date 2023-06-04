#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

//3.--------------------------------------------------------------------------
class vector {
    int* arr;
    int size;

public:
    vector();

    vector(int);

    vector(const vector&);

    void set();

    void print() const;

    void addEnd(int);

    void addBeg(int);

    void addPos(int, int);

    void delBeg();

    void delEnd();

    void delPos(int);

    int retMax();

    int retMin();

    int retSize();

    int retEL(int pos);

    void sortAsc();

    void sortDesc();

    void reverse();

    void moveLeft(int);

    void moveRight(int);

    void clear();

    bool operator==(const vector&);

    bool operator!=(const vector&);

    vector& operator+(const vector&);

    vector& operator=(const vector&);

    int& operator[](int) const;

    operator int();

    operator char*();

    ~vector();
};

ostream& operator<<(ostream&, const vector&);

istream& operator>>(istream&, vector&);
