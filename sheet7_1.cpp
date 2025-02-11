#include<iostream>
using namespace std;
#define el endl
class rect {
protected:
	float dim[10][2];
	int n;
public:
	void read() {
		cout << "n:  ";
		cin >> n;
		cout << "dim : ";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				cin >> dim[i][j];
			}
		}
	}
	float area(int x) {
		return (dim[x][0] * dim[x][1]);
	}
	void print() {
		cout << "dim is: "<<el;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				cout<< dim[i][j]<<" ";
			}
			cout << el;
		}
		cout << el;
	}
};
class rarea :public rect {
protected:
	float ra[10];
public:
	void set() {
		read();
		for (int i = 0; i < n; i++) {
			ra[i] = area(i);
		}
	}
	void print() {
		rect::print();
		cout << "ra is: " << el;
		for (int i = 0; i < n; i++) {
			cout << ra[i]<<" ";
		}
		cout << el<<el;
	}
};
class pvolum :public rarea {
protected:
	float h[10], v[10];
public:
	void set() {
		rarea::set();
		cout << " h: "<<el;
		for (int i = 0; i < n; i++) {
			cin>> h[i];
		}
		for (int i = 0; i < n; i++) {
			v[i] = h[i] * ra[i];
		}
	}
	void print() {
		rarea::print();
		cout << "h and v : "<<el;
		for (int i = 0; i < n; i++) {
			cout << h[i] << " " << v[i]<<el;
		}
	}
};
int main() {
	pvolum ob;
	ob.set();
	ob.print();
	return 0;
}