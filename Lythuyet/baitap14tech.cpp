#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>


using namespace std;

string ChuanHoaHoten(string a)
{
    string res = "";
    string tmp;
    stringstream ss(a);
    while( ss >> tmp)
    {
        res += toupper(tmp[0]);
        for(int i = 1; i < tmp.length(); i++)
        {
            res += tolower(tmp[i]);
        }
        res += " ";
    }
    res.erase(res.length() - 1);
    return res;
}

string ChuanHoaBoMon(string a)
{
    string res = "";
    string tmp;
    stringstream ss(a);
    while(ss >> tmp)
    {
        res += toupper(tmp[0]);
    }
    return res;
}



class GiaoVien
{
    private:
        static int stt;
        string Ma = "GV" + string(2 - to_string(stt).length(), '0') + to_string(stt);
        string Hoten, Bomon;
    public:
        GiaoVien();
        GiaoVien(string, string);
        ~GiaoVien();
        string getTen()
        {
            string res;
            stringstream ss(this -> Hoten);
            string tmp;
            
            while(ss >> tmp)
            {
                res = tmp;
            }
            return res;
        }
        string getBoMon()
        {
            return this -> Bomon;
        }
        friend istream & operator >> (istream &, GiaoVien &);
        friend ostream & operator << (ostream &, GiaoVien );
        friend bool search(GiaoVien, string);
        friend bool cmp(GiaoVien, GiaoVien);

};

int GiaoVien::stt = 1;

GiaoVien::GiaoVien()
{
    stt++;
    this -> Hoten = "";
    this -> Bomon = ""; 
}
GiaoVien::GiaoVien(string Hoten, string Bomon)
{
    stt++;
    this -> Hoten = Hoten;
    this -> Bomon = Bomon;
}
GiaoVien::~GiaoVien()
{

}
istream & operator >> (istream & in, GiaoVien & a)
{
    
    getline(in, a.Hoten, '\n');
    a.Hoten = ChuanHoaHoten(a.Hoten);
    getline(in, a.Bomon, '\n');
    a.Bomon = ChuanHoaBoMon(a.Bomon);
    return in;
}

ostream & operator << (ostream & out, GiaoVien a)
{
    out << a.Ma << " " << a.Hoten << " " << a.Bomon << endl;
    return out;
}
bool cmp(GiaoVien a, GiaoVien b)
{
    return (a.getTen().compare(b.getTen()) < 0) || ((a.getTen().compare(b.getTen()) == 0) && a.Ma.compare(b.Ma) < 0);
}
bool search(GiaoVien a, string word)
{
    for(char &x : a.Hoten) x = tolower(x);
    for(char &x : word) x = tolower(x);
    return (a.Hoten.find(word) != string::npos);
}
int main()
{
    map<string, vector<GiaoVien>> mp;
    int n;
    cin >> n;
    cin.ignore();
    GiaoVien *a = new GiaoVien [n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    string find;
    getline(cin, find, '\n');//find = ChuanHoaBoMon(find);
    for(int i = 0; i < n; i++)
    {
        if(search(a[i], find))
        {
            cout << a[i];
        }
        
        mp[a[i].getBoMon()].push_back(a[i]);
    }
    
    
    
    
    


    return 0;
}