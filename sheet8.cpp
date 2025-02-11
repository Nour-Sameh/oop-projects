#include<iostream>
#define ll long long 
using namespace std;
class base {
protected:
	int B[30], n;
	char T[30];
public:
	void read() {
		cout << "enter n: ";
		cin >> n;
		cout << "enter arr of b: ";
		for (int i = 0; i < n; i++) {
			cin >> B[i];
		}
		set();
	}
	bool is_p(int x) {
		if (x == 1)return false;
		for (int i = 2; i * i < x; i++) {
			if (x % i == 0)return false;
		}
		return true;
	}
	void set() {
		for (int i = 0; i < n; i++) {
			if (is_p(B[i])) {
				T[i] = 'Y';
			}
			else T[i] = 'F';
		}
	}
	virtual float avg() {
		float sum = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			if (T[i] == 'Y') {
				sum += B[i];
				cnt++;
			}
		}
		return sum / cnt;
	}
};
class derive :public base {
	ll F[30];
	int h;
public:
	int fact(int x) {
		if (x <= 1)return x;
		return x * fact(x - 1);
	}
	void read() {
		base::read();
		cout << "enter h: ";
		cin >> h;
		for (int i = 0; i < n; i++) {
			F[i] = fact(B[i]);
		}
	}
	float avg() {
		float sum = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			if (F[i] > h) {
				sum += F[i];
				cnt++;
			}
		}
		return sum / cnt;
	}
};
int main() {
	base b, * p;
	derive d;
	p = &b;
	b.read();
	cout << "average of first class: " << p->avg() << endl;
	p = &d;
	d.read();
	cout << "average of second class: " << p->avg() << endl;
	return 0;
}