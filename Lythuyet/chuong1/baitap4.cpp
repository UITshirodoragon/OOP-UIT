#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
// Cho một danh sách lưu thông tin của các nhân viên trong một công ty, thông tin gồm:
// - Mã nhân viên (chuỗi, tối đa là 8 ký tự)
// - Họ và tên (chuỗi, tối đa là 20 ký tự)
// - Phòng ban (chuỗi, tối đa 10 ký tự)
// - Lương cơ bản (số nguyên)
// - Thưởng (số nguyên)
// - Thực lãnh (số nguyên, trong đó thực lãnh = lương cơ bản + thưởng )
// Hãy thực hiện các công việc sau:

// b.In danh sách những nhân viên có mức lương cơ bản thấp nhất.
// c.Đếm số lượng nhân viên có mức thưởng >= 1200000.
// d.In danh sách các nhân viên tăng dần theo phòng ban, nếu phòng ban trùng nhau thì 
// giảm dần theo mã nhân viên.
struct nhanvien
{
    char ma[9];
    char hoten[21];
    char phongban[11];
    long luong, thuong, thuclanh;
};

void inputNV(nhanvien *&list, int &n)
{
    cin >> n;
    cin.ignore();
    list = new nhanvien[n];
    
    for(int i = 0; i < n; i++)
    {
        
        cin.getline((list+i)->ma, 9);
        cin.getline((list+i)->hoten, 21);
        cin.getline((list+i)->phongban, 11);
        cin >> (list+i) ->luong >> (list+i)->thuong;
        cin.ignore();
        (list+i)->thuclanh = (list+i)->luong + (list+i)->thuong;
    }

}
void outputNV(nhanvien *list, int n)
{
    
    cout << setw(10) << left << "ID";
    cout << setw(22) << left << "Ho Ten";
    cout << setw(12) << left << "Phong Ban";
    cout << setw(10) << left << "Luong";
    cout << setw(10) << left << "Thuong";
    cout << setw(10) << left << "Thuc lanh";
    cout << "\n";
    cout << setfill('-');
    cout << setw(75) << '-' << endl;
    cout << setfill(' '); // reset

    for(int i = 0; i < n; i++)
    { 
            cout << setw(10) << left << (list+i)->ma;
            cout << setw(22) << left << (list+i)->hoten;
            cout << setw(12) << left << (list+i)->phongban;
            cout << setw(10) << left << (list+i)->luong;
            cout << setw(10) << left << (list+i)->thuong;
            cout << setw(10) << left << (list+i)->thuclanh;
            cout << "\n";
    }
    cout << setfill('-');
    cout << setw(75) << '-' << endl;
    cout << setfill(' '); // reset
}
// a.Tính tổng thực lãnh tháng của tất cả nhân viên trong công ty.
void tongthuclanh(nhanvien *list, int n)
{
    long sum = 0;
    for(int i = 0; i < n; i++)
    {   
        sum += (list+i)->thuclanh;
    }
    cout << "tong thuc lanh: " << sum << endl;
}

// b.In danh sách những nhân viên có mức lương cơ bản thấp nhất.
void outputleast(nhanvien *list, int n)
{
    cout << "luong co ban thap nhat\n";
    int min = 0;
    for(int i = 1; i < n; i++)
    {
        if( (list+i)->luong < (list+min)->luong ) min = i;
    }
    cout << setw(10) << left << "ID";
    cout << setw(22) << left << "Ho Ten";
    cout << setw(12) << left << "Phong Ban";
    cout << setw(10) << left << "Luong";
    cout << setw(10) << left << "Thuong";
    cout << setw(10) << left << "Thuc lanh";
    cout << "\n";
    cout << setfill('-');
    cout << setw(75) << '-' << endl;
    cout << setfill(' '); // reset

    for(int i = 0; i < n; i++)
    { 
        if((list+min)->luong == (list+i)->luong)
        {   
            cout << setw(10) << left << (list+i)->ma;
            cout << setw(22) << left << (list+i)->hoten;
            cout << setw(12) << left << (list+i)->phongban;
            cout << setw(10) << left << (list+i)->luong;
            cout << setw(10) << left << (list+i)->thuong;
            cout << setw(10) << left << (list+i)->thuclanh;
            cout << "\n";
        }
            
    }
    cout << setfill('-');
    cout << setw(75) << '-' << endl;
    cout << setfill(' '); // reset

}
//c.Đếm số lượng nhân viên có mức thưởng >= 1200000.

void count(nhanvien *list, int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if((list+i)->thuong >= 1200000)
        {
            c++;
        }
    }
    cout << "so luong: " << c << endl;
}
//d.In danh sách các nhân viên tăng dần theo phòng ban, nếu phòng ban trùng nhau thì 
// giảm dần theo mã nhân viên.

void sortNV(nhanvien *list, int n)
{
    for (int i = 0; i < n - 1; ++i) {
        
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (strcmp( (list+j)->phongban , (list+minIndex)->phongban ) < 0 || (strcmp( (list+j)->phongban , (list+minIndex)->phongban ) == 0 && strcmp( (list+j)->ma , (list+minIndex)->ma ) == 1)) {
                minIndex = j;
            }
        }
        nhanvien t = *(list+i);
        *(list+i) = *(list+minIndex);
        *(list+minIndex) = t;
        // thêm điều kiện là được
    }
}

int main()
{
    int n;
    nhanvien *data;
    inputNV(data, n);
    outputNV(data, n);
    outputleast(data,n);
    count(data, n);
    sortNV(data, n);
    outputNV(data,n);
    return 0;

}