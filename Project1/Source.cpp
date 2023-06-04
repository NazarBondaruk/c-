#include <iostream>
#include <time.h>
#include <string>

using namespace std;

class prior_queueItem {
    char value;
    int prior;
public:
    prior_queueItem(): value(' '), prior(0) {}

    prior_queueItem(int value, int prior) {
        this->value = value;
        this->prior = prior;
    }

    void setValue(int value) {
        this->value = value;
    }

    void setPrior(int prior) {
        this->prior = prior;
    }

    char get_value() const { return value; }
    char get_prior() const { return prior; }

    void print() const {
        cout << "Value: " << value << endl;
        cout << "Priority: " << prior << endl << endl;
    }
};

class vector {
    prior_queueItem* data;
    int size;
public:
    vector() {
        size = 0;
        data = nullptr;
    }
    vector(int size) {
        this->size = size;
        data = new prior_queueItem[size];
    }
    vector(const vector& other) {
        this->size = other.size;
        this->data = new prior_queueItem[other.size];

        for (int i = 0; i < other.size; i++)
        {
            this->data[i] = other.data[i];
        }
    }

    void print() const {
        for (int i = 0; i < size; i++)
            data[i].print();

        cout << endl;
    }
    void addEnd(prior_queueItem number) {
        prior_queueItem* p = new prior_queueItem[size + 1];
        for (int i = 0; i < size; i++)
            p[i] = data[i];
        p[size] = number;

        delete[] data;
        data = nullptr;
        size++;
        data = p;

    }
    void addBegin(prior_queueItem number) {
        prior_queueItem* p = new prior_queueItem[size + 1];
        for (int i = 0; i < size; i++)
            p[i + 1] = data[i];
        p[0] = number;

        delete[] data;
        data = nullptr;
        size++;

        data = p;
    }

    void addPosition(int pos, prior_queueItem value) {
        prior_queueItem* other = new prior_queueItem[size + 1];
        for (int i = 0; i < pos; i++)
            other[i] = data[i];

        other[pos] = value;

        for (int i = pos; i < size; i++)
            other[i + 1] = data[i];

        delete[] data;
        data = other;
        size++;
    }


    void deleteBegin() {
        prior_queueItem* p = new prior_queueItem[size - 1];
        for (int i = 1; i < size; i++)
            p[i - 1] = data[i];

        size--;
        delete[] data;
        data = p;

    }

    void deleteEnd() {
        prior_queueItem* p = new prior_queueItem[size - 1];
        for (int i = 0; i < size - 1; i++)
            p[i] = data[i];

        size--;
        delete[] data;
        data = p;

    }
    void deletePosition(int pos, prior_queueItem value) {
        prior_queueItem* p = new prior_queueItem[size - 1];
        for (int i = 0; i < pos; i++)
            p[i] = data[i];

        for (int i = pos; i < size - 1; i++)
            p[i] = data[i + 1];

        size--;
        delete[] data;
        data = p;

    }

    void deleteAll() {
        if (data) delete[] data;
        size = 0;
        data = nullptr;
    }

    void reverse() {
        prior_queueItem* p = new prior_queueItem[size];
        int j = size - 1;
        for (int i = 0; i < size; i++)
        {
            p[i] = data[j];
            j--;
        }

        delete[] data;
        data = p;
    }

    int getSize() {
        return size;
    }
    bool isEmpty() const {
        return size == 0;
    }

    ~vector() {
        delete[]data;
    }

    prior_queueItem& operator[](int index) const {
        return data[index];
    }
};


class prior_queue {
    vector data;
public:
       prior_queue() {}

    void push(prior_queueItem value) {
        if (is_empty())
            data.addBegin(value);

        else {
            int i = 0;
            while (i < data.getSize() && data[i].get_prior() <= value.get_prior())
                i++;

            data.addPosition(i, value);
        }
    }

    bool is_empty() { return data.isEmpty(); }

    void print() const {
        data.print();
    }

    prior_queueItem top() const { if (!data.isEmpty())return data[0]; }

    prior_queueItem pop() {
        if (!is_empty()) {
            prior_queueItem top = data[0];
            data.deleteEnd();
            return top;
        }
    }

    void clear() { data.deleteAll(); }
};



int main() {
    srand(time(0));

    prior_queue q1;

    system("Pause");
    int num = rand() % 101 - 50;
    int num2 = rand() % 101 - 50;
    int num3 = rand() % 101 - 50;

    int sum = num + num2 + num3;

    q1.push(prior_queueItem(abs(num), abs(num)));
    q1.push(prior_queueItem(abs(num2), abs(num2)));
    q1.push(prior_queueItem(abs(num3), abs(num3)));

    q1.print();

    if (sum % 3 == 0)
        cout  << "You won!\n";

    else if (num == num2 == num3)
        cout << "You won!\n";






    return 0;
}