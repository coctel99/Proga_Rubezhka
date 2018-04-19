#include <iostream>
using namespace std;

class irrnum{
private:
    int a; //Числитель
    int b; //Знаменатель
public:
    irrnum(int n, int m){
        if (m == 0) {
            cout << "Число не существует" << endl;
            return;
        } else {
            a = n;
            b = m;
        }
    }
    friend istream&operator>>(istream& in, irrnum& i){
        in >> i.a >> i.b;
        return in;
    }

    friend ostream&operator<<(ostream& out, const irrnum& i){
        out << i.a << "/" << i.b << endl;
        return out;
    }

    irrnum&operator=(const irrnum& i){
        a = i.a;
        b = i.b;
        return *this;
    }

    bool operator==(const irrnum& i) const {
        if( a == i.a and b == i.b)
            return true;
        else
            return false;
    }

    irrnum&operator*=(const int i){
        a *= i;
        minimize();
        return *this;
    }

    irrnum& operator/=(const int i){
        return *this *= i;
    }

    irrnum&operator*=(const irrnum& i){
        a *= i.a;
        b *= i.b;
        minimize();
        return *this;
    }

    irrnum&operator/=(irrnum& i){
        i.invert();
        minimize();
        return *this *= i;
    }

    irrnum&operator+=(const irrnum& i){
        if(b != i.b){
            a = a * i.b + i.a * b;
            b *= i.b;
        } else {
            a += i.a;
        }
        minimize();
        return *this;
    }

    irrnum&operator-=(const irrnum& i){
        if(b != i.b){
            a = a * i.b - i.a * b;
            b *= i.b;
        } else {
            a -= i.a;
        }
        minimize();
        return *this;
    }


    irrnum&operator+(const irrnum& i){
        irrnum& copy(*this);
        if(copy.b != i.b){
            copy.a = copy.a * i.b + i.a * copy.b;
            copy.b *= i.b;
        } else {
            copy.a += i.a;
        }
        copy.minimize();
        return copy;
    }

    irrnum&operator-(const irrnum& i){
        irrnum& copy(*this);
        if(copy.b != i.b){
            copy.a = copy.a * i.b - i.a * copy.b;
            copy.b *= i.b;
        } else {
            copy.a -= i.a;
        }
        copy.minimize();
        return copy;
    }

    irrnum&operator+(const int i){
        irrnum& copy(*this);
        copy.a += copy.b;
        copy.minimize();
        return copy;
    }

    irrnum&operator-(const int i){
        irrnum& copy(*this);
        copy.a -= copy.b;
        copy.minimize();
        return copy;
    }

    void invert(){
        int c = a;
        a = b;
        b = c;
    };

    void minimize(){
        while(true){
            if (a < 0 and b < 0){
                a = abs(a);
                b = abs(b);
            }
            if (a % 2 == 0 and b % 2 == 0){
                a /= 2;
                b /= 2;
            } else if(a % 3 == 0 and b % 3 == 0){
                a /= 3;
                b /= 3;
            } else if(a % 5 == 0 and b % 5 == 0) {
                a /= 5;
                b /= 5;
            } else if(a % 7 == 0 and b % 7 == 0) {
                a /= 7;
                a /= 7;
            } else break;
        }
    }
};

int main() {
    int n = 1, m = 3;
    irrnum os(n, m);
    irrnum ot(1, 3);
    cin >> os;
    cout << os << endl;
    os -= ot;
    //cout << os << endl;
    irrnum on(1,9);
    os = on + ot + 1;
    //cout << os << endl;
    return 0;
}