// b. Viết chương trình nhập họ tên, điểm toán, 
// điểm văn của một học sinh. Tính điểm 
// trung bình và xuất kết quả.

#include <iostream>
using namespace std;

struct student
{
    char hoten[100];
    double toan, van, dtb;
};
void inputST(student &a)
{
    cin.getline(a.hoten, 100);
    cin >> a.toan >> a.van;
    a.dtb = (a.van + a.toan)/2;
}
void outputST(student a)
{
    puts(a.hoten);
    cout << "toan\tvan\tdtb\n";
    cout.precision(2);
    cout << a.toan << "\t" << a.van << "\t" << a.dtb << endl;
}
int main()
{
    student a;
    inputST(a);
    outputST(a);
    return 0;

}