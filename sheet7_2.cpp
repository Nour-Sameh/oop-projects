#include<iostream>
#include<string>
using namespace std;
class program {
protected:
	string name, div[2];
public:
	void read() {
		cout << "Enter program name: ";
		cin >> name;
		cout << "Enter division names 1,2: ";
		cin >> div[0] >> div[1];
	}
};
class div1 :virtual public program {
protected:
	string nd1, con1[3], gpac1[3];
	float cod1[3], avg;
	int tcod1[3];
public:
	void read() {
		program::read();
		nd1 = div[0];
		cout << "enter cond1: ";
		for (int i = 0; i < 3; i++) {
			cout << "Enter course name, obtained marks, and total marks for course " << i + 1 << ": ";
			cin >> con1[i] >> cod1[i] >> tcod1[i];
			float pre = (cod1[i] / tcod1[i]) * 100;
			if (pre >= 92) {
				gpac1[i] = "A";
			}
			else if (pre >= 84) {
				gpac1[i] = "B+";
			}
			else if (pre >= 80) {
				gpac1[i] = "B";
			}
			else if (pre >= 75) {
				gpac1[i] = "C+";
			}
			else if (pre >= 65) {
				gpac1[i] = "C";
			}
			else if (pre >= 60) {
				gpac1[i] = "D";
			}
			else {
				gpac1[i] = "F";
			}
		}
	}
	float total() {
		float tot = 0,sum=0;
		for (int i = 0; i < 3; i++) {
			if (gpac1[i] != "F") {
				tot += cod1[i];
			}
		}
		avg = tot / 3.0;
		return tot;
	}
};
class div2 :virtual public program {
protected:
	string nd2, con2[4], gpac2[4];
	float cod2[4], avg;
	int tcod2[4];
public:
	void read() {
		nd2 = div[1];
		for (int i = 0; i < 4; i++) {
			cout << "Enter course name, obtained marks, and total marks for course " << i + 1 << ": ";
			cin >> con2[i] >> cod2[i] >> tcod2[i];
			float pre = (cod2[i] / tcod2[i]) * 100;
			if (pre >= 92) {
				gpac2[i] = "A";
			}
			else if (pre >= 84) {
				gpac2[i] = "B+";
			}
			else if (pre >= 80) {
				gpac2[i] = "B";
			}
			else if (pre >= 75) {
				gpac2[i] = "C+";
			}
			else if (pre >= 65) {
				gpac2[i] = "C";
			}
			else if (pre >= 60) {
				gpac2[i] = "D";
			}
			else {
				gpac2[i] = "F";
			}
		}
	}
	float total() {
		float tot = 0;
		for (int i = 0; i < 4; i++) {
			if (gpac2[i] != "F") {
				tot += cod2[i];
			}
		}
		avg = tot / 4.0;
		return tot;
	}
};
class student :public div1, div2 {
protected:
	string name, gpa;
	float average, age;
	int id;
public:
	void read() {
		cout << "Enter student name & age& id: ";
		cin >> name >> age >> id;
		div1::read();
		div1::total();
		div2::read();
		div2::total();
		average = (div1::avg + div2::avg) / 2;
		float pre = average;
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
	float total() {
		return (div1::total() + div2::total());
	}
	void display() {
		cout << "Name: " << name << "\nAge: " << age << "\nID: " << id << "\ngpa: " << gpa << "\navg" << average << endl;
		cout << nd1 << endl;
		for (int i = 0; i < 3; i++) {
			cout << con1[i] << " " << cod1[i] << " " << tcod1[i] << " " << gpac1[i] << " " << endl;
		}
		cout << "Division 1 Total: " << div1::total() << "\n";
		cout << nd2 << endl;
		for (int i = 0; i < 4; i++) {
			cout << con2[i] << " " << cod2[i] << " " << tcod2[i] << " " << gpac2[i] << " " << endl;
		}
		cout << "Division 2 Total: " << div2::total();
	}
};
int main() {
	student st;
	st.read();
	st.display();
	return 0;
}