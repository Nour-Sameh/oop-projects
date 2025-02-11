#include <iostream>
#define ll long long
using namespace std;
template<class t>
class mat {
protected:
    t m[30][30], n;
public:
    void read() {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
    }
    t prod(int x) {
        t prod = 1;
        for (int i = 0; i < n; i++) {
            prod *= m[i][x];
        }
        return prod;
    }
};
template<class t>
class Data :public mat<t> {//      class name  <t>
    t d[30];
public:
    void set() {
        for (int i = 0; i < this->n; i++) {
            d[i] = this->prod(i);  //         this->
        }
    }
    void display() {
        for (int i = 0; i < this->n; i++) {
            for (int j = 0; j < this->n; j++) {
                cout << this->m[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl << " element in d:  ";
        for (int i = 0; i < this->n; i++) {
            cout << d[i] << "\t";
        }
        cout << endl;
    }
};
int main() {
    Data<int>ob1;
    Data<int>ob2;
    ob1.read();
    ob1.set();
    ob1.display();
    ob2.read();
    ob2.set();
    ob2.display();
    return 0;
}