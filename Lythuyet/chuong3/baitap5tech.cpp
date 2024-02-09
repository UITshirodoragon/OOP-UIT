#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

class SinhVien
{
    private:
        string Ma, HoTen, Lop, email;
        static int stt;
    public:
        SinhVien()
        {
            stt++;
            this -> Ma = "B20DCCN" + string(3 - to_string(stt).length(), '0') + to_string(stt);
            this -> HoTen = strdup(" ");
            this -> Lop = strdup(" ");
            this -> email = strdup(" ");
            
        }
        SinhVien(string HoTen, string Lop, string email)
        {
            stt++;
            this -> Ma = "B20DCCN" + string(3 - to_string(stt).length(), '0') + to_string(stt);
            this -> HoTen = HoTen;
            this -> Lop = Lop;
            this -> email = email;
        }
        friend istream& operator >> (istream& input, SinhVien& a)
        {
            getline(input, a.HoTen, '\n');
            getline(input, a.Lop, '\n');
            getline(input, a.email, '\n');
            input.ignore();
            return input;
        }

        friend ostream& operator << (ostream& output, SinhVien a)
        {
            output << a.Ma << " " << a.HoTen << " " << a.Lop << " " << a.email << endl;
            return output;
        }
        friend bool cmp(SinhVien , SinhVien);

        friend void nhap(SinhVien &);
        friend void in(SinhVien);
        
};

int SinhVien::stt = 0;

void nhap(SinhVien& a)
{
    getline(cin, a.HoTen);
    getline(cin, a.Lop);
    getline(cin, a.email);
    cin.ignore();
}

void in(SinhVien a)
{
    cout << a.Ma << " " << a.HoTen << " " << a.Lop << " " << a.email << endl;
}

bool cmp(SinhVien a, SinhVien b)
{
    return ((a.Lop.compare(b.Lop) < 0) || (a.Lop.compare(b.Lop) == 0 && a.Ma.compare(b.Ma) < 0));
}
void sortSV(SinhVien *data, int n)
{
    for (int i = 0; i < n - 1; ++i) {
        
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (cmp(data[j], data[minIndex])) {
                minIndex = j;
            }
        }
        SinhVien t = data[i];
        data[i] = data[minIndex];
        data[minIndex] = t;
        // thêm điều kiện là được
    }
}
int main()
{
    // int n;
    // cin >> n;
    // cin.ignore();
    // SinhVien *data = new SinhVien [n];
    // for(int i = 0; i < n; i++)
    // {
    //     nhap(data[i]);
    // }
    // sortSV(data, n);
    // for(int i = 0; i < n; i++)
    // {
    //     in(data[i]);
    // }
    // return 0;
    

    // nhap den khi nao het thi thoi
    
    vector<SinhVien> a;
    SinhVien temp;
    while(cin >> temp)
    {
        a.push_back(temp);
    }

    sort(a.begin(),a.end(),cmp );

    for(SinhVien t : a)
    {
        cout << t;
    }
}