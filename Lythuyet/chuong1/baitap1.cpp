#include <iostream>
#include <cmath>
using namespace std;
struct phanso
{
    int tu, mau;
};

// bổ trợ
int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int lcm(int a, int b)
{
    a = abs(a);
    b = abs(b);
    return (a * b) / gcd(a, b);

}

void nhapPS(phanso &a)
{
    cin >> a.tu >> a.mau;
}
// a. Viết chương trình nhập vào một phân số, 
// rút gọn phân số và xuất kết quả.
void xuatPSrutgon(phanso a)
{
    if(a.tu == 0)
    {
        cout << 0 << endl;
    }
    else if(a.tu % a.mau == 0)
    {
        cout << a.tu / a.mau << endl;
    }
    else
    {   
        if(a.mau < 0)
        {
            a.tu *= -1;
            a.mau *= -1;
        }
        int temp = gcd(a.tu, a.mau);
        a.tu /= temp;
        a.mau /= temp;
        cout << a.tu << "/" << a.mau << endl; 
    }
}

// b. Viết chương trình nhập vào hai phân số, 
// tìm phân số lớn nhất và xuất kết quả.

phanso PSmax(phanso a, phanso b)
{
    if(a.tu / a.mau > b.tu / b.mau)
    {
        return a;
    }
    else return b;
}
// c. Viết chương trình nhập vào hai phân số. 
// Tính tổng, hiệu, tích, thương giữa chúng 
// và xuất kết quả.

phanso tongPS(phanso a, phanso b)
{
    phanso tong;
    int temp = lcm(a.mau, b.mau);
    tong.tu = a.tu *(temp / a.mau) + b.tu *(temp / b.mau);
    tong.mau = temp;
    return tong;
}

phanso hieuPS(phanso a, phanso b)
{
    phanso hieu;
    int temp = lcm(a.mau, b.mau);
    hieu.tu = a.tu *(temp / a.mau) - b.tu *(temp / b.mau);
    hieu.mau = temp;
    return hieu;
}

phanso tichPS(phanso a, phanso b)
{
    phanso tich;
    tich.tu = a.tu * b.tu;
    tich.mau = b.mau * a.mau;
    return tich;
}

phanso thuongPS(phanso a, phanso b)
{
    phanso thuong;
    thuong.tu = a.tu * b.mau;
    thuong.mau = b.tu * a.mau;
    return thuong;
}



int main()
{

    phanso a, b;
    nhapPS(a);
    nhapPS(b);
    xuatPSrutgon(a);
    xuatPSrutgon( PSmax(a, b));
    xuatPSrutgon( tongPS(a, b));
    xuatPSrutgon( hieuPS(a, b));
    xuatPSrutgon( tichPS(a, b));
    xuatPSrutgon( thuongPS(a, b));

    return 0;

}
