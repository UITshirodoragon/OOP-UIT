#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// B20DCCN001 Nguyen Van A D20CQCN04-B 02/02/2002 2.00

class SinhVien
{
    private:
        string Ma, HoTen, Lop, NgaySinh;
        double gpa;
        static int stt;
    public:
        SinhVien()
        {
            stt++;
            this -> Ma = "B20DCCN" + string(3 - to_string(stt).length(), '0') + to_string(stt);
            this -> HoTen = strdup(" ");
            this -> Lop = strdup(" ");
            this -> NgaySinh = strdup("dd/mm/yyyy");
            this -> gpa = 0;
        }
        SinhVien(string HoTen, string Lop, string NgaySinh, double gpa)
        {
            stt++;
            this -> Ma = "B20DCCN" + string(3 - to_string(stt).length(), '0') + to_string(stt);
            this -> HoTen = HoTen;
            this -> Lop = Lop;
            this -> NgaySinh = NgaySinh;
            this -> gpa = gpa;
        }
        friend istream& operator >> (istream& input, SinhVien& a)
        {
            getline(input, a.HoTen, '\n');
            getline(input, a.Lop, '\n');
            getline(input, a.NgaySinh, '\n');
            if(a.NgaySinh[2] != '/')
            {
                a.NgaySinh = '0' +  a.NgaySinh;
            }
            if(a.NgaySinh[5] != '/')
            {
                a.NgaySinh.insert(a.NgaySinh.begin() + 3, '0');
            }
            input >> a.gpa;
            input.ignore();
            return input;
        }

        friend ostream& operator << (ostream& output, SinhVien a)
        {
            output << a.Ma << " " << a.HoTen << " " << a.Lop << " " << a.NgaySinh << " " << a.gpa << endl;
            return output;
        }
        friend void nhap(SinhVien &);
        friend void in(SinhVien);
        
};

int SinhVien::stt = 0;

void nhap(SinhVien& a)
{
    getline(cin, a.HoTen, '\n');
    getline(cin, a.Lop, '\n');
    getline(cin, a.NgaySinh, '\n');
    if(a.NgaySinh[2] != '/')
    {
        a.NgaySinh = '0' +  a.NgaySinh;
    }
    if(a.NgaySinh[5] != '/')
    {
        a.NgaySinh.insert(a.NgaySinh.begin() + 3, '0');
    }
    cin >> a.gpa;
    cin.ignore();

}

void in(SinhVien a)
{
    cout << a.Ma << " " << a.HoTen << " " << a.Lop << " " << a.NgaySinh << " " << a.gpa << endl;
}





int main()
{
    SinhVien a;
    cin >> a;
    cout << a;
    return 0;

}