#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

class String {
    char* userStr;
    int size;
public:
    String();

    String(int, char*);

    String(const String&);

    void set();

    void addPos(char*, int);

    void delSub(char*);

    void swap(char*, char* , int);

    int printElCount();

    int get_size() const;

    void print() const;

    bool operator==(const String&);

    bool operator!=(const String&);

    bool operator<(const String&);

    bool operator>(const String&);

    String& operator+(const String&);

    String& operator=(const String&);

    char& operator[](int);

    int& operator()(char&);

    operator int();

    ~String();
};

ostream& operator<<(ostream&, const String&);
