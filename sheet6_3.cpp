#include<iostream>
#include<cmath>
#include<string>
using namespace std;
#define el endl
class data1 {
protected:
	string s1;
	double d1[20];
	int a, n;
public:
	void read() {
		cout << "enter n & s1: ";
		cin >> n>>s1;
		cout << "enter d1: ";
		for (int i = 0; i < n; i++) {
			cin >> d1[i];
		}
	}
	double sum() {
		double s = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j <= i + 1; j++) {
				if (int(d1[i]) % a == 0) {
					s += pow(d1[i], 2 * (j + 1));
				}
				else {
					s += pow(d1[i], (j + 1));
				}
			}
		}
		return s;
	}
	void display() {
		cout << "d1 is: ";
		for (int i = 0; i < n; i++) {
			cout<< d1[i]<<" ";
		}
		cout << endl;
	}
};
class data2 {
protected:
	string s2;
	double d2[20];
	int b, m;
public:
	void read() {
		cout << "enter m & s2: ";
		cin >> m >> s2;
		cout << "enter m & d2: ";
		for (int i = 0; i < m; i++) {
			cin >> d2[i];
		}
	}
	double sum() {
		double s = 0;
		for (int i = 0; i < m; i++) {
			for (int j = i; j <= i + 1; j++) {
				if (d2[i] > b ) {
					s += pow(d2[i], 2 * (j + 1));
				}
				else {
					s += pow(d2[i], (j + 1));
				}
			}
		}
		return s;
	}
	void display() {
		cout << "d2 is: ";
		for (int i = 0; i < m; i++) {
			cout << d2[i]<<" ";
		}
		cout << endl;
	}
};
class DATA :public data1, data2 {
	string nd;
	int t_sum;
public:
	void set_tot_sum() {
		data1::read();
		data1::sum();
		data2::read();
		data2::sum();
		t_sum = data1::sum() + data2::sum();
	}
	void display() {
		data1::display();
		data2::display();
		cout <<"total sum : " << t_sum<<endl;
	}
};
int main() {
	DATA x, y;
	x.set_tot_sum();
	x.display();
	return 0;
}