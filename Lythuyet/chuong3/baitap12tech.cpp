#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;


class NhanVien
{
    private:
        static int stt;
        string Ma;
        string HoTen;
        string Gioitinh;
        string Ngaysinh;
        string Diachi;
        string MasoThue;
        string NgaykyHD;
    public:
        NhanVien();
        NhanVien(string,string,string,string,string,string);
        friend void inputNV();
        friend void outputNV();
        friend istream & operator >> (istream &, NhanVien &);
        friend ostream & operator << (ostream &, NhanVien );
        friend bool operator < (NhanVien, NhanVien);
        ~NhanVien();
            
};

int NhanVien::stt = 0;

NhanVien::NhanVien()
{
    stt++;
    this -> Ma = string(5 - to_string(stt).length(), '0') + to_string(stt);
    this -> HoTen = " ";
    this -> Gioitinh = " ";
    this -> Ngaysinh = " ";
    this -> Diachi = " ";
    this -> MasoThue = " ";
    this -> NgaykyHD = " ";

}

NhanVien::NhanVien(string HoTen, string Gioitinh, string Ngaysinh,string Diachi,string MasoThue,string NgaykyHD)
{
    stt++;
    this -> HoTen = HoTen;
    this -> Gioitinh = Gioitinh;
    this -> Ngaysinh = Ngaysinh;
    this -> Diachi = Diachi;
    this -> MasoThue = MasoThue;
    this -> NgaykyHD = NgaykyHD;
}

istream & operator >> (istream &input, NhanVien &a)
{
    input.ignore();
    getline(input, a.HoTen ,'\n');
    getline(input, a.Gioitinh,'\n');
    getline(input, a.Ngaysinh,'\n');
    getline(input, a.Diachi,'\n');
    getline(input, a.MasoThue,'\n');
    getline(input, a.NgaykyHD,'\n');
    return input;
}

ostream & operator << (ostream & output, NhanVien a)
{
    output << a.Ma << " " << a.HoTen << " " << a.Gioitinh << " " << a.Ngaysinh << " " << a.Diachi << " " << a.MasoThue << " " << a.NgaykyHD << endl;
    return output;
}

bool operator < (NhanVien a, NhanVien b)
{
    bool year = stoi(a.Ngaysinh.substr(6,4)) == stoi(b.Ngaysinh.substr(6,4));
    bool month = stoi(a.Ngaysinh.substr(3,2)) == stoi(b.Ngaysinh.substr(3,2));
    bool day = stoi(a.Ngaysinh.substr(0,2)) == stoi(b.Ngaysinh.substr(0,2));
    bool year1 = stoi(a.Ngaysinh.substr(6,4)) < stoi(b.Ngaysinh.substr(6,4));
    bool month1 = stoi(a.Ngaysinh.substr(3,2)) < stoi(b.Ngaysinh.substr(3,2));
    bool day1 = stoi(a.Ngaysinh.substr(0,2)) < stoi(b.Ngaysinh.substr(0,2));

    return (year1 || (year && (month1 || (month && day1 ) ) ) );
}

NhanVien::~NhanVien()
{
    
}

int main()
{
    int t;
    cin >> t;

    NhanVien *a = new NhanVien [t];
    for(int i = 0; i < t; i++)
    {
        cin >> a[i];
    }

    sort(a, a + t);
    for(int i = 0; i < t; i++)
    {
        cout << a[i];
    }
    return 0;
}