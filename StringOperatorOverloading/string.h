#ifndef _STRING_H_
#define _STRING_H_

class MyString {
               
	private:
		char *str;
	public:
		MyString();
		MyString(const char *s);
		MyString(const MyString &source);
		MyString(MyString &&source);
		~MyString();
		
		MyString &operator = (const MyString &rhs);
		MyString &operator = (MyString &&rhs);

		void display() const;
		
		int get_length() const;
		const char* get_str() const;
	
		MyString operator-(); // make lovercase
		MyString operator+(const MyString &rhs); // concatenate
		bool operator == (const MyString &rhs) const;
		bool operator != (const MyString &rhs) const;
		bool operator < (const MyString &rhs) const;
		bool operator > (const MyString &rhs) const;

		MyString &operator += (const MyString &rhs);
		MyString operator * (int n) const; // repeat n times
		MyString &operator *= (int n);
		MyString &operator ++ ();
		MyString operator ++ (int);
		friend std::ostream &operator<<(std::ostream &os, const MyString &rhs);
   	 	friend std::istream &operator>>(std::istream &in, MyString &rhs);
};

#endif
