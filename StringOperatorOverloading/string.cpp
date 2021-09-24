#include<iostream>
#include "string.h"
#include <cstring>

MyString::MyString() : str {nullptr} {
	str = new char[1];
	*str='\0';
}

MyString::MyString(const char *s) : str {nullptr} {
	if(s == nullptr) {
		str = new char[1];
		*str = '\0';
	} else {
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
}

MyString::MyString(const MyString &source) : str {nullptr} {
	str = new char[strlen(source.str) + 1];
	strcpy(str, source.str);
}

MyString::MyString(MyString &&source) : str(source.str) {
	source.str = nullptr;
}

MyString::~MyString() {
	delete [] str;
}

MyString &MyString::operator=(const MyString &rhs) {
	if(this == &rhs) {
		return *this;
	}

	delete [] str;
	str = new char[strlen(rhs.str) + 1];
	strcpy(str, rhs.str);
	return *this;
}

MyString &MyString::operator=(MyString &&rhs) {
	if(this == &rhs) {
		return *this;
	}
	delete [] str;
	str = rhs.str;
	rhs.str = nullptr;
	return *this;
}

void MyString::display() const {
	std::cout << str << " : " << get_length() << std::endl;
}

int MyString::get_length() const {
	return std::strlen(str);
}

const char *MyString::get_str() const {
	return str;
}

bool MyString::operator == (const MyString &rhs) const {
	return (strcmp(str,rhs.str) == 0);
}

bool MyString::operator != (const MyString &rhs) const {
	return (strcmp(str, rhs.str) != 0);
}

bool MyString::operator<(const MyString &rhs) const {
	return get_length() < rhs.get_length();
}

bool MyString::operator>(const MyString &rhs) const {
	return get_length() > rhs.get_length();
}

MyString MyString::operator+(const MyString &rhs) {
	char *buff = new char[strlen(str) + strlen(rhs.str) + 1];
	strcpy(buff, str);
	strcat(buff, rhs.str);
	MyString temp {buff};
	return temp;
}

MyString &MyString::operator += (const MyString &rhs) {
	char *buff = new char[strlen(str) + strlen(rhs.str) + 1];
	strcpy(buff, str);
	strcat(buff,rhs.str);
	str = buff;
	return *this;
}

MyString MyString::operator*(int n) const {
	char *buff = new char[strlen(str) * n + 1];
	strcpy(buff, str);

	if(n > 1) {
		for(int i = 1; i < n; i++) {
			strcat(buff, str);
		}
	}
	MyString temp {buff};
	return temp;
}

MyString &MyString::operator *= (int n) {
	char *buff = new char[strlen(str) * n + 1];
	strcpy(buff, str);
		
	if(n > 1) {
		for(int i = 1; i < n; i++) {
			strcat(buff, str);
		}
	}
	str = buff;
	return *this;
}	

MyString MyString::operator-()
{
    char *buff = new char[strlen(str) + 1];
    strcpy(buff, str);
    for (size_t i {0}; i < strlen(str); ++i) {
        buff[i] = std::tolower(buff[i]);
    }
    MyString temp {buff};
    delete [] buff;
    return temp;
}

MyString &MyString::operator ++() {
        char *buff =  new char[strlen(str) + 1];
        strcpy(buff, str);
        for(int i = 0; i < strlen(str); i++) {
                buff[i] = std::tolower(buff[i]);
        }
        str = buff;
        return *this;
}

std::ostream &operator<<(std::ostream &os, const MyString &rhs)
{
    os << rhs.str;
    return os;
}

std::istream &operator>>(std::istream &in, MyString &rhs)
{
    char *buff = new char[1000];
    in >> buff;
    rhs = MyString{buff};
    delete [] buff;
    return in;
}
