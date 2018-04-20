#include<iostream>
#include<cstring>
using namespace std;

class TestCopyConstructor {
	int size;
	char* str;
public:
	TestCopyConstructor(char* _str) {
		int len = strlen(_str);
		this->size = len;
		str = new char[this->size+1];
		for (int i = 0; i < len; i++) {
			this->str[i] = _str[i];
		}
		this->str[len] = 0;
		cout << "Inside Reular Constructor: " << this->str << endl;
	}

	TestCopyConstructor(const TestCopyConstructor &t) {
		int len = strlen(t.str);
		this->size = len + 1;

		this->str = new char[this->size+1];
		for (int i = 0; i < len; i++) {
			this->str[i] = t.str[i];
		}

		this->str[this->size - 1] = '0'+this->size;
		this->str[this->size] = 0;
		cout << "Inside Copy Constructor: " << this->str << endl;

	}

	void print_str() {
		cout << this->str << "\n";
	}

	~TestCopyConstructor() {
		cout << "Inside Destructor: " << this->str << endl;
		delete[] str;

	}
};

void foo(TestCopyConstructor t) {
	cout << "----Inside void foo(t)------\n";
	t.print_str();
	cout << "----Getting out of void foo(t)------\n";
}

TestCopyConstructor foo_bar() {
	char* p = new char[4];
	p[0] = 'D';
	p[1] = 'E';
	p[2] = 'F';
	p[3] = 0;

	cout << "----Creating Object in foo_bar()------\n";
	TestCopyConstructor t(p);
	cout << "----Calling print_str() inside foo_bar()------\n";
	t.print_str();
	cout << "----Returning Object from foo_bar()------\n";
	return t;
}

int main() {

	if (true) {
		char* p = new char[4];
		p[0] = 'A';
		p[1] = 'B';
		p[2] = 'C';
		p[3] = 0;

		cout << "----Creating Object (t) in Main()------\n";
		TestCopyConstructor t(p);
		cout << "----Calling void foo(t)------\n";
		foo(t);
		cout << "----Returned to main after calling void foo(t)------\n";

		cout << "----Calling t.print_str() from Main()------\n";
		t.print_str();

		cout << "----Calling foo_bar() from Main()------\n";
		cout << "----Creating a new object (t1) to hold the returned value from foo_bar()------\n";
		TestCopyConstructor t1 = foo_bar();
		cout << "----Finished Calling foo_bar() from Main()------\n";
		cout << "----Calling t1.print_str() from Main()------\n";
		t1.print_str();



		cout << "----Creating a new object (t2) assign value from t1------\n";
		TestCopyConstructor t2 = t1;
		cout << "----calling t2.print_str()------\n";
		t2.print_str();

		cout << "----calling t.print_str()------\n";
		t.print_str();

		cout << "----Next line t=t2 is going to produce runtime error before going out of scope------\n";
		t = t2;
		cout << "----calling t.print_str()------\n";
		t.print_str();
		cout << "----going out of scope in main()------\n";
		getchar();
	}
	getchar();
	return 0;
}