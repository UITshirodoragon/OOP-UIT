#include <iostream>
using namespace std;

using ll = long long;


class PhanSo
{
    private:
        long long tu, mau;

    public:
        PhanSo(): tu(0), mau(0) {}
        PhanSo(long long a, long long b): tu(a), mau(b) {}
        friend istream &operator >> (istream& , PhanSo&);
        
        friend ostream &operator << (ostream& , PhanSo);
        
        PhanSo operator + (PhanSo a);
        void rutgon();

};

istream &operator >> (istream& input, PhanSo& a)
{
    input >> a.tu >> a.mau;
    return input;
}
ostream &operator << (ostream& output, PhanSo a)
{
    output << a.tu << "/" << a.mau << endl;
    return output;
}

long long gcd(long long a, long long b)
{
    a = abs(a);
    b = abs(b);

    while (b != 0) {
        long long temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

long long lcm(long long a, long long b)
{
    a = abs(a);
    b = abs(b);

    return (a * b)/ gcd(a, b);
}
PhanSo PhanSo::operator + (PhanSo a)
{
    PhanSo tong;
    long long temp = lcm(this -> mau, a.mau);
    tong.tu = (this -> tu) * (temp / this -> mau) + a.tu * (temp / a.mau);
    tong.mau = temp;
    return tong;
}
void PhanSo::rutgon()
{
    long long temp = gcd(this -> tu, this -> mau);
    this -> tu /= temp;
    this -> mau /= temp;
}




int main()
{
    PhanSo p(1, 1);
    cin >> p;
    p.rutgon();
    cout << p;
    return 0;
}