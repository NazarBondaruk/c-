#include "vector(header).h"

vector::vector() {
    arr = nullptr;
    size = 0;
}

vector::vector(int size) {
    this->size = size;
    this->arr = new int[this->size];

    for (int i = 0; i < size; i++)
        arr[i] = rand() % 101 - 50;
}

vector::vector(const vector& other) {
    this->size = other.size;
    this->arr = new int[other.size];

    for (int i = 0; i < other.size; i++)
        arr[i] = other.arr[i];
}

void vector::set() {
    cout << "Enter size:\n";
    cin >> this->size;

    for (int i = 0; i < size; i++)
        arr[i] = rand() % 101 - 50;
}

void vector::print() const {
    for (int i = 0; i < size; i++)
        cout << setw(5) << arr[i];

    cout << endl;
}

void vector::addEnd(int value) {
    int* new_arr = new int[size + 1];

    for (int i = 0; i < size; i++)
        new_arr[i] = arr[i];

    new_arr[size] = value;

    delete[] arr;
    arr = new_arr;
    new_arr = nullptr;
    size++;
}

void vector::addBeg(int value) {
    int* new_arr = new int[size + 1];

    for (int i = 0; i < size; i++)
        new_arr[i + 1] = arr[i];

    new_arr[0] = value;

    delete[] arr;
    arr = new_arr;
    new_arr = nullptr;
    size++;
}

void vector::addPos(int value, int pos) {
    int* new_arr = new int[size + 1];
    int ind = 0;

    for (int i = 0; i < size; i++)
    {
        if (i == pos) {
            ind = i;
            break;
        }

        new_arr[i] = arr[i];
    }

    new_arr[ind] = value;

    for (int i = ind; i < size; i++)
    {
        new_arr[i + 1] = arr[i];
    }

    delete[] arr;
    arr = new_arr;
    new_arr = nullptr;
    size++;
}

void vector::delBeg() {
    int* new_arr = new int[size - 1];

    for (int i = 0; i < size; i++)
        new_arr[i] = arr[i + 1];

    delete[] arr;
    arr = new_arr;
    new_arr = nullptr;
    size--;
}

void vector::delEnd() {
    int* new_arr = new int[size - 1];

    for (int i = 0; i < size - 1; i++)
        new_arr[i] = arr[i];

    delete[] arr;
    arr = new_arr;
    new_arr = nullptr;
    size--;
}

void vector::delPos(int pos) {
    int* new_arr = new int[size - 1];
    int ind = 0;

    for (int i = 0; i < size; i++)
    {
        if (i == pos) {
            ind = i;
            break;
        }

        new_arr[i] = arr[i];
    }

    for (int i = ind; i < size; i++)
    {
        new_arr[i] = arr[i + 1];
    }

    delete[] arr;
    arr = new_arr;
    new_arr = nullptr;
    size--;
}

int vector::retMax() {
    int max = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }

    return max;
}

int vector::retMin() {
    int min = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (min > arr[i])
            min = arr[i];
    }

    return min;
}

int vector::retSize() {
    return size;
}

int vector::retEL(int pos) {
    for (int i = 0; i < size; i++)
    {
        if (i == pos)
            return arr[i];
    }

    return -1;
}

void vector::sortAsc() {
    int tmp = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (arr[j - 1] > arr[j]) {
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
}

void vector::sortDesc() {
    int tmp = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (arr[j - 1] < arr[j]) {
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
}

void vector::reverse() {
    int tmp = 0;

    for (int i = 0; i < size / 2; i++)
    {
        tmp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = tmp;
    }
}

void vector::moveLeft(int num) {
    int j = 0;
    vector v;
    v = *this;

    for (int i = 0; i < this->size; i++) {
        if (i + num <= size - 1)
            arr[i] = v.arr[i + num];

        else
            arr[i] = v.arr[0 + (j++)];
    }
}

void vector::moveRight(int num) {
    vector v;
    v = *this;
    int j = 0;

    for (int i = this->size - 1; i >= 0; i--) {
        if (i - num >= 0)
            arr[i] = v.arr[i - num];

        else
            arr[i] = v.arr[this->size - 1 - (j++)];
    }
}

void vector::clear() {
    delete[] arr;
    arr = nullptr;
    size = 0;
}

bool vector::operator==(const vector& arr) {
    if (this->size == arr.size) {
        for (int i = 0; i < size; i++)
        {
            if (this->arr[i] != arr.arr[i])
                return false;
        }

        return true;
    }

    return false;
}

bool vector::operator!=(const vector& arr) {
    if (this->size == arr.size) {
        for (int i = 0; i < size; i++)
        {
            if (this->arr[i] != arr.arr[i])
                return true;
        }

        return false;
    }

    return true;
}

vector& vector::operator+(const vector& arr) {
    int* p = new int[this->size + arr.size];

    for (int i = 0; i < this->size; i++)
        p[i] = this->arr[i];

    for (int i = this->size; i < arr.size + this->size; i++)
        p[i] = arr.arr[i - this->size];

    delete[] this->arr;
    this->arr = p;
    this->size += arr.size;

    return *this;
}

vector& vector::operator=(const vector& v) {
    if (this != &v) {
        delete[] this->arr;
        this->arr = nullptr;

        this->arr = new int[v.size];
        for (int i = 0; i < v.size; i++)
            this->arr[i] = v.arr[i];

        this->size = v.size;

        return *this;
    }

    return *this;
}

int& vector::operator[](int i) const {
    return this->arr[i];
}

vector::operator int() {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

vector::operator char* () {
    char* result = new char[size * 10 + 1];
    result[0] = '\0';
    char tmp[10];
    for (int i = 0; i < size; i++) {
        _itoa_s(arr[i], tmp, 10);
        strcat_s(result, size * 10 + 1, tmp);
    }
    return result;
}

vector::~vector() {
    delete[] arr;
}

ostream& operator<<(ostream& os, const vector& v) {
    v.print();
    return os;
}

istream& operator>>(istream& is, vector& v) {
    for (int i = 0; i < v.retSize(); i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> v[i];
    }

    return is;
}