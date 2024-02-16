#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class DoanhNghiep
{
    private:
        string Ma;
        string Ten;
        int SoluongSV;

    public:
        DoanhNghiep();
        DoanhNghiep(string, string, int);
        friend istream& operator >> (istream & input, DoanhNghiep & a)
        {
            input.ignore();
            getline(input, a.Ma, '\n');
            getline(input, a.Ten, '\n');
            input >> a;
            input.ignore();
            return input;
        }
        friend ostream& operator << (ostream &, DoanhNghiep );
        friend bool cmp(DoanhNghiep a, DoanhNghiep b);
        friend void input(DoanhNghiep &);
        friend void output(DoanhNghiep);
        ~DoanhNghiep();
};

DoanhNghiep::DoanhNghiep()
{
    this -> Ma = "";
    this -> Ten = "";
    this -> SoluongSV = 0;
}
DoanhNghiep::DoanhNghiep(string Ma, string Ten, int SoluongSV)
{
    this -> Ma = Ma;
    this -> Ten = Ten;
    this -> SoluongSV = SoluongSV;
}

DoanhNghiep::~DoanhNghiep()
{
    
}


ostream& operator << (ostream & output, DoanhNghiep a)
{
    output << a.Ma << " " << a.Ten << " " << a.SoluongSV << endl;
    return output;
}

bool cmp(DoanhNghiep a, DoanhNghiep b)
{
    return ( a.SoluongSV > b.SoluongSV || (a.SoluongSV == b.SoluongSV && a.Ma.compare(b.Ma) < 0));
}

void input(DoanhNghiep &a)
{
    getline(cin, a.Ma, '\n');
    getline(cin, a.Ten, '\n');
    cin >> a.SoluongSV;

}
void output(DoanhNghiep a)
{
    cout << a.Ma << " " << a.Ten << " " << a.SoluongSV << endl;
}

int main()
{
    int n;
    vector<DoanhNghiep> vDN;

    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        DoanhNghiep x;
        input(x);
        cin.ignore();
        vDN.push_back(x);
    }

    sort(vDN.begin(), vDN.end(), cmp);

    for(DoanhNghiep x : vDN)
    {
        cout << x;
    }
}