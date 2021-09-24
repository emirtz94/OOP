#include<iostream>
#include "string.h"

using namespace std;

int main() {
	MyString a {"frank"};
	MyString b {"frank"};
	cout << (a == b) << endl;
	cout << (a != b) << endl;

	b = "george";
	cout << (a == b) << endl;
	cout << (a != b) << endl;
	cout << (a < b) << endl;
	cout << (a > b) << endl;

	MyString s1 {"FRANK"};
	s1 = -s1;
	cout << s1 << endl;

	s1 = s1 + "******";
	cout << s1 << endl;

	s1 += "------";
	cout << s1 << endl;

	MyString s2{"123456"};
	s1 = s2 * 3;
	cout << s1 << endl;

	MyString s3("abcdef");
	s3 *= 5;
	cout << s3 << endl;

	MyString s4 {"abC"};
	s4 *= 4;
	
	return 0;
}
