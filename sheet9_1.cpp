#include <iostream>
using namespace std;
class base {
protected:
    int b[30];
    int n;
    int fac(int x) {
        if (x <= 1) return 1;
        else return x * fac(x - 1);
    }
public:
    void read() {
        cout << "enter n: ";
        cin >> n;
        cout << "enter arr of B: ";
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
    }
    int max() {
        int max_val = b[0];
        for (int i = 1; i < n; i++) {
            if (b[i] > max_val) max_val = b[i];
        }
        return max_val;
    }
    virtual int facsum() {
        return fac(max());
    }
    void display() {
        cout << this->facsum() << endl;
    }
};
class div1 : virtual public base {
protected:
    int d1[30];
public:
    void read() {
        for (int i = 0; i < n; i++) {
            d1[i] = 0;
            for (int j = 1; j <= b[i]; j++) {
                if (b[i] % 2 == 0) d1[i] += j * j;
                else d1[i] += j * j * j;
            }
        }
    }
    int max() {
        int max_val = d1[0];
        for (int i = 1; i < n; i++) {
            if (d1[i] > max_val) max_val = d1[i];
        }
        return max_val;
    }
    int facmax() {
        return fac(max());
    }
};
class div2 : virtual public base {
protected:
    int d2[30];
public:
    void read() {
        for (int i = 0; i < n; i++) {
            d2[i] = 1;
            for (int j = 1; j <= b[i]; j++) {
                if (b[i] % 2 == 0) d2[i] *= j * j;
                else d2[i] *= j * j * j;
            }
        }
    }
    int max() {
        int max_val = d2[0];
        for (int i = 1; i < n; i++) {
            if (d2[i] > max_val) max_val = d2[i];
        }
        return max_val;
    }
    int facmax() {
        return fac(max());
    }
};
class drive : public div1, public div2 {
private:
    int d[30];
public:
    void read() {
        base::read();
        div1::read();
        div2::read();
        d[0] = base::max();
        d[1] = div1::max();
        d[2] = div2::max();
    }
    int facsum() {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += d[i];
        }
        return fac(sum);
    }
};
int main() {
    div1 obj1;
    div2 obj2;
    drive obj3;
    cout << "Enter data for div1:\n";
    obj1.base::read();
    obj1.read();
    cout << "Enter data for div2:\n";
    obj2.base::read();
    obj2.read();
    cout << "Enter data for drive:\n";
    obj3.read();
    base* ptr[3] = { &obj1, &obj2, &obj3 };
    for (int i = 0; i < 3; i++) {
        ptr[i]->display();
    }
    cout << "Factorial of sum in drive: " << obj3.facsum() << endl;
    return 0;
}