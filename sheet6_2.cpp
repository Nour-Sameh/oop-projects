#include<iostream>
#include<string>
using namespace std;
#define el endl
class course{
public:
	string c_name;
	float degree;
	int credit;
};
class level {
protected:
	course l[5];
public:
	void read() {
		cout << "course name,degree,credit: ";
		for (int i = 0; i < 5 ; i++) {
			cin >> l[i].c_name >> l[i].degree >> l[i].credit;
		}
	}
	void display() {
		for (int i = 0; i < 5; i++) {
			cout<< l[i].c_name << l[i].degree << l[i].credit;
		}
	}
};
class student :public level {
	string name,gpa;
	int id, total_c;
	float total_d;
public:
	void read() {
		cout << "name &id: ";
		cin >> name >> id;		
		level::read();
		total_c = 0;
		total_d = 0;
		for (int i = 0; i < 5; i++) {
			total_c += l[i].credit;
			total_d += l[i].degree;
		}
		float pre = total_d / 5.0;
		if (pre >= 92) {
			gpa = "A";
		}
		else if (pre >= 84) {
			gpa = "B+";
		}
		else if (pre >= 80) {
			gpa = "B";
		}
		else if (pre >= 75) {
			gpa = "C+";
		}
		else if (pre >= 65) {
			gpa = "C";
		}
		else if (pre >= 60) {
			gpa = "D";
		}
		else {
			gpa = "F";
		}
	}
	void display() {
		cout << "name: " << name << "\nid: " << id << "\ntotal_c: " << total_c << "\ntotal_d: " << total_d << "\ngpa: "<<gpa<<endl;
	}
};
int main() {
	cout <<"enter n: ";
	int n; cin >> n;
	student st[10];
	for (int i = 0; i < n; i++) {
		st[i].read();
		st[i].display();
	}
	return 0;
}