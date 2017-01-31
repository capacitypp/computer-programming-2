#include <iostream>

using namespace std;

class complex {
	double re, im;

public:
	complex(double r, double i) : re(r), im(i) {cout << "a" << endl;}
	complex(double r) : re(r), im(0) {cout << "b" << endl;}
	complex operator+(complex) { return *this; };
	complex operator*(complex) { return *this; };
	complex operator-(complex) { return *this; };
	complex operator+=(complex) { return *this; };
};

int main()
{
	complex a = *(new complex(1, 3));
	complex b = {4, -1};
	complex c {b};
	const complex d = 3;
	//complex a(0, 0);
	cout << "bb" << endl;
	a += {1, 2};
	b = a + 2;
	//c += complex(2) + b  - a;

	return 0;
}

