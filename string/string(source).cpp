#include "string(header).h"

String::String() {
    this->size = 0;
    userStr = new char[this->size + 1];
}

String::String(int size, char* str) {
    this->size = size;

    userStr = new char[this->size + 1];
    strcpy_s(this->userStr, strlen(str) + 1, str);
    userStr[strlen(str)] = '\0';
}

String::String(const String& str) {
        this->size = 0;
        this->userStr = nullptr;

        this->userStr = new char[strlen(str.userStr) + 1];
        strcpy_s(this->userStr, strlen(str.userStr) + 1, str.userStr);

        this->size = strlen(str.userStr) + 1;
}

void String::set() {
    cout << "Enter size of string:\n";
    (cin >> size).get();
    size += 1;

    cout << "Enter your string:\n";
    gets_s(userStr, size);
    size = strlen(this->userStr) + 1;
    userStr[strlen(userStr)] = '\0';
}

int String::get_size() const { return this->size; }

void String::addPos(char* subStr, int pos) {
    char* tempStr;
    tempStr = new char[this->size + strlen(subStr)];
    tempStr[this->size + strlen(subStr) - 1] = '\0';
    int i = 0, j = 0, ind = 0;

    while (userStr[ind] != '\0') {
        if (i == pos)
            break;

        tempStr[i++] = userStr[ind++];
    }

    while (true) {
        if (subStr[j] == '\0')
            break;

        tempStr[i++] = subStr[j++];
    }

    while (userStr[ind] != '\0') {
        tempStr[i++] = userStr[ind++];
    }

    delete[] userStr;
    userStr = tempStr;

    cout << userStr << endl;
}

void String::delSub(char* subStr) {
    if (strstr(userStr, subStr)) {
        char* tempStr;
        char* sideStr;
        int i = 0, j = 0, ind = 0, pos = 0;

        sideStr = new char[strlen(subStr) + 1];
        sideStr[strlen(subStr)] = '\0';

        tempStr = new char[this->size];

        while (true) {
            if (userStr[ind + strlen(subStr) - 1] == '\0')
                break;

            for (int i = 0; i < strlen(subStr); i++)
                sideStr[i] = userStr[i + ind];

            if (!strcmp(sideStr, subStr)) {
                pos = ind;
                break;
            }

            ind++;
        }

        ind = 0;

        while (userStr[ind] != '\0') {
            if (i == pos)
                break;

            tempStr[i++] = userStr[ind++];
        }

        while (true) {
            if (userStr[ind + strlen(subStr)] == '\0')
                break;

            tempStr[i++] = userStr[(ind++) + strlen(subStr)];
        }

        tempStr[this->size - strlen(subStr)] = '\0';
        userStr = tempStr;

        cout << userStr << "(" << strlen(userStr) << ")" << endl;
    }

    else
        cout << "Substring not found!\n\n";
}

void String::swap(char* str, char* str2, int pos) {
    if (strstr(userStr, str)) {
        this->delSub(str);
        this->addPos(str2, pos);
    }
}

int String::printElCount() {
    return strlen(this->userStr);
}

void String::print() const {
    cout << "String: " << this->userStr << endl;
}

bool String::operator==(const String& str) {
    return !strcmp(this->userStr, str.userStr);
}

bool String::operator!=(const String& str) {
    return strcmp(this->userStr, str.userStr);
}

bool String::operator<(const String& str) {
    return strlen(this->userStr) < strlen(str.userStr);
}

bool String::operator>(const String& str) {
    return strlen(this->userStr) > strlen(str.userStr);
}

String& String::operator + (const String & str) {
    this->size += str.size;
    strcat_s(this->userStr, this->size, str.userStr);
    return *this;
}

String& String::operator=(const String& str) {
    delete[] this->userStr;
    userStr = nullptr;

    this->userStr = new char[strlen(str.userStr) + 1];
    strcpy_s(this->userStr, strlen(str.userStr) + 1, str.userStr);
    this->size = strlen(str.userStr) + 1;

    return *this;
}

char& String::operator[](int i) {
    return this->userStr[i];
}

int& String::operator()(char& sym) {
    int i = 0;
    int not_found = -1;

    while (true) {
        if (this->userStr[i] == '\0')
            break;

        else {
            if (this->userStr[i] == sym)
                return i;
        }

        i++;
    }

    return not_found;
}

String::operator int() {
    return strlen(this->userStr);
}

String::~String() {
    delete[] this->userStr;
}

ostream& operator<<(ostream& os, const String& str) {
    str.print();
    return os;
}